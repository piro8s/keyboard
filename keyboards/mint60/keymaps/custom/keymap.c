/* Copyright 2018 Eucalyn
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
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

#include "action_layer.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum custom_keycodes {
  RGBRST = SAFE_RANGE,
  KC_BSDL // BS,  Shift: Del
};

/* tap dance */
enum tap_dances {
    SINGLE_TAP = 1,
    SINGLE_HOLD = 2,
    DOUBLE_TAP = 3,
    DOUBLE_HOLD = 4,
    DOUBLE_SINGLE_TAP = 5, //send two single taps
    TRIPLE_TAP = 6,
    TRIPLE_HOLD = 7

    TD_MINS = 11,
    TD_LBRC = 12,
    TD_RBRC = 13,
    TD_SCLN = 14,
    TD_QUOT = 15,
    TD_COMM = 16,
    TD_DOT  = 17,

    TD_LSFT_CAPS = 21,

    TD_LONG_GUI = 31,
    TD_LONG_ALT = 32,

    TD_OTHER = 99
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

static tap tap_state = {
  .is_press_action = true,
  .state = 0
};

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 9; //magic number. At some point this method will expand to work for more presses
}

void td_long_gui_finished (qk_tap_dance_state_t *state, void *user_data) {
  tap_state.state = cur_dance(state);
  if (tap_state.state == SINGLE_HOLD) {
    register_code(KC_LCTL);
    register_code(KC_LGUI);
  }
  else {
    register_code(KC_LGUI);
  }
}

void td_long_gui_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (tap_state.state == SINGLE_HOLD) {
    unregister_code(KC_LGUI);
    unregister_code(KC_LCTL);
  }
  else {
    unregister_code(KC_LGUI);
  }
  tap_state.state = 0;
}

void td_long_alt_finished (qk_tap_dance_state_t *state, void *user_data) {
  tap_state.state = cur_dance(state);
  if (tap_state.state == SINGLE_HOLD) {
    register_code(KC_LCTL);
    register_code(KC_LALT);
  }
  else {
    register_code(KC_LALT);
  }
}

void td_long_alt_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (tap_state.state == SINGLE_HOLD) {
    unregister_code(KC_LALT);
    unregister_code(KC_LCTL);
  }
  else {
    unregister_code(KC_LALT);
  }
  tap_state.state = 0;
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, LSFT(KC_MINS)),
    [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LSFT(KC_LBRC)),
    [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LSFT(KC_RBRC)),
    [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN)),
    [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, LSFT(KC_QUOT)),
    [TD_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, LSFT(KC_COMM)),
    [TD_DOT ] = ACTION_TAP_DANCE_DOUBLE(KC_DOT , LSFT(KC_DOT )),

    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT , KC_CAPS),

    [TD_LONG_GUI] = ACTION_TAP_DANCE_FN(td_long_gui_finished, td_long_gui_reset),
    [TD_LONG_ALT] = ACTION_TAP_DANCE_FN(td_long_alt_finished, td_long_alt_reset),

    // complex tap dance function (to specify what happens when key is pressed 3+ times, for example). See https://docs.qmk.fm/tap_dance.html for how to define
    [TD_2] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_ESC)
};

