// Copyright 2023 Audite Marlow (@auditemarlow)
// SPDX-License-Identifier: GPL-3.0

#include QMK_KEYBOARD_H

enum layers {
	_BASE,
	_LOWER,
	_RAISE,
	_GAME
};

#define LOWER LT(_LOWER, KC_SPC)
#define RAISE LT(_RAISE, KC_ENT)
#define GAME TG(_GAME)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * .-----------------------------------------------------------------------------------------------.
 * | Tab   | Q     | W     | E     | R     | T     | Y     | U     | I     | O     | P     | Bksp  |
 * |-----------------------------------------------------------------------------------------------|
 * | Esc     | A     | S     | D     | F     | G     | H     | J     | K     | L     | ;           |
 * |-----------------------------------------------------------------------------------------------|
 * | Shift       | Z     | X     | C     | V     | B     | N     | M     | ,     | .     | /       |
 * |-----------------------------------------------------------------------------------------------|
 * | Ctrl    | GUI   | Alt     | Enter/Raise     | Space/Lower        | Alt      | GUI   | Game    |
 * '-----------------------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT(
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
	KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,             KC_SCLN,
	KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
	KC_LCTL, KC_LGUI, KC_LALT,          RAISE,                     LOWER,            KC_RALT, KC_RGUI, GAME
),

/* Lower
 * .-----------------------------------------------------------------------------------------------.
 * |       | !     | @     | #     | $     | %     | ^     | &     | *     | (     | )     | Del   |
 * |-----------------------------------------------------------------------------------------------|
 * | `       | \     | -     | =     | [     | ]     | Left  | Down  | Up    | Right | '           |
 * |-----------------------------------------------------------------------------------------------|
 * |             |       |       |       |       |       |       |       | <     | >     | ?       |
 * |-----------------------------------------------------------------------------------------------|
 * |         |       |         |                 |                    |          |       | Bloader |
 * '-----------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT(
	_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
	KC_GRV,  KC_BSLS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,          KC_QUOT,
	_______,          _______, _______, _______, _______, _______, _______, _______, KC_LT,   KC_GT,   KC_QUES,
	_______, _______, _______,          _______,                   _______,          _______, _______, QK_BOOT
),

/* Raise
 * .-----------------------------------------------------------------------------------------------.
 * |       | 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 0     |       |
 * |-----------------------------------------------------------------------------------------------|
 * | ~       | |     | _     | +     | {     | }     |       | 4     | 5     | 6     | "           |
 * |-----------------------------------------------------------------------------------------------|
 * |             |       |       |       |       |       | 0     | 1     | 2     | 3     |         |
 * |-----------------------------------------------------------------------------------------------|
 * |         |       |         |                 |                    |          |       |         |
 * '-----------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT(
	_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
	KC_TILD, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, KC_4,    KC_5,    KC_6,             KC_DQUO,
	_______,          _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    _______,
	_______, _______, _______,          _______,                   _______,          _______, _______, _______
),

/* Game
 * .-----------------------------------------------------------------------------------------------.
 * |       |       |       |       |       |       | F1    | F2    | F3    | F4    |       |       |
 * |-----------------------------------------------------------------------------------------------|
 * |         |       |       |       |       |       | F5    | F6    | F7    | F8    | Enter       |
 * |-----------------------------------------------------------------------------------------------|
 * |             | 1     | 2     | 3     | 4     | 5     | F9    | F10   | F11   | F12   |         |
 * |-----------------------------------------------------------------------------------------------|
 * |         | Alt   | C       | Space           |                    |          |       |         |
 * '-----------------------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT(
	_______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______,
	_______, _______, _______, _______, _______, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,            KC_ENT,
	_______,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
	_______, KC_LALT, KC_C,             KC_SPC,                    _______,          _______, _______, _______
)
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case LT(1, KC_SPC):
        case LT(2, KC_ENT):
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}
