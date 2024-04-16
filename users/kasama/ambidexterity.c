#include "ambidexterity.h"
#include "action.h"
#include "action_tapping.h"
#include "action_util.h"
#include "keycode_config.h"
#include "print.h"
#include "keyboard.h"
#include "quantum.h"
#include "transactions.h"
#include "version.h"

bool ambidextrous_pre_process_record(keyrecord_t *record) {
    return pre_process_record_kb(record->keycode, record) &&
#ifdef COMBO_ENABLE
           process_combo(record->keycode, record) &&
#endif
           true;
}

void ambidextrous_action_exec(keyrecord_t record) {
    if (IS_EVENT(record.event)) {
        ac_dprintf("\n---- ambidextrous_action_exec: start -----\n");
        ac_dprintf("EVENT: ");
        debug_event(record.event);
        ac_dprintf("\n");
#if defined(RETRO_TAPPING) || defined(RETRO_TAPPING_PER_KEY) || (defined(AUTO_SHIFT_ENABLE) && defined(RETRO_SHIFT))
        retro_tapping_counter++;
#endif
    }

    if (record.event.pressed) {
        // clear the potential weak mods left by previously pressed keys
        clear_weak_mods();
    }

#ifdef SWAP_HANDS_ENABLE
    // Swap hands handles both keys and encoders, if ENCODER_MAP_ENABLE is defined.
    if (IS_EVENT(record.event)) {
        process_hand_swap(&record.event);
    }
#endif

#ifndef NO_ACTION_ONESHOT
    if (keymap_config.oneshot_enable) {
#    if (defined(ONESHOT_TIMEOUT) && (ONESHOT_TIMEOUT > 0))
        if (has_oneshot_layer_timed_out()) {
            clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        }
        if (has_oneshot_mods_timed_out()) {
            clear_oneshot_mods();
        }
#        ifdef SWAP_HANDS_ENABLE
        if (has_oneshot_swaphands_timed_out()) {
            clear_oneshot_swaphands();
        }
#        endif
#    endif
    }
#endif

#ifndef NO_ACTION_TAPPING
#    if defined(AUTO_SHIFT_ENABLE) && defined(RETRO_SHIFT)
    if (record.event.pressed) {
        retroshift_poll_time(&record.event);
    }
#    endif
    if (IS_NOEVENT(record.event) || ambidextrous_pre_process_record(&record)) {
        action_tapping_process(record);
    }
#else
    if (IS_NOEVENT(record.event) || ambidextrous_pre_process_record(&record)) {
        process_record(&record);
    }
    if (IS_EVENT(record.event)) {
        ac_dprintf("processed: ");
        debug_record(record);
        dprintln();
    }
#endif
}

typedef struct _master_to_slave_t {
    keyrecord_t record;
} master_to_slave_t;

typedef struct _slave_to_master_t {
    bool received;
} slave_to_master_t;

void transaction_keyrecord_mapper(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data) {
    // NOTE: This executes only on the master side

    const master_to_slave_t *data = in_data;
    uprintf("processing message from slave: keycode [%d, %d] = %d\n", data->record.event.key.row, data->record.event.key.col, data->record.keycode);

    // ambidextrous_action_exec(data->record);

    slave_to_master_t *out = out_data;
    out->received          = true;
}

void initialize_master_ambidexterity(void) {
    uprintf("hello from master v%s\n", QMK_BUILDDATE);
}

void initialize_slave_ambidexterity(void) {
    uprintf("hello from slave\n");
}

void initialize_ambidexterity(void) {
    transaction_register_rpc(TRANSACTION_KEYRECORD_MAPPING, transaction_keyrecord_mapper);
    if (is_keyboard_master()) {
        initialize_master_ambidexterity();
    } else {
        initialize_slave_ambidexterity();
    }
}

bool should_process_keypress(void) {
    // uprintf("negating master access to processing");
    return !is_keyboard_master();
    // return is_keyboard_master();
    // return true;
}

bool pre_process_ambidextrous(uint16_t keycode, keyrecord_t *record) {
    if (is_keyboard_master()) {
        // if (keycode == KC_KP_0) {
        //     if (ok) {
        //         uprintf("got response from other side: %d\n", response.received);
        //     } else {
        //         uprintf("didn't get responde from the other side\n");
        //     }
        // }

        // doesnt happen on "normal" flow from action_exec, instead it runs from ambidextrous_action_exec
        uprintf("Must only occur after message sent from slave\n");
    } else {
        master_to_slave_t val = {.record = *record};
        slave_to_master_t response;
        transaction_rpc_exec(TRANSACTION_KEYRECORD_MAPPING, sizeof(val), &val, sizeof(response), &response);
        return false;
    }
    return true;
}
