#pragma once

#include "action.h"

bool process_record_mouse_jiggler(uint16_t keycode, keyrecord_t *record);
void matrix_scan_mouse_jiggler(void);
bool is_mouse_jiggler_enabled(void);
void set_mouse_jiggler(bool value);
