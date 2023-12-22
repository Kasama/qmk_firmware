#include "kasama.h"

__attribute__((weak)) bool pre_process_record_kasama(uint16_t keycode, keyrecord_t *record) {
    return true;
}
__attribute__((weak)) bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    return pre_process_record_user(keycode, record);
}

__attribute__((weak)) bool process_record_kasama(uint16_t keycode, keyrecord_t *record) {
    return true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return
#ifdef KASAMA_KEYCODES
        process_record_custom_keycode(keycode, record) &&
#endif
        process_record_kasama(keycode, record);
}

__attribute__((weak)) void post_process_record_kasama(uint16_t keycode, keyrecord_t *record) {}

__attribute__((weak)) void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    post_process_record_kasama(keycode, record);
}

__attribute__((weak)) bool shutdown_kasama(bool jump_to_bootloader) {
    return true;
}
__attribute__((weak)) bool shutdown_user(bool jump_to_bootloader) {
    return shutdown_kasama(jump_to_bootloader);
}
