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
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
// iris:base
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                           KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_BSPC ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                           KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_MINS ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   CESC    ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                           KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,NQUO    ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_LALT ,         KC_LCTRL,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_ENT  ,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  KC_LGUI ,LOWER   ,KC_UNDS ,                  KC_SPC  ,RAISE   ,MSPC    
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
// iris:lower
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_TILD ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,                           KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_TILD ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,                           KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,KC_PLUS ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_BSPC ,KC_LBRC ,KC_RBRC ,KC_LCBR ,KC_RCBR ,KC_PIPE ,                           KC_PIPE ,KC_LPRN ,KC_RPRN ,_______ ,KC_COLN ,KC_DQUO ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,TZM_OUT ,TZM_IN  ,_______ ,_______ ,C(KC_B) ,_______ ,         _______ ,NEWLN   ,KC_EQL  ,KC_PLUS ,KC_MINS ,KC_QUES ,_______ ,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______ ,_______ ,_______ ,                  _______ ,_______ ,_______ 
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
// iris:raise
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                           KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_BSPC ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                           KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,KC_VOLU ,_______ ,_______ ,                           _______ ,KC_MINS ,KC_EQL  ,_______ ,KC_COLN ,KC_BSLS ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   KC_MUTE ,_______ ,_______ ,KC_VOLD ,_______ ,_______ ,_______ ,         _______ ,_______ ,_______ ,_______ ,LAMBDA  ,HSHRKT  ,_______ ,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______ ,_______ ,KC_BSPC ,                  KC_DEL  ,_______ ,_______ 
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
// iris:adjust
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                           KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                           _______ ,_______ ,_______ ,_______ ,_______ ,KC_F12  ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                           _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,         KC_VOLU ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______ ,_______ ,_______ ,                  KC_VOLD ,_______ ,_______ 
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
// iris:nav
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                           _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,SPECW   ,_______ ,_______ ,_______ ,                           _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,SPECL   ,SPECF   ,SPECR   ,_______ ,_______ ,                           KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,TZM_IN  ,TZM_OUT ,_______ ,_______ ,_______ ,KC_HOME ,         KC_PGUP ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______ ,_______ ,KC_END  ,                  KC_PGDN ,_______ ,_______ 
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_MOUSE] = LAYOUT(
// iris:mouse
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                           _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                           _______ ,_______ ,KC_MS_U ,_______ ,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                           _______ ,KC_MS_L ,KC_MS_D ,KC_MS_R ,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,_______ ,_______ ,KC_BTN3 ,KC_BTN2 ,         KC_BTN2 ,KC_BTN3 ,_______ ,_______ ,_______ ,_______ ,_______ ,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______ ,_______ ,KC_BTN1 ,                  KC_BTN1 ,_______ ,_______ 
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
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
