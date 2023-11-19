/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
//  Keyboard layout
// ┌────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┐
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
// └────────┼────────┼────────┼────────┴────────┘                             └────────┴────────┼────────┼────────┼────────┘
//          └────────┴────────┘┌────────┬────────┐                           ┌────────┬────────┐└────────┴────────┘
//                             └────────┴────────┘                           └────────┴────────┘
//                                         ┌────────┬────────┐   ┌────────┬────────┐
//                                         ├────────┼────────┤   ├────────┼────────┤
//                                         └────────┴────────┘   └────────┴────────┘

// clang-format off

#include <stdint.h>
#include <string.h>
#include "action.h"
#include "action_layer.h"
#include "sendstring_brazilian_abnt2.h"
#include "keycodes.h"
#include "keymap_brazilian_abnt2.h"
#include "quantum.h"
#include "quantum_keycodes.h"
#include "raw_hid.h"
#include QMK_KEYBOARD_H
#include "process_combo.h"

#define _QWERTY     0
#define _WORKMAN    1
#define _SYS        2
#define _NUMROW     3
#define _GAME       5
#define _CODE       6
#define _NUMPAD     7
#define _LAYER_SEL  14
#define _TRANS      15

#define SFT_ESC  SFT_T(KC_ESC)
#define C_BSPC   CTL_T(KC_BSPC)
#define ALT_SPC  RALT_T(KC_SPC)
#define ALT_TAB  ALT_T(KC_TAB)
#define ALT_LBC  ALT_T(KC_TAB)
#define SFT_ENT  RSFT_T(KC_ENT)
#define SFT_DQUO SFT_T(BR_DQUO)

#define COD_ESC LT(_CODE, KC_ESC)

// homerow tap mod keys
#define HM_SA SFT_T(KC_A)
#define HM_CS CTL_T(KC_S)
#define HM_AD ALT_T(KC_D)
#define HM_GF GUI_T(KC_F)

#define HM_GJ GUI_T(KC_J)
#define HM_AK ALT_T(KC_K)
#define HM_CL CTL_T(KC_L)
#define HM_SÇ SFT_T(BR_SCLN)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2
#define KC_PRINT KC_PRINT_SCREEN

#define SYSTM OSL(_SYS)
#define NUMROW OSL(_NUMROW)
#define CODE OSL(_CODE)

#define NUMPAD MO(_NUMPAD)
#define LAYER_SEL MO(_LAYER_SEL)

#define LOWER_R OSL(_NUMROW)
#define LOWER_B OSL(_NUMROW)

#define BR_RCBR S(BR_RBRC)
#define BR_LCBR S(BR_LBRC)

enum custom_keycodes {
    K_VIMCMD = SAFE_RANGE,
};

// tap dance
enum {
    TD_SYS_GUI,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_SYS_GUI] = ACTION_TAP_DANCE_DOUBLE(SYSTM, KC_LGUI)
};


