#include "layers.h"

// clang-format off
const char* layer_names[] = {
    [_QWERTY] = "QWERTY",
    [_WORKMAN] = "Workman",
    [_SYS] = "SYS",
    [_NUMROW] = "Numrow",
    [_GAME] = "Game",
    [_GAME_NUM_2] = "Game 2",
    [_SYMB] = "Symbols",
    [_NUMPAD] = "Numpad",
    [_TRANS] = "Trans",
};

const char* get_common_layer_name(int layer) {
    return layer_names[layer];
}
// clang-format on
