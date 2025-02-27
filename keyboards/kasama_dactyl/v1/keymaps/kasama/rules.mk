# QMK features
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes
RAW_ENABLE = yes
CONSOLE_ENABLE = yes

# Kasama features

# Allow the keyboard to be controlled by the computer through rawHID, implies RAW_ENABLE = yes
REMOTE_CONTROL_ENABLE = yes
# Add common keycodes from Kasama
KASAMA_KEYCODES_ENABLE = yes
# Automatically turn on NumLock when changing to the numpad layer
AUTO_NUMLOCK_ENABLE = yes
# Support for the keyboard to be plugged in from either half with the same keymap
AMBIDEXTERITY_ENABLE = no
MOUSE_JIGGLE_ENABLE = yes
