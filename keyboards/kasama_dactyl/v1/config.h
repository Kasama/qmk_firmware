// Copyright 2023 Kasama (@Kasama)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT

// #define MASTER_RIGHT
#define MASTER_LEFT

#define SERIAL_PIO_USE_PIO1     // Force the usage of PIO1 peripheral, by default the Serial implementation uses the PIO0 peripheral
#define SERIAL_USART_TX_PIN GP0 // The GPIO pin that is used split communication.

#define TAPPING_TOGGLE 1
// #define ONESHOT_TIMEOUT 500
// #define HOLD_ON_OTHER_KEY_PRESS
// #define PERMISSIVE_HOLD

// #define COMBO_ONLY_FROM_LAYER 0

// #define ENABLE_COMPILE_KEYCODE

#ifdef BOOTMAGIC_ENABLE
#    define BOOTMAGIC_LITE_ROW_LEFT 0
#    define BOOTMAGIC_LITE_COLUMN_LEFT 0

#    define BOOTMAGIC_LITE_ROW_RIGHT 4
#    define BOOTMAGIC_LITE_COLUMN_RIGHT 5
#endif
