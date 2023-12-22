#include <stdint.h>
#include <string.h>
#include "action_layer.h"
#include "bootloader.h"
#include "raw_hid.h"

#define HID_NOP 0x41
#define HID_BOOT 0x42

#define HID_RESP_BASE 0

#define HID_GET_LAYER 0x43
#define HID_RESP_LAYER 0x43
#define HID_RESP_GET_LAYER_ARG_LAYER 1

#define HID_SET_LAYER 0x44
#define HID_SET_LAYER_ARG_LAYER 1
#define HID_RESP_SET_LAYER 0x44
#define HID_RESP_SET_LAYER_ARG_LAYER 1

#define HID_ACTION_MATRIX 0x45
#define HID_ACTION_MATRIX_ARG_STATE 1
#define HID_ACTION_MATRIX_ARG_ROW 2
#define HID_ACTION_MATRIX_ARG_COL 3

void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t operation = data[0];
    uint8_t response[length];
    memset(response, 0, length);

    if (operation == HID_BOOT) {
        bootloader_jump();
    } else if (operation == HID_GET_LAYER) {
        response[HID_RESP_BASE]                = HID_RESP_LAYER;
        response[HID_RESP_GET_LAYER_ARG_LAYER] = get_highest_layer(layer_state);
        raw_hid_send(response, length);
    } else if (operation == HID_SET_LAYER) {
        layer_move(data[HID_SET_LAYER_ARG_LAYER]);
        response[HID_RESP_BASE]                = HID_RESP_SET_LAYER;
        response[HID_RESP_SET_LAYER_ARG_LAYER] = get_highest_layer(layer_state);
        raw_hid_send(response, length);
    } else if (operation == HID_ACTION_MATRIX) {
        uint8_t state   = data[HID_ACTION_MATRIX_ARG_STATE];
        uint8_t row     = data[HID_ACTION_MATRIX_ARG_ROW];
        uint8_t col     = data[HID_ACTION_MATRIX_ARG_COL];
        bool    pressed = state > 0;

        action_exec(MAKE_KEYEVENT(row, col, pressed));

        response[0] = HID_RESP_SET_LAYER;
        response[1] = get_highest_layer(layer_state);
        raw_hid_send(response, length);
    }
}
