#include QMK_KEYBOARD_H

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
#define _NUM 1
#define _FUNC 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUM,
  FUNC,
  RGB_RST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_GRAVE,KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                 KC_Y,  KC_U,  KC_I,  KC_O,  KC_P, KC_BSLS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     LCTL_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G,              KC_H,  KC_J,  KC_K,  KC_L, KC_SCLN, RCTL_T(KC_QUOT),\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     LSFT_T(KC_LBRC), KC_Z, KC_X, KC_C, KC_V, KC_B,             KC_N,  KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_RBRC),\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LGUI, TT(_NUM), KC_SPC,   KC_BSPC, LT(_FUNC, KC_ENT) ,RALT_T(KC_APP) \
                              //`--------------------'  `--------------------'
  ),

  [_NUM] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC, KC_INS, KC_HOME, KC_UP, KC_PGUP, KC_SLCK,          KC_PSCR, KC_7, KC_8, KC_9, KC_0, KC_MINS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_TRNS, KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS,      KC_NLCK, KC_4, KC_5, KC_6, KC_SLSH, RCTL_T(KC_EQL),\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_TRNS, KC_LALT, KC_END, KC_DEL, KC_PGDN, KC_PENT,       KC_BSPC, KC_1, KC_2, KC_3, KC_DOT, KC_TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                            KC_TRNS, KC_TRNS, KC_TRNS,   KC_DEL, KC_TRNS, RALT_T(KC_PAUSE) \
                              //`--------------------'  `--------------------'
  ),

  [_FUNC] = LAYOUT( \
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

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
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
const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_host_led_state());
    matrix_write_ln(matrix, read_keylog());
    // matrix_write_ln(matrix, read_keylogs());
    // matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    // matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
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
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGB_RST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