// Combos
const uint16_t PROGMEM c_escbspc[] = {COD_ESC, C_BSPC, COMBO_END};
const uint16_t PROGMEM c_systab[]  = {SYSTM, ALT_TAB, COMBO_END};
const uint16_t PROGMEM c_sysesc[]  = {SYSTM, COD_ESC, COMBO_END};
const uint16_t PROGMEM c_jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM c_lç[] = {KC_L, HM_SÇ, COMBO_END};
const uint16_t PROGMEM c_as[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM c_atab[] = {KC_A, ALT_TAB, COMBO_END};
const uint16_t PROGMEM c_homerow_r[]     = {KC_J, KC_K, KC_L, HM_SÇ, COMBO_END};
const uint16_t PROGMEM c_idx_homerow_r[] = {KC_H, KC_K, KC_L, HM_SÇ, COMBO_END};
const uint16_t PROGMEM c_u_homerow_r[]     = {KC_U, KC_I, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM c_u_idx_homerow_r[] = {KC_Y, KC_I, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM c_l_homerow_r[]     = {KC_M, KC_COMM, KC_DOT, BR_SLSH, COMBO_END};
const uint16_t PROGMEM c_l_idx_homerow_r[] = {KC_N, KC_COMM, KC_DOT, BR_SLSH, COMBO_END};
const uint16_t PROGMEM c_homerow_l[]     = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM c_idx_homerow_l[] = {KC_A, KC_S, KC_D, KC_G, COMBO_END};

combo_t key_combos[] = {
    COMBO(c_jk, KC_ESC),
    COMBO(c_escbspc, LM(_NUMROW, MOD_LGUI)),
    COMBO(c_systab, LM(_NUMROW, MOD_LGUI)),
    COMBO(c_sysesc, TG(_GAME)),
    COMBO(c_u_idx_homerow_r, QK_BOOT),
    COMBO(c_l_idx_homerow_r, QK_MAKE),
    COMBO(c_lç, K_VIMCMD),
    COMBO(c_homerow_l, NUMPAD),
    COMBO(c_idx_homerow_l, KC_ENTER),
    COMBO(c_as, OSM(MOD_LSFT)),
    COMBO(c_atab, KC_LGUI),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┐
      KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,                                KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  ,
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
      KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,                                KC_H  ,  KC_J  ,  KC_K  ,  KC_L  ,  HM_SÇ ,
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
      KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,                                KC_N  ,  KC_M  , KC_COMM, KC_DOT , BR_SLSH,
// └────────┼────────┼────────┼────────┴────────┘                             └────────┴────────┼────────┼────────┼────────┘
              BR_LBRC, BR_RBRC,                                                                   KC_MINS, KC_EQL ,
//          └────────┴────────┘┌────────┬────────┐                           ┌────────┬────────┐└────────┴────────┘
                                 COD_ESC,  C_BSPC,                             ALT_SPC,  NUMROW,
//                             └────────┴────────┘                           └────────┴────────┘
//                                         ┌────────┬────────┐   ┌────────┬────────┐
                                              SYSTM , ALT_TAB,     SFT_ENT,  CODE  ,
//                                         ├────────┼────────┤   ├────────┼────────┤
                                             KC_NO  ,  KC_NO ,      KC_NO ,  KC_NO
//                                         └────────┴────────┘   └────────┴────────┘
    ),

    [_WORKMAN] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┐
      KC_Q  ,  KC_D  ,  KC_R  ,  KC_W  ,  KC_B  ,                                KC_J  ,  KC_F  ,  KC_U  ,  KC_P  , BR_SCLN,
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
      HM_SA ,  KC_S  ,  KC_H  ,  KC_T  ,  KC_G  ,                                KC_Y  ,  KC_N  ,  KC_E  ,  KC_O  ,  KC_I  ,
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
      KC_Z  ,  KC_X  ,  KC_M  ,  KC_C  ,  KC_V  ,                                KC_K  ,  KC_L  , KC_COMM, KC_DOT , BR_SLSH,
// └────────┼────────┼────────┼────────┴────────┘                             └────────┴────────┼────────┼────────┼────────┘
             BR_LBRC , BR_RBRC,                                                                   KC_MINS,  KC_EQL,
//          └────────┴────────┘┌────────┬────────┐                           ┌────────┬────────┐└────────┴────────┘
                                 COD_ESC,  C_BSPC,                             ALT_SPC,  NUMROW,
//                             └────────┴────────┘                           └────────┴────────┘
//                                         ┌────────┬────────┐   ┌────────┬────────┐
                                               SYSTM, ALT_TAB,     SFT_ENT,  CODE  ,
//                                         ├────────┼────────┤   ├────────┼────────┤
                                              NUMROW, KC_LGUI,     BR_QUOT, BR_BSLS
//                                         └────────┴────────┘   └────────┴────────┘
    ),

    [_CODE] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┐
     BR_QUOT, BR_DQUO, _______, _______, _______,                              KC_PRINT, BR_LBRC, BR_RBRC, BR_GRV , BR_ACUT,
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
    SFT_DQUO, _______,  KC_DEL, _______, _______,                               _______, KC_LPRN, KC_RPRN, BR_CIRC, BR_TILD,
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
     BR_BSLS, KC_CAPS, BR_CCED, _______, _______,                               _______, BR_LCBR, BR_RCBR, BR_SCLN, BR_PIPE,
// └────────┼────────┼────────┼────────┴────────┘                             └────────┴────────┼────────┼────────┼────────┘
              _______, _______,                                                                S(KC_MINS), KC_PLUS,
//          └────────┴────────┘┌────────┬────────┐                           ┌────────┬────────┐└────────┴────────┘
                                 _______, _______,                             _______, _______,
//                             └────────┴────────┘                           └────────┴────────┘
//                                         ┌────────┬────────┐   ┌────────┬────────┐
                                             _______, _______,     _______, _______,
//                                         ├────────┼────────┤   ├────────┼────────┤
                                             _______, _______,     _______, _______
//                                         └────────┴────────┘   └────────┴────────┘
    ),

    [_SYS] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┐
     QK_BOOT, _______, KC_MU,   _______, AC_TOGG,                               KC_VOLD, KC_MUTE, KC_VOLU, _______, KC_PGUP,
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
     BR_QUOT, KC_ML,   KC_MD,   KC_MR,   KC_F23 ,                               KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGDN,
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
     BR_BSLS, KC_MPRV, KC_MPLY, KC_MNXT, TG(_WORKMAN),                           KC_F23, KC_SLSH, KC_BSLS, KC_QUES, KC_PIPE,
// └────────┼────────┼────────┼────────┴────────┘                             └────────┴────────┼────────┼────────┼────────┘
      QK_COMBO_TOGGLE, _______,                                                                    KC_MB1,  KC_MB2,
//          └────────┴────────┘┌────────┬────────┐                           ┌────────┬────────┐└────────┴────────┘
                                 _______,LAYER_SEL,                            _______, _______,
//                             └────────┴────────┘                           └────────┴────────┘
//                                         ┌────────┬────────┐   ┌────────┬────────┐
                                             _______, NUMPAD ,     _______, _______,
//                                         ├────────┼────────┤   ├────────┼────────┤
                                             _______, _______,     _______, _______
//                                         └────────┴────────┘   └────────┴────────┘
    ),

    [_NUMROW] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┐
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                               KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
// └────────┼────────┼────────┼────────┴────────┘                             └────────┴────────┼────────┼────────┼────────┘
               KC_F11,  KC_F12,                                                                   _______, _______,
