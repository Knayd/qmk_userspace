/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "knayd.h"
#include "os_mode.h"

#define EDIT_REDO  LCTL(LSFT(KC_Z))
#define EDIT_UNDO  LCTL(KC_Z)
#define EDIT_CUT   LCTL(KC_X)
#define EDIT_COPY  LCTL(KC_C)
#define EDIT_PASTE LCTL(KC_V)

enum layers {
    _BASE,
    _SYM,
    _NAV,
    _WIN,
    _NUM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3_ex2(
      KC_ESC,   KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,             MS_BTN2,                    KC_VOLU,    KC_Y,             KC_U,           KC_I,           KC_O,           KC_P,               SCRN_SHOT,
      KC_BSPC,  LGUI_T(KC_A),   LALT_T(KC_S),   LSFT_T(KC_D),   LCTL_T(KC_F),   KC_G,             MS_BTN1,                    KC_VOLD,    KC_H,             LCTL_T(KC_J),   LSFT_T(KC_K),   LALT_T(KC_L),   LGUI_T(KC_QUOT),    KC_SCLN,
      _______,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                     KC_N,             KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,            KC_CAPS,
                                                                MO(_NUM),       LT(_NAV, KC_TAB), LT(_WIN, KC_ENT),           KC_LSFT,    LT(_SYM, KC_SPC), KC_DEL 

  ),

  [_SYM] = LAYOUT_split_3x6_3_ex2(
    _______, KC_CIRC,  KC_HASH, KC_DQUO,  KC_DLR,    _______,  _______,     _______, KC_ASTR, KC_PERC, KC_AMPR, KC_PIPE, KC_PLUS, _______,
    _______, KC_MINUS, KC_LABK, KC_RABK,  KC_EQUAL,  KC_GRAVE, _______,     _______, KC_EXLM, KC_LPRN, KC_RPRN, KC_COLN, KC_UNDS, _______,
    _______, KC_BSLS,  KC_LBRC, KC_RBRC,  KC_AT,     _______,                        KC_TILD, KC_LCBR, KC_RCBR, _______, KC_QUES, _______,
                                          _______,   KC_SPC,   _______,     _______, _______, _______
  ),

  [_NAV] = LAYOUT_split_3x6_3_ex2(
    _______,   LCTL(KC_W),   _______,      PREV_TAB,        NEXT_TAB,       _______,  _______,      _______,  KC_PGUP, KC_HOME,          KC_UP,   KC_END,   _______, SCRN_REC,
    DLT_WRD,   KC_LEFT_GUI,  KC_LEFT_ALT,  KC_LEFT_SHIFT,   KC_LEFT_CTRL,   _______,  _______,      _______,  KC_PGDN, KC_LEFT,          KC_DOWN, KC_RIGHT, _______, _______,
    EDIT_REDO, EDIT_UNDO,    EDIT_CUT,     EDIT_COPY,       EDIT_PASTE,     _______,                          _______, LALT(LCTL(KC_L)), _______, _______,  _______, _______,
                                                            _______,        _______,  _______,      _______,  _______, _______
  ),

  [_WIN] = LAYOUT_split_3x6_3_ex2(
    _______,    SHOW_DESK,  KC_APPS,      _______,    KC_LEFT_CTRL, _______,  _______,          _______,  MON_LEFT, WIN_UP,     MON_RIGHT,  _______, _______, _______,
    _______,    _______,    MS_BTN3,      MS_BTN2,    MS_BTN1,      _______,  _______,          _______,  WIN_LEFT, WIN_DOWN,   WIN_RIGHT,  _______, _______, _______,
    EDIT_REDO,  EDIT_UNDO,  EDIT_CUT,     EDIT_COPY,  EDIT_PASTE,   _______,                              _______,  DESK_LEFT,  DESK_RIGHT, _______, _______, _______,
                                                      _______,      _______,  _______,          WIN_FULL, _______,  _______
  ),

