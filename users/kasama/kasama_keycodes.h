#pragma once

#ifdef KASAMA_KEYCODES_ENABLE

#    include "quantum_keycodes.h"
#    include "action.h"

enum kasama_custom_keycodes {
    K_VIMCMD = SAFE_RANGE,
    K_XSET,
    K_EMAIL,
    K_JIGGLE,
    KASAMA_SAFE_RANGE,
};

#    undef SAFE_RANGE
#    define SAFE_RANGE KASAMA_SAFE_RANGE

bool process_record_custom_keycode(uint16_t keycode, keyrecord_t *record);

#endif

// mod taps and thumb keys
#define SFT_ESC SFT_T(KC_ESC)
#define C_BSPC CTL_T(KC_BSPC)
#define ALT_SPC RALT_T(KC_SPC)
#define SFT_SPC SFT_T(KC_SPC)
#define ALT_TAB ALT_T(KC_TAB)
#define ALT_LBC ALT_T(KC_TAB)
#define SFT_ENT RSFT_T(KC_ENT)
#define RALT_ENT RALT_T(KC_ENT)
#define SFT_DQUO SFT_T(BR_DQUO)

#define SYM_ESC LT(_SYMB, KC_ESC)

// homerow mod tap
#define HM_SA SFT_T(KC_A)
#define HM_SZ SFT_T(KC_Z)
#define HM_CS CTL_T(KC_S)
#define HM_AD ALT_T(KC_D)
#define HM_GF GUI_T(KC_F)

#define HM_GJ GUI_T(KC_J)
#define HM_AK ALT_T(KC_K)
#define HM_CL CTL_T(KC_L)
#define HM_SC SFT_T(BR_SCLN)

// other mod taps
#define CTRL_1 CTL_T(KC_1)

// Shorform names
#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2
#define KC_MWU KC_MS_WH_UP
#define KC_MWD KC_MS_WH_DOWN
#define KC_PRINT KC_PRINT_SCREEN

#define BR_RCBR S(BR_RBRC)
#define BR_LCBR S(BR_LBRC)
#define BR_LESS S(BR_COMM)
#define BR_GRTR S(BR_DOT)

// Layer Keycodes
#define SYSTM OSL(_SYS)
#define NUMROW OSL(_NUMROW)
#define SYMB OSL(_SYMB)
#define NUMPAD MO(_NUMPAD)
#define GAME2 MO(_GAME_NUM_2)