//          └────────┴────────┘┌────────┬────────┐                           ┌────────┬────────┐└────────┴────────┘
                               TG(_GAME), _______,                             _______, _______,
//                             └────────┴────────┘                           └────────┴────────┘
//                                         ┌────────┬────────┐   ┌────────┬────────┐
                                             _______, _______,     _______, _______,
//                                         ├────────┼────────┤   ├────────┼────────┤
                                             _______, _______,     _______, _______
//                                         └────────┴────────┘   └────────┴────────┘
    ),

    [_NUMPAD] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┐
     _______, BR_LBRC, BR_RBRC, _______, _______,                           KC_KP_SLASH, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_ASTERISK,
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
     _______, KC_LPRN, KC_RPRN, _______, _______,                           KC_KP_MINUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS,
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
     _______, BR_LCBR, BR_RCBR, _______, _______,                           KC_KP_EQUAL, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_EQUAL,
// └────────┼────────┼────────┼────────┴────────┘                             └────────┴────────┼────────┼────────┼────────┘
              _______, _______,                                                                  KC_KP_0 ,KC_KP_DOT,
//          └────────┴────────┘┌────────┬────────┐                           ┌────────┬────────┐└────────┴────────┘
                                 _______, _______,                         KC_KP_ENTER,  KC_TAB,
//                             └────────┴────────┘                           └────────┴────────┘
//                                         ┌────────┬────────┐   ┌────────┬────────┐
                                             _______,TG(_NUMPAD),  KC_BSPC, _______,
//                                         ├────────┼────────┤   ├────────┼────────┤
                                             _______, _______,     _______, _______
