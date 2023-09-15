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

// clang-format off

#include "keymap_brazilian_abnt2.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _OMEG 4
#define _LAYERRR 5
#define _NUMPAD 6
#define _TRANS 15

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  RALT_T(KC_SPC)
#define ALT_TAB  ALT_T(KC_TAB)
#define ALT_LBC  ALT_T(KC_TAB)
#define SFT_ENT  RSFT_T(KC_ENT)

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

#define RAISE OSL(_RAISE)
#define LOWER OSL(_LOWER)
#define LAYERRR OSL(_LAYERRR)
#define NUMPAD OSL(_NUMPAD)

#define LOWER_R OSL(_LOWER)
#define LOWER_B OSL(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * ,----------------------------------,                             ,----------------------------------,
     * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |  [   |   ]  |                                                         |   -  |   =  |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      | ESC  |  BS  |                             | SPACE|ENTER |
     *                      |  +   |   +  |                             |  +   |  +   |
     *                      | SHIFT| CTRL |                             | ALT  |SHIFT |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    | TAB  | HOME | | END  | DEL  |
     *                                    '------+------' '------+------'
     *                                    | Raise|  ~   | | GUI  | Lower|
     *                                    '------+------' '------+------'
     */
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,
       HM_SA,    KC_S,    KC_D,    KC_F,    KC_G,                                         KC_H,    KC_J,    KC_K,     KC_L,    HM_SÇ,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                         KC_N,    KC_M,   KC_COMM, KC_DOT,  BR_SLSH,
             BR_LBRC , BR_RBRC,                                                                            KC_MINS, KC_EQL,
                               SFT_ESC, CTL_BSPC,                                         ALT_SPC, LOWER,
                                                     ALT_TAB, KC_LGUI,  BR_BSLS, SFT_ENT,
                                                     RAISE,   LOWER ,   BR_QUOT, LAYERRR
    ),

    [_LAYERRR] = LAYOUT(
     BR_QUOT, _______, _______, _______, AC_TOGG,                                        KC_PRINT, _______, _______, _______, BR_ACUT,
     _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, BR_TILD,
     BR_BSLS, _______, BR_CCED, _______, _______,                                         _______, _______, _______, BR_SCLN, _______,
                       _______, _______,                                                           _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    ),

    /* Raise
     * ,----------------------------------,                             ,----------------------------------,
     * |      |      |  mup |      |      |                             | VOL+ |      |  up  |      | PgUp |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |      | mleft| mdown|mright|      |                             | MUTE | left | down |right | PgDn |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |      |      |      |      |      |                             | VOL- |  /   |  \   |  ?   |  |   |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |      |      |                                                         | mbtn |mbtn2 |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */
    [_RAISE] = LAYOUT(
        QK_BOOT, _______, KC_MU,   _______, _______,                                      KC_VOLU, KC_MUTE, KC_VOLD, _______, KC_PGUP,
        BR_QUOT, KC_ML,   KC_MD,   KC_MR,   _______,                                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGDN,
        BR_BSLS, _______, _______, _______, _______,                                      KC_F22 , KC_SLSH, KC_BSLS, KC_QUES, KC_PIPE,
                 _______, _______,                                                                          KC_MB1,  KC_MB2,
                                   _______,  KC_DEL,                                      _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    ),

    /* Lower
     * ,----------------------------------,                             ,----------------------------------,
     * | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  0   |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        | F11  | F12  |                                                         |  -   |  =   |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */
    [_LOWER] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
                 KC_F11,  KC_F12,                                                                           _______, _______,
                                   TG(_OMEG), _______,                                    _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    ),

    [_NUMPAD] = LAYOUT(
     _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
                       _______, _______,                                                           _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    ),

    [_OMEG] = LAYOUT(
        KC_Q,    KC_Q,    KC_W,    KC_R,    KC_R,                                         _______, _______, _______, _______, _______,
        KC_Q,    KC_A,    KC_S,    KC_D,    KC_F,                                         _______, _______, _______, _______, _______,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         _______, _______, _______, _______, _______,
                          KC_F1,  KC_F2,                                                           _______, _______,
                                                     KC_ESC ,   KC_SPC, _______, _______,
                                                     _______,  _______, _______, _______,
                                                     _______,TG(_OMEG), _______, _______
    ),

    [_TRANS] = LAYOUT(
     _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
                       _______, _______,                                                           _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    ),
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
