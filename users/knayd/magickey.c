#include "magickey.h"
#include "os_mode.h"

bool handle_magic_key(magic_key_config_t config, uint16_t keycode, keyrecord_t *record) {
    if (keycode != config.trigger) return true;

    uint16_t key;
    uint8_t  mods;

    // Determine key
    if (is_linux_os() && config.linux_key) {
        key = config.linux_key;
    } else if (is_mac_os() && config.mac_os_key) {
        key = config.mac_os_key;
    } else {
        key = config.default_key;
    }

    // Determine mods (independent from key)
    if (is_linux_os() && config.linux_mods) {
        mods = config.linux_mods;
    } else if (is_mac_os() && config.mac_os_mods) {
        mods = config.mac_os_mods;
    } else {
        mods = config.default_mods;
    }

    if (record->event.pressed) {
        if (mods) {
            add_mods(mods);
            send_keyboard_report();
        }
        register_code(key);
    } else {
        unregister_code(key);
        if (mods) {
            del_mods(mods);
            send_keyboard_report();
        }
    }

    return false;
}
