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
     * |         |  HOME  | UP  | END |    |   |    |    |    |    |    |      |     |           |
     * |-----------------------------------------------------------------------------------------+
     * |         |LEFT |DOWN |RIGHT|    |    | DEL|    |    |    |     |       |                 |
     * |-----------------------------------------------------------------------------------------+
     * |    SHIFT   |     |    |      |     |     |     |     |     |     |     |      UP        |
     * |-----------------------------------------------------------------------------------------+
     * |       |      |        |              space           |  Alt  |  LEFT  |  DOWN  | RIGHT  |
     * \-----------------------------------------------------------------------------------------/
     *
     */
    [_FN1_LAYER] = KEYMAP(/* Base */
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
    KC_NO, KC_HOME, KC_UP, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_DEL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_LSHIFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    /*
     * Layer _FN2_LAYER
     * ,-----------------------------------------------------------------------------------------.
     * |     |     |     |    |    |   |   |   |LEDOF|LEDON|LED_INTENS|LED_SPEED|   |CTRL_ALT_DEL|
     * |-----------------------------------------------------------------------------------------+
     * |      | KC_1| KC_2| KC_3|  |  |PREV_TRACK|PLAY/PAUSE|NEXT_TRACK|   |   |    |     |      |
     * |-----------------------------------------------------------------------------------------+
     * |          |KC_4 |KC_5 |KC_6|     |     |V_DOWN| MUTE|V_UP|     |     |     |             |
     * |-----------------------------------------------------------------------------------------+
     * |            |  KC_7  |  KC_8  |  KC_9  |     |     |     |     |     |      |    |       |
     * |-----------------------------------------------------------------------------------------+
     * |       |       |       |               KC_0             |       |       |  FN2  |        |
     * \-----------------------------------------------------------------------------------------/
     *
     */
    [_FN2_LAYER] = KEYMAP(/* Base */
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_AP_LED_OFF, KC_AP_LED_ON, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED, KC_NO, LALT(LCTL(KC_DEL)),
    KC_NO, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_0, KC_NO, KC_NO, MO(_FN2_LAYER), KC_NO
    ),
};
const uint16_t keymaps_size = sizeof(keymaps);

void enableProfileColor(uint8_t * profile, const uint16_t * keymap);
void resetProfileColor(void);

bool is_caps_set = false;

uint8_t default_profile = 0;
uint8_t base_profile[] = {0xC8, 0x00, 0xFF};
uint8_t caps_profile[] = {0xFF,0x00,0x00};
uint8_t fn1_profile[] = {0xFF,0x60,0xDF};
uint8_t fn2_profile[] = {0x00,0xFF,0xD5};

uint32_t sleep_timer;
int8_t ap2_is_asleep = 0;

void ap2_dim_leds(void) {
    annepro2LedNextIntensity();
    sleep_timer = timer_read32();
    if(annepro2LedStatus.ledIntensity == 7){
        ap2_is_asleep = 1;
        annepro2LedDisable();
    }
}

void ap2_wake(void) {
    annepro2LedEnable();
    annepro2LedSetIntensity(5);
    ap2_is_asleep = 0;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {
    if (annepro2LedStatus.matrixEnabled &&
        ap2_is_asleep == 0 &&
        timer_elapsed32(sleep_timer) >= SLEEP_TIME_AMOUNT)
    {
        ap2_dim_leds();
    }
}

void keyboard_post_init_user(void) {
    annepro2LedEnable();
    annepro2LedSetIntensity(5);
    resetProfileColor();
}

// The function to handle the caps lock logic
// It's called after the capslock changes state or after entering layers 1 and 2.
bool led_update_user(led_t leds) {
    if (leds.caps_lock) {
        is_caps_set = true;
        resetProfileColor();
        return true;
    } else if(is_caps_set) {
        is_caps_set = false;
        resetProfileColor();
    }

    return true;
}

layer_state_t layer_state_set_user(layer_state_t layer) {
    const uint16_t *keymap = &keymaps[get_highest_layer(layer)][0][0];
    switch (get_highest_layer(layer)) {
        case _FN1_LAYER:
            enableProfileColor(fn1_profile, keymap);
            break;
        case _FN2_LAYER:
            enableProfileColor(fn2_profile, keymap);
            break;
        default:
            resetProfileColor();
            break;
    }
    return layer;
}

void enableProfileColor (uint8_t * profile, const uint16_t * keymap) {
    if(is_caps_set) {
        annepro2LedSetForegroundColor(caps_profile[0], caps_profile[1], caps_profile[2]);
    } else {
        annepro2Led_t color = {
            .p.red = 0, .p.green = 0, .p.blue = 0, .p.alpha = 0xff, 
            };

        annepro2Led_t black = {
            .p.red = 0, .p.green = 0, .p.blue = 0, .p.alpha = 0xff, 
            };

        color.p.red = profile[0];
        color.p.green = profile[1];
        color.p.blue = profile[2];

        for (int row = 0; row < MATRIX_ROWS; row++) {
            for (int col = 0; col < MATRIX_COLS; col++) {
                if (keymap[MATRIX_COLS * row + col] != KC_NO) {
                    ledMask[ROWCOL2IDX(row, col)] = color;
                } else {
                    ledMask[ROWCOL2IDX(row, col)] = black;
                }
            }
            annepro2LedMaskSetRow(row);
        }
    }
}

void resetProfileColor(void) {
    if(is_caps_set) {
        annepro2LedSetForegroundColor(caps_profile[0], caps_profile[1], caps_profile[2]);
    } else {
        annepro2LedSetForegroundColor(base_profile[0], base_profile[1], base_profile[2]);
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    sleep_timer = timer_read32();
        if (ap2_is_asleep) {
            ap2_wake();
        }
    return true;
}