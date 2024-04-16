#pragma once

// Override this function to give a name for each layer
const char *get_layer_name(int layer);
void raw_hid_receive(uint8_t *data, uint8_t length);
