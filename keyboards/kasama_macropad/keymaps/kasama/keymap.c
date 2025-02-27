// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "debug.h"
#include "pointing_device_internal.h"
#include QMK_KEYBOARD_H

void keyboard_post_init_kasama(void) {
    debug_enable = true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        QK_BOOT,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO
    ),
};
// clang-format on
