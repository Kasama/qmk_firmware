#include "auto_numlock.h"

#include "action.h"
#include "host.h"

#define CASES(...) _CASES(__VA_ARGS__, END)
#define _CASES(arg1, arg2, ...) \
    case arg1:                  \
        break;                  \
        _CASES(arg2, __VA_ARGS__)
#define END

void auto_enable_numlock() {
#ifdef AUTO_NUMLOCK_LAYERS
    switch (get_highest_layer(state)) {
        CASES(AUTO_NUMLOCK_LAYERS)
#endif
        // turn on numlock, if it isn't already on.
        if (!(host_keyboard_led_state().num_lock)) {
            register_code(KC_NUM_LOCK);
            unregister_code(KC_NUM_LOCK);
        }
#ifdef AUTO_NUMLOCK_LAYERS
        break;
    }
#endif
};
