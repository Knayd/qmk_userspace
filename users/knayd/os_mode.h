#pragma once
#include "quantum.h"

typedef enum {
    OS_TYPE_WINDOWS,
    OS_TYPE_MACOS,
    OS_TYPE_LINUX
} os_type_t;

void os_mode_init(os_variant_t);

void os_mode_toggle(void);

void os_mode_swap_ctrl_gui(void);

bool is_mac_os(void);

bool is_mac_os(void);
bool is_linux_os(void);
bool is_windows_os(void);

os_type_t get_current_os(void);
