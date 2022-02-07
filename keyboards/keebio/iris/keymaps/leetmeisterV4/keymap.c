#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

typedef enum {
    CUSTOM_1 = SAFE_RANGE,
} custom_keycode_t;

typedef enum {
    TD_F7_RAISE,
    TD_NLCK_RAISE,
    TD_ESC_UNMOD,
    TD_OTT_ADJUST,
} tap_code_t;

// --------------------------
// Keymap formatting defines
// --------------------------
#define ___X___ KC_NO

// QWERTY Layer
#define T_LA_TAB LALT_T(KC_TAB)
#define T_LC_EQL LCTL_T(KC_EQL)
#define T_LS_LBRC LSFT_T(KC_LBRC)
#define T_RA_BSLS RALT_T(KC_BSLS)
#define T_RC_QUOT RCTL_T(KC_QUOT)
#define T_RS_RBRC RSFT_T(KC_RBRC)
#define T_LT1_DEL LT(1, KC_DEL)
#define T_LT1_BSP LT(1, KC_BSPC)
#define T_TD_ESC TD(TD_ESC_UNMOD)

// LOWER Layer
#define _LA_TAB_ KC_TRNS  // Indicate special process_record_user() handling of T_LA_TAB in this layer
#define T_LA_CAPS LCTL_T(KC_CAPS)
#define T_LT2_PS LT(2, KC_PAUS)
#define T_TD_F7_2 TD(TD_F7_RAISE)
#define T_OS_LSFT OSM(MOD_LSFT)
#define T_OS_RALT OSM(MOD_RALT)
#define T_OS_RCTL OSM(MOD_RCTL)
#define T_OS_RSFT OSM(MOD_RSFT)
#define T_TD_ADJ TD(TD_OTT_ADJUST)

#define T_ALT_LFT LALT(KC_LEFT)
#define T_ALT_RT LALT(KC_RIGHT)

// RAISE Layer
#define T_ALT_UP LALT(KC_UP)
#define T_ALT_DWN LALT(KC_DOWN)
#define T_ALT_F4 LALT(KC_F4)
#define T_ALT_F8 LALT(KC_F8)
#define T_ALT_PSC RALT(KC_PSCR)
#define T_TD_NL_2 TD(TD_NLCK_RAISE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_GRV,    KC_1, KC_2, KC_3, KC_4, KC_5,          /*...*/        KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS,
        T_LA_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,          /*...*/        KC_Y, KC_U, KC_I,    KC_O,   KC_P,    T_RA_BSLS,
        T_LC_EQL,  KC_A, KC_S, KC_D, KC_F, KC_G,          /*...*/        KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, T_RC_QUOT,
        T_LS_LBRC, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, /*...*/ TG(3), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, T_RS_RBRC,
                         KC_LGUI, T_LT1_DEL, KC_SPC,      /*...*/         KC_ENT, T_LT1_BSP, T_TD_ESC
        ),
    [_LOWER] = LAYOUT(
        KC_ESC,    KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,            /*...*/          KC_F6,     T_TD_F7_2, KC_F8,    KC_F9,    KC_F10,  KC_PAUS,
        _LA_TAB_,  KC_BSPC,   KC_HOME, KC_UP,   KC_PGUP, KC_F11,           /*...*/          KC_F12,    KC_LOCK,   KC_MS_U,  KC_WH_U,  KC_BTN3, T_OS_RALT,
        T_LA_CAPS, T_LT2_PS,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PENT,          /*...*/          T_ALT_LFT, KC_MS_L,   KC_MS_D,  KC_MS_R,  KC_BTN1, T_OS_RCTL,
        T_OS_LSFT, T_TD_ADJ,  KC_END,  _______, KC_PGDN, KC_INS,  KC_MPLY, /*...*/ _______, T_ALT_RT,  KC_WH_L,   KC_WH_R,  KC_WH_D,  KC_BTN2, T_OS_RSFT,
                                       _______, _______, _______,          /*...*/          _______, _______, _______
        ),
    [_RAISE] = LAYOUT(
        _______, _______, _______,   _______,   T_ALT_F4, T_ALT_F8,         /*...*/          T_ALT_PSC, T_TD_NL_2, KC_PSLS, KC_PAST, KC_ESC,  KC_CALC,
        _______, _______, _______,   T_ALT_UP,  _______,  _______,          /*...*/          KC_PSCR,   KC_7,      KC_8,    KC_9,    KC_PMNS, _______,
        _______, _______, T_ALT_LFT, T_ALT_DWN, T_ALT_RT, _______,          /*...*/          KC_SLCK,   KC_4,      KC_5,    KC_6,    KC_PPLS, _______,
        _______, _______, _______,   _______,   _______,  _______, _______, /*...*/ _______, KC_PCMM,   KC_1,      KC_2,    KC_3,    KC_PENT, _______,
                                       _______, _______, _______,           /*...*/           KC_0,  _______,  KC_DOT
        ),
    [_ADJUST] = LAYOUT(
        _______, ___X___, ___X___, ___X___, ___X___, ___X___,          /*...*/          RGB_TOG,  ___X___, ___X___, ___X___, ___X___, KC_MSEL,
        _______, ___X___, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,          /*...*/          RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, ___X___, ___X___,
        _______, ___X___, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,          /*...*/          RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, ___X___, ___X___,
        _______, ___X___, KC_EXLM, KC_AT,   KC_HASH, ___X___, _______, /*...*/ _______, ___X___,  ___X___, KC_BRID, KC_BRIU, ___X___, ___X___,
                                   KC_LCBR, KC_RCBR, KC_UNDS,          /*...*/          _______, _______, _______
        ),
};
// clang-format on

