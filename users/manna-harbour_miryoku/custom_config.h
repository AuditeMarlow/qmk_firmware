// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,   "Base") \
MIRYOKU_X(EXTRA,  "Extra") \
MIRYOKU_X(TAP,    "Tap") \
MIRYOKU_X(GAME,   "Game") \
MIRYOKU_X(BUTTON, "Button") \
MIRYOKU_X(NAV,    "Nav") \
MIRYOKU_X(MOUSE,  "Mouse") \
MIRYOKU_X(MEDIA,  "Media") \
MIRYOKU_X(NUM,    "Num") \
MIRYOKU_X(SYM,    "Sym") \
MIRYOKU_X(FUN,    "Fun")

#define XXX KC_NO

#define MIRYOKU_LAYERMAPPING_BASE( \
      K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09, \
      K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19, \
      K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29, \
      N30,  N31,  K32,  K33,  K34,         K35,  K36,  K37,  N38,  N39 \
) \
LAYOUT_split_3x6_3( \
XXX,  K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09,  TG(U_GAME), \
XXX,  K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19,  XXX, \
XXX,  K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29,  XXX, \
                  K32,  K33,  K34,         K35,  K36,  K37 \
)

#define MIRYOKU_LAYER_GAME \
KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
KC_A,    KC_S,    KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, \
KC_1,    KC_2,    KC_3,    KC_4,    KC_B,              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
U_NP,    U_NP,    KC_LCTL, KC_SPC,  KC_C,              KC_ENT,  KC_BSPC, KC_DEL,  U_NP,    U_NP

#define MIRYOKU_LAYERMAPPING_GAME( \
      K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09, \
      K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19, \
      K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29, \
      N30,  N31,  K32,  K33,  K34,         K35,  K36,  K37,  N38,  N39 \
) \
LAYOUT_split_3x6_3( \
KC_TAB,   K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09,  TG(U_GAME), \
KC_ESC,   K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19,  KC_QUOT, \
KC_LSFT,  K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29,  XXX, \
                      K32,  K33,  K34,         K35,  K36,  K37 \
)

/*
 * The insane attempt for a single-handed layout
 */

/* #define MIRYOKU_LAYERMAPPING_NUM( \ */
/*       K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09, \ */
/*       K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19, \ */
/*       K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29, \ */
/*       N30,  N31,  K32,  K33,  K34,         K35,  K36,  K37,  N38,  N39 \ */
/* ) \ */
/* LAYOUT_split_3x6_3( \ */
/* XXX,      K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09,  XXX, \ */
/* KC_MINS,  K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19,  XXX, \ */
/* XXX,      K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29,  XXX, \ */
/*                       K32,  K33,  K34,         K35,  K36,  K37 \ */
/* ) */

/* #define MIRYOKU_LAYERMAPPING_SYM( \ */
/*       K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09, \ */
/*       K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19, \ */
/*       K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29, \ */
/*       N30,  N31,  K32,  K33,  K34,         K35,  K36,  K37,  N38,  N39 \ */
/* ) \ */
/* LAYOUT_split_3x6_3( \ */
/* TG(U_GAME), K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09,  XXX, \ */
/* KC_UNDS,    K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19,  XXX, \ */
/* XXX,        K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29,  XXX, \ */
/*                         K32,  K33,  K34,         K35,  K36,  K37 \ */
/* ) */

/* #define MIRYOKU_LAYER_NAV \ */
/* U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_NA,              TD(U_TD_U_NAV),    TD(U_TD_U_NUM),    KC_ALGR,           U_NA,              \ */
/* CW_TOGG,           KC_LEFT,           KC_UP,             KC_DOWN,           KC_RGHT,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \ */
/* KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \ */
/* U_NP,              U_NP,              KC_DEL,            KC_BSPC,           KC_ENT,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP */

/* #define MIRYOKU_LAYER_MOUSE \ */
/* U_UND,             U_CUT,             KC_MS_U,           U_PST,             U_RDO,             U_NA,              TD(U_TD_U_MOUSE),  TD(U_TD_U_SYM),    KC_ALGR,           U_NA,              \ */
/* U_NU,              KC_MS_L,           KC_MS_D,           KC_MS_R,           U_NA,              U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \ */
/* U_NU,              KC_WH_L,           KC_WH_U,           KC_WH_D,           KC_WH_R,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \ */
/* U_NP,              U_NP,              KC_BTN3,           KC_BTN1,           KC_BTN2,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP */

/* #define MIRYOKU_LAYER_LEFT \ */
/* KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              U_NP,              U_NP,              U_NP,              U_NP,              U_NP,              \ */
/* LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              U_NP,              U_NP,              U_NP,              U_NP,              U_NP,              \ */
/* LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              U_NP,              U_NP,              U_NP,              U_NP,              U_NP,              \ */
/* U_NP,              U_NP,              LT(U_NUM,KC_BSPC), LT(U_RIGHT,KC_SPC),LT(U_SYM,KC_ENT),  U_NP,              U_NP,              U_NP,              U_NP,              U_NP */

/* #define MIRYOKU_LAYERMAPPING_LEFT( \ */
/*       K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09, \ */
/*       K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19, \ */
/*       K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29, \ */
/*       N30,  N31,  K32,  K33,  K34,         K35,  K36,  K37,  N38,  N39 \ */
/* ) \ */
/* LAYOUT_split_3x6_3( \ */
/* LT(U_FUN,KC_TAB),  K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09,  XXX, \ */
/* LT(U_NAV,KC_ESC),  K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19,  XXX, \ */
/* KC_LSFT,           K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29,  XXX, \ */
/*                                K32,  K33,  K34,         K35,  K36,  K37 \ */
/* ) */

/* #define MIRYOKU_LAYER_RIGHT \ */
/* KC_P,              KC_O,              KC_I,              KC_U,              KC_Y,              U_NP,              U_NP,              U_NP,              U_NP,              U_NP,              \ */
/* LGUI_T(KC_QUOT),   LALT_T(KC_L),      LCTL_T(KC_K),      LSFT_T(KC_J),      KC_H,              U_NP,              U_NP,              U_NP,              U_NP,              U_NP,              \ */
/* LT(U_BUTTON,KC_SLSH), ALGR_T(KC_DOT), KC_COMM,           KC_M,              KC_N,              U_NP,              U_NP,              U_NP,              U_NP,              U_NP,              \ */
/* U_NP,              U_NP,              KC_BSPC,           KC_SPC,            KC_ENT,            U_NP,              U_NP,              U_NP,              U_NP,              U_NP */

/* #define MIRYOKU_LAYERMAPPING_RIGHT( \ */
/*       K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09, \ */
/*       K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19, \ */
/*       K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29, \ */
/*       N30,  N31,  K32,  K33,  K34,         K35,  K36,  K37,  N38,  N39 \ */
/* ) \ */
/* LAYOUT_split_3x6_3( \ */
/* KC_TAB,  K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09,  XXX, \ */
/* KC_ESC,  K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19,  XXX, \ */
/* KC_LSFT, K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29,  XXX, \ */
/*                      K32,  K33,  K34,         K35,  K36,  K37 \ */
/* ) */
