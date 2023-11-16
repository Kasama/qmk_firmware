// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

// clang-format off

#include <stdint.h>
#include <string.h>
#include "action.h"
#include "action_layer.h"
#include "bootloader.h"
#include "quantum.h"
#include "raw_hid.h"
#include QMK_KEYBOARD_H

enum custom_keycodes {
    SHRUG = SAFE_RANGE,
};

enum layers {
    _BASE,
    _RAISE,
    _LOWER,
};

#define K_1 SHRUG
#define K_2 BL_ON
#define K_3 BL_OFF
#define K_4 BL_TOGG

const uint16_t PROGMEM all[] = {K_1, K_2, K_3, K_4, COMBO_END};
const uint16_t PROGMEM top[] = {K_1, K_2, COMBO_END};
const uint16_t PROGMEM bot[] = {K_3, K_4, COMBO_END};
const uint16_t PROGMEM left[] = {K_1, K_3, K_4, COMBO_END};
const uint16_t PROGMEM right[] = {K_2, K_4, COMBO_END};

combo_t key_combos[] = {
    COMBO(all, QK_BOOT),
    COMBO(top, TG(_RAISE)),
    COMBO(bot, TG(_LOWER)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(K_1, K_2, K_3, K_4),
    [_RAISE] = LAYOUT(K_1, K_2, K_3, K_4),
    [_LOWER] = LAYOUT(K_1, K_2, K_3, K_4)
};

void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t response[length];
    memset(response, 0, length);

    if (layer_state_is(_BASE)) {
        response[0] = _BASE;
    } else if (layer_state_is(_RAISE)) {
        response[0] = _RAISE;
    } else if (layer_state_is(_LOWER)) {
        response[0] = _LOWER;
    }

    if (data[0] == 0x41) {
        raw_hid_send(response, length);
    } else if (data[0] == 0x42) {
        bootloader_jump();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case SHRUG: { // ¯\_(ツ)_/¯
                if (record->event.pressed) {
                    send_unicode_string("¯\\_(ツ)_/¯");
                }
                return false;
                break;
            }
        }
    }
    return true;
}
