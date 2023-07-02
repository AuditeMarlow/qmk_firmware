#include QMK_KEYBOARD_H

enum layers {
	_L0,
	_L1,
	_L2,
	_L3
};

typedef enum {
	TD_NONE,
	TD_UNKNOWN,
	TD_SINGLE_TAP,
	TD_SINGLE_HOLD,
	TD_DOUBLE_TAP,
	TD_DOUBLE_HOLD,
	TD_DOUBLE_SINGLE_TAP, // Send two single taps
	TD_MORE_TAPS
} td_state_t;

typedef struct {
	bool is_press_action;
	td_state_t state;
} td_tap_t;

enum tap_dance_codes {
	BSLS,
	PIPE
};

// Home-row mod keys
#define MT_A MT(MOD_LGUI, KC_A)
#define MT_S MT(MOD_LALT, KC_S)
#define MT_D MT(MOD_LSFT, KC_D)
#define MT_F MT(MOD_LCTL, KC_F)
#define MT_J MT(MOD_RCTL, KC_J)
#define MT_K MT(MOD_RSFT, KC_K)
#define MT_L MT(MOD_RALT, KC_L)
#define MT_SCLN MT(MOD_RGUI, KC_SCLN)

// Tap dances
#define TD_BSLS TD(BSLS)
#define TD_PIPE TD(PIPE)

// Navigation
#define NV_BWD LALT(KC_LEFT)
#define NV_FWD LALT(KC_RGHT)
#define NV_PTAB LCTL(LSFT(KC_TAB))
#define NV_NTAB LCTL(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* Base
	 *
	 * .-----------------------------------------------------------------------------------------------.
	 * | Tab   | Q     | W     | E     | R     | T     | Y     | U     | I     | O     | P     | Bspc  |
	 * |-----------------------------------------------------------------------------------------------|
	 * | Esc   | A     | S     | D     | F     | G     | H     | J     | K     | L     | ;     | '     |
	 * |-----------------------------------------------------------------------------------------------|
	 * | Shift | Z     | X     | C     | V     | B     | N     | M     | ,     | .     | /     | Shift |
	 * '-----------------------------------------------------------------------------------------------'
	 *                         | GUI   | L1    | Space | Enter | L2    | Del   |
	 *                         '-----------------------------------------------'
	 */
	[_L0] = LAYOUT_split_3x6_3(
		KC_TAB,	 KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_ESC,  MT_A,    MT_S,    MT_D,    MT_F,    KC_G,    KC_H,    MT_J,    MT_K,    MT_L,    MT_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
								   KC_LGUI, MO(_L1), KC_SPC,  KC_ENT,  MO(_L2), KC_DEL
	),

	/* Numpad/Control
	 *
	 * .-----------------------------------------------------------------------------------------------.
	 * |       |       | MPlay | MNext | MPrev | _     | -     | 7     | 8     | 9     | 0     |       |
	 * |-----------------------------------------------------------------------------------------------|
	 * |       |       |       | VolD  | VolU  | +     | =     | 4     | 5     | 6     |       |       |
	 * |-----------------------------------------------------------------------------------------------|
	 * |       |       |       | LEDD  | LEDU  | .     | 0     | 1     | 2     | 3     |       |       |
	 * '-----------------------------------------------------------------------------------------------'
	 *                         |       |       |       |       | L3    |       |
	 *                         '-----------------------------------------------'
	 */
	[_L1] = LAYOUT_split_3x6_3(
		_______, _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_UNDS, KC_MINS, KC_7,    KC_8,    KC_9,    KC_0,    _______,
		_______, _______, _______, KC_VOLD, KC_VOLU, KC_PLUS, KC_EQL,  KC_4,    KC_5,    KC_6,    _______, _______,
		_______, _______, _______, _______, _______, KC_DOT,  KC_0,    KC_1,    KC_2,    KC_3,    _______, _______,
		                           _______, _______, _______, _______, MO(_L3), _______
	),

	/* Numpad/Control
	 *
	 * .-----------------------------------------------------------------------------------------------.
	 * | `     | !     | @     | #     | $     | %     | ^     | &     | *     | (     | )     |       |
	 * |-----------------------------------------------------------------------------------------------|
	 * |       |       | -     | =     | [     | ]     | \     | {     | }     | |     |       |       |
	 * |-----------------------------------------------------------------------------------------------|
	 * |       |       |       |       |       |       |       |       |       |       |       |       |
	 * '-----------------------------------------------------------------------------------------------'
	 *                         |       | L3    |       |       |       |       |
	 *                         '-----------------------------------------------'
	 */
	[_L2] = LAYOUT_split_3x6_3(
		KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
		_______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, TD_BSLS, KC_LCBR, KC_RCBR, TD_PIPE, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		                           _______, MO(_L3), _______, _______, _______, _______
	),

	/* Navigation
	 *
	 * .-----------------------------------------------------------------------------------------------.
	 * |       |       | ScLft | MUp   | ScRgt |       | Bwd   | PTab  | NTab  | Fwd   |       |       |
	 * |-----------------------------------------------------------------------------------------------|
	 * |       |       | MLeft | MDown | MRght |       | \     | {     | }     | |     |       |       |
	 * |-----------------------------------------------------------------------------------------------|
	 * |       |       |       | ScUp  | ScDwn | RClck | LClck | ACL1  | ACL2  | ACL3  |       |       |
	 * '-----------------------------------------------------------------------------------------------'
	 *                         |       |       |       |       |       |       |
	 *                         '-----------------------------------------------'
	 */
	[_L3] = LAYOUT_split_3x6_3(
		_______, _______, KC_WH_L, KC_MS_U, KC_WH_R, _______, NV_BWD,  NV_PTAB, NV_NTAB, NV_FWD,  _______, _______,
		_______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
		_______, _______, _______, KC_WH_U, KC_WH_D, KC_BTN1, KC_BTN2, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
		                           _______, _______, _______, _______, _______, _______
	)

};

