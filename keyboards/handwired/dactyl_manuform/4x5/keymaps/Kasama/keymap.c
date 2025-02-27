/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2023 Roberto Alegro

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
// ┌────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┐
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
// └────────┼────────┼────────┼────────┴────────┘         └────────┴────────┼────────┼────────┼────────┘
//          └────────┴────────┘┌────────┬────────┐       ┌────────┬────────┐└────────┴────────┘
//                             └────────┴────────┘       └────────┴────────┘
//                               ┌────────┬────────┐   ┌────────┬────────┐
//                               ├────────┼────────┤   ├────────┼────────┤
//                               └────────┴────────┘   └────────┴────────┘

// clang-format off

#include <stdint.h>
#include <string.h>
#include "action_layer.h"
#include "sendstring_brazilian_abnt2.h"
#include "raw_hid.h"
#include QMK_KEYBOARD_H
#include "numpad.h"

enum layers {
    _QWERTY = 0,
    _WORKMAN,
    _SYS,
    _NUMROW,
    _GAME,
    _GAME_NUM_2,
    _SYMB,
    _NUMPAD,
    _VIMMODE,
    _TRANS = 15
};

const char* layer_names[] = {
    [_QWERTY] = "QWERTY",
    [_WORKMAN] = "Workman",
    [_SYS] = "SYS",
    [_NUMROW] = "Numrow",
    [_GAME] = "Game",
    [_GAME_NUM_2] = "Game 2",
    [_SYMB] = "Symbols",
    [_NUMPAD] = "Numpad",
    [_VIMMODE] = "Vim mode",
    [_TRANS] = "Trans",
};

#define SFT_ESC  SFT_T(KC_ESC)
#define C_BSPC   CTL_T(KC_BSPC)
#define ALT_SPC  RALT_T(KC_SPC)
#define ALT_TAB  ALT_T(KC_TAB)
#define ALT_LBC  ALT_T(KC_TAB)
#define SFT_ENT  RSFT_T(KC_ENT)
#define SFT_DQUO SFT_T(BR_DQUO)

#define COD_ESC LT(_SYMB, KC_ESC)

// homerow tap mod keys
#define HM_SA SFT_T(KC_A)
#define HM_SZ SFT_T(KC_Z)
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
#define SYMB OSL(_SYMB)

#define NUMPAD MO(_NUMPAD)
#define GAME2 MO(_GAME_NUM_2)

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
const uint16_t PROGMEM c_leadsftent[]  = {QK_LEAD, SFT_ENT, COMBO_END};
const uint16_t PROGMEM c_jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM c_lç[] = {KC_L, HM_SÇ, COMBO_END};
const uint16_t PROGMEM c_as[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM c_zx[] = {KC_Z, KC_X, COMBO_END};
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
    COMBO(c_leadsftent, SYSTM),
    COMBO(c_sysesc, TG(_GAME)),
    COMBO(c_u_idx_homerow_r, QK_BOOT),
    COMBO(c_l_idx_homerow_r, QK_MAKE),
    COMBO(c_lç, K_VIMCMD),
    COMBO(c_homerow_l, NUMPAD),
    COMBO(c_idx_homerow_l, KC_ENTER),
    COMBO(c_zx, OSM(MOD_LSFT)),
    COMBO(c_atab, KC_LGUI),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  if (get_highest_layer(layer_state) == _GAME || get_highest_layer(layer_state) == _GAME_NUM_2) {
    return false;
  }

  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┐
      KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,            KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  ,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
      KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,            KC_H  ,  KC_J  ,  KC_K  ,  KC_L  ,  HM_SÇ ,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
      HM_SZ ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,            KC_N  ,  KC_M  , KC_COMM, KC_DOT , BR_SLSH,
// └────────┼────────┼────────┼────────┴────────┘         └────────┴────────┼────────┼────────┼────────┘
              BR_LBRC, BR_RBRC,                                               KC_MINS, KC_EQL ,
//          └────────┴────────┘┌────────┬────────┐       ┌────────┬────────┐└────────┴────────┘
                                 COD_ESC,  C_BSPC,         ALT_SPC,  NUMROW,
//                             └────────┴────────┘       └────────┴────────┘
//                               ┌────────┬────────┐   ┌────────┬────────┐
                                    SYSTM , ALT_TAB,     SFT_ENT, QK_LEAD,
//                               ├────────┼────────┤   ├────────┼────────┤
                                   KC_NO  ,  KC_NO ,      KC_NO ,  KC_NO
//                               └────────┴────────┘   └────────┴────────┘
    ),

    [_WORKMAN] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┐
      KC_Q  ,  KC_D  ,  KC_R  ,  KC_W  ,  KC_B  ,            KC_J  ,  KC_F  ,  KC_U  ,  KC_P  , BR_SCLN,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
      HM_SA ,  KC_S  ,  KC_H  ,  KC_T  ,  KC_G  ,            KC_Y  ,  KC_N  ,  KC_E  ,  KC_O  ,  KC_I  ,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
      KC_Z  ,  KC_X  ,  KC_M  ,  KC_C  ,  KC_V  ,            KC_K  ,  KC_L  , KC_COMM, KC_DOT , BR_SLSH,
