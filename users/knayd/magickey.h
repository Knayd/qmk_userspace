#pragma once

#include QMK_KEYBOARD_H
#include "quantum.h"

typedef struct {
    uint16_t trigger;
    uint16_t default_key;
    uint8_t default_mods;  // Optional
    uint16_t mac_os_key;
    uint8_t mac_os_mods;  // Optional
    uint8_t linux_key;  // Optional
    uint8_t linux_mods;  // Optional
} magic_key_config_t;

bool handle_magic_key(
    magic_key_config_t config,
    uint16_t keycode,
    keyrecord_t *record
);
