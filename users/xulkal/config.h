#pragma once

#undef TAPPING_TERM
#define TAPPING_TERM 175

#undef QUICK_TAP_TERM
#define QUICK_TAP_TERM TAPPING_TERM

#define SPACE_CADET_MODIFIER_CARRYOVER
#define LSPO_KEYS KC_LSFT, KC_TRNS, KC_LBRC
#define RSPC_KEYS KC_RSFT, KC_TRNS, KC_RBRC
#define LCPO_KEYS KC_LCTL, KC_TRNS, KC_MINS
#define RCPC_KEYS KC_RCTL, KC_TRNS, KC_EQL

// Running out of firmware space
#undef RGB_MATRIX_KEYRELEASES
#if !defined(__AVR__)
#    define ENABLE_TYPING_HEATMAP_DISTANCE_CHECK
#endif

// No need for the single versions when multi performance isn't a problem =D
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH

// 20m timeout (20m * 60s * 1000mil)
#define RGB_MATRIX_TIMEOUT 1200000
#define OLED_SCROLL_TIMEOUT 20000
