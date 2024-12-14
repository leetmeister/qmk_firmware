#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
#define QWERTY 0
#define NUMPAD 1
#define FNMETA 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_GRAVE,KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                 KC_Y,  KC_U,  KC_I,  KC_O,  KC_P, KC_BSLS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     LCTL_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G,              KC_H,  KC_J,  KC_K,  KC_L, KC_SCLN, RCTL_T(KC_QUOT),\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     LSFT_T(KC_LBRC), KC_Z, KC_X, KC_C, KC_V, KC_B,             KC_N,  KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_RBRC),\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LGUI, TT(NUMPAD), KC_SPC,   KC_BSPC, LT(FNMETA, KC_ENT) ,RALT_T(KC_APP) \
                              //`--------------------'  `--------------------'
  ),

  [NUMPAD] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC, KC_INS, KC_HOME, KC_UP, KC_PGUP, KC_SCRL,          KC_PSCR, KC_7, KC_8, KC_9, KC_0, KC_MINS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_TRNS, KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS,      KC_NUM, KC_4, KC_5, KC_6, KC_SLSH, RCTL_T(KC_EQL),\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_TRNS, KC_LALT, KC_END, KC_DEL, KC_PGDN, KC_PENT,       KC_BSPC, KC_1, KC_2, KC_3, KC_DOT, KC_TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                            KC_TRNS, KC_TRNS, KC_TRNS,   KC_DEL, KC_TRNS, RALT_T(KC_PAUSE) \
                              //`--------------------'  `--------------------'
  ),

  [FNMETA] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_CALC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_TRNS, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_F11,       KC_F12, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, KC_TRNS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU,      RGB_TOG, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD, KC_TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                            KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS \
                              //`--------------------'  `--------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
