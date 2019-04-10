#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _NAV 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  LAMBDA,
  HSHRKT,
  NEWLN,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_RST   RESET
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)

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

#include "layouts/raise.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
// corne:base
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                           KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSPC ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   CESC    ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                           KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,NQUO    ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ┌────────┼────────┼────────┼────────┼────────┼────────┤
   KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                           KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_ENT  ,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  KC_LGUI ,LOWER   ,KC_UNDS ,                  KC_SPC  ,RAISE   ,ASPC    
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT( \
// corne:lower
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_TILD ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,                           KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,KC_BSPC ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_BSPC ,KC_LBRC ,KC_RBRC ,KC_LCBR ,KC_RCBR ,KC_PIPE ,                           KC_PIPE ,KC_LPRN ,KC_RPRN ,_______ ,KC_COLN ,KC_DQUO ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ┌────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,TZM_OUT ,TZM_IN  ,_______ ,_______ ,TMUX    ,                           NEWLN   ,KC_EQL  ,KC_PLUS ,KC_MINS ,KC_QUES ,_______ ,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______ ,_______ ,_______ ,                  _______ ,_______ ,_______ 
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = CRKRS, 

  [_NAV] = LAYOUT( \
// corne:nav
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______ ,_______ ,SPECW   ,_______ ,_______ ,_______ ,                           _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,SPECL   ,SPECF   ,SPECR   ,_______ ,_______ ,                           KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ┌────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,TZM_IN  ,TZM_OUT ,_______ ,_______ ,KC_HOME ,                           KC_PGUP ,_______ ,_______ ,_______ ,_______ ,_______ ,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______ ,_______ ,KC_END  ,                  KC_PGDN ,_______ ,_______ 
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT( \
// FIXME: more Fn keys
// corne:adjust
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______ ,RESET   ,_______ ,_______ ,_______ ,_______ ,                           _______ ,_______ ,_______ ,_______ ,_______ ,KC_F12  ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                           _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ┌────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                           _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______ ,_______ ,_______ ,                  _______ ,_______ ,_______ 
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  /* if (is_master) { */
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  /* } else { */
  /*   matrix_write(matrix, read_logo()); */
  /* } */
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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

// layer state
#define L_BASE 0
#define L_LOWER 8
#define L_RAISE 16
#define L_NAV 32
#define L_ADJUST 65536
#define L_ADJUST_TRI 65560

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "          DEFAULT");
    break;
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "          RAISE");
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "          LOWER");
    break;
  case L_NAV:
    snprintf(layer_state_str, sizeof(layer_state_str), "          NAV");
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "          ADJUST");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "        LAYER-%ld", layer_state);
  }

  return layer_state_str;
}
