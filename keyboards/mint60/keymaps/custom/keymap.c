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
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum custom_keycodes {
  RGBRST = SAFE_RANGE
};

/* Qwerty
 * , ----------------------------\     \---------------------------------------------.
 * | ^~ | 1! | 2" | 3# | 4$ | 5% ||     || 6& | 7' | 8( | 9) | 0  | -= | \| | Bksp   |
 * |----+-+--+-+--+-+--+-+--+-+--++\     \+---+-+--+-+--+-+--+-+--+-+--+-+--+-+------|
 * | Tab  | Q  | W  | E  | R  | T  ||     || Y  | U  | I  | O  | P  | @` | [{ | }]   |
 * |------++---++---++---++---++---+\      \+---++---++---++---++---++---++---+------|
 * | Ctrl  | A  | S  | D  | F  | G  ||     || H  | J  | K  | L  | ;+ | :* | Entr     |
 * |-------++---++---++---++---++---+\      \+---++---++---++---++---++---++----+----|
 * | Shft   | Z  | X  | C  | V  | B  ||     || N  | M  | ,< | .> | /? | \_ | Up |Shft|
 * |----+---++---+-+--+--+-+----+---+/      /+----+----+--+-+---++----+----+----+----|
 * |Esc |Ctrl| GUI | Alt | Spc       ||    || Spc         | GRV |Ctrl |Left|Down|Rght|
 * `---------------------------------/     /-----------------------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* M(0): Default
 * , ----------------------------\     \---------------------------------------------.
 * | ^~ | 1! | 2" | 3# | 4$ | 5% ||     || 6& | 7' | 8( | 9) | 0  | -= | \| | Bksp   |
 * |----+-+--+-+--+-+--+-+--+-+--++\     \+---+-+--+-+--+-+--+-+--+-+--+-+--+-+------|
 * | Tab  | Q  | W  | E  | R  | T  ||     || Y  | U  | I  | O  | P  | @` | [{ | }]   |
 * |------++---++---++---++---++---+\      \+---++---++---++---++---++---++---+------|
 * | Ctrl  | A  | S  | D  | F  | G  ||     || H  | J  | K  | L  | ;+ | :* | Entr     |
 * |-------++---++---++---++---++---+\      \+---++---++---++---++---++---++----+----|
 * | Shft   | Z  | X  | C  | V  | B  ||     || N  | M  | ,< | .> | /? | \_ | Up |Shft|
 * |----+---++---+-+--+--+-+----+---+/      /+----+----+--+-+---++----+----+----+----|
 * |M(2)|M(1)| GUI | Alt | Spc       ||    || Spc         | GRV |M(1) |Left|Down|Rght|
 * `---------------------------------/     /-----------------------------------------' */
  [0] = LAYOUT( \
    JP_CIRC , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    /**/,   KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS, JP_YEN , KC_BSPC    , \
    KC_TAB   , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    /**/,   KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , JP_AT  , JP_LBRC, JP_RBRC   , \
    KC_LCTL   , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    /**/,   KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , JP_COLN, KC_ENT            , \
    KC_LSFT    , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    /**/,   KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , JP_BSLS, KC_UP  , KC_RSFT , \
    MO(2)   , MO(1)   , KC_LGUI  , KC_LALT  , KC_SPC            /**/,    KC_SPC                 , JP_ZHTG     , MO(1)    , KC_LEFT, KC_DOWN, KC_RGHT   \
  )
  , 
/* M(1): Func & Number
 * , ----------------------------\     \---------------------------------------------.
 * |Esc | .. | .. | .. | .. | .. ||     || .. | .. | .. | .. | .. | .. | .. | Del    |
 * |----+-+--+-+--+-+--+-+--+-+--++\     \+---+-+--+-+--+-+--+-+--+-+--+-+--+-+------|
 * | Tab  | F1 | F2 | F3 | F4 | .. ||     || .. | 7' | 8( | 9) | =  | .. | .. | ..   |
 * |------++---++---++---++---++---+\      \+---++---++---++---++---++---++---+------|
 * | Ctrl  | F5 | F6 | F7 | F8 | .. ||     || -= | 4$ | 5% | 6& | +  | .. | Entr     |
 * |-------++---++---++---++---++---+\      \+---++---++---++---++---++---++----+----|
 * | Shft   | F9 |F10 |F11 |F12 | .. ||     || 0  | 1! | 2" | 3# | .> |App |PgUp|Shft|
 * |----+---++---+-+--+--+-+----+---+/      /+----+----+--+-+---++----+----+----+----|
 * |M(2)|M(1)| GUI | Alt | Spc       ||    || Spc         | GRV |M(1) |Home|PgDw|End |
 * `---------------------------------/     /-----------------------------------------' */
  [1] = LAYOUT( \
    KC_ESC  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX /**/,   XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX, XXXXXXX, KC_DEL     , \
    _______  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , XXXXXXX /**/,   XXXXXXX , KC_7    , KC_8    , KC_9    ,S(KC_MINS), XXXXXXX, XXXXXXX, XXXXXXX   , \
    _______   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , XXXXXXX /**/,   KC_MINS , KC_4    , KC_5    , KC_6    ,S(KC_SCLN), XXXXXXX, _______           , \
    _______    , KC_F9   , KC_F10  , KC_F11  , KC_F12  , XXXXXXX /**/,   KC_0    , KC_1    , KC_2    , KC_3    , KC_DOT   , KC_APP , KC_PGUP, _______ , \
    _______ , _______ , _______  , _______  , _______           /**/, _______                   , _______     , _______   , KC_HOME, KC_PGDN, KC_END    \
  )
  , 
