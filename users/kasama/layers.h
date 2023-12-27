#pragma once
#ifndef COMMON_LAYERS
#define COMMON_LAYERS

// clang-format off
enum layers {
    _QWERTY = 0,
    _WORKMAN,
    _SYS,
    _NUMROW,
    _GAME,
    _GAME_NUM_2,
    _SYMB,
    _NUMPAD,
    _TRANS = 15
};
// clang-format on

const char* get_common_layer_name(int layer);

#endif // COMMON_LAYERS
