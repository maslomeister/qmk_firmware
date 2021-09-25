#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers {
    _BASE_LAYER,
    _FN1_LAYER,
    _FN2_LAYER,
};

// Key symbols are based on QMK. Use them to remap your keyboard
/*
 * Layer TAP _BASE_LAYER
 * ,-----------------------------------------------------------------------------------------.
 * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
 * |-----------------------------------------------------------------------------------------+
 * |  Esc    |   a    |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter |
 * |-----------------------------------------------------------------------------------------+
 * | Shift       |   z   |   x   |   c   |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |   UP    |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl  |  L1   |  Alt  |               space           |  CAPS  |  LEFT  | DOWN  | RIGHT |
 * \-----------------------------------------------------------------------------------------/
 * Layer HOLD in _BASE_LAYER
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |   FN1   |           |     |     |     |     |     |     |     |     |     |     |       |
 * |-----------------------------------------------------------------------------------------+
 * |         |      |     |      |       |     |     |     |     |     |     |               |
 * |-----------------------------------------------------------------------------------------+
 * |       |       |       |                                  |     FN2    |    |    |       |
 * \-----------------------------------------------------------------------------------------/
 */
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE_LAYER] = KEYMAP(/* Base */
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    LT(_FN1_LAYER, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, LT(_FN2_LAYER, KC_CAPS), KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    /*
     * Layer _FN1_LAYER
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
     * |-----------------------------------------------------------------------------------------+
     * |         |PGDN| UP  |PGUP |    |   |    |    |    |    | PS | HOME | END |               |
     * |-----------------------------------------------------------------------------------------+
     * |         |LEFT |DOWN |RIGHT|    |    |    |    |    |    |     |       |                 |
     * |-----------------------------------------------------------------------------------------+
     * |            |V-UP |V-DWN|MUTE |     |     |     |     |     |INSRT| DEL |      UP        |
     * |-----------------------------------------------------------------------------------------+
     * |       |      |        |              space           |  Alt  |  LEFT  |  DOWN  | RIGHT  |
     * \-----------------------------------------------------------------------------------------/
     *
     */
    [_FN1_LAYER] = KEYMAP(/* Base */
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
    KC_TRNS, KC_PGDN, KC_UP, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_TRNS,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_UP,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    /*
     * Layer _FN2_LAYER
     * ,-----------------------------------------------------------------------------------------.
     * |     |     |     |     |     |     |     |     |LEDOF|LEDON|LED_INTENS|LED_SPEED|   |    |
     * |-----------------------------------------------------------------------------------------+
     * |        | KC_1| KC_2| KC_3|     |     |     |     |     |     | PS | HOME | END |        |
     * |-----------------------------------------------------------------------------------------+
     * |          |KC_4 |KC_5 |KC_6|     |     |     |     |     |     |     |     |             |
     * |-----------------------------------------------------------------------------------------+
     * |            |  KC_7  |  KC_8  |  KC_9  |     |     |     |     |     |INSRT| DEL |       |
     * |-----------------------------------------------------------------------------------------+
     * |       |       |       |               KC_0             |       |       |  FN2  |        |
     * \-----------------------------------------------------------------------------------------/
     *
     */
    [_FN2_LAYER] = KEYMAP(/* Base */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AP_LED_OFF, KC_AP_LED_ON, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_TRNS,
    KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_TRNS, MO(_FN2_LAYER), KC_TRNS
    ),
};
const uint16_t keymaps_size = sizeof(keymaps);

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
    // Here are two common functions that you can use. For more LED functions, refer to the file "qmk_ap2_led.h"

    // annepro2-shine disables LEDs by default. Uncomment this function to enable them at startup.
    annepro2LedEnable();

    // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
    // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
    // annepro2LedSetProfile(i);
}

layer_state_t layer_state_set_user(layer_state_t layer) {
    const uint16_t *keymap = &keymaps[get_highest_layer(layer)][0][0];
    annepro2Led_t color = {
        .p.red = 0, .p.green = 0, .p.blue = 0, .p.alpha = 0xff, /* Overwrite color */
    };
    switch (get_highest_layer(layer)) {
        case _FN1_LAYER:
            // Set the leds to green
            color.p.red = 0xFF;
            color.p.green = 0x60;
            color.p.blue = 0xDF;
            break;
        case _FN2_LAYER:
            // Set the leds to blue
            color.p.red = 0x60;
            color.p.green = 0xFF;
            color.p.blue = 0xFF;
            break;
        default:
            // Reset back to the current profile
            annepro2LedResetForegroundColor();
            //annepro2LedSetForegroundColor(0x66, 0, 0xFF);
            return layer;
    }
    for (int row = 0; row < MATRIX_ROWS; row++) {
        for (int col = 0; col < MATRIX_COLS; col++) {
            // if (keymaps[get_highest_layer(layer)][row][col] != KC_TRNS) {
            if (keymap[MATRIX_COLS * row + col] != KC_TRNS) {
                color.p.alpha                 = 0xFF; /* Overwrite */
                ledMask[ROWCOL2IDX(row, col)] = color;
            } else {
                color.p.alpha                 = 0x00; /* Don't overwrite */
                ledMask[ROWCOL2IDX(row, col)] = color;
            }
        }
        annepro2LedMaskSetRow(row);
    }
    return layer;
}

// The function to handle the caps lock logic
// It's called after the capslock changes state or after entering layers 1 and 2.
bool led_update_user(led_t leds) {
    if (leds.caps_lock) {
        // Set the leds to red
        annepro2LedSetForegroundColor(0xFF, 0x00, 0x00);
    } else {
        annepro2LedResetForegroundColor();
    }

    return true;
}