// └────────┼────────┼────────┼────────┴────────┘         └────────┴────────┼────────┼────────┼────────┘
             BR_LBRC , BR_RBRC,                                               KC_MINS,  KC_EQL,
//          └────────┴────────┘┌────────┬────────┐       ┌────────┬────────┐└────────┴────────┘
                                 COD_ESC,  C_BSPC,         ALT_SPC,  NUMROW,
//                             └────────┴────────┘       └────────┴────────┘
//                               ┌────────┬────────┐   ┌────────┬────────┐
                                     SYSTM, ALT_TAB,     SFT_ENT,  SYMB  ,
//                               ├────────┼────────┤   ├────────┼────────┤
                                    NUMROW, KC_LGUI,     BR_QUOT, BR_BSLS
//                               └────────┴────────┘   └────────┴────────┘
    ),

    [_SYMB] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┐
     BR_QUOT, BR_DQUO, _______, DM_REC2, DM_PLY2,          KC_PRINT, BR_LBRC, BR_RBRC, BR_GRV , BR_ACUT,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     _______, _______,  KC_DEL, DM_REC1, DM_PLY1,           _______, KC_LPRN, KC_RPRN, BR_CIRC, BR_TILD,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     BR_BSLS, KC_CAPS, BR_CCED, _______, _______,           _______, BR_LCBR, BR_RCBR, BR_SCLN, BR_PIPE,
// └────────┼────────┼────────┼────────┴────────┘         └────────┴────────┼────────┼────────┼────────┘
              _______, _______,                                            S(KC_MINS), KC_PLUS,
//          └────────┴────────┘┌────────┬────────┐       ┌────────┬────────┐└────────┴────────┘
                                 _______, _______,         _______, _______,
//                             └────────┴────────┘       └────────┴────────┘
//                               ┌────────┬────────┐   ┌────────┬────────┐
                                   _______, _______,     _______, _______,
//                               ├────────┼────────┤   ├────────┼────────┤
                                   _______, _______,     _______, _______
//                               └────────┴────────┘   └────────┴────────┘
    ),

    [_SYS] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┐
     QK_BOOT, KC_MB1 , KC_MU,   KC_MB2 , AC_TOGG,           KC_VOLD, KC_MUTE, KC_VOLU, _______, KC_PGUP,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     BR_QUOT, KC_ML,   KC_MD,   KC_MR,   KC_F23 ,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGDN,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     BR_BSLS, KC_MPRV, KC_MPLY, KC_MNXT, TG(_WORKMAN),       KC_F23, KC_SLSH, KC_BSLS, KC_QUES, KC_PIPE,
// └────────┼────────┼────────┼────────┴────────┘         └────────┴────────┼────────┼────────┼────────┘
      QK_COMBO_TOGGLE, _______,                                                KC_MB1,  KC_MB2,
//          └────────┴────────┘┌────────┬────────┐       ┌────────┬────────┐└────────┴────────┘
                                 _______, _______,         _______, _______,
