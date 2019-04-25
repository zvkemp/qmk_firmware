/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define IGNORE_MOD_TAP_INTERRUPT
#define BASE 0 // default layer
#define _LOWER 1
#define _RAISE 2
#define _NAV 3

#include "generated.h"

enum customKeycodes {
  LOWER,
  RAISE,
  ADJUST,
  LAMBDA,
  HSHRKT,
  NEWLN,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = GERGO__BASE,
  [_LOWER] = GERGO__LOWER,
  [_RAISE] = GERGO__RAISE,
  [_NAV] = GERGO__NAV,
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    //uint8_t layer = biton32(layer_state);
    biton32(layer_state);
};
