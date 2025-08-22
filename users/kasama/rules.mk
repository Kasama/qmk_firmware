SRC += kasama.c
SRC += layers.c

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

ifeq ($(strip $(AMBIDEXTERITY_ENABLE)), yes)
	SRC += ambidexterity.c
    OPT_DEFS += -DAMBIDEXTERITY_ENABLE
endif

ifeq ($(strip $(LEADER_ENABLE)), yes)
	SRC += kasama_leader.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tap_dance.c
endif

ifeq ($(strip $(MOUSE_JIGGLE_ENABLE)), yes)
	SRC += mouse_jiggle.c
    OPT_DEFS += -DMOUSE_JIGGLE_ENABLE
endif

ifeq ($(strip $(AUTOCORRECT_ENABLE)), yes)
	SRC += autocorrect.c
    OPT_DEFS += -DAUTOCORRECT_ENABLE
endif