/* Qwerty
 * , ----------------------------\     \----------------------------------------------.
 * | `~ | 1! | 2@ | 3#| 4$ | 5% ||     || 6^ | 7& | 8* | 9( | 0) | -_ | =+ |Bksp     |
 * |-----+----+----+----+----+----+\     \+----+----+----+----+----+----+----+-------|
 * |Tab   | Q  | W  | E  | R  | T  ||     || Y  | U  | I  | O  | P  | [  | ]  | \|   |
 * |------+----+----+----+----+-----+\     \+---+----+----+----+----+----+----+------|
 * |Ctrl   | A  | S  | D  | F  | G  ||     || H  | J  | K  | L  | ;: | '" |Entr      |
 * |--------+----+----+----+----+----+\     \+----+----+----+----+----+----+----+----|
 * |Shft    | Z  | X  | C  | V  | B  ||     || N  | M  | ,< | .> | /? |Shft|Up  |Fn  |
 * |----+----+-----+------+-----+----+/     /+------------+-----+-----+----+----+----|
 * |Esc |Ctrl|GUI  |Alt   | ------- ||     ||Spc          | GRV |Ctrl |Left|Down|Rght|
 * `---------------------------------/     /-----------------------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( \
    KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    /**/,   KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS, KC_EQL , KC_BSDL    , \
    KC_TAB   , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    /**/,   KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_LBRC, KC_RBRC, KC_BSLS   , \
    KC_LCTL   , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    /**/,   KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT, KC_ENT            , \
    KC_LSFT    , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    /**/,   KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , MO(1)  , KC_UP  , KC_RSFT , \
    MO(2)   , MO(1)   , KC_LGUI  , KC_LALT  , KC_SPC            /**/,    KC_SPC                 , LALT(KC_GRV), MO(2)    , KC_LEFT, KC_DOWN, KC_RGHT   \
  ), 
  [1] = LAYOUT( \
    KC_ESC  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   /**/,   KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11 , KC_F12 , KC_BSDL    , \
    XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX /**/,   XXXXXXX , XXXXXXX , KC_UP   , XXXXXXX , XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX   , \
    XXXXXXX   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX /**/,   XXXXXXX , KC_LEFT , KC_DOWN , KC_RGHT , XXXXXXX , XXXXXXX, XXXXXXX           , \
    _______    , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX /**/,   XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______, KC_PGUP, _______ , \
    _______ , _______ , _______  , _______  , _______           /**/, _______                   , _______     , _______  , KC_HOME, KC_PGDN, KC_END    \
  ), 
  [2] = LAYOUT( \
    KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    /**/,   KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , XXXXXXX, XXXXXXX, XXXXXXX    , \
    XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX /**/,   XXXXXXX , XXXXXXX , KC_UP   , XXXXXXX , XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX   , \
    XXXXXXX   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX /**/,   XXXXXXX , KC_LEFT , KC_DOWN , KC_RGHT , XXXXXXX , XXXXXXX, XXXXXXX           , \
    _______    , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX /**/,   XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______, KC_PGUP, _______ , \
    _______ , _______ , _______  , _______  , _______           /**/, _______                   , _______     , _______  , KC_HOME, KC_PGDN, KC_END    \
  )
};
// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool lctl_pressed = get_mods() & MOD_BIT(KC_LCTL);
  bool rctl_pressed = get_mods() & MOD_BIT(KC_RCTL);
  switch (keycode) {
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case KC_BSDL:
        // Shift-BS = DEL
        if (record->event.pressed) {
            mods_bsdl[0] = lctl_pressed;
            mods_bsdl[1] = rctl_pressed;
            if (lctl_pressed) unregister_mods(MOD_LCTL);
            if (rctl_pressed) unregister_mods(MOD_RCTL);
            register_code((mods_bsdl[0] || mods_bsdl[1]) ? KC_DEL : KC_BSPC);
        } else {
            if (mods_bsdl[0]) register_mods(MOD_LCTL);
            if (mods_bsdl[1]) register_mods(MOD_RCTL);
            unregister_code((mods_bsdl[0] || mods_bsdl[1]) ? KC_DEL : KC_BSPC);
            mods_bsdl[0] = false;
            mods_bsdl[1] = false;
        }
        return false;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
/*
// control IME
void dance_lang (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_MHEN);
    unregister_code (KC_MHEN);
    register_code (KC_LANG2);
    unregister_code (KC_LANG2);
  } else {
    register_code (KC_HENK);
    unregister_code (KC_HENK);
    register_code (KC_LANG1);
    unregister_code (KC_LANG1);
  }
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LANG]  = ACTION_TAP_DANCE_FN (dance_lang)
};
*/