#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    LOWER_ALT_TAB,
};

bool is_alt_tab_active = false;

// Short names for custom actions to help in formatting keymaps
#define ___X___ KC_NO

#define T_LA_TAB LALT_T(KC_TAB)
#define T_LC_EQL LCTL_T(KC_EQL)
#define T_LS_LBRC LSFT_T(KC_LBRC)
#define T_RA_BSLS RALT_T(KC_BSLS)
#define T_RC_QUOT RCTL_T(KC_QUOT)
#define T_RS_RBRC RSFT_T(KC_RBRC)
#define T_LT1_DEL LT(1, KC_DEL)
#define T_LT1_BSP LT(1, KC_BSPC)
#define T_LT3_ESC LT(1, KC_ESC)

#define T_LA_CAPS LCTL_T(KC_CAPS)
#define T_L1_ATAB LOWER_ALT_TAB
#define T_LT2_PS LT(2, KC_PAUS)
#define T_RA_PAST RALT_T(KC_PAST)
#define T_RC_EQL RCTL_T(KC_EQL)
#define T_LT2_PLS LT(2, KC_PPLS)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_GRV,    KC_1, KC_2, KC_3, KC_4, KC_5,          /*...*/         KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS,
        T_LA_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,          /*...*/         KC_Y, KC_U, KC_I,    KC_O,   KC_P,    T_RA_BSLS,
        T_LC_EQL,  KC_A, KC_S, KC_D, KC_F, KC_G,          /*...*/         KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, T_RC_QUOT,
        T_LS_LBRC, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, /*...*/ KC_APP, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, T_RS_RBRC,
                         KC_LGUI, T_LT1_DEL, KC_SPC,      /*...*/         KC_ENT, T_LT1_BSP, T_LT3_ESC
        ),
    [_LOWER] = LAYOUT(
        KC_ESC,    KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,            /*...*/          KC_F6,  KC_F7, KC_F8, KC_F9, KC_F10,    KC_MINS,
        _______,   T_L1_ATAB, KC_HOME, KC_UP,   KC_PGUP, KC_F11,           /*...*/          KC_F12, KC_7,  KC_8,  KC_9,  KC_0,      T_RA_PAST,
        T_LA_CAPS, T_LT2_PS,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PENT,          /*...*/          KC_DOT, KC_4,  KC_5,  KC_6,  T_LT2_PLS, T_RC_EQL,
        _______,   KC_BSPC,   KC_END,  KC_DEL,  KC_PGDN, KC_LEAD, _______, /*...*/ _______, KC_ENT, KC_1,  KC_2,  KC_3,  KC_SLSH,   _______,
                                       _______, _______, _______,          /*...*/          _______, _______, _______
        ),
    [_RAISE] = LAYOUT(
        _______, ___X___, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSEL,          /*...*/          RALT(KC_PSCR), KC_PSCR, KC_SLCK, KC_PAUS, KC_NLCK, KC_CALC,
        _______, ___X___, KC_LCBR, KC_PIPE, KC_RCBR, LALT(KC_LEFT),    /*...*/          LCA(KC_DEL),   KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, _______, KC_LT,   KC_COLN, KC_GT,   LALT(KC_RGHT),    /*...*/          RCTL(KC_PAUS), KC_DLR,  KC_PERC, KC_CIRC, _______, _______,
        _______, ___X___, KC_TILD, KC_UNDS, KC_DQUO, ___X___, _______, /*...*/ _______, KC_COMM,       KC_EXLM, KC_AT,   KC_HASH, KC_QUES, _______,
                                   _______, _______, _______,          /*...*/          _______, _______, _______
        ),
    [_ADJUST] = LAYOUT(
        _______, ___X___, ___X___, ___X___, ___X___, ___X___,          /*...*/          RGB_VAD,  RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI,
        _______, ___X___, ___X___, ___X___, ___X___, ___X___,          /*...*/          RGB_MOD,  BL_TOGG, ___X___, KC_MS_U, KC_WH_U, KC_BTN3,
        _______, ___X___, ___X___, ___X___, ___X___, ___X___,          /*...*/          RGB_RMOD, BL_STEP, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2,
        _______, ___X___, ___X___, ___X___, ___X___, ___X___, _______, /*...*/ _______, RGB_TOG,  ___X___, KC_WH_L, KC_WH_R, KC_WH_D, KC_BTN1,
                                   _______, _______, _______,          /*...*/          _______, _______, _______
        )
};
// clang-format on

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
        case LOWER_ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    // These are disabled in matrix_scan_user based on layer
                    // state so that holding LOWER substitutes for holding ALT
                    // in ALT-TAB combo.
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    }
    return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    if (is_alt_tab_active && !(layer_state & (1UL << _LOWER))) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
    }

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_LEAD) { tap_code(KC_INS); }

        SEQ_THREE_KEYS(KC_C, KC_A, KC_D) {
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_DEL);
            unregister_code(KC_DEL);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
        }

        SEQ_THREE_KEYS(KC_C, KC_S, KC_E) {
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_ESC);
            unregister_code(KC_ESC);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
        }
    }
}

void suspend_power_down_user(void) {
    backlight_disable();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
}

void suspend_wakeup_init_user(void) {
    backlight_enable();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