//                                         └────────┴────────┘   └────────┴────────┘
    ),

    [_GAME] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┐
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                               _______, _______,  KC_UP , _______, _______,
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                               _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______,
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               _______, _______, _______, _______, _______,
// └────────┼────────┼────────┼────────┴────────┘                             └────────┴────────┼────────┼────────┼────────┘
                KC_F1,   KC_F2,                                                                   _______, _______,
//          └────────┴────────┘┌────────┬────────┐                           ┌────────┬────────┐└────────┴────────┘
                                  KC_ESC,  KC_SPC,                             _______, _______,
//                             └────────┴────────┘                           └────────┴────────┘
//                                         ┌────────┬────────┐   ┌────────┬────────┐
                                             _______, KC_LCTL,     _______, _______,
//                                         ├────────┼────────┤   ├────────┼────────┤
                                           TG(_GAME), _______,     _______, _______
//                                         └────────┴────────┘   └────────┴────────┘
    ),

    [_LAYER_SEL] = LAYOUT_kasama(
// ┌────────┬────────────┬─────────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┐
     _______, _______    , _______     , _______, _______,                      _______, _______, _______, _______, _______,
// ├────────┼────────────┼─────────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┤
   TG(_GAME), TG(_NUMPAD), TG(_WORKMAN), _______, _______,                      _______, _______, _______, _______, _______,
// ├────────┼────────────┼─────────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┤
     _______, _______    , _______     , _______, _______,                      _______, _______, _______, _______, _______,
// └────────┼────────────┼─────────────┼────────┴────────┘                    └────────┴────────┼────────┼────────┼────────┘
              _______    , _______     ,                                                          _______, _______,
//          └────────────┴─────────────┘┌────────┬────────┐                  ┌────────┬────────┐└────────┴────────┘
                                          _______, _______,                    _______, _______,
//                                      └────────┴────────┘                  └────────┴────────┘
//                                            ┌────────┬────────┐   ┌────────┬────────┐
                                                _______, _______,     _______, _______,
//                                            ├────────┼────────┤   ├────────┼────────┤
                                                _______, _______,     _______, _______
//                                            └────────┴────────┘   └────────┴────────┘
    ),

    [_TRANS] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______,
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______,
// ├────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______,
// └────────┼────────┼────────┼────────┴────────┘                             └────────┴────────┼────────┼────────┼────────┘
              _______, _______,                                                                   _______, _______,
//          └────────┴────────┘┌────────┬────────┐                           ┌────────┬────────┐└────────┴────────┘
                                 _______, _______,                             _______, _______,
//                             └────────┴────────┘                           └────────┴────────┘
//                                         ┌────────┬────────┐   ┌────────┬────────┐
                                             _______, _______,     _______, _______,
//                                         ├────────┼────────┤   ├────────┼────────┤
                                             _______, _______,     _______, _______
//                                         └────────┴────────┘   └────────┴────────┘
    ),
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch(get_highest_layer(state)) {
  case _NUMPAD:
    // turn on numlock, if it isn't already on.
    if (!(host_keyboard_led_state().num_lock)) {
      register_code(KC_NUM_LOCK);
      unregister_code(KC_NUM_LOCK);
    }
    break;
  }
  return state;
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  if (layer_state_is(_GAME)) {
    return false;
  }

  return true;
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t response[length];
    memset(response, 0, length);

    if (data[0] == 0x41) {
        raw_hid_send(response, length);
    } else if (data[0] == 0x42) {
        bootloader_jump();
    } else if (data[0] == 0x43) {
        response[0] = 0x43;
        response[1] = get_highest_layer(layer_state);
        raw_hid_send(response, length);
    } else if (data[0] == 0x44) {
        layer_move(data[1]);
        response[0] = 0x44;
        response[1] = get_highest_layer(layer_state);
        raw_hid_send(response, length);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case K_VIMCMD:
            SEND_STRING(SS_TAP(X_ESC) SS_DELAY(30) ":");
            break;
    }
    return true;
}
