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
#define GERGO__BASE LAYOUT_GERGO( \
KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSPC, \
CESC,KC_A,KC_S,KC_D,KC_F,KC_G,_______,_______,KC_H,KC_J,KC_K,KC_L,KC_SCLN,NQUO, \
KC_LSFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_GRV,_______,KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_ENT, \
KC_LGUI,LOWER,RAISE,ASPC, \
_______,KC_LCTRL, \
KC_UNDS,KC_ENT,KC_LSFT,KC_SPC \
)
#define GERGO__LOWER LAYOUT_GERGO( \
KC_TILD,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_PLUS, \
KC_BSPC,KC_LBRC,KC_RBRC,KC_LCBR,KC_RCBR,KC_PIPE,_______,_______,KC_PIPE,KC_LPRN,KC_RPRN,_______,KC_COLN,KC_DQUO, \
_______,TZM_OUT,TZM_IN,KC_TILD,KC_GRV,TMUX,_______,_______,NEWLN,KC_EQL,KC_PLUS,KC_MINS,KC_QUES,_______, \
_______,_______,_______,_______, \
_______,_______, \
_______,_______,_______,_______ \
)
#define GERGO__RAISE LAYOUT_GERGO( \
KC_GRV,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,_______, \
_______,_______,_______,KC__VOLUP,_______,KC_DOT,_______,_______,KC_DOT,KC_MINS,KC_EQL,_______,KC_COLN,KC_BSLS, \
KC__MUTE,_______,_______,KC__VOLDOWN,_______,_______,_______,_______,_______,_______,_______,LAMBDA,HSHRKT,_______, \
_______,_______,_______,_______, \
_______,_______, \
KC_BSPC,_______,_______,KC_DEL \
)
#define GERGO__NAV LAYOUT_GERGO( \
_______,_______,SPECW,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
_______,SPECL,SPECF,SPECR,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,_______,_______, \
_______,TZM_IN,TZM_OUT,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
_______,_______,_______,_______, \
_______,_______, \
_______,_______,_______,_______ \
)
