SRC += kasama.c
SRC += kasama_keycodes.c

ifeq ($(strip $(RAW_HID_ENABLE)), yes)
	SRC += hid.c
ifeq ($(strip $(REMOTE_CONTROL_ENABLE)), yes)
	SRC += remote_control.c
    OPT_DEFS += -DREMOTE_CONTROL_ENABLE
endif
endif
