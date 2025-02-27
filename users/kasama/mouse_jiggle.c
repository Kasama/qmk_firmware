#include "mouse_jiggle.h"
#include "debug.h"
#include "kasama_keycodes.h"
#include "timer.h"

#define SECONDS *1000
#define MINUTES *60 SECONDS

bool         kasama_mouse_jiggler = false;
fast_timer_t last_mouse_jiggle    = 0;

bool process_record_mouse_jiggler(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case K_JIGGLE:
            if (record->event.pressed) {
                set_mouse_jiggler(!kasama_mouse_jiggler);
            }
            break;
    }
    // Reset mouse jiggle on any record event
    if (kasama_mouse_jiggler && record->event.pressed) {
        last_mouse_jiggle = timer_read_fast();
    }
    return true;
}

void matrix_scan_mouse_jiggler() {
    if (kasama_mouse_jiggler) {
        fast_timer_t time = timer_read_fast();

        fast_timer_t diff = TIMER_DIFF_FAST(time, last_mouse_jiggle);
        if (diff > 5 MINUTES) {
            dprintf("jiggling the mouse\n");
            for (int i = 0; i < 2; i++) {
                tap_code(KC_MS_UP);
            }
            for (int i = 0; i < 2; i++) {
                tap_code(KC_MS_DOWN);
            }
            last_mouse_jiggle = time;
        }
    }
}

bool is_mouse_jiggler_enabled(void) {
    return kasama_mouse_jiggler;
}

void set_mouse_jiggler(bool value) {
    kasama_mouse_jiggler = value;
    dprintf("mouse_jiggler: %s\n", kasama_mouse_jiggler ? "enabled" : "disabled");
}
