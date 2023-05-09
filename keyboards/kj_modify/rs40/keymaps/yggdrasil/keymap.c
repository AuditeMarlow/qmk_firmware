// Copyright 2023 Audite Marlow (@auditemarlow)
// SPDX-License-Identifier: GPL-3.0

#include QMK_KEYBOARD_H

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum layers {
	L0,
	L1,
	L2,
	L3,
	L4
};

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};

enum tap_dance_codes {
	BSLS,
	PIPE,
	COMM,
	DOT,
	SLSH,
	QUOT
};

// Home-row mod keys
#define MT_A MT(MOD_LGUI, KC_A)
#define MT_S MT(MOD_LALT, KC_S)
#define MT_D MT(MOD_LSFT, KC_D)
#define MT_F MT(MOD_LCTL, KC_F)
#define MT_J MT(MOD_RCTL, KC_J)
#define MT_K MT(MOD_RSFT, KC_K)
#define MT_L MT(MOD_RALT, KC_L)
#define MT_ENT MT(MOD_RGUI, KC_ENT)

// Tap dances
#define TD_BSLS TD(BSLS)
#define TD_PIPE TD(PIPE)
#define TD_COMM TD(COMM)
#define TD_DOT TD(DOT)
#define TD_SLSH TD(SLSH)
#define TD_QUOT TD(QUOT)

// Navigation
#define NV_BWD LALT(KC_LEFT)
#define NV_FWD LALT(KC_RGHT)
#define NV_PTAB LCTL(LSFT(KC_TAB))
#define NV_NTAB LCTL(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * .-----------------------------------------------------------------------------------------------.
 * | Tab   | Q     | W     | E     | R     | T     | Y     | U     | I     | O     | P     | Bspc  |
 * |-----------------------------------------------------------------------------------------------|
 * | Esc     | A     | S     | D     | F     | G     | H     | J     | K     | L     | Return      |
 * |-----------------------------------------------------------------------------------------------|
 * | Shift       | Z     | X     | C     | V     | B     | N     | M     | ,     | .     | /       |
 * |-----------------------------------------------------------------------------------------------|
 * |         |       |         | Space           | L1                 |          |       |         |
 * '-----------------------------------------------------------------------------------------------'
 */
[L0] = LAYOUT(
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
	KC_ESC,  MT_A,    MT_S,    MT_D,    MT_F,    KC_G,    KC_H,    MT_J,    MT_K,    MT_L,             MT_ENT,
	KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    TD_COMM, TD_DOT,  TD_SLSH,
	_______, _______, _______,          KC_SPC,                    TO(L1),           _______, _______, _______
),

/* Symbols
 * .-----------------------------------------------------------------------------------------------.
 * |       | !     | @     | #     | $     | %     | ^     | &     | *     | ;     | :     |       |
 * |-----------------------------------------------------------------------------------------------|
 * |         | ~     | =     |       |       | '     | \     | {     | }     | |     |             |
 * |-----------------------------------------------------------------------------------------------|
 * |             |       |       |       |       | "     | [     | (     | )     | ]     | L3      |
 * |-----------------------------------------------------------------------------------------------|
 * |         |       |         | L0              | L2                 |          |       | Bloader |
 * '-----------------------------------------------------------------------------------------------'
 */
[L1] = LAYOUT(
	_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_SCLN, KC_COLN, _______,
	_______, KC_TILD, KC_EQL,  _______, _______, TD_QUOT, TD_BSLS, KC_LCBR, KC_RCBR, TD_PIPE,          _______,
	_______,          _______, _______, _______, _______, KC_DQUO, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, TO(L3),
	_______, _______, _______,          TO(L0),                    TO(L2),           _______, _______, QK_BOOT
),

