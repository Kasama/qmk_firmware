#include "matrix.h"

matrix_row_t matrix_get_row(uint8_t row) {
    // Do nothing as this is for a virtual keyboard with no matrix
    return 0;
}

void matrix_print(void) {
    // Do nothing
}

void matrix_init(void) {
    // Do nothing as this is for a virtual keyboard with no matrix
}

uint8_t matrix_scan(void) {
    // The matrix doesn't ever change, because there is no physical matrix
    bool changed = false;
    return changed;
}
