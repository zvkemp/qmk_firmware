#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2
#define _RAISE 3
#define _NAV 4
#define _NUMPAD 5
#define _ADJUST 16

#define CESC CTL_T(KC_ESC)
#define NQUO LT(_NAV, KC_QUOT)
#define MSPC LT(_MOUSE, KC_BSPC)
#define ASPC ALT_T(KC_BSPC)
#define TMUX C(KC_B)
#define TZM_IN LCTL(LSFT(KC_EQL))
#define TZM_OUT LCTL(LSFT(KC_MINS))
#define SPECW KC_F9
#define SPECL LCTL(LGUI(KC_LEFT))
#define SPECF LCTL(LGUI(KC_UP))
#define SPECR LCTL(LGUI(KC_RIGHT))

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  ADJUST,
  HSHRKT,
  LAMBDA,
  NEWLN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT( \
// nyquist:base
//┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,         KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_BSPC ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,         KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_MINS ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   CESC    ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,         KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,NQUO    ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,         KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_ENT  ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,KC_LCTRL,KC_LALT ,KC_LGUI ,LOWER   ,KC_UNDS ,         KC_SPC  ,RAISE   ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT
//└────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CEsc |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  | Ent  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |   _  |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS, \
  CTL_T(KC_ESC),KC_A,KC_R,   KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    LT(_NAV, KC_QUOT), \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_UNDS,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

[_LOWER] = LAYOUT( \
// nyquist:lower
//┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_TILD ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,         KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_TILD ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,         KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,KC_PLUS ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_BSPC ,KC_LBRC ,KC_RBRC ,KC_LCBR ,KC_RCBR ,KC_PIPE ,         KC_PIPE ,KC_LPRN ,KC_RPRN ,_______ ,KC_COLN ,KC_DQUO ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,TZM_OUT ,TZM_IN  ,_______ ,_______ ,TMUX    ,         NEWLN   ,KC_EQL  ,KC_PLUS ,KC_MINS ,KC_QUES ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,         _______ ,_______ ,_______ ,_______ ,_______ ,_______ 
//└────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘

),

[_RAISE] = LAYOUT( \
// nyquist:raise
//┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,         KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_BSPC ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,         KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,KC_VOLU ,_______ ,_______ ,         _______ ,KC_MINS ,KC_EQL  ,_______ ,KC_COLN ,KC_BSLS ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_MUTE ,_______ ,_______ ,KC_VOLD ,_______ ,_______ ,         _______ ,_______ ,_______ ,LAMBDA  ,HSHRKT  ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,_______ ,_______ ,KC_BSPC ,         KC_DEL  ,_______ ,_______ ,_______ ,_______ ,_______ 
//└────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
),

[_NAV] = LAYOUT( \
// nyquist:nav
//┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,         _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,SPECW   ,_______ ,_______ ,_______ ,         _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,SPECL   ,SPECF   ,SPECR   ,_______ ,_______ ,         KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,TZM_IN  ,TZM_OUT ,_______ ,_______ ,_______ ,         _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,         _______ ,_______ ,KC_HOME ,KC_PGUP ,KC_PGDN ,KC_END  
//└────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  _______, RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
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
