#include "kasama.h"

__attribute__((weak)) bool pre_process_record_kasama(uint16_t keycode, keyrecord_t *record) {
    return true;
}
bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    return pre_process_record_kasama(keycode, record);
}

__attribute__((weak)) bool process_record_kasama(uint16_t keycode, keyrecord_t *record) {
    return true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_record_kasama(keycode, record) &&
#ifdef KASAMA_KEYCODES_ENABLE
           process_record_custom_keycode(keycode, record) &&
#endif
           true;
}

__attribute__((weak)) void post_process_record_kasama(uint16_t keycode, keyrecord_t *record) {}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    post_process_record_kasama(keycode, record);
}

__attribute__((weak)) bool shutdown_kasama(bool jump_to_bootloader) {
    return true;
}
bool shutdown_user(bool jump_to_bootloader) {
    return shutdown_kasama(jump_to_bootloader);
}

__attribute__((weak)) layer_state_t layer_state_set_kasama(layer_state_t state) {
    return state;
}
layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef AUTO_NUMLOCK_ENABLE
    auto_enable_numlock();
#endif
    return layer_state_set_kasama(state);
};
