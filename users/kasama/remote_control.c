#include "remote_control.h"
#include "mouse_jiggle.h"

#ifdef REMOTE_CONTROL_ENABLE

#    include <string.h>
#    include "action_layer.h"
#    include "quantum.h"
#    include "raw_hid.h"
#    include "hid.h"
#    include "layers.h"

#    define HID_NOP 0x41
#    define HID_BOOT 0x42

#    define HID_RESP_BASE 0

#    define HID_GET_LAYER 0x43
#    define HID_RESP_LAYER 0x43
#    define HID_RESP_GET_LAYER_ARG_LAYER 1
#    define HID_RESP_GET_LAYER_ARG_LAYER_NAME 2

#    define HID_SET_LAYER 0x44
#    define HID_SET_LAYER_ARG_LAYER 1
#    define HID_RESP_SET_LAYER 0x44
#    define HID_RESP_SET_LAYER_ARG_LAYER 1

#    define HID_ACTION_MATRIX 0x45
#    define HID_ACTION_MATRIX_ARG_STATE 1
#    define HID_ACTION_MATRIX_ARG_ROW 2
#    define HID_ACTION_MATRIX_ARG_COL 3

#    define HID_GET_LAYERS 0x46
#    define HID_RESP_GET_LAYERS 0x46
#    define HID_RESP_GET_LAYERS_END 0x46
#    define HID_RESP_GET_LAYERS_LAYER_NUM 1
#    define HID_RESP_GET_LAYERS_LAYER_NAME 2

#    define HID_GET_JIGGLE 0x47
#    define HID_RESP_GET_JIGGLE 0x47
#    define HID_RESP_GET_JIGGLE_ARG 1

#    define HID_SET_JIGGLE 0x48
#    define HID_SET_JIGGLE_ARG 1

bool raw_hid_handle_remote_control(uint8_t *data, uint8_t length) {
    uint8_t operation = data[0];
    uint8_t response[length];
    memset(response, 0, length);

    if (operation == HID_BOOT) {
        reset_keyboard();
        return false;
    } else if (operation == HID_GET_LAYER) {
        response[HID_RESP_BASE]                = HID_RESP_LAYER;
        response[HID_RESP_GET_LAYER_ARG_LAYER] = get_highest_layer(layer_state);
        strncpy((char *)&response[HID_RESP_GET_LAYER_ARG_LAYER_NAME], get_layer_name(response[HID_RESP_GET_LAYER_ARG_LAYER]), length - HID_RESP_GET_LAYER_ARG_LAYER_NAME - 1);
        raw_hid_send(response, length);
        return false;
    } else if (operation == HID_SET_LAYER) {
        layer_move(data[HID_SET_LAYER_ARG_LAYER]);
        response[HID_RESP_BASE]                = HID_RESP_SET_LAYER;
        response[HID_RESP_SET_LAYER_ARG_LAYER] = get_highest_layer(layer_state);
        raw_hid_send(response, length);
        return false;
    } else if (operation == HID_ACTION_MATRIX) {
        uint8_t state   = data[HID_ACTION_MATRIX_ARG_STATE];
        uint8_t row     = data[HID_ACTION_MATRIX_ARG_ROW];
        uint8_t col     = data[HID_ACTION_MATRIX_ARG_COL];
        bool    pressed = state > 0;

        action_exec(MAKE_KEYEVENT(row, col, pressed));

        response[0] = HID_RESP_SET_LAYER;
        response[1] = get_highest_layer(layer_state);
        raw_hid_send(response, length);
        return false;
    } else if (operation == HID_GET_LAYERS) {
        uint8_t num_layers = get_num_layers();
        for (uint8_t i = 0; i < num_layers; i++) {
            response[HID_RESP_BASE]                = HID_RESP_GET_LAYERS;
            response[HID_RESP_GET_LAYER_ARG_LAYER] = i;
            strncpy((char *)&response[HID_RESP_GET_LAYERS_LAYER_NAME], get_layer_name(i), length - HID_RESP_GET_LAYER_ARG_LAYER_NAME - 1);
            raw_hid_send(response, length);
        }
        response[HID_RESP_BASE]                = HID_RESP_GET_LAYERS;
        response[HID_RESP_GET_LAYER_ARG_LAYER] = HID_RESP_GET_LAYERS_END;
        raw_hid_send(response, length);
#    ifdef MOUSE_JIGGLE_ENABLE
    } else if (operation == HID_GET_JIGGLE) {
        bool enabled                      = is_mouse_jiggler_enabled();
        response[HID_RESP_BASE]           = HID_RESP_GET_JIGGLE;
        response[HID_RESP_GET_JIGGLE_ARG] = enabled;
        raw_hid_send(response, length);
    } else if (operation == HID_SET_JIGGLE) {
        bool value = data[HID_SET_JIGGLE_ARG] == 0 ? false : true;
        set_mouse_jiggler(value);
        bool enabled                      = is_mouse_jiggler_enabled();
        response[HID_RESP_BASE]           = HID_RESP_GET_JIGGLE;
        response[HID_RESP_GET_JIGGLE_ARG] = enabled;
        raw_hid_send(response, length);
#    endif
    }
    return true;
}

#endif
