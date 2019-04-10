#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NAV 3
#define _MOUSE 4
#define _ADJUST 16

#define MSPC LT(_MOUSE, KC_BSPC)
#define CESC CTL_T(KC_ESC)
#define NQUO LT(_NAV, KC_QUOT)

// Spectacle keycodes
#define SPECL LCTL(LGUI(KC_LEFT))  // left half
#define SPECR LCTL(LGUI(KC_RIGHT)) // right half
#define SPECF LCTL(LGUI(KC_UP))    // fill screen
#define SPECW KC_F9                // next display

// Terminal zoom
#define TZM_IN LCTL(LSFT(KC_EQL))
#define TZM_OUT LCTL(LSFT(KC_MINS))

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  HSHRKT,
  LAMBDA,
  NEWLN,
};

/*
enum td_keycodes {
  TD_SH_UND = 0
};

typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD
} td_state_t;

static td_state_t td_state;

int cur_dance(qk_tap_dance_state_t *state);
void td_sh_und_finished (qk_tap_dance_state_t *state, void *user_data);
void td_sh_und_reset (qk_tap_dance_state_t *state, void *user_data);
*/

#include "generated.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = IRIS__BASE,
  [_LOWER] = IRIS__LOWER,
  [_RAISE] = IRIS__RAISE,
  [_ADJUST] = IRIS__ADJUST,
  [_NAV] = IRIS__NAV,
  [_MOUSE] = IRIS__MOUSE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case LAMBDA:
      if (record->event.pressed) { SEND_STRING("->"); }
      break;
    case HSHRKT:
      if (record->event.pressed) { SEND_STRING("=>"); }
      break;
    case NEWLN:
      if (record->event.pressed) { SEND_STRING("\\n"); }
      break;
  }
  return true;
}

/*
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) { return SINGLE_TAP; }
    else { return SINGLE_HOLD; }
  } else {
    return 2;
  }
}

void td_sh_und_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(KC_UNDS);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LSFT));
      break;
  }
}

void td_sh_und_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_UNDS);
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LSFT));
      break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SH_UND] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_sh_und_finished, td_sh_und_reset)
};
*/