//                             └────────┴────────┘       └────────┴────────┘
//                               ┌────────┬────────┐   ┌────────┬────────┐
                                   _______, NUMPAD ,     _______, _______,
//                               ├────────┼────────┤   ├────────┼────────┤
                                   _______, _______,     _______, _______
//                               └────────┴────────┘   └────────┴────────┘
    ),

    [_NUMROW] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┐
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,             KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
// └────────┼────────┼────────┼────────┴────────┘         └────────┴────────┼────────┼────────┼────────┘
               KC_F11,  KC_F12,                                               _______, _______,
//          └────────┴────────┘┌────────┬────────┐       ┌────────┬────────┐└────────┴────────┘
                               TG(_GAME), _______,         _______, _______,
//                             └────────┴────────┘       └────────┴────────┘
//                               ┌────────┬────────┐   ┌────────┬────────┐
                                   _______, _______,     _______, _______,
//                               ├────────┼────────┤   ├────────┼────────┤
                                   _______, _______,     _______, _______
//                               └────────┴────────┘   └────────┴────────┘
    ),

    [_NUMPAD] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┐
     _______, BR_LBRC, BR_RBRC, _______, _______,          KP_SLASH,  KP_7  ,  KP_8  ,  KP_9  , KP_STAR,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     _______, KC_LPRN, KC_RPRN, _______, _______,          KP_MINUS,  KP_4  ,  KP_5  ,  KP_6  , KP_PLUS,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     _______, BR_LCBR, BR_RCBR, _______, _______,           KP_EQUL,  KP_1  ,  KP_2  ,  KP_3  , KP_EQUL,
// └────────┼────────┼────────┼────────┴────────┘         └────────┴────────┼────────┼────────┼────────┘
              _______, _______,                                                KP_0  ,  KP_COM,
//          └────────┴────────┘┌────────┬────────┐       ┌────────┬────────┐└────────┴────────┘
                                 _______, _______,         KC_SPC , KC_TAB ,
//                             └────────┴────────┘       └────────┴────────┘
//                               ┌────────┬────────┐   ┌────────┬────────┐
                                   _______,TG(_NUMPAD),  KP_ENTR, _______,
//                               ├────────┼────────┤   ├────────┼────────┤
                                   _______, _______,     _______, _______
//                               └────────┴────────┘   └────────┴────────┘
    ),

    [_GAME] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┐
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,           _______, _______,  KC_UP , _______, _______,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,           _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           _______, _______, _______, _______, _______,
// └────────┼────────┼────────┼────────┴────────┘         └────────┴────────┼────────┼────────┼────────┘
                KC_F1,   KC_F2,                                               _______, _______,
//          └────────┴────────┘┌────────┬────────┐       ┌────────┬────────┐└────────┴────────┘
                                  KC_ESC,  KC_SPC,         _______, _______,
//                             └────────┴────────┘       └────────┴────────┘
//                               ┌────────┬────────┐   ┌────────┬────────┐
                                    GAME2 , KC_LCTL,     _______, _______,
//                               ├────────┼────────┤   ├────────┼────────┤
                                 TG(_GAME), KC_LALT,     _______, _______
//                               └────────┴────────┘   └────────┴────────┘
    ),

    [_GAME_NUM_2] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,           _______, _______, _______, _______, _______,
// └────────┼────────┼────────┼────────┴────────┘         └────────┴────────┼────────┼────────┼────────┘
                KC_F1,   KC_F2,                                               _______, _______,
//          └────────┴────────┘┌────────┬────────┐       ┌────────┬────────┐└────────┴────────┘
                                 _______, _______,         _______, _______,
//                             └────────┴────────┘       └────────┴────────┘
//                               ┌────────┬────────┐   ┌────────┬────────┐
                                    GAME2 , _______,     _______, _______,
//                               ├────────┼────────┤   ├────────┼────────┤
                                   _______, _______,     _______, _______
//                               └────────┴────────┘   └────────┴────────┘
    ),

    [_VIMMODE] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,
