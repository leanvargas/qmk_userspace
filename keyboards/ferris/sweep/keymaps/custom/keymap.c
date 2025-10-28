#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#include "keymap.h"
#endif

// CUSTOM KEYCODES
enum custom_keycodes {
    EURO = SAFE_RANGE,
	HACEK,
};

// COMBOS
const uint16_t PROGMEM slash_combo[] = {KC_COMM, KC_DOT, COMBO_END};
combo_t key_combos[] = {
    COMBO(slash_combo, KC_SLSH),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case EURO:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_ALGR) SS_TAP(X_5) SS_UP(X_ALGR));
        } else {
            // when keycode EURO is released
        }
        break;
    case HACEK:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_ALGR) SS_DOWN(X_LSFT) SS_TAP(X_DOT) SS_UP(X_LSFT) SS_UP(X_ALGR));
        } else {
            // when keycode HACEK is released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
        KC_Q,       KC_W,        KC_E,        KC_R,        KC_T,               KC_Y,        KC_U,        KC_I,        KC_O,   KC_P,
        KC_A, SFT_T(KC_S), CTL_T(KC_D), GUI_T(KC_F), ALT_T(KC_G),        ALT_T(KC_H), GUI_T(KC_J), CTL_T(KC_K), SFT_T(KC_L),  KC_SCLN,
		KC_Z,	    KC_X,        KC_C,        KC_V,        KC_B,               KC_N,        KC_M,        KC_COMM,     KC_DOT, KC_SLSH,
		                                      KC_SPC,      MO(2),              MO(1),       KC_ENT
		),
    [1] = LAYOUT_split_3x5_2(
        KC_TRNS,    KC_1,       KC_2,       KC_3,       EURO,              KC_HOME,        KC_PGDN,        KC_PGUP,     KC_BSPC,   KC_END,
        KC_TRNS,    KC_4,       KC_5,       KC_6,       HACEK,             KC_LEFT,        KC_DOWN,        KC_UP,       KC_RGHT,   KC_TRNS,
		CW_TOGG,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,           KC_TRNS,        KC_DEL,         KC_TRNS,     KC_TRNS,   KC_TRNS,
		                                     KC_SPC,    MO(3),             KC_TRNS,        KC_ENT
		),
    [2] = LAYOUT_split_3x5_2(
        KC_TAB,     KC_ESC,     KC_LCBR,    KC_RCBR,    KC_LBRC,           KC_RBRC,        KC_LPRN,        KC_RPRN,     KC_AMPR,   KC_QUES,
        KC_EXLM,    KC_AT,      KC_GRV,     KC_PIPE,    KC_PERC,           KC_ASTR,        KC_TILD,        KC_MINS,     KC_DQUO,   KC_QUOT,
		KC_BSLS,    KC_NO,      KC_CIRC,    KC_DLR,     KC_HASH,           KC_PLUS,        KC_UNDS,        KC_EQL,      KC_TRNS,   KC_NO,
		                                    KC_TRNS,    KC_TRNS,           MO(3),          KC_TRNS
		),
    [3] = LAYOUT_split_3x5_2(
        QK_RBT,     KC_TRNS,    KC_PSCR,    KC_TRNS,    KC_TRNS,           KC_F10,         KC_F1,          KC_F2,       KC_F3,     KC_TRNS,
        QK_BOOT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_TRNS,           KC_F11,         KC_F4,          KC_F5,       KC_F6,     KC_TRNS,
		KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,           KC_F12,         KC_F7,          KC_F8,       KC_F9,     KC_TRNS,
		                                    KC_TRNS,    KC_TRNS,           KC_TRNS,        KC_TRNS
		),
};

#ifdef OTHER_KEYMAP_C
#include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C
