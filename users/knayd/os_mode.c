#include "os_mode.h"
#include "eeconfig.h"

static os_type_t current_os = OS_TYPE_WINDOWS;

void os_mode_init(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            current_os = OS_TYPE_MACOS;
            break;
        case OS_LINUX:
            current_os = OS_TYPE_LINUX;
            break;
        default:
            current_os = OS_TYPE_WINDOWS;
            break;
    }
    os_mode_swap_ctrl_gui();
}

void os_mode_toggle(void) {
    current_os = (current_os + 1) % 3;
    os_mode_swap_ctrl_gui();
}

void os_mode_swap_ctrl_gui(void) {
    keymap_config.swap_lctl_lgui = (current_os == OS_TYPE_MACOS);
}

bool is_mac_os(void) {
    return current_os == OS_TYPE_MACOS;
}

bool is_linux_os(void) {
    return current_os == OS_TYPE_LINUX;
}

bool is_windows_os(void) {
    return current_os == OS_TYPE_WINDOWS;
}

os_type_t get_current_os(void) {
    return current_os;
}
