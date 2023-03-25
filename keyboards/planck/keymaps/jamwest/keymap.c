/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum planck_layers {
    _ANISBVHTRO,
    _LOWER,
    _RAISE,
    _NAV
};

enum planck_keycodes {
    ANISBVHTRO = SAFE_RANGE
};

#define LOW_ESC LT(_LOWER, KC_ESC)
#define UP_ENT LT(_RAISE, KC_ENT)

#define HOME_A LCTL_T(KC_A)
#define HOME_N LALT_T(KC_N)
#define HOME_I LGUI_T(KC_I)
#define HOME_S LSFT_T(KC_S)
#define HOME_H RSFT_T(KC_H)
#define HOME_T RGUI_T(KC_T)
#define HOME_R LALT_T(KC_R)
#define HOME_O RCTL_T(KC_O)

#define HOME_9 LCTL_T(KC_9)
#define HOME_7 LALT_T(KC_7)
#define HOME_1 LGUI_T(KC_1)
#define HOME_3 LSFT_T(KC_3)
#define HOME_2 RSFT_T(KC_2)
#define HOME_0 RGUI_T(KC_0)
#define HOME_6 LALT_T(KC_6)
#define HOME_8 RCTL_T(KC_8)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |   P  |   U  |   C  |   J  |      |      |   K  |   L  |   D  |   W  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   _  |   N  |   I  |   S  |   B  |      |      |   V  |   H  |   T  |   R  |   X  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |      |   Y  |   F  |      |      |      |      |   M  |   G  |      |   O  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |      |  BS  |EscSym|   E  |             |  SPC |EntNum|  TAB |      |   Q  |
 * `-----------------------------------------------------------------------------------'
 */
[_ANISBVHTRO] = LAYOUT_planck_grid(

    KC_NO,      KC_P,       KC_U,       KC_C,       KC_J,       KC_NO,      KC_NO,      KC_K,       KC_L,       KC_D,       KC_W,       KC_NO,
    KC_UNDS,    HOME_N,     HOME_I,     HOME_S,     KC_B,       KC_NO,      KC_NO,      KC_V,       HOME_H,     HOME_T,     HOME_R,     KC_X,
    HOME_A,     KC_NO,      KC_Y,       KC_F,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_M,       KC_G,       KC_NO,      HOME_O,
    KC_Z,       KC_NO,      KC_BSPC,    LOW_ESC,    KC_E,       KC_NO,      KC_NO,      KC_SPC,     UP_ENT,     KC_TAB,     KC_NO,      KC_Q
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  F3  |  F4  |  F5  |  F6  |      |      |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F2  |  @   |   !  |   '  |   `  |      |      |   ~  |   "  |   ?  |   $  |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |      |   |  |   &  |      |      |      |      |   #  |   \  |      |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Base |      |             |   ;  |  Nav |   :  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_NO,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_NO,      KC_NO,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_NO,
    KC_F2,      KC_AT,      KC_EXLM,    KC_QUOT,    KC_GRV,     KC_NO,      KC_NO,      KC_TILD,    KC_DQUO,    KC_QUES,    KC_DLR,     KC_F11,
    KC_F1,      KC_NO,      KC_PIPE,    KC_AMPR,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_HASH,    KC_BSLS,    KC_NO,      KC_F12,
    KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_SCLN,    KC_TRNS,    KC_COLN,    KC_NO,      KC_NO
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   <  |   {  |   (  |   [  |      |      |   ]  |   )  |   }  |   >  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ^  |   7  |   1  |   3  |   5  |      |      |   4  |   2  |   0  |   6  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   9  |      |   +  |   -  |      |      |      |      |   *  |   /  |      |   8  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   ,  |  Nav |   .  |             |      | Base |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_NO,      KC_LABK,    KC_LCBR,    KC_LPRN,    KC_LBRC,    KC_NO,      KC_NO,      KC_RBRC,    KC_RPRN,    KC_RCBR,    KC_RABK,    KC_NO,
    KC_CIRC,    HOME_7,     HOME_1,     HOME_3,     KC_5,       KC_NO,      KC_NO,      KC_4,       HOME_2,     HOME_0,     HOME_6,     KC_EQL,
    HOME_9,     KC_NO,      KC_PLUS,    KC_MINS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_ASTR,    KC_SLSH,    KC_NO,      HOME_8,
    KC_NO,      KC_NO,      KC_COMM,    KC_TRNS,    KC_DOT,     KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO
),

/* Nav (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | BrtUp| BrtDw| Mute | VolUp|      |      | PgUp | Bk   |  Up  |  Del |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  ALT |  GUI | Shift| VolDw|      |      | PgDw | Left | Down | Right|  HUI |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL |      |RGBTOG|RGBMOD|      |      |      |      | Home |  End |      |  SAI |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Base |      |             |      | Base |      |      |  VAI |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
    KC_NO,      KC_BRIU,    KC_BRID,    KC_MUTE,    KC_VOLU,    KC_NO,      KC_NO,      KC_PGUP,    KC_BSPC,    KC_UP,      KC_DEL,     KC_NO,
    KC_NO,      KC_LALT,    KC_LGUI,    KC_LSFT,    KC_VOLD,    KC_NO,      KC_NO,      KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    RGB_HUI,
    KC_LCTL,    RGB_TOG,    RGB_MOD,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_HOME,    KC_END,     KC_NO,      RGB_SAI,
    KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      RGB_VAI
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _NAV);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ANISBVHTRO:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_ANISBVHTRO);
        }
        return false;
        break;
    }
    return true;
}