/* Numpad/Control
 * .-----------------------------------------------------------------------------------------------.
 * |       |       | MPlay | MNext | MPrev | _     | -     | 7     | 8     | 9     | 0     |       |
 * |-----------------------------------------------------------------------------------------------|
 * |         |       |       | VolD  | VolU  | +     | =     | 4     | 5     | 6     |             |
 * |-----------------------------------------------------------------------------------------------|
 * |             |       | *     |       |       | .     | 0     | 1     | 2     | 3     |         |
 * |-----------------------------------------------------------------------------------------------|
 * |         |       |         | L0              | L2                 |          |       | L4      |
 * '-----------------------------------------------------------------------------------------------'
 */
[L2] = LAYOUT(
	_______, _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_UNDS, KC_MINS, KC_7,    KC_8,    KC_9,    KC_0,    _______,
	_______, _______, _______, KC_VOLD, KC_VOLU, KC_PLUS, KC_EQL,  KC_4,    KC_5,    KC_6,             _______,
	_______,          _______, KC_PAST, _______, _______, KC_PDOT, KC_0,    KC_1,    KC_2,    KC_3,    _______,
	_______, _______, _______,          TO(L0),                    TO(L2),           _______, _______, TG(L4)
),

/* Navigation
 * .-----------------------------------------------------------------------------------------------.
 * |       |       | ScLft | MUp   | ScRgt |       | Bwd   | PTab  | NTab  | Fwd   |       |       |
 * |-----------------------------------------------------------------------------------------------|
 * |         |       | MLeft | MDown | MRght |       | Left  | Down  | Up    | Right |             |
 * |-----------------------------------------------------------------------------------------------|
 * |             |       |       | ScUp  | ScDwn | LClck | RClck | Acl0  | Acl1  | Acl2  |         |
 * |-----------------------------------------------------------------------------------------------|
 * |         |       |         | L0              | L1                 |          |       |         |
 * '-----------------------------------------------------------------------------------------------'
 */
[L3] = LAYOUT(
	_______, _______, KC_WH_L, KC_MS_U, KC_WH_R, _______, NV_BWD,  NV_PTAB, NV_NTAB, NV_FWD,  _______, _______,
	_______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,          _______,
	_______,          _______, _______, KC_WH_U, KC_WH_D, KC_BTN2, KC_BTN1, KC_ACL0, KC_ACL1, KC_ACL2, _______,
	_______, _______, _______,          TO(L0),                    TO(L1),           _______, _______, _______
),

/* Game
 * .-----------------------------------------------------------------------------------------------.
 * | Tab   | Q     | W     | E     | R     | T     | F1    | F2    | F3    | F4    |       |       |
 * |-----------------------------------------------------------------------------------------------|
 * | Escape  | A     | S     | D     | F     | G     | F5    | F6    | F7    | F8    | Enter       |
 * |-----------------------------------------------------------------------------------------------|
 * | Shift       | 1     | 2     | 3     | 4     | 5     | F9    | F10   | F11   | F12   |         |
 * |-----------------------------------------------------------------------------------------------|
 * | Ctrl    | Alt   | C       | Space           | X                  |          |       |         |
 * '-----------------------------------------------------------------------------------------------'
 */
[L4] = LAYOUT(
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______,
	KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_F5,   KC_F6,   KC_F7,   KC_F8,            KC_ENT,
	KC_LSFT,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
	KC_LCTL, KC_LALT, KC_C,             KC_SPC,                    KC_X,             _______, _______, _______
)

};

void dance_default_each(tap_dance_state_t *state, void *user_data, uint16_t kc_tap) {
	if (state->count == 3) {
        tap_code16(kc_tap);
        tap_code16(kc_tap);
        tap_code16(kc_tap);
    }
    if (state->count > 3) {
        tap_code16(kc_tap);
    }
}

uint8_t dance_default_step(tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}

void dance_default_finished(tap_dance_state_t *state, void *user_data, uint16_t kc_tap, uint16_t kc_hold) {
	dance_state.step = dance_default_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(kc_tap); break;
		case SINGLE_HOLD: register_code16(kc_hold); break;
		case DOUBLE_TAP: register_code16(kc_tap); register_code16(kc_tap); break;
		case DOUBLE_SINGLE_TAP: tap_code16(kc_tap); register_code16(kc_tap);
	}
}

