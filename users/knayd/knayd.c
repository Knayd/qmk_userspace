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
            .default_key = KC_BSPC,
            .default_mods = MOD_LCTL,
            .mac_os_mods = MOD_LALT
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = NEXT_TAB,
            .default_key = KC_PGDN,
            .default_mods = MOD_LCTL,
            .mac_os_key = KC_RBRC,
            .mac_os_mods = MOD_LSFT | MOD_LGUI
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = PREV_TAB,
            .default_key = KC_PAGE_UP,
            .default_mods = MOD_LCTL,
            .mac_os_key = KC_LBRC,
            .mac_os_mods = MOD_LSFT | MOD_LGUI
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = KC_APPS,
            .default_key = KC_TAB,
            .default_mods = MOD_LGUI,
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
            .default_key = KC_LEFT,
            .default_mods = MOD_LGUI,
            .mac_os_mods = MOD_LCTL | MOD_LALT,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = WIN_RIGHT,
            .default_key = KC_RIGHT,
            .default_mods = MOD_LGUI,
            .mac_os_mods = MOD_LCTL | MOD_LALT,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = WIN_UP,
            .default_key = KC_UP,
            .default_mods = MOD_LGUI,
            .mac_os_mods = MOD_LCTL | MOD_LALT,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = WIN_DOWN,
            .default_key = KC_DOWN,
            .default_mods = MOD_LGUI,
            .mac_os_mods = MOD_LCTL | MOD_LALT,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = WIN_FULL,
            .default_key = KC_UP,
            .default_mods = MOD_LGUI,
            .mac_os_mods = MOD_LCTL | MOD_LALT,
            .mac_os_key = KC_ENTER,
            .linux_key = KC_ENTER,
            .linux_mods = MOD_LGUI,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = DESK_LEFT,
            .default_key = KC_LEFT,
            .default_mods = MOD_LGUI | MOD_LCTL,
            .mac_os_mods = MOD_LCTL,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = DESK_RIGHT,
            .default_key = KC_RIGHT,
            .default_mods = MOD_LGUI | MOD_LCTL,
            .mac_os_mods = MOD_LCTL,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = MON_LEFT,
            .default_key = KC_LEFT,
            .default_mods = MOD_LGUI | MOD_LSFT,
            .mac_os_mods = MOD_LGUI | MOD_LALT | MOD_LCTL,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = MON_RIGHT,
            .default_key = KC_RIGHT,
            .default_mods = MOD_LGUI | MOD_LSFT,
            .mac_os_mods = MOD_LGUI | MOD_LALT | MOD_LCTL,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = SHOW_DESK,
            .default_key = KC_D,
            .default_mods = MOD_LGUI,
            .mac_os_key = KC_F11,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = WRD_LEFT,
            .default_key = KC_LEFT,
            .default_mods = MOD_LCTL,
            .mac_os_mods = MOD_LALT,
        },
        keycode,
        record
    );

    handle_magic_key(
        (magic_key_config_t){
            .trigger = WRD_RIGHT,
            .default_key = KC_RIGHT,
            .default_mods = MOD_LCTL,
            .mac_os_mods = MOD_LALT,
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