  [_NUM] = LAYOUT_split_3x6_3_ex2(
    _______, _______, _______, _______, _______, _______, _______,        _______, KC_ASTR,   KC_7,   KC_8, KC_9, KC_PLUS,  OS_TOGGLE,
    _______, _______, _______, _______, _______, _______, _______,        _______, KC_SLASH,  KC_4,   KC_5, KC_6, KC_MINUS, _______,
    QK_BOOT, _______, _______, _______, _______, _______,                          _______,   KC_1,   KC_2, KC_3, KC_DOT,   KC_EQUAL,
                                        _______, _______, _______,        _______, KC_0,      _______
  )
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x6_3_ex2(
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R',
                      '*', '*', '*', '*', '*', '*'
);

const uint16_t PROGMEM combo_wrd_left[] = { KC_LEFT, KC_HOME, COMBO_END};
const uint16_t PROGMEM combo_wrd_right[] = { KC_RIGHT, KC_END, COMBO_END};
const uint16_t PROGMEM combo_f1[] = { KC_Q, MT(MOD_LGUI, KC_A), COMBO_END};
const uint16_t PROGMEM combo_f2[] = { KC_W, MT(MOD_LALT, KC_S), COMBO_END};
const uint16_t PROGMEM combo_f3[] = { KC_E, MT(MOD_LSFT, KC_D), COMBO_END};
const uint16_t PROGMEM combo_f4[] = { KC_R, MT(MOD_LCTL, KC_F), COMBO_END};
const uint16_t PROGMEM combo_f5[] = { KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_f6[] = { KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_f7[] = { KC_U, MT(MOD_LCTL, KC_J), COMBO_END};
const uint16_t PROGMEM combo_f8[] = { KC_I, MT(MOD_LSFT, KC_K), COMBO_END};
const uint16_t PROGMEM combo_f9[] = { KC_O, MT(MOD_LALT, KC_L), COMBO_END};
const uint16_t PROGMEM combo_f10[] = { KC_P, MT(MOD_LGUI, KC_QUOTE), COMBO_END};
const uint16_t PROGMEM combo_f11[] = { LT(_NAV, KC_TAB), LT(_SYM, KC_SPC), COMBO_END};
const uint16_t PROGMEM combo_f12[] = { LT(_WIN, KC_ENT), KC_LSFT, COMBO_END};
const uint16_t PROGMEM combo_enter[] = { KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo_bscp[] = { KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_delete_wrd[] = { KC_M, KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_left_click[] = { MT(MOD_LCTL, KC_F), KC_G, COMBO_END};
const uint16_t PROGMEM combo_middle_click[] = { MS_BTN1, MS_BTN2, COMBO_END};
const uint16_t PROGMEM combo_media_play[] = { KC_VOLD, KC_VOLU, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_wrd_left, WRD_LEFT),
    COMBO(combo_wrd_right, WRD_RIGHT),
    COMBO(combo_f11, KC_F11),
    COMBO(combo_f1, KC_F1),
    COMBO(combo_f2, KC_F2),
    COMBO(combo_f3, KC_F3),
    COMBO(combo_f4, KC_F4),
    COMBO(combo_f5, KC_F5),
    COMBO(combo_f6, KC_F6),
    COMBO(combo_f7, KC_F7),
    COMBO(combo_f8, KC_F8),
    COMBO(combo_f9, KC_F9),
    COMBO(combo_f10, KC_F10),
    COMBO(combo_f12, KC_F12),
    COMBO(combo_enter, KC_ENTER),
    COMBO(combo_bscp, KC_BSPC),
    COMBO(combo_delete_wrd, DLT_WRD),
    COMBO(combo_left_click, MS_BTN1),
    COMBO(combo_middle_click, MS_BTN3),
    COMBO(combo_media_play, KC_MPLY),
};

bool rgb_matrix_indicators_user(void) {

  uint8_t os_indicator_index = g_led_config.matrix_co[3][5];

  if (is_mac_os()) {
    rgb_matrix_set_color(os_indicator_index, RGB_RED);
  }

  if (is_linux_os()) {
    rgb_matrix_set_color(os_indicator_index, RGB_GREEN);
  }

  return true;
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
        uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    #endif
  return true;
}