void dance_default_reset(tap_dance_state_t *state, void *user_data, uint16_t kc_tap, uint16_t kc_hold) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(kc_tap); break;
		case SINGLE_HOLD: unregister_code16(kc_hold); break;
		case DOUBLE_TAP: unregister_code16(kc_tap); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(kc_tap); break;
	}
	dance_state.step = 0;
}

void dance_bsls_each(tap_dance_state_t *state, void *user_data) {
	dance_default_each(state, NULL, KC_BSLS);
}
void dance_bsls_finished(tap_dance_state_t *state, void *user_data) {
	dance_default_finished(state, NULL, KC_BSLS, KC_HOME);
}
void dance_bsls_reset(tap_dance_state_t *state, void *user_data) {
	dance_default_reset(state, NULL, KC_BSLS, KC_HOME);
}

void dance_pipe_each(tap_dance_state_t *state, void *user_data) {
	dance_default_each(state, NULL, KC_PIPE);
}
void dance_pipe_finished(tap_dance_state_t *state, void *user_data) {
	dance_default_finished(state, NULL, KC_PIPE, KC_END);
}
void dance_pipe_reset(tap_dance_state_t *state, void *user_data) {
	dance_default_reset(state, NULL, KC_PIPE, KC_END);
}

void dance_comm_each(tap_dance_state_t *state, void *user_data) {
	dance_default_each(state, NULL, KC_COMM);
}
void dance_comm_finished(tap_dance_state_t *state, void *user_data) {
	dance_default_finished(state, NULL, KC_COMM, KC_MINS);
}
void dance_comm_reset(tap_dance_state_t *state, void *user_data) {
	dance_default_reset(state, NULL, KC_COMM, KC_MINS);
}

void dance_dot_each(tap_dance_state_t *state, void *user_data) {
	dance_default_each(state, NULL, KC_DOT);
}
void dance_dot_finished(tap_dance_state_t *state, void *user_data) {
	dance_default_finished(state, NULL, KC_DOT, KC_EXLM);
}
void dance_dot_reset(tap_dance_state_t *state, void *user_data) {
	dance_default_reset(state, NULL, KC_DOT, KC_EXLM);
}

void dance_slsh_each(tap_dance_state_t *state, void *user_data) {
	dance_default_each(state, NULL, KC_SLSH);
}
void dance_slsh_finished(tap_dance_state_t *state, void *user_data) {
	dance_default_finished(state, NULL, KC_SLSH, KC_UNDS);
}
void dance_slsh_reset(tap_dance_state_t *state, void *user_data) {
	dance_default_reset(state, NULL, KC_SLSH, KC_UNDS);
}

void dance_quot_each(tap_dance_state_t *state, void *user_data) {
	dance_default_each(state, NULL, KC_QUOT);
}
void dance_quot_finished(tap_dance_state_t *state, void *user_data) {
	dance_default_finished(state, NULL, KC_QUOT, KC_GRV);
}
void dance_quot_reset(tap_dance_state_t *state, void *user_data) {
	dance_default_reset(state, NULL, KC_QUOT, KC_GRV);
}

tap_dance_action_t tap_dance_actions[] = {
	[BSLS] = ACTION_TAP_DANCE_FN_ADVANCED(dance_bsls_each, dance_bsls_finished, dance_bsls_reset),
	[PIPE] = ACTION_TAP_DANCE_FN_ADVANCED(dance_pipe_each, dance_pipe_finished, dance_pipe_reset),
	[COMM] = ACTION_TAP_DANCE_FN_ADVANCED(dance_comm_each, dance_comm_finished, dance_comm_reset),
	[DOT] = ACTION_TAP_DANCE_FN_ADVANCED(dance_dot_each, dance_dot_finished, dance_dot_reset),
	[SLSH] = ACTION_TAP_DANCE_FN_ADVANCED(dance_slsh_each, dance_slsh_finished, dance_slsh_reset),
	[QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(dance_quot_each, dance_quot_finished, dance_quot_reset)
};
