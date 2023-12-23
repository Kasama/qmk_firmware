#include "remote_control.h"

#include "raw_hid.h"
#include "hid.h"

__attribute__((weak)) const char *get_layer_name(int layer) {
    return "unnamed";
}

__attribute__((weak)) bool raw_hid_receive_kasama(uint8_t *data, uint8_t length) {
    return true;
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    __attribute__((unused)) bool used_only_for_short_circuit =
#ifdef REMOTE_CONTROL_ENABLE
        raw_hid_handle_remote_control(data, length) &&
#endif
        raw_hid_receive_kasama(data, length);
}
