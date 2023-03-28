#include QMK_KEYBOARD_H

#include "keymap_japanese.h"  // Japanese key-mapping
#include "keycode_revival.h"  // 失われたキーコードに復活の呪文

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
rgblight_config_t RGB_current_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _JIS = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    // _ADJUST1,
    // _ADJUST2,
};

enum custom_keycodes {
  // Keymap Layer
  JIS = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  KANA,
  EISU,
  RGBRST,
  // Set Key Layout for Windows/Mac
  SET_WIN,
  SET_MAC,
  // Same Key on Windows & Mac
  WM_ZHTG,  // 全角半角
  WM_LGUI,  // Windows/Control
  WM_LCTL,  // Control/Command
  // JIS One-Symbol Keys
  JS_AT,    // @
  JS_GRV,   // `
  JS_LPRN,  // (
  JS_RPRN,  // )
  JS_LCBR,  // {
  JS_RCBR,  // }
  JS_LBRC,  // [
  JS_RBRC,  // ]
  JS_MINS,  // -
  JS_UNDS,  // _
  JS_AMPR,  // &
  JS_ASTR,  // *
  JS_PLUS,  // +
  // like US key on JIS leyout
  JU_SCLN,  // ; and :
  JU_QUOT,  // ' and "
  // LED
  LED_TOG,
};

/* Tap Dance */
#define SCP TD_SFT_CPS
enum {
    TD_SFT_CPS,   // 1:Shift(Left), 2:Caps Lock (Windows/Mac共用)
};
void wmscp_finished(tap_dance_state_t *state, void *user_data);  // Tap Dance finished for TD_SFT_CPS
void wmscp_reset(tap_dance_state_t *state, void *user_data);     // Tap Dance reset for TD_SFT_CPS
tap_dance_action_t tap_dance_actions[] = {
    [TD_SFT_CPS]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, wmscp_finished, wmscp_reset),
};