// └────────┼────────┼────────┼────────┴────────┘         └────────┴────────┼────────┼────────┼────────┘
              _______, _______,                                               _______, _______,
//          └────────┴────────┘┌────────┬────────┐       ┌────────┬────────┐└────────┴────────┘
                                 _______, _______,         _______, _______,
//                             └────────┴────────┘       └────────┴────────┘
//                               ┌────────┬────────┐   ┌────────┬────────┐
                                   _______, _______,     _______, _______,
//                               ├────────┼────────┤   ├────────┼────────┤
                                   _______, _______,     _______, _______
//                               └────────┴────────┘   └────────┴────────┘
    ),


    [_TRANS] = LAYOUT_kasama(
// ┌────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,
// ├────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,
// └────────┼────────┼────────┼────────┴────────┘         └────────┴────────┼────────┼────────┼────────┘
              _______, _______,                                               _______, _______,
//          └────────┴────────┘┌────────┬────────┐       ┌────────┬────────┐└────────┴────────┘
                                 _______, _______,         _______, _______,
//                             └────────┴────────┘       └────────┴────────┘
//                               ┌────────┬────────┐   ┌────────┬────────┐
                                   _______, _______,     _______, _______,
//                               ├────────┼────────┤   ├────────┼────────┤
                                   _______, _______,     _______, _______
//                               └────────┴────────┘   └────────┴────────┘
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

#define HID_NOP 0x41
#define HID_BOOT 0x42

#define HID_RESP_BASE 0

#define HID_GET_LAYER 0x43
#define HID_RESP_LAYER 0x43
#define HID_RESP_GET_LAYER_ARG_LAYER 1
#define HID_RESP_GET_LAYER_ARG_LAYER_NAME 2

#define HID_SET_LAYER 0x44
#define HID_SET_LAYER_ARG_LAYER 1
#define HID_RESP_SET_LAYER 0x44
#define HID_RESP_SET_LAYER_ARG_LAYER 1

#define HID_ACTION_MATRIX 0x45
#define HID_ACTION_MATRIX_ARG_STATE 1
#define HID_ACTION_MATRIX_ARG_ROW 2
#define HID_ACTION_MATRIX_ARG_COL 3

void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t operation = data[0];
    uint8_t response[length];
    memset(response, 0, length);

    if (operation == HID_BOOT) {
        bootloader_jump();
    } else if (operation == HID_GET_LAYER) {
        response[HID_RESP_BASE]                = HID_RESP_LAYER;
        response[HID_RESP_GET_LAYER_ARG_LAYER] = get_highest_layer(layer_state);
        strncpy(
            (char *) &response[HID_RESP_GET_LAYER_ARG_LAYER_NAME],
            layer_names[response[HID_RESP_GET_LAYER_ARG_LAYER]],
            length - HID_RESP_GET_LAYER_ARG_LAYER_NAME - 1
        );
        raw_hid_send(response, length);
    } else if (operation == HID_SET_LAYER) {
        layer_move(data[HID_SET_LAYER_ARG_LAYER]);
        response[HID_RESP_BASE]                = HID_RESP_SET_LAYER;
        response[HID_RESP_SET_LAYER_ARG_LAYER] = get_highest_layer(layer_state);
        raw_hid_send(response, length);
    } else if (operation == HID_ACTION_MATRIX) {
        uint8_t state   = data[HID_ACTION_MATRIX_ARG_STATE];
        uint8_t row     = data[HID_ACTION_MATRIX_ARG_ROW];
        uint8_t col     = data[HID_ACTION_MATRIX_ARG_COL];
        bool    pressed = state > 0;

        action_exec(MAKE_KEYEVENT(row, col, pressed));

        response[0] = HID_RESP_SET_LAYER;
        response[1] = get_highest_layer(layer_state);
        raw_hid_send(response, length);
    }
}

void keyboard_post_init_user(void) {
    debug_enable = true;
    debug_matrix = true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case K_VIMCMD:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC) SS_DELAY(30) ":");
            }
            break;
    }
    return true;
}
