#!/usr/bin/env node

import { execSync } from "node:child_process";
import fs from "node:fs";
import path from "node:path";
import os from "node:os";
import https from "node:https";
import { fileURLToPath } from "node:url";
import AdmZip from "adm-zip";

function exec(cmd) {
  console.log(`> ${cmd}`);
  execSync(cmd, { stdio: "inherit" });
}

const args = process.argv.slice(2);
const layoutId = args[0];
const geometry = args[1];

if (!layoutId || !geometry) {
  console.error("Usage: sync-oryx-layout <layoutId> <geometry>");
  process.exit(1);
}

/* ---------------- Git setup ---------------- */

exec("git checkout oryx");
exec("git pull --unshallow || git pull");

/* ---------------- GraphQL ---------------- */

const query = JSON.stringify({
  query: `
    query getLayout($hashId: String!, $revisionId: String!, $geometry: String) {
      layout(hashId: $hashId, geometry: $geometry, revisionId: $revisionId) {
        revision { hashId qmkVersion title }
      }
    }
  `,
  variables: {
    hashId: layoutId,
    geometry,
    revisionId: "latest",
  },
});

function postJson(url, body) {
  return new Promise((resolve, reject) => {
    const req = https.request(
      url,
      {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
          "Content-Length": Buffer.byteLength(body),
        },
      },
      res => {
        let data = "";
        res.on("data", c => (data += c));
        res.on("end", () => resolve(JSON.parse(data)));
      }
    );
    req.on("error", reject);
    req.write(body);
    req.end();
  });
}

console.log("Fetching layout metadata...");
const response = await postJson("https://oryx.zsa.io/graphql", query);

const revision = response.data.layout.revision;
const hashId = revision.hashId;
const firmwareVersion = Math.round(revision.qmkVersion);
const changeDescription =
  revision.title || "latest layout modification made with Oryx";

/* ---------------- Download ZIP ---------------- */

const zipUrl = `https://oryx.zsa.io/source/${hashId}`;
const zipPath = path.join(os.tmpdir(), "oryx-source.zip");

await new Promise((resolve, reject) => {
  const file = fs.createWriteStream(zipPath);
  https.get(zipUrl, res => {
    res.pipe(file);
    file.on("finish", () => file.close(resolve));
  }).on("error", reject);
});

/* ---------------- Extract ---------------- */

// const targetDir = path.resolve(layoutId);
const targetDir = "keyboards/zsa/voyager/keymaps/knayd";
fs.mkdirSync(targetDir, { recursive: true });

const zip = new AdmZip(zipPath);
zip.getEntries()
  .filter(e =>
    e.entryName.includes("_source/") &&
    !e.isDirectory
  )
  .forEach(e => {
    const dest = path.join(
      targetDir,
      path.basename(e.entryName)
    );
    fs.writeFileSync(dest, e.getData());
  });

/* ---------------- Commit ---------------- */

exec("git add .");

try {
  exec(`git commit -m "✨(oryx): ${changeDescription}"`);
  exec(`git checkout main`);
  exec(`git merge -Xignore-all-space oryx`);
} catch {
  console.log("No layout change");
}

// exec("git push");