/* Macros
 * enum macro_keycodes {
 *   KC_SAMPLEMACRO,
 * };
 * #define M_SAMPLE M(KC_SAMPLEMACRO)
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { \
  /* JIS
   * ,-----------------------------------------------.             ,-----------------------------------------------.
   * |  Tab  |   Q   |   W   |   E   |   R   |   T   |             |   Y   |   U   |   I   |   O   |   P   |  Bksp |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * | Ctrl  |   A   |   S   |   D   |   F   |   G   |             |   H   |   J   |   K   |   L   |   ;:  | Enter |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * | Shift |   Z   |   X   |   C   |   V   |   B   |             |   N   |   M   |   ,<  |   .>  |   /?  |   '"  |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * |       |       |Win/Cmd|  Alt  | LOWER | Space |             | Space | RAISE |  App  |   _   |   @`  | 全/半 |
   * `-----------------------------------------------'             `-----------------------------------------------'
   */
  [_JIS] = LAYOUT_ortho_4x12(
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,           KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC, \
    WM_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,           KC_H   , KC_J   , KC_K   , KC_L   , JU_SCLN, KC_ENT , \
    TD(SCP), KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,           KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, JU_QUOT, \
    XXXXXXX, XXXXXXX, WM_LGUI, KC_LALT, LOWER  , KC_SPC ,           KC_SPC , RAISE  , KC_APP , JS_UNDS, JP_AT  , WM_ZHTG  \
  ),
  /* Lower
   * ,-----------------------------------------------.             ,-----------------------------------------------.
   * |  Esc  |   !   |   ?   |   (   |   )   |   $   |             |   \|  |   7'  |   8(  |   9)  |   *   |  Del  |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * | Ctrl  |   #   |   `   |   {   |   }   |   @   |             |   -   |   4$  |   5%  |   6&  |   +   | Enter |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * | Shift |   _   |   &   |   [   |   ]   |   %   |             |   0   |   1!  |   2"  |   3#  |   /?  |   ^~  |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * |       |       |Win/Cmd|  Alt  | LOWER |       |             |   =   | RAISE |  App  |   ,<  |   .>  | 全/半 |
   * `-----------------------------------------------'             `-----------------------------------------------'
   */
  [_LOWER] = LAYOUT_ortho_4x12( \
    KC_ESC , KC_EXLM, KC_QUES, JS_LPRN, JS_RPRN, KC_DLR ,           JP_YEN , KC_7   , KC_8   , KC_9   , JS_ASTR, KC_DEL , \
    WM_LCTL, KC_HASH, JS_GRV , JS_LCBR, JS_RCBR, JS_AT  ,           JS_MINS, KC_4   , KC_5   , KC_6   , JS_PLUS, KC_ENT , \
    KC_LSFT, JS_UNDS, JS_AMPR, JS_LBRC, JS_RBRC, KC_PERC,           KC_0   , KC_1   , KC_2   , KC_3   , KC_SLSH, JP_CIRC, \
    XXXXXXX, XXXXXXX, WM_LGUI, KC_LALT, LOWER  , XXXXXXX,           KC_PEQL, RAISE  , KC_APP , KC_COMM, KC_DOT , WM_ZHTG  \
  ),

  /* Raise
   * ,-----------------------------------------------.             ,-----------------------------------------------.
   * |  Esc  |  F1   |  F2   |  F3   |  F4   |       |             |       | PgUp  |   Up  |  PgDw |       |  Del  |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * | Ctrl  |  F5   |  F6   |  F7   |  F8   |       |             |  Home |  Left |  Down | Right |  End  | Enter |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * | Shift |  F9   |  F10  |  F11  |  F12  |       |             |  WlLf |  WlUp | LtClc | RtClc |  WlDw |  WlRt |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * |       |       |Win/Cmd|  Alt  | LOWER | Space |             |       | RAISE |  App  |       |       | 全/半 |
   * `-----------------------------------------------'             `-----------------------------------------------'
   */
  [_RAISE] = LAYOUT_ortho_4x12( \
    KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , XXXXXXX,           XXXXXXX, KC_PGUP, KC_UP  , KC_PGDN, XXXXXXX, KC_DEL , \
    WM_LCTL, KC_F5  , KC_F6  , KC_F7  , KC_F8  , XXXXXXX,           KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END , KC_ENT , \
    KC_LSFT, KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX,           KC_WH_L, KC_WH_U, KC_BTN1, KC_BTN2, KC_WH_D, KC_WH_R, \
    XXXXXXX, XXXXXXX, WM_LGUI, KC_LALT, LOWER  , KC_SPC ,           XXXXXXX, RAISE  , KC_APP , XXXXXXX, XXXXXXX, WM_ZHTG  \
  ),
  // ),

  /* Adjust ( Lower + Raise )
   * ,-----------------------------------------------.             ,-----------------------------------------------.
   * |       |       |Win Map|       |       |       |             |       |       |       |       |       |  LED  |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |             |       |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |             |       |Mac Map|       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       | LOWER |       |             |       | RAISE |       |       |       | Reset |
   * `-----------------------------------------------'             `-----------------------------------------------'
   */
  [_ADJUST] =  LAYOUT_ortho_4x12( \
    XXXXXXX, XXXXXXX, AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, AG_NORM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOWER  , XXXXXXX,           XXXXXXX, RAISE  , XXXXXXX, XXXXXXX, XXXXXXX, RESET    \
  ),

  /* Adjust1
   * ,-----------------------------------------------.             ,-----------------------------------------------.
   * |       |       |       |       |       |       |             |       |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |             |       |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |             |       |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |             |       |       |       |       |       |       |
   * `-----------------------------------------------'             `-----------------------------------------------'
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      | Reset|RGBRST|Aud on|Audoff|      |             |      |Base  |Colemk|Dvorak|      | Ins  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |RGB ON| HUE+ | SAT+ | VAL+ | Mac  |             | Win  |  -   |   =  |Print |ScLock|Pause |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |MODE R| MODE | HUE- | SAT- | VAL- |      |             |      |      |      |      |PageUp|      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      | EISU | EISU | EISU |             | KANA | KANA | Home |PageDn|PageUp| End  |
   * `-----------------------------------------'             `-----------------------------------------'
   *//*
  [_ADJUST1] =  LAYOUT_ortho_4x12( \
      _______, RESET,   RGBRST,  _______, _______, _______,                   _______, JIS   ,  COLEMAK, DVORAK,  _______, KC_INS, \
      _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, AG_NORM,                   AG_SWAP, KC_MINS, KC_EQL,  KC_PSCR, KC_SLCK, KC_PAUS,\
      RGB_RMOD,RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,                   _______, _______, _______, _______, KC_PGUP, _______,\
      _______, _______, _______, EISU,    EISU,    EISU,                      KANA,    KANA,    KANA,    KC_HOME, KC_PGDN, KC_END\
  ),*/

  /* Adjust2
   * ,-----------------------------------------------.             ,-----------------------------------------------.
   * |       |       |       |       |       |       |             |       |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |             |       |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |             |       |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|             |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |             |       |       |       |       |       |       |
   * `-----------------------------------------------'             `-----------------------------------------------'
   *//*
  [_ADJUST2] =  LAYOUT_ortho_4x12( \
      _______, RESET,   RGBRST,  _______, _______, _______,                   _______, JIS   ,  COLEMAK, DVORAK,  _______, KC_INS, \
      _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, AG_NORM,                   AG_SWAP, KC_MINS, KC_EQL,  KC_PSCR, KC_SLCK, KC_PAUS,\
      RGB_RMOD,RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,                   _______, _______, _______, _______, KC_PGUP, _______,\
      _______, _______, _______, EISU,    EISU,    EISU,                      KANA,    KANA,    KANA,    KC_HOME, KC_PGDN, KC_END\
  ),*/

};

// define variables for reactive RGB
bool TOG_RGBLIGHT_LAYER = false;  // LEDライト光らせる用
bool TOG_STATUS_ZENHAN = false;   // 全角/半角切り替え用(Mac)

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      rgblight_mode_noeeprom(RGB_current_config.mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* Debug Log */
  #ifdef CONSOLE_ENABLE
  bool IS_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));
  bool IS_mod_control = (keyboard_report->mods & MOD_BIT(KC_LCTL));
  bool IS_windows_layout = (keymap_config.swap_lalt_lgui);
  if (record->event.pressed) {
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u, sft: %u, ctl: %u, win: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, IS_mod_shift, IS_mod_control, IS_windows_layout);
  }
  #endif
   //*/
  switch (keycode) {
    /*****************************
     *****************************
     * Keymap Layer              *
     *****************************
     *****************************/
    case JIS:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_JIS);
      }
      return false;
      break;

    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_RGBLIGHT_LAYER) { //TOG_RGBLIGHT_LAYER checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_RGBLIGHT_LAYER = !TOG_RGBLIGHT_LAYER;
          #ifdef RGBLIGHT_ENABLE
           rgblight_mode_noeeprom(16);
          #endif
        }
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode_noeeprom(RGB_current_config.mode);   // revert RGB to initial mode prior to RGB mode change
        #endif
        TOG_RGBLIGHT_LAYER = false;
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_RGBLIGHT_LAYER) { //TOG_RGBLIGHT_LAYER checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_RGBLIGHT_LAYER = !TOG_RGBLIGHT_LAYER;
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode_noeeprom(15);
          #endif
        }
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode_noeeprom(RGB_current_config.mode);  // revert RGB to initial mode prior to RGB mode change
        #endif
        layer_off(_RAISE);
        TOG_RGBLIGHT_LAYER = false;
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;

      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGB_RMOD:
      #if defined(RGBLIGHT_ENABLE)
        if (record->event.pressed) {
          rgblight_mode_noeeprom(RGB_current_config.mode);
          rgblight_step_reverse();
          RGB_current_config.mode = rgblight_config.mode;
        }
        return false;
      #endif
      break;

    case RGB_MOD:
      #if defined(RGBLIGHT_ENABLE)
        if (record->event.pressed) {
          rgblight_mode_noeeprom(RGB_current_config.mode);
          rgblight_step();
          RGB_current_config.mode = rgblight_config.mode;
        }
        return false;
      #endif
      break;

    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_config = rgblight_config;
        }
      #endif
      break;

    /*****************************
     *****************************
     * Set Key Layout for Windows/Mac *
     *****************************
     *****************************/
    case SET_WIN: // Set Windows Layout
      if (record->event.pressed) {
        tap_code16(AG_SWAP);    // Change Key Layout for Windows
      }
      return false;
      break;

    case SET_MAC: // Set Mac Keymap
      if (record->event.pressed) {
        tap_code16(AG_NORM);    // Change Key Layout for Mac
      }
      return false;
      break;

    /*****************************
     *****************************
     * Same Key on Windows & Mac *
     *****************************
     *****************************/
    case WM_ZHTG: // 全角/英数切替(Windows/Mac共用: ただし、キーマップの切替が必要)
      if (record->event.pressed) {
        // Shift, Ctrlが押されていても、全角/半角の切り替えを行えるようにする
        bool is_mod_shift   = (keyboard_report->mods & MOD_BIT(KC_LSFT));
        bool is_mod_control = (keyboard_report->mods & MOD_BIT(KC_LCTL));
        if (is_mod_shift  ) unregister_mods(KC_LSFT);
        if (is_mod_control) unregister_code(KC_LCTL);
        // Windows/Macのキーマップが切り替わっているか判断し、全角/英数切替する
        if(keymap_config.swap_lalt_lgui) SEND_STRING(SS_LALT("`")); // for Windows
        else {                                                      // for Mac
          TOG_STATUS_ZENHAN = !TOG_STATUS_ZENHAN;
          if (TOG_STATUS_ZENHAN) tap_code(KC_LNG1);  // KANA: 全角
          else                   tap_code(KC_LNG2);  // EISU：半角
        }
        if (is_mod_shift  ) register_mods(KC_LSFT);
        if (is_mod_control) register_code(KC_LCTL);
      }
      return false;
      break;

    case WM_LGUI: // GUI: Win/Cmd(Windows/Mac共用)
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui) register_code(KC_LALT);    // for Windows
        else                             register_code(KC_LCTL);    // for Mac
      }
      else {
        if(keymap_config.swap_lalt_lgui) unregister_code(KC_LALT);  // for Windows
        else                             unregister_code(KC_LCTL);  // for Mac
      }
      return false;
      break;

    case WM_LCTL: // Alt(Windows/Mac共用)
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui) register_code(KC_LCTL);    // for Windows
        else                             register_code(KC_LGUI);    // for Mac
      }
      else {
        if(keymap_config.swap_lalt_lgui) unregister_code(KC_LCTL);  // for Windows
        else                             unregister_code(KC_LGUI);  // for Mac
      }
      return false;
      break;

    /*****************************
     *****************************
     * JIS One-Symbol Keys       *
     *****************************
     *****************************/
    case JS_AT: // Always JIS @
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));
        if (is_mod_shift) unregister_code(KC_LSFT);
        tap_code(KC_LBRC);
        if (is_mod_shift)  register_code(KC_LSFT);
      }
      return false;
      break;

    case JS_GRV: // Always JIS `
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));
        if (is_mod_shift)  ;
        else register_code(KC_LSFT);
        tap_code(KC_LBRC);
        if (is_mod_shift)  ;
        else  unregister_code(KC_LSFT);
      }
      return false;
      break;

    case JS_LPRN: // Always JIS (
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));
        if (is_mod_shift)  ;
        else register_code(KC_LSFT);
        tap_code(KC_8);
        if (is_mod_shift)  ;
        else  unregister_code(KC_LSFT);
      }
      return false;
      break;

    case JS_RPRN: // Always JIS )
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));
        if (is_mod_shift)  ;
        else register_code(KC_LSFT);
        tap_code(KC_9);
        if (is_mod_shift)  ;
        else  unregister_code(KC_LSFT);
      }
      return false;
      break;

    case JS_LCBR: // Always JIS {
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));
        if (is_mod_shift)  ;
        else register_code(KC_LSFT);
        tap_code(KC_RBRC);
        if (is_mod_shift)  ;
        else  unregister_code(KC_LSFT);
      }
      return false;
      break;

    case JS_RCBR: // Always JIS }
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));
        if (is_mod_shift)  ;
        else register_code(KC_LSFT);
        tap_code(KC_BSLS);
        if (is_mod_shift)  ;
        else  unregister_code(KC_LSFT);
      }
      return false;
      break;

    case JS_LBRC: // Always JIS [
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));
        if (is_mod_shift) unregister_code(KC_LSFT);
        tap_code(KC_RBRC);
        if (is_mod_shift)  register_code(KC_LSFT);
      }
      return false;
      break;

    case JS_RBRC: // Always JIS ]
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));
        if (is_mod_shift) unregister_code(KC_LSFT);
        tap_code(KC_BSLS);
        if (is_mod_shift)  register_code(KC_LSFT);
      }
      return false;
      break;

    case JS_MINS: // Always JIS -
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));
        if (is_mod_shift) unregister_code(KC_LSFT);
        tap_code(KC_MINS);
        if (is_mod_shift)  register_code(KC_LSFT);
      }
      return false;
      break;

    case JS_UNDS: // Always JIS _ ( Mac:__ , Windows:\_ )
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));
        if (is_mod_shift)  ;
        else register_code(KC_LSFT);
        tap_code(KC_RO);
        if (is_mod_shift)  ;
        else  unregister_code(KC_LSFT);
      }
      return false;
      break;

    case JS_AMPR: // Always JIS &
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));
        if (is_mod_shift)  ;
        else register_code(KC_LSFT);
        tap_code(KC_6);
        if (is_mod_shift)  ;
        else  unregister_code(KC_LSFT);
      }
      return false;
      break;

    case JS_ASTR: // Always JIS *
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));
        if (is_mod_shift)  ;
        else register_code(KC_LSFT);
        tap_code(KC_QUOT);
        if (is_mod_shift)  ;
        else  unregister_code(KC_LSFT);
      }
      return false;
      break;

    case JS_PLUS: // Always JIS +
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));
        if (is_mod_shift)  ;
        else register_code(KC_LSFT);
        tap_code(KC_SCLN);
        if (is_mod_shift)  ;
        else  unregister_code(KC_LSFT);
      }
      return false;
      break;

    /*****************************
     *****************************
     * like US key on JIS leyout *
     *****************************
     *****************************/
    case JU_SCLN: // JIS Key as ; and :
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
          unregister_code(KC_LSFT);
          tap_code(JP_COLN);     // :
          register_code(KC_LSFT);
        } else {
          tap_code(JP_SCLN);     // ;
        }
      }
      return false;
      break;

    case JU_QUOT: // JIS Key as ' and "
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
          tap_code(JP_2);      // "
        } else {
          tap_code16(S(JP_7));  // '
        }
      }
      return false;
      break;

    /*****************************
     *****************************
     * LED                       *
     *****************************
     *****************************/
    // なんか上手くいかなかった
    // case LED_TOG: // LED ON/OFF Toggle
    //   if (record->event.pressed) {
    //       tap_code16(RGB_TOG);
    //   }
    //   return false;
    //   break;

  }
  return true;
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      rgblight_init();
      RGB_current_config = rgblight_config;
    #endif
}

/* Tap Dance */
// Tap Dance の状態
typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_SINGLE_TAP
} td_state_t;
static td_state_t td_state;   // Tap Dance の状態を保持する
// 現在の Tap Dance の状態を取得
uint8_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    }
    if (state->count == 2) return DOUBLE_SINGLE_TAP;
    else return 99; // 上記で返却する最大の状態の値より大きい任意の数
}
// Tap Dance の状態が決まった瞬間に呼ばれる
void wmscp_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
          register_code16(KC_LSFT);
          break;
        case SINGLE_HOLD:
          register_mods(MOD_BIT(KC_LSFT));
          break;
        case DOUBLE_SINGLE_TAP:
          if(keymap_config.swap_lalt_lgui) register_code16(S(KC_CAPS));   // for Windows
          else                             register_code16(  KC_CAPS );   // for Mac
          break;
    }
}
// Tap Dance の状態が終了した瞬間に呼ばれる
void wmscp_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
          unregister_code16(KC_LSFT);
          break;
        case SINGLE_HOLD:
          unregister_mods(MOD_BIT(KC_LSFT));
          break;
        case DOUBLE_SINGLE_TAP:
          break;
    }
}