// --------------------------
//  Custom keycode behaviors
// --------------------------

static bool is_alt_tab_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(KC_TAB):
            // If on _LOWER layer, override ALT/TAB Mod-Tap to behave like ALT+TAB instead.
            if (get_highest_layer(layer_state) == _LOWER) {
                if (record->event.pressed) {
                    if (!is_alt_tab_active) {
                        // Keep ALT pressed while _LOWER is active (i.e. Layer Toggle key for _LOWER is held)
                        // matrix_scan_user() will scan the layer_state to reset the bool and unregister the
                        // ALT keycode when the layer toggle is released.
                        is_alt_tab_active = true;
                        register_code(KC_LALT);
                    }
                    register_code(KC_TAB);
                } else {
                    unregister_code(KC_TAB);
                }
                return false;
            }
            // Return true for normal processing of the ALT/TAB Mod-Tap
            return true;
    }
    return true;
}

void matrix_scan_user(void) {
    if (is_alt_tab_active && !layer_state_is(_LOWER)) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
    }
}

// -------------------
//  Tap Dance actions
// -------------------

typedef enum {
    TD_STATE_NONE,
    TD_STATE_TAP,
    TD_STATE_HOLD,
    TD_STATE_DOUBLE_TAP,
    TD_STATE_LIMIT,
} tap_state_t;

static tap_state_t ott_adjust_state = TD_STATE_NONE;

static tap_state_t get_tap_state(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return TD_STATE_TAP;
        else
            return TD_STATE_HOLD;
    } else if (state->count == 2) {
        return TD_STATE_DOUBLE_TAP;
    }
    return TD_STATE_LIMIT;
}

// 3-state tap dance for _ADJUST layer:
// - Tap for OSM(_ADJUST)
// - Hold for MO(_ADJUST)
// - Double-tap for TG(_ADJUST)
static void td_ott_adjust_finished(qk_tap_dance_state_t *state, void *user_data) {
    ott_adjust_state = get_tap_state(state);
    switch (ott_adjust_state) {
        case TD_STATE_TAP:
            del_mods(get_oneshot_locked_mods());
            if (get_oneshot_layer_state() == ONESHOT_TOGGLED) {
                reset_oneshot_layer();
                layer_off(_ADJUST);
            } else {
                layer_on(_ADJUST);
                set_oneshot_layer(_ADJUST, ONESHOT_START);
            }
            break;
        case TD_STATE_HOLD:
            layer_on(_ADJUST);
            break;
        case TD_STATE_DOUBLE_TAP:
            del_mods(get_oneshot_locked_mods());
            break;
        default:
            ott_adjust_state = TD_STATE_NONE;
    }
}

static void td_ott_adjust_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ott_adjust_state) {
        case TD_STATE_TAP:
            add_mods(get_oneshot_locked_mods());
            clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        case TD_STATE_HOLD:
            layer_off(_ADJUST);
            break;
        case TD_STATE_DOUBLE_TAP:
            add_mods(get_oneshot_locked_mods());
            reset_oneshot_layer();
            clear_oneshot_locked_mods();
            set_oneshot_layer(_ADJUST, ONESHOT_TOGGLED);
            break;
        default:
            break;
    }
    ott_adjust_state = TD_STATE_NONE;
}

// Multi-tap ESC to clear all oneshot mods, including locked mods
static void td_esc_unmod_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count > 1) {
        unregister_mods(0xFF);
        clear_oneshot_locked_mods();
        clear_oneshot_mods();
    } else {
        register_code(KC_ESC);
    }
}

static void td_esc_unmod_reset(qk_tap_dance_state_t *state, void *user_data) { unregister_code(KC_ESC); }

// All tap dance functions would go here.
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_F7_RAISE]   = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_F7, _RAISE),
    [TD_NLCK_RAISE] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_NLCK, _RAISE),
    [TD_ESC_UNMOD]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_esc_unmod_finished, td_esc_unmod_reset),
    [TD_OTT_ADJUST] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_ott_adjust_finished, td_ott_adjust_reset),
};

// -------------------
//  Encoder functions
// -------------------

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (get_highest_layer(layer_state) == _LOWER) {
            if (clockwise) {
                tap_code(KC_MNXT);
            } else {
                tap_code(KC_MPRV);
            }
        } else {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
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

// -----------------------------------
// RGB Light suspend/resume behaviors
// -----------------------------------

void suspend_power_down_user(void) {
    backlight_disable();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
}

void suspend_wakeup_init_user(void) {
    backlight_enable();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
