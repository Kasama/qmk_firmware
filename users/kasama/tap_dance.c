#include "tap_dance.h"
#include "action.h"
#include "action_util.h"
#include "keycodes.h"

#define SPC_SHIFT_TAP_DANCE_DEBUG 0
// #define SPC_SHIFT_TAP_DANCE_DEBUG 1
#if SPC_SHIFT_TAP_DANCE_DEBUG != 0
#    include "print.h"
#endif

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return TD_SINGLE_TAP;
        } else {
            // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
            return TD_SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) {
            return TD_DOUBLE_SINGLE_TAP;
        } else if (state->pressed) {
            return TD_DOUBLE_HOLD;
        } else {
            return TD_DOUBLE_TAP;
        }
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) {
            return TD_TRIPLE_TAP;
        } else {
            return TD_TRIPLE_HOLD;
        }
    } else {
        return TD_UNKNOWN;
    }
}

static uint8_t spc_shift_state = KC_NO;

void spc_shift_finished(tap_dance_state_t *state, void *user_data) {
#if SPC_SHIFT_TAP_DANCE_DEBUG != 0
    print("finished pressing spc_sft. count: ");
    print_dec(state->count);
    print(" interrupted: ");
    print_dec(state->interrupted);
    print("\n");
#endif
    if ((state->interrupted && state->pressed) || (state->pressed && state->count <= 2)) {
        spc_shift_state = KC_LSFT;
    } else {
        spc_shift_state = KC_SPACE;
    }
    for (int i = state->count - 1; i > 0; i--) {
        tap_code(KC_SPACE);
    }

    if (spc_shift_state == KC_LSFT && state->count > 1) {
        add_oneshot_mods(MOD_LSFT);
        spc_shift_state = KC_NO;
    } else {
        register_code(spc_shift_state);
    }
}
void spc_shift_reset(tap_dance_state_t *state, void *user_data) {
#if SPC_SHIFT_TAP_DANCE_DEBUG != 0
    print("resetting spc_sft. SFT: ");
    print_dec(KC_LSFT);
    print(" SPC: ");
    print_dec(KC_SPACE);
    print(". State: ");
    print_dec(spc_shift_state);
    print("\n");
#endif
    clear_oneshot_mods();
    unregister_code(spc_shift_state);
    spc_shift_state = KC_NO;
}

#if 0
static uint8_t magic_backspace_state = KC_NO;

void magic_basckspace_finished(tap_dance_state_t *state, void *user_data) {
#    if SPC_SHIFT_TAP_DANCE_DEBUG != 0
    print("finished pressing spc_sft. count: ");
    print_dec(state->count);
    print(" interrupted: ");
    print_dec(state->interrupted);
    print("\n");
#    endif
    if ((state->interrupted && state->pressed) || (state->pressed && state->count <= 2)) {
        spc_shift_state = KC_LSFT;
    } else {
        spc_shift_state = KC_SPACE;
    }
    for (int i = state->count - 1; i > 0; i--) {
        tap_code(KC_SPACE);
    }

    if (spc_shift_state == KC_LSFT && state->count > 1) {
        add_oneshot_mods(MOD_LSFT);
        spc_shift_state = KC_NO;
    } else {
        register_code(spc_shift_state);
    }
}
void magic_basckspace_reset(tap_dance_state_t *state, void *user_data) {
#    if SPC_SHIFT_TAP_DANCE_DEBUG != 0
    print("resetting spc_sft. SFT: ");
    print_dec(KC_LSFT);
    print(" SPC: ");
    print_dec(KC_SPACE);
    print(". State: ");
    print_dec(spc_shift_state);
    print("\n");
#    endif
    clear_oneshot_mods();
    unregister_code(spc_shift_state);
    spc_shift_state = KC_NO;
}
#endif

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {.is_press_action = true, .state = TD_NONE};

void x_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_X);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LCTL);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_ESC);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LALT);
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_X);
            register_code(KC_X);
            break;
        default:
            break;
    }
}

void x_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_X);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LCTL);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_ESC);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LALT);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_X);
            break;
        default:
            break;
    }
    xtap_state.state = TD_NONE;
}
