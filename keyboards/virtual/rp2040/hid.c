#include <stdint.h>
#include <string.h>
#include "action_layer.h"
#include "bootloader.h"
#include "raw_hid.h"

#define HID_BOOT 0x42
#define HID_GET_LAYER 0x43
#define HID_SET_LAYER 0x44
#define HID_ACTION_MATRIX 0x45

#define HID_RESP_LAYER 0x43
#define HID_RESP_SET_LAYER 0x44

void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t operation = data[0];

    uint8_t response[length];
    memset(response, 0, length);

    if (operation == 0x41) {
        raw_hid_send(response, length);
    } else if (operation == HID_BOOT) {
        bootloader_jump();
    } else if (operation == HID_GET_LAYER) {
        response[0] = HID_RESP_LAYER;
        response[1] = get_highest_layer(layer_state);
        raw_hid_send(response, length);
    } else if (operation == HID_SET_LAYER) {
        layer_move(data[1]);
        response[0] = HID_RESP_SET_LAYER;
        response[1] = get_highest_layer(layer_state);
        raw_hid_send(response, length);
    } else if (operation == HID_ACTION_MATRIX) {
        uint8_t state   = data[1];
        uint8_t row     = data[2];
        uint8_t col     = data[3];
        bool    pressed = state > 0;

        action_exec(MAKE_KEYEVENT(row, col, pressed));

        response[0] = HID_RESP_SET_LAYER;
        response[1] = get_highest_layer(layer_state);
        raw_hid_send(response, length);
    }
}
