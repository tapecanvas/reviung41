/* Copyright 2020 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,
                                            KC_LALT,   LOWER,    KC_SPC,   RAISE,    LT(3,KC_RGUI)
  ),

  [_LOWER] = LAYOUT_reviung41(
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    _______,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,   KC_PIPE,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_GRV,   KC_TILD,
    _______,  KC_NO,   KC_NO,  KC_NO,  KC_NO,   KC_NO,                 KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_PSCR,  KC_NO,
                                            KC_TRNS,   KC_TRNS,  KC_SPC,   KC_TRNS,  KC_TRNS
  ),

  [_RAISE] = LAYOUT_reviung41(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
    _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_BSLS,            KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,    KC_END,    KC_HOME,
    _______,  KC_NO,   KC_NO,  KC_MUTE,  KC_VOLD,   KC_VOLU,            KC_WBAK,    KC_WFWD,    KC_WSCH,    KC_NO,   KC_PGDN,   KC_PGUP,
                                            KC_TRNS,   KC_TRNS,  KC_SPC,  KC_TRNS,  KC_TRNS
  ),

  [_ADJUST] = LAYOUT_reviung41(
    KC_ESC,   KC_EXLM,   KC_AT,  KC_HASH,   KC_DLR,   KC_AMPR,            KC_PERC,  KC_PSLS,  KC_PAST,  KC_CIRC,  KC_LPRN,  KC_RPRN,
     KC_F1,     KC_F2,   KC_F3,    KC_F4,    KC_F5,     KC_F6,            KC_PMNS,  KC_PPLS,  KC_PEQL,    KC_LT,   KC_LCBR, KC_RCBR,
     KC_F7,     KC_F8,   KC_F9,   KC_F10,   KC_F11,    KC_F12,            KC_UNDS,  KC_TILD,  KC_PIPE,    KC_GT,   KC_LBRC, KC_RBRC,
                                            KC_TRNS,   KC_TRNS,  KC_NO,   KC_TRNS,  KC_TRNS
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
