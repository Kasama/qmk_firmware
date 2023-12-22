#pragma once
#ifndef KASAMA_KEYCODES
#define KASAMA_KEYCODES

#include "quantum_keycodes.h"
#include "action.h"

enum kasama_custom_keycodes {
    K_VIMCMD = SAFE_RANGE,
    KASAMA_SAFE_RANGE,
};

#undef SAFE_RANGE
#define SAFE_RANGE KASAMA_SAFE_RANGE

bool process_record_custom_keycode(uint16_t keycode, keyrecord_t *record);

#define SFT_ESC SFT_T(KC_ESC)
#define C_BSPC CTL_T(KC_BSPC)
#define ALT_SPC RALT_T(KC_SPC)
#define ALT_TAB ALT_T(KC_TAB)
#define ALT_LBC ALT_T(KC_TAB)
#define SFT_ENT RSFT_T(KC_ENT)
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
#define HM_SC SFT_T(BR_SCLN)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2
#define KC_PRINT KC_PRINT_SCREEN

#define BR_RCBR S(BR_RBRC)
#define BR_LCBR S(BR_LBRC)

#endif
