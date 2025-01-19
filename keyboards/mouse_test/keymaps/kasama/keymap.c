// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "debug.h"
#include "pointing_device_internal.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT(QK_BOOT)};

void keyboard_post_init_kasama(void) {
    debug_enable = true;
}

void pointing_device_init_user(void) {
    pd_dprintf("after pointing device init");
}
