/* Copyright 2023 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdbool.h>
#include QMK_KEYBOARD_H
#include "magickey.h"
#include "os_mode.h"

bool caps_state = false;

enum custom_keycodes {
    DESK_LEFT = SAFE_RANGE,
    DESK_RIGHT,
    KC_APPS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( MS_BTN3, DESK_LEFT, DESK_RIGHT, DRAG_SCROLL,
                    MS_BTN1,                        MS_BTN2 )
};

const uint16_t PROGMEM combo_apps[] = { DRAG_SCROLL, MS_BTN1, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_apps, KC_APPS),
};

bool process_detected_host_os_kb(os_variant_t detected_os) {
    os_mode_init(detected_os);
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
            .trigger = KC_APPS,
            .default_key = KC_TAB,
            .default_mods = MOD_LGUI,
            .mac_os_key = KC_UP,
            .mac_os_mods = MOD_LCTL
        },
        keycode,
        record
    );

    return true;
}

bool is_key_with_delayed_mods(uint16_t keycode) {
    switch (keycode) {
    default:
        return false;
    }
}

// bool led_update_user(led_t led_state) {
//     if (caps_state != led_state.caps_lock) {
//         toggle_drag_scroll();
//         caps_state = led_state.caps_lock;
//     }
//     return true;
// }
