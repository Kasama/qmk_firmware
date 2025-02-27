#include "layers.h"
#include <stdint.h>

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
    [_STENO] = "Steno"
};

const char* get_common_layer_name(int layer) {
    return layer_names[layer];
}

uint8_t get_num_layers() {
    return sizeof(layer_names);
}
// clang-format on
