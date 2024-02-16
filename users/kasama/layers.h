#pragma once
#ifndef COMMON_LAYERS
#    define COMMON_LAYERS

// clang-format off
enum layers {
    _QWERTY = 0,
    _WORKMAN,
    _GAME,
    _GAME_NUM_2,
    _SYS,
    _NUMROW,
    _SYMB,
    _NUMPAD,
    _TRANS = 15
};
// clang-format on

const char* get_common_layer_name(int layer);
uint8_t     get_num_layers(void);

#endif // COMMON_LAYERS