td_state_t cur_dance(tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
		else return TD_SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
		else if (state->pressed) return TD_DOUBLE_HOLD;
		else return TD_DOUBLE_TAP;
	}
	return TD_MORE_TAPS;
}

static td_tap_t tap_state = {
	.is_press_action = true,
	.state = TD_NONE
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

void dance_default_finished(tap_dance_state_t *state, void *user_data, uint16_t kc_tap, uint16_t kc_hold) {
	tap_state.state = cur_dance(state);
	switch (tap_state.state) {
		case TD_SINGLE_TAP: register_code16(kc_tap); break;
		case TD_SINGLE_HOLD: register_code16(kc_hold); break;
		case TD_DOUBLE_TAP: register_code16(kc_tap); register_code16(kc_tap); break;
		case TD_DOUBLE_SINGLE_TAP: tap_code16(kc_tap); register_code16(kc_tap); break;
		default: break;
	}
}

void dance_default_reset(tap_dance_state_t *state, void *user_data, uint16_t kc_tap, uint16_t kc_hold) {
	switch (tap_state.state) {
		case TD_SINGLE_TAP: unregister_code16(kc_tap); break;
		case TD_SINGLE_HOLD: unregister_code16(kc_hold); break;
		case TD_DOUBLE_TAP: unregister_code16(kc_tap); break;
		case TD_DOUBLE_SINGLE_TAP: unregister_code16(kc_tap); break;
		default: break;
	}
	tap_state.state = TD_NONE;
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

tap_dance_action_t tap_dance_actions[] = {
	[BSLS] = ACTION_TAP_DANCE_FN_ADVANCED(dance_bsls_each, dance_bsls_finished, dance_bsls_reset),
	[PIPE] = ACTION_TAP_DANCE_FN_ADVANCED(dance_pipe_each, dance_pipe_finished, dance_pipe_reset)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
