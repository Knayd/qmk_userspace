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
#include "knayd.h"

bool caps_state = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( MS_BTN3, DESK_LEFT, DESK_RIGHT, DRAG_SCROLL,
                    MS_BTN1,                        MS_BTN2 )
};

const uint16_t PROGMEM combo_apps[] = { DRAG_SCROLL, MS_BTN1, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_apps, KC_APPS),
};

// bool led_update_user(led_t led_state) {
//     if (caps_state != led_state.caps_lock) {
//         toggle_drag_scroll();
//         caps_state = led_state.caps_lock;
//     }
//     return true;
// }
