SRC += kasama.c

ifeq ($(strip $(KASAMA_KEYCODES_ENABLE)), yes)
	SRC += kasama_keycodes.c
    OPT_DEFS += -DKASAMA_KEYCODES_ENABLE
endif

ifeq ($(strip $(AUTO_NUMLOCK_ENABLE)), yes)
	SRC += auto_numlock.c
    OPT_DEFS += -DAUTO_NUMLOCK_ENABLE
endif

ifeq ($(strip $(RAW_ENABLE)), yes)
	SRC += hid.c
ifeq ($(strip $(REMOTE_CONTROL_ENABLE)), yes)
	SRC += remote_control.c
    OPT_DEFS += -DREMOTE_CONTROL_ENABLE
endif
endif
