#pragma once

#include "quantum.h"
#include "action.h"
#include "quantum_keycodes.h"
#include "version.h"

enum custom_keycodes {
    DLT_WRD, // Delete word
    NEXT_TAB,
    PREV_TAB,
    KC_APPS, // Mission control / Task view
    WRD_LEFT,
    WRD_RIGHT,
    // Win manager keys
    WIN_LEFT,
    WIN_RIGHT,
    WIN_UP,
    WIN_DOWN,
    WIN_FULL,
    DESK_LEFT,
    DESK_RIGHT,
    MON_LEFT,
    MON_RIGHT,
    SHOW_DESK,
    // OS mode
    OS_TOGGLE,
    NEW_SAFE_RANGE  //use "NEW_SAFE_RANGE" for keymap specific codes
};
