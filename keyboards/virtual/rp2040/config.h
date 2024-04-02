<<<<<<< HEAD:keyboards/virtual/rp2040/config.h
// Copyright 2023 Kasama (@Kasama)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

<<<<<<<< HEAD:keyboards/virtual/rp2040/config.h
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
|||||||| b7468f4785:keyboards/handwired/alcor_dactyl/config.h
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP10
#define SERIAL_USART_RX_PIN GP9
#define RGB_MATRIX_LED_COUNT 2
#define RGB_MATRIX_SPLIT { 1, 1 }
#define EE_HANDS
========
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP10
#define SERIAL_USART_RX_PIN GP9

#define EE_HANDS
>>>>>>>> b108524314047b947031d1cb688e2a378cf586c7:keyboards/handwired/alcor_dactyl/config.h
||||||| b7468f4785:keyboards/virtual/rp2040/config.h
=======
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#define BACKLIGHT_PWM_DRIVER PWMD3
#define BACKLIGHT_PWM_CHANNEL 1
#define BACKLIGHT_PAL_MODE 1
>>>>>>> b108524314047b947031d1cb688e2a378cf586c7:keyboards/hineybush/h87_g2/config.h
