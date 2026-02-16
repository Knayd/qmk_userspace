#include "magickey.h"
#include "os_mode.h"

bool handle_magic_key(magic_key_config_t config, uint16_t keycode, keyrecord_t *record) {
    if (keycode != config.trigger) return true;

    uint16_t key;
    uint8_t  mods;

    if (is_linux_os()) {
        key = config.linux_key;
        mods = config.linux_mods;
    } else if (is_mac_os()) {
        key = config.mac_os_key;
        mods = config.mac_os_mods;
    } else {
        key = config.windows_key;
        mods = config.windows_mods;
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
