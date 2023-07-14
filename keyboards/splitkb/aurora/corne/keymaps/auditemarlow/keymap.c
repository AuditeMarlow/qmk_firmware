#include QMK_KEYBOARD_H

enum layers {
	_QWERTY,
	_LOWER,
	_RAISE,
	_NAVIGATION,
	_GAME
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

// Layer keys
#define L_RAISE MO(_RAISE)
#define L_LOWER MO(_LOWER)
#define L_NAVI MO(_NAVIGATION)
#define L_GAME TG(_GAME)

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
	 *.-----------------------------------------------------,                          ,-----------------------------------------------------.
	 *| Tab    | Q      | W      | E      | R      | T      |                          | Y      | U      | I      | O      | P      | Bspc   |
	 *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
	 *| Escape | A      | S      | D      | F      | G      |                          | H      | J      | K      | L      | ;      | '      |
	 *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
	 *| Shift  | Z      | X      | C      | V      | B      |                          | N      | M      | ,      | .      | /      | Shift  |
	 *'-----------------------------------+--------+--------+--------,        ,--------+--------+--------+-----------------------------------'
	 *                                    | GUI    | L1     | Space  |        | Enter  | L2     | Del    |
	 *                                    '--------------------------'        '--------------------------'
	 */
	[_QWERTY] = LAYOUT_split_3x6_3(
		KC_TAB,	 KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_ESC,  MT_A,    MT_S,    MT_D,    MT_F,    KC_G,                               KC_H,    MT_J,    MT_K,    MT_L,    MT_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
								            KC_LGUI, L_LOWER, KC_SPC,           KC_ENT,  L_RAISE, KC_DEL
	),

	/* Numpad/Control
	 *
	 *.-----------------------------------------------------,                          ,-----------------------------------------------------.
	 *|        |        | MPlay  | MNext  | MPrev  | _      |                          | -      | 7      | 8      | 9      | 0      |        |
	 *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
	 *|        |        |        | VolD   | VolU   | +      |                          | =      | 4      | 5      | 6      |        |        |
	 *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
	 *|        |        |        | LEDD   | LEDU   | .      |                          | 0      | 1      | 2      | 3      |        |        |
	 *'-----------------------------------+--------+--------+--------,        ,--------+--------+--------+-----------------------------------'
	 *                                    |        |        |        |        |        | L3     |        |
	 *                                    '--------------------------'        '--------------------------'
	 */
	[_LOWER] = LAYOUT_split_3x6_3(
		_______, _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_UNDS,                            KC_MINS, KC_7,    KC_8,    KC_9,    KC_0,    _______,
		_______, _______, _______, KC_VOLD, KC_VOLU, KC_PLUS,                            KC_EQL,  KC_4,    KC_5,    KC_6,    _______, _______,
		_______, _______, _______, _______, _______, KC_DOT,                             KC_0,    KC_1,    KC_2,    KC_3,    _______, _______,
		                                    _______, _______, _______,          _______, L_NAVI,  _______
	),

	/* Numpad/Control
	 *
	 *.-----------------------------------------------------,                          ,-----------------------------------------------------.
	 *|        | !      | @      | #      | $      | %      |                          | ^      | &      | *      | (      | )      |        |
	 *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
	 *|        | `      | -      | =      | [      | ]      |                          | \      | {      | }      | |      |        |        |
	 *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
	 *|        |        |        |        |        |        |                          |        |        |        |        |        |        |
	 *'-----------------------------------+--------+--------+--------,        ,--------+--------+--------+-----------------------------------'
	 *                                    | L4     | L3     |        |        |        |        |        |
	 *                                    '--------------------------'        '--------------------------'
	 */
	[_RAISE] = LAYOUT_split_3x6_3(
		_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
		_______, KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,                            TD_BSLS, KC_LCBR, KC_RCBR, TD_PIPE, _______, _______,
		_______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
		                                    L_GAME,  L_NAVI,  _______,          _______, _______, _______
	),

	/* Navigation
	 *
	 *.-----------------------------------------------------,                          ,----------------------------------------------------.
	 *|        |        | ScLeft | MUp    | ScRght |        |                          | Bwd    | PTab   | NTab   | Fwd    |        |        |
	 *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
	 *|        |        | MLeft  | MDown  | MRight |        |                          | Left   | Down   | Up     | Right  |        |        |
	 *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
	 *|        |        |        | ScUp   | ScDown | RClick |                          | LClick | ACL1   | ACL2   | ACL3   |        |        |
	 *'-----------------------------------+--------+--------+--------,        ,--------+--------+--------+-----------------------------------'
	 *                                    |        |        |        |        |        |        |        |
	 *                                    '--------------------------'        '--------------------------'
	 */
	[_NAVIGATION] = LAYOUT_split_3x6_3(
		_______, _______, KC_WH_L, KC_MS_U, KC_WH_R, _______,                            NV_BWD,  NV_PTAB, NV_NTAB, NV_FWD,  _______, _______,
		_______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
		_______, _______, _______, KC_WH_U, KC_WH_D, KC_BTN1,                            KC_BTN2, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
		                                    _______, _______, _______,          _______, _______, _______
	),

	/* Game
	 *
	 *.-----------------------------------------------------,                          ,-----------------------------------------------------.
	 *| Tab    | T      | Q      | W      | E      | R      |                          | Y      | F9     | F10    | F11    | F12    |        |
	 *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
	 *| Escape | G      | A      | S      | D      | F      |                          | H      | F5     | F6     | F7     | F8     |        |
	 *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
	 *| Ctrl   | Shift  | 1      | 2      | 3      | 4      |                          | N      | F1     | F2     | F3     | F4     |        |
	 *'-----------------------------------+--------+--------+--------,        ,--------+--------+--------+-----------------------------------'
	 *                                    | Alt    | C      | Space  |        | Enter  | L0     |        |
	 *                                    '--------------------------'        '--------------------------'
	 */
	[_GAME] = LAYOUT_split_3x6_3(
		KC_TAB,	 KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,                               KC_Y,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
		KC_ESC,  KC_G,    KC_A,    KC_S,    KC_D,    KC_F,                               KC_H,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   _______,
		KC_LCTL, KC_LSFT, KC_1,    KC_2,    KC_3,    KC_4,                               KC_N,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
								            KC_LALT, KC_C,    KC_SPC,           KC_ENT,  L_GAME,  _______
	),

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
