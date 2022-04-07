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

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

enum planck_layers {
  _ANISBVHTRO,
  _QWERTY,
  _LOWER,
  _RAISE,
  _MOUSE,
  _BACKLIT,
  _NAV
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  MOUSE,
  BACKLIT
};

#define LOW_ESC LT(_LOWER, KC_ESC)
#define UP_ENT LT(_RAISE, KC_ENT)
#define SPC_TAB SHIFT_NO(KC_SPC, KC_TAB)
#define ENT_ESC SHIFT_NO(KC_ENT, KC_ESC)
#define BK_DEL SHIFT_NO(KC_BSPC, KC_DEL)
#define HOME_A LCTL_T(KC_A)
#define HOME_N LALT_T(KC_N)
#define HOME_I LGUI_T(KC_I)
#define HOME_S LSFT_T(KC_S)
#define HOME_H RSFT_T(KC_H)
#define HOME_T RGUI_T(KC_T)
#define HOME_R LALT_T(KC_R)
#define HOME_O RCTL_T(KC_O)

const uint16_t PROGMEM q_combo[] = {KC_O, KC_X, COMBO_END};
const uint16_t PROGMEM z_combo[] = {KC_A, KC_UNDS, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(q_combo, KC_Q),
    COMBO(z_combo, KC_Z),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |   P  |   U  |   C  |   J  |      |      |   K  |   L  |   D  |   W  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   _  |   N  |   I  |   S  |   B  |      |      |   V  |   H  |   T  |   R  |   X  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |      |   Y  |   F  |      |  BS  |  TAB |      |   M  |   G  |      |   O  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  ESC |   E  |             |  Spc |  Ent |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ANISBVHTRO] = LAYOUT_planck_grid(

  KC_NO,    KC_P,     KC_U,     KC_C,     KC_J,     KC_NO,    KC_NO,    KC_K,     KC_L,     KC_D,     KC_W,     KC_NO,
  KC_UNDS,  HOME_N,   HOME_I,   HOME_S,   KC_B,     KC_NO,    KC_NO,    KC_V,     HOME_H,   HOME_T,   HOME_R,   KC_X,
  HOME_A,   KC_NO,    KC_Y,     KC_F,     KC_NO,    BK_DEL,   KC_TAB,   KC_NO,    KC_M,     KC_G,     KC_NO,    HOME_O,
  KC_NO,    KC_NO,    KC_NO,    LOW_ESC,  KC_E,     KC_NO,    KC_NO,    KC_SPC,   UP_ENT,  KC_NO,    KC_NO,    KC_NO
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  F3  |  F4  |  F5  |  F6  |      |      |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F2  |  @   |   !  |   '  |   `  |      |      |   ~  |   "  |   ?  |   $  |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |      |   |  |   &  |      |      |   :  |      |   #  |   \  |      |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Base |      |             |   ;  |  Nav |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_NO,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_NO, KC_NO, KC_F7,  KC_F8,   KC_F9,  KC_F10,   KC_NO,
    KC_F2,   KC_AT,   KC_EXLM,   KC_,   KC_F8,   _______, KC_NO,   KC_PPLS,  KC_P4,   KC_P5,  KC_P6,   KC_PAST,
    KC_F1,   KC_NO,   KC_PIPE,   KC_F3,   KC_F4,   _______, _______, KC_PMNS,  KC_P1,   KC_P2,  KC_P3,   KC_PSLS,
    KC_NO, KC_NO,   KC_NO,   KC_NO,   _______, SPCSFT,  SPCSFT,  _______,  ENTALT,  KC_P0,  KC_PDOT, KC_EQL
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   <  |   {  |   (  |   [  |      |      |   ]  |   )  |   }  |   >  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ^  |   7  |   1  |   3  |   5  |      |      |   4  |   2  |   0  |   6  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   9  |      |   +  |   -  |      |   ,  |      |      |   *  |   /  |      |   8  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  Nav |   .  |             |      | Base |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_NO,   KC_NO,   KC_TILD, KC_PEQL, KC_LCBR, _______, KC_DEL,  KC_RCBR,  KC_AMPR, KC_ASTR, KC_UNDS, KC_NO,
    KC_NO,   KC_NO,   KC_GRV,  KC_GT,   KC_LBRC, _______, KC_NO,   KC_RBRC,  KC_DLR,  KC_PERC, KC_CIRC, KC_BSLS,
    KC_NO,   KC_NO,   KC_PIPE, KC_PMNS, KC_LPRN, _______, _______, KC_RPRN,  KC_EXLM, KC_AT,   KC_HASH, KC_SLSH,
    KC_NLCK, KC_NO,   KC_NO,   KC_NO,   _______, SPCSFT,  SPCSFT,  _______,  ENTALT,  KC_NO,   KC_NO,   KC_NO
),

/* Navigation (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | BrtUp| BrtDw| Mute | VolUp|      |      | PgUp | Bk   |  Up  |  Del |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  ALT |  GUI | Shift| VolDw|      |      | PgDw | Left | Down | Right|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL |      |      |      |      |      |      |      | Home |  End |      | Mouse|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Base |      |             |      | Base |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
    KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_NO,   _______, KC_DEL, KC_INS,  KC_PSCR, KC_NO,   KC_NO,   KC_NO,
    KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_NO,   _______, KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
    KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_NO,   _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,
    KC_NO,   KC_UP,   KC_NO,   KC_NO,   _______, KC_SPC,  KC_SPC,  _______, KC_ENT,   KC_UP,   KC_NO,   KC_NO
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |MoBut1|MoBut3|MoBut2|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MoLeft|MoDown| MoUp |MoRght|      |      | Play | Stop | Prev | Next |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MoAcc0|MoAcc1|MoAcc2|      |      | BrtUp|BrtDwn|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |QWERTY|      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
    KC_NO,   KC_NO,   KC_BTN1, KC_BTN3, KC_BTN2, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,   KC_NO,   KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_NO,
    KC_NO,   KC_NO,   KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_NO, KC_NO, KC_BRIU, KC_BRID, KC_NO, KC_NO, KC_NO,
    KC_NO,   KC_NO,   KC_NO,   QWERTY,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
),

/* BackLight
 * ,-----------------------------------------------------------------------------------.
 * |      |      | SAT- | SAT+ | HUE+ |      |      | BLUp |      |      |      |AudTog|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |RgbMoD|RgbMoU|RgbTog| HUE- |      |      | BLDn | BLTog| BLCyc| BLBre|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |RgbVad|RgbVai|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |QWERTY|      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BACKLIT] = LAYOUT_planck_grid(
    KC_NO,   KC_NO,   RGB_SAD, RGB_SAI, RGB_HUI, KC_NO,   KC_NO,   BL_INC,  KC_NO,   KC_NO,   KC_NO,   AU_TOG,
    KC_NO,   RGB_RMOD,RGB_MOD, RGB_TOG, RGB_HUD, KC_NO,   KC_NO,   BL_DEC,  BL_TOGG, BL_STEP, BL_BRTG, KC_NO,
    KC_NO,   RGB_M_R,   KC_NO,   RGB_VAD, RGB_VAI, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    QWERTY,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _NAV);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case MOUSE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MOUSE);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BACKLIT);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_NAV);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_NAV);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