/* M(2): Mouse
 * , ----------------------------\     \---------------------------------------------.
 * |Esc | .. | .. | .. | .. | .. ||     || .. | .. | .. | .. | .. | .. | .. | Del    |
 * |----+-+--+-+--+-+--+-+--+-+--++\     \+---+-+--+-+--+-+--+-+--+-+--+-+--+-+------|
 * | Tab  |Spd0|Spd1| .. | .. | .. ||     || .. |Lclc| Up |Rclc| .. | .. | .. | ..   |
 * |------++---++---++---++---++---+\      \+---++---++---++---++---++---++---+------|
 * | Ctrl  | .. | .. |Spd2| .. | .. ||     || .. |Left|Down|Rght| .. | .. | Entr     |
 * |-------++---++---++---++---++---+\      \+---++---++---++---++---++---++----+----|
 * | Shft   | .. | .. | .. | .. | .. ||     || .. |WlUp|WlDw|WlLf|WlRt|App | Up |Shft|
 * |----+---++---+-+--+--+-+----+---+/      /+----+----+--+-+---++----+----+----+----|
 * |M(2)|M(1)| GUI | Alt | Spc       ||    || Spc         | GRV |M(1) |Left|Down|Rght|
 * `---------------------------------/     /-----------------------------------------' */
  [2] = LAYOUT( \
    KC_ESC  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX /**/,   XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX, XXXXXXX, KC_DEL     , \
    _______  , KC_ACL0 , KC_ACL1 , XXXXXXX , XXXXXXX , XXXXXXX /**/,   XXXXXXX ,KC_MS_BTN1, KC_MS_U ,KC_MS_BTN2, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX   , \
    _______   , XXXXXXX , XXXXXXX , KC_ACL2 , XXXXXXX , XXXXXXX /**/,   XXXXXXX , KC_MS_L ,  KC_MS_D , KC_MS_R  , XXXXXXX , XXXXXXX, KC_ENT            , \
    _______    , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX /**/,   XXXXXXX , KC_WH_U  , KC_WH_D , KC_WH_L  , KC_WH_R , KC_APP , _______, _______ , \
    _______ , _______ , _______  , _______  , _______           /**/, _______                    , _______      , _______  , _______, _______, _______   \
  )
  ,
/* M(2): Mouse
 * , ----------------------------\     \---------------------------------------------.
 * |Esc | .. | .. | .. | .. | .. ||     || .. | .. | .. | .. | .. | .. | .. | Del    |
 * |----+-+--+-+--+-+--+-+--+-+--++\     \+---+-+--+-+--+-+--+-+--+-+--+-+--+-+------|
 * | Tab  |LClc|MsUp|RClc| .. | .. ||     || .. |LClc|MsUp|RClc| .. | .. | .. | ..   |
 * |------++---++---++---++---++---+\      \+---++---++---++---++---++---++---+------|
 * | Ctrl  |MsLt|MsDw|MsRt| .. | .. ||     || .. |MsLt|MsDw|MsRt| .. | .. | Entr     |
 * |-------++---++---++---++---++---+\      \+---++---++---++---++---++---++----+----|
 * | Shft   | .. | .. | .. | .. | .. ||     || .. |WlUp|WlDw|WlLf|WlRt|LClc|MsUp|RClc|
 * |----+---++---+-+--+--+-+----+---+/      /+----+----+--+-+---++----+----+----+----|
 * |M(2)|M(1)| GUI | Alt | Spc       ||    || Spc         | GRV |M(1) |MsLt|MsDw|MsRt|
 * `---------------------------------/     /-----------------------------------------' */
  [3] = LAYOUT( \
    KC_ESC  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX /**/,   XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX, XXXXXXX, KC_DEL     , \
    _______  , KC_ACL0 , KC_ACL1 , XXXXXXX , XXXXXXX , XXXXXXX /**/,   XXXXXXX ,KC_MS_BTN1, KC_MS_U ,KC_MS_BTN2, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX   , \
    _______   , XXXXXXX , XXXXXXX , KC_ACL2 , XXXXXXX , XXXXXXX /**/,   XXXXXXX , KC_MS_L ,  KC_MS_D , KC_MS_R  , XXXXXXX , XXXXXXX, KC_ENT            , \
    _______    , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX /**/,   XXXXXXX , KC_WH_U  , KC_WH_D , KC_WH_L  , KC_WH_R , KC_APP , _______, _______ , \
    _______ , _______ , _______  , _______  , _______           /**/, _______                    , _______      , _______  , _______, _______, _______   \
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
  switch (keycode) {
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
