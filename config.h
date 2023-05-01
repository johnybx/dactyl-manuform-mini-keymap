#pragma once

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// row-driven
#define MATRIX_ROW_PINS \
    { F7, B1, B3, B2, B6 }
#define MATRIX_COL_PINS \
    { D4, C6, D7, E6, B4, B5 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Serial communication pins */
#define SOFT_SERIAL_PIN D0

// WS2812 RGB LED strip input and number of LEDs
#define RGB_DI_PIN D3
#define RGBLED_NUM 50
#define RGBLED_SPLIT \
    { 25, 25 }
#define RGBLIGHT_SLEEP
#define RGBLIGHT_SPLIT

#define USB_SUSPEND_WAKEUP_DELAY 0
#define AUTO_SHIFT_TIMEOUT 200
#define NO_AUTO_SHIFT_TAB
#define NO_AUTO_SHIFT_ALPHA
#define MASTER_LEFT
// #define MASTER_RIGHT
#define RGBLIGHT_LIMIT_VAL 150
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL RGBLIGHT_MODE_RAINBOW_SWIRL + 2
#define RGBLIGHT_EFFECT_SNAKE RGBLIGHT_MODE_SNAKE + 3
#define RGBLIGHT_EFFECT_TWINKLE RGBLIGHT_EFFECT_TWINKLE + 4
#define RGBLIGHT_EFFECT_RAINBOW_MOOD RGBLIGHT_MODE_RAINBOW_MOOD + 3

#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT

#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT
// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md
// #define PERMISSIVE_HOLD_PER_KEY
