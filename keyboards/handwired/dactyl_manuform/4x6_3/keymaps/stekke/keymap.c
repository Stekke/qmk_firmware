#include QMK_KEYBOARD_H

enum layer_names {
    _COLEMAK,
    _QWERTY,
    _NUM,
    _SYM,
    _FUN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT(
        KC_GESC,   KC_Q,     KC_W,      KC_F,        KC_P,      KC_B,                                          KC_J,            KC_L,      KC_U,     KC_Y,      KC_MINUS,  KC_EQUAL,
        KC_BSPC,   KC_A,     KC_R,      KC_S,        KC_T,      KC_G,                                          KC_M,            KC_N,      KC_E,     KC_I,      KC_O,      KC_ENTER,
        KC_DEL,    KC_Z,     KC_X,      KC_C,        KC_D,      KC_V,                                          KC_K,            KC_H,      KC_COMM,  KC_DOT,    KC_SLSH,   KC_BSLS,
                           DF(_QWERTY), LCA(KC_NO),  KC_LCTL,   MO(_NUM),     KC_RALT,        LGUI_T(KC_TAB),  LSFT_T(KC_SPC),  MO(_SYM),  KC_LEAD,  OSL(_FUN)
    ),

    [_QWERTY] = LAYOUT(
        KC_GESC,   KC_Q,     KC_W,      KC_E,        KC_R,      KC_T,                                          KC_Y,            KC_U,      KC_I,     KC_O,      KC_P,      KC_EQUAL,
        KC_BSPC,   KC_A,     KC_S,      KC_D,        KC_F,      KC_G,                                          KC_H,            KC_J,      KC_K,     KC_L,      KC_SCLN,   KC_ENTER,
        KC_DEL,    KC_Z,     KC_X,      KC_C,        KC_V,      KC_B,                                          KC_N,            KC_M,      KC_COMM,  KC_DOT,    KC_SLSH,   KC_BSLS,
                          DF(_COLEMAK), LCA(KC_NO),  KC_LCTL,   MO(_NUM),     KC_RALT,        LGUI_T(KC_TAB),  LSFT_T(KC_SPC),  MO(_SYM),  KC_LEAD,  OSL(_FUN)
    ),

    [_NUM] = LAYOUT(
        _______,   KC_NO,    KC_HOME,   KC_UP,       KC_END,    KC_PAGE_UP,                                     KC_NO,           KC_7,      KC_8,     KC_9,      _______,   _______,
        _______,   KC_NO,    KC_LEFT,   KC_DOWN,     KC_RIGHT,  KC_PAGE_DOWN,                                   KC_COMM,         KC_4,      KC_5,     KC_6,      KC_0,      _______,
        RESET  ,   KC_DQUO,  KC_QUOTE,  KC_SCLN,     KC_COLN,   KC_SCLN,                                        KC_DOT,          KC_1,      KC_2,     KC_3,      _______,   _______,
                             _______,   _______,     _______,   KC_NO,        _______,               _______,   _______,         KC_NO,     _______,  _______
    ),

    [_SYM] = LAYOUT(
        KC_GRAVE,  KC_EXLM,  KC_AT,     KC_HASH,     KC_DLR,    KC_NO,                                          KC_NO,           KC_PERC,   KC_CIRC,  KC_AMPR,   KC_ASTR,   KC_NO,
        _______,   KC_LT,    KC_LCBR,   KC_LPRN,     KC_LBRC,   KC_PIPE,                                        KC_QUES,         KC_RBRC,   KC_RPRN,  KC_RCBR,   KC_GT,     _______,
        RESET,     KC_DQUO,  KC_QUOTE,  KC_SCLN,     KC_COLN,   KC_SCLN,                                        KC_NO,           KC_MINS,   KC_UNDS,  _______,   _______,   _______,
                             _______,   _______,     _______,   KC_NO,        _______,               _______,   _______,         _______,   _______,  _______
    ),

    [_FUN] = LAYOUT(
        _______,   _______,  _______,   _______,     _______,   _______,                                        KC_NO,           KC_F9,     KC_F10,   KC_F11,    KC_F12,    _______,
        _______,   _______,  _______,   _______,     _______,   _______,                                        KC_NO,           KC_F5,     KC_F6,    KC_F7,     KC_F8,     _______,
        RESET,     _______,  _______,   _______,     _______,   _______,                                        KC_NO,           KC_F1,     KC_F2,    KC_F3,     KC_F4,     _______,
                             _______,   _______,     _______,   _______,      _______,               _______,   _______,         _______,   _______,  _______
    ),
};

LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_TWO_KEYS(KC_S, KC_C) {
      SEND_STRING(";-;");
    }
    SEQ_TWO_KEYS(KC_S, KC_S) {
      SEND_STRING("^~^");
    }
    SEQ_TWO_KEYS(KC_S, KC_H) {
      SEND_STRING("^^");
    }
  }
}
