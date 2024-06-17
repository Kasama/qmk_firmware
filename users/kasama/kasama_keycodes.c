#include "kasama_keycodes.h"

#include "send_string_keycodes.h"
#include "sendstring_brazilian_abnt2.h"

#ifdef LEADER_ENABLE
#endif // LEADER_ENABLE

bool process_record_custom_keycode(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case K_VIMCMD:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC) SS_DELAY(30) ":");
            }
            break;
        case K_XSET:
            if (record->event.pressed) {
                SEND_STRING("xset r rate 200 35");
            }
            break;
        case K_EMAIL:
            if (record->event.pressed) {
                SEND_STRING("@robertoalegro.com");
            }
            break;
    }
    return true;
}
