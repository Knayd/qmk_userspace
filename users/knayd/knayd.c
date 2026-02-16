#include "knayd.h"
#include "keycodes.h"
#include "magickey.h"
#include "os_mode.h"

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    handle_magic_key(
        (magic_key_config_t){
            .trigger = DLT_WRD,
            .windows_key = KC_BSPC,
            .windows_mods = MOD_LCTL,
            .mac_os_key = KC_BSPC,
            .mac_os_mods = MOD_LALT,
            .linux_key = KC_BSPC,
            .linux_mods = MOD_LCTL,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = NEXT_TAB,
            .windows_key = KC_PGDN,
            .windows_mods = MOD_LCTL,
            .mac_os_key = KC_RBRC,
            .mac_os_mods = MOD_LSFT | MOD_LGUI,
            .linux_key = KC_PGDN,
            .linux_mods = MOD_LCTL,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = PREV_TAB,
            .windows_key = KC_PAGE_UP,
            .windows_mods = MOD_LCTL,
            .mac_os_key = KC_LBRC,
            .mac_os_mods = MOD_LSFT | MOD_LGUI,
            .linux_key = KC_PAGE_UP,
            .linux_mods = MOD_LCTL,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = KC_APPS,
            .windows_key = KC_TAB,
            .windows_mods = MOD_LGUI,
            .mac_os_key = KC_UP,
            .mac_os_mods = MOD_LCTL,
            .linux_key = KC_W,
            .linux_mods = MOD_LGUI,
        },
        keycode,
        record
    );

    // Win manager keys

    handle_magic_key(
        (magic_key_config_t){
            .trigger = WIN_LEFT,
            .windows_key = KC_LEFT,
            .windows_mods = MOD_LGUI,
            .mac_os_key = KC_LEFT,
            .mac_os_mods = MOD_LCTL | MOD_LALT,
            .linux_key = KC_LEFT,
            .linux_mods = MOD_LGUI,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = WIN_RIGHT,
            .windows_key = KC_RIGHT,
            .windows_mods = MOD_LGUI,
            .mac_os_key = KC_RIGHT,
            .mac_os_mods = MOD_LCTL | MOD_LALT,
            .linux_key = KC_RIGHT,
            .linux_mods = MOD_LGUI,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = WIN_UP,
            .windows_key = KC_UP,
            .windows_mods = MOD_LGUI,
            .mac_os_key = KC_UP,
            .mac_os_mods = MOD_LCTL | MOD_LALT,
            .linux_key = KC_UP,
            .linux_mods = MOD_LGUI,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = WIN_DOWN,
            .windows_key = KC_DOWN,
            .windows_mods = MOD_LGUI,
            .mac_os_key = KC_DOWN,
            .mac_os_mods = MOD_LCTL | MOD_LALT,
            .linux_key = KC_DOWN,
            .linux_mods = MOD_LGUI,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = WIN_FULL,
            .windows_key = KC_UP,
            .windows_mods = MOD_LGUI,
            .mac_os_mods = MOD_LCTL | MOD_LALT,
            .mac_os_key = KC_ENTER,
            .linux_key = KC_PAGE_UP,
            .linux_mods = MOD_LGUI,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = DESK_LEFT,
            .windows_key = KC_LEFT,
            .windows_mods = MOD_LGUI | MOD_LCTL,
            .mac_os_key = KC_LEFT,
            .mac_os_mods = MOD_LCTL,
            .linux_key = KC_LEFT,
            .linux_mods = MOD_LGUI | MOD_LCTL,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = DESK_RIGHT,
            .windows_key = KC_RIGHT,
            .windows_mods = MOD_LGUI | MOD_LCTL,
            .mac_os_key = KC_RIGHT,
            .mac_os_mods = MOD_LCTL,
            .linux_key = KC_RIGHT,
            .linux_mods = MOD_LGUI | MOD_LCTL,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = MON_LEFT,
            .windows_key = KC_LEFT,
            .windows_mods = MOD_LGUI | MOD_LSFT,
            .mac_os_key = KC_LEFT,
            .mac_os_mods = MOD_LGUI | MOD_LALT | MOD_LCTL,
            .linux_key = KC_LEFT,
            .linux_mods = MOD_LGUI | MOD_LSFT,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = MON_RIGHT,
            .windows_key = KC_RIGHT,
            .windows_mods = MOD_LGUI | MOD_LSFT,
            .mac_os_key = KC_RIGHT,
            .mac_os_mods = MOD_LGUI | MOD_LALT | MOD_LCTL,
            .linux_key = KC_RIGHT,
            .linux_mods = MOD_LGUI | MOD_LSFT,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = SHOW_DESK,
            .windows_key = KC_D,
            .windows_mods = MOD_LGUI,
            .mac_os_key = KC_F11,
            .linux_key = KC_D,
            .linux_mods = MOD_LGUI,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = WRD_LEFT,
            .windows_key = KC_LEFT,
            .windows_mods = MOD_LCTL,
            .mac_os_key = KC_LEFT,
            .mac_os_mods = MOD_LALT,
            .linux_key = KC_LEFT,
            .linux_mods = MOD_LCTL,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = WRD_RIGHT,
            .windows_key = KC_RIGHT,
            .windows_mods = MOD_LCTL,
            .mac_os_key = KC_RIGHT,
            .mac_os_mods = MOD_LALT,
            .linux_key = KC_RIGHT,
            .linux_mods = MOD_LCTL,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = SCRN_SHOT,
            .windows_key = KC_PSCR,
            .mac_os_key = KC_4,
            .mac_os_mods = MOD_LGUI | MOD_LSFT,
            .linux_key = KC_PSCR,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = SCRN_REC,
            .windows_key = KC_R,
            .windows_mods = MOD_LGUI | MOD_LSFT,
            .mac_os_key = KC_5,
            .mac_os_mods = MOD_LGUI | MOD_LSFT,
            .linux_key = KC_R,
            .linux_mods = MOD_LGUI | MOD_LSFT,
        },
        keycode,
        record
    );

    switch (keycode) {
        case OS_TOGGLE:
            if (record->event.pressed) {
                os_mode_toggle();
                return false;
            }
    }

  return process_record_keymap(keycode, record);
}

bool process_detected_host_os_kb(os_variant_t detected_os) {
    os_mode_init(detected_os);
    return true;
 }
