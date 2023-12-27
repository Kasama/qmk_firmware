#include "auto_numlock.h"
#include "action_layer.h"
#include "host.h"

#define MULTI_CASES(...) _MULTI_CASES(__VA_ARGS__, END)
#define _MULTI_CASES(arg1, arg2, ...) \
    case arg1:                        \
        _MULTI_CASES(arg2, __VA_ARGS__)
#define END

void auto_enable_numlock(layer_state_t state) {
#ifdef AUTO_NUMLOCK_LAYERS
    switch (get_highest_layer(state)) {
        MULTI_CASES(AUTO_NUMLOCK_LAYERS)
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
