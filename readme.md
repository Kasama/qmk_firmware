# Quantum Mechanical Keyboard Firmware

This is my personal fork of QMK, for upstream, go to [this repo](https://github.com/qmk/qmk_firmware)

## My keyboard

I have built a dactyl manuform 4x5, so my keymap and configuration for that keyboard is located at `keyboards/handwired/dactyl_manuform/4x5/` and the layout is at `./keyboards/handwired/dactyl_manuform/4x5/keymaps/Kasama`.

to flash it, run

```
qmk flash -kb handwired/dactyl_manuform/4x5 -km Kasama
```

I've wired it a bit differently from the one upstream, so my `info.json` reflects the pins and matrix of my board.

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
