// Copyright 2023 Kasama (@Kasama)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define OLED_FONT_H "keyboards/mechwild/mokulua/glcdfont.c"

#define MASTER_LEFT
//#define MASTER_RIGHT
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

#define COMBO_TERM 100

#define BACKLIGHT_PIN GP15

#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

#define COMBO_ONLY_FROM_LAYER 0
