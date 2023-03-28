/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "keymap_japanese.h"    // Japanese key-mapping
#include "keycode_revival.h"    // 失われたキーに復活の呪文

enum layer_number {
    _MAIN = 0,
    _NUMBERS,
    _FUNCTIONS,
    _MOUSE,
    _ADJUST1,
    _ADJUST2,
};

enum custom_keycodes {
  // Keymap Layer
  MAIN = SAFE_RANGE,  // _MAIN
  NUMS,               // _NUMS
  FUNCS,              // _FUNCS
  MOUSE,              // _MOUSE
  ADJUST1,            // _ADJUST1
  ADJUST2,            // _ADJUST2
  // Set Key Layout for Windows/Mac
  SET_WIN,
  SET_MAC,
  // Same Key on Windows & Mac
  WM_ZHTG,  // Win:全角/半角, Mac:かな/英数
  WM_LGUI,  // Win:Windows, Mac:Control
  WM_LCTL,  // Win:Control, Mac:Command
  // JIS One-Symbol Keys
  JS_LPRN,  // (
  JS_RPRN,  // )
  JS_LCBR,  // {
  JS_RCBR,  // }
  JS_LBRC,  // [
  JS_RBRC,  // ]
  JS_UNDS,  // _
  // like US key on JIS leyout
  JU_SCLN,  // ; and :
  JU_QUOT,  // ' and "
  // Original key
  MY_CLCDM, // / and *
  MY_CLCDI, // - and +
  MY_CLCZE, // 0 and =
  MY_ORAND, // | and &
  MY_DRYN,  // $ and \ .
  MY_PRSH,  // % and #
  MY_EXQW,  // ! and ?
  MY_ALTTAB,// Alt + Tab
  // Microsoft Teams short cut key
  TMS_MICMT,// Mic Mute on Microsoft Teams: Control + Shift + M
  // Swipe Gesture
  SW_TAB,   // ↑:Non, ↓:Non, ←:Control+Shift+Tab, →:Control+Tab
  SW_WHEEL, // ↑:Whell Up ↓:Wheel Down, ←:Wheel Left, →:Wheel Right  // SCRL_TO として純正が用意されている

};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* MAIN
   *                     ,---------.                                                                                  ,---------.
   *           ,---------|    E    |---------.                                                              ,---------|    I    |---------.
   * ,---------|    W    |---------|    R    |---------.                                          ,---------|    U    |---------|    O    |---------.
   * |    Q    |---------|    D    |---------|    T    |                                          |    Y    |---------|    K    |---------|    P    |
   * |---------|    S    |---------|    F    |---------|                                          |---------|    J    |---------|    L    |---------|
   * |    A    |---------|    C    |---------|    G    |                                          |    H    |---------|   , <   |---------|   : ;   |
   * |---------|    X    |---------|    V    |---------|                                          |---------|    M    |---------|   . >   |---------|
   * |    Z    |---------|   Alt   |---------|    B    |                                          |    N    |---------'         `---------|   ' "   |
   * |---------|  Ctrl   |---------',--------`.--------'                                          `---------'                             |---------|
   * |  Shift  |---------'          |   Win   |,---------.                                     ,---------.                                |Ctrl(Alt)|
   * `---------'                    `---------'|  MOUSE  |,---------.               ,---------.|  Space  |                                `---------'
   *                                           `---------'|  NUMS   |               |  FUNCS  |`---------'
   *                                                      `---------'               `---------'
   */
  [_MAIN] = LAYOUT_right_ball(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                    KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,\
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                    KC_H     , KC_J     , KC_K     , KC_L     , JU_SCLN  ,\
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                    KC_N     , KC_M     , KC_COMM  , KC_DOT   , JU_QUOT  ,\
    KC_LSFT  , KC_LCTL  , KC_LALT  , WM_LGUI  , MOUSE    , NUMS     ,               FUNCS ,   KC_SPC   ,                                 C(KC_LALT) \
  ),


  /* NUMBERS
   *                     ,---------.                                                                                  ,---------.
   *           ,---------|    (    |---------.                                                              ,---------|   8 (   |---------.
   * ,---------|   ! ?   |---------|    )    |---------.                                          ,---------|   7 '   |---------|   9 )   |---------.
   * |  Tab*   |---------|    {    |---------|   $ \   |                                          |   / *   |---------|   5 %   |---------|  Bksp   |
   * |---------|   ^ ~   |---------|    }    |---------|                                          |---------|   4 $   |---------|   6 &   |---------|
   * |  Ctrl   |---------|    [    |---------|   @ `   |                                          |   - +   |---------|   2 "   |---------|  Enter  |
   * |---------|    _    |---------|    ]    |---------|                                          |---------|   1 !   |---------|   3 #   |---------|
   * |  Shift  |---------|   Alt   |---------|   % #   |                                          |   0 =   |---------'         `---------|   | &   |
   * |---------|   Win   |---------',--------`.--------'                                          `---------'                             |---------|
   * |   Esc   |---------'          |   Win   |,---------.                                     ,---------.                                |   Win   |
   * `---------'                    `---------'|  MOUSE  |,---------.               ,---------.|  Space  |                                `---------'
   *                                           `---------'|  NUMS   |               |  FUNCS  |`---------'
   *                                                      `---------'               `---------'
   */
  [_NUMBERS] = LAYOUT_right_ball(
    SW_TAB   , MY_EXQW  , JS_LPRN  , JS_RPRN  , MY_DRYN  ,                                    MY_CLCDM , KC_7     , KC_8     , KC_9     , KC_BSPC  ,\
    KC_LCTL  , JP_CIRC  , JS_LCBR  , JS_RCBR  , JP_AT    ,                                    MY_CLCDI , KC_4     , KC_5     , KC_6     , KC_ENT   ,\
    KC_LSFT  , JS_UNDS  , JS_LBRC  , JS_RBRC  , MY_PRSH  ,                                    MY_CLCZE , KC_1     , KC_2     , KC_3     , MY_ORAND ,\
    KC_ESC   , WM_LGUI  , KC_LALT  , _______  , _______  , _______  ,              _______ ,  _______  ,                                  WM_LGUI   \
  ),

  /* FUNCTIONS
   *                     ,---------.                                                                                  ,---------.
   *           ,---------|   F2    |---------.                                                              ,---------|   ↑    |---------.
   * ,---------|   F1    |---------|   F3    |---------.                                          ,---------|  PgUp   |---------|  PgDw   |---------.
   * |   Tab   |---------|   F6    |---------|   F4    |                                          |         |---------|   ↓    |---------|   Del   |
   * |---------|   F5    |---------|   F7    |---------|                                          |---------|   ←    |---------|   →    |---------|
   * |  Ctrl   |---------|   F10   |---------|   F8    |                                          |  Home   |---------|   App   |---------|   End   |
   * |---------|   F9    |---------|   F11   |---------|                                          |---------|         |---------|         |---------|
   * |  Shift  |---------|   Alt   |---------|   F12   |                                          |         |---------'         `---------|  全半   |
   * |---------|         |---------',--------`.--------'                                          `---------'                             |---------|
   * |   Esc   |---------'          |         |,---------.                                     ,---------.                                |  Reset  |
   * `---------'                    `---------'|  MOUSE  |,---------.               ,---------.|         |                                `---------'
   *                                           `---------'|  NUMS   |               |  FUNCS  |`---------'
   *                                                      `---------'               `---------'
   */
  [_FUNCTIONS] = LAYOUT_right_ball(
    KC_TAB   , KC_F1    , KC_F2    , KC_F3    , KC_F4    ,                                    XXXXXXX  , KC_PGUP  , KC_UP    , KC_PGDN  , KC_DEL   ,\
    KC_LCTL  , KC_F5    , KC_F6    , KC_F7    , KC_F8    ,                                    KC_HOME  , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_END   ,\
    KC_LSFT  , KC_F9    , KC_F10   , KC_F11   , KC_F12   ,                                    XXXXXXX  , XXXXXXX  , KC_APP   , XXXXXXX  , WM_ZHTG  ,\
    KC_ESC   , XXXXXXX  , KC_LALT  , XXXXXXX  , _______  , _______  ,              _______ ,  _______  ,                                  RESET     \
  ),

  /* MOUSE
   *                     ,---------.                                                                                  ,---------.
   *           ,---------|         |---------.                                                              ,---------| Wheel*  |---------.
   * ,---------| Win Map |---------|         |---------.                                          ,---------|         |---------|ScrlDiv+ |---------.
   * |  Reset  |---------|         |---------| SndVol+ |                                          | Forward |---------| ClickRt |---------|  Reset  |
   * |---------|         |---------|         |---------|                                          |---------| ClickLf |---------|ScrlDiv- |---------|
   * | Alt+Tab |---------|         |---------| SndVol- |                                          |  Back   |---------|         |---------|         |
   * |---------|         |---------| MicMute |---------|                                          |---------| Mac Map |---------|         |---------|
   * |         |---------|   Alt   |---------| SndMute |                                          |         |---------'         `---------|  全半   |
   * |---------|  Ctrl   |---------',--------`.--------'                                          `---------'                             |---------|
   * |  Shift  |---------'          |         |,---------.                                     ,---------.                                |         |
   * `---------'                    `---------'|  MOUSE  |,---------.               ,---------.|         |                                `---------'
   *                                           `---------'|  NUMS   |               |  FUNCS  |`---------'
   *                                                      `---------'               `---------'
   */
  [_MOUSE] = LAYOUT_right_ball(
    RESET    , SET_WIN  , XXXXXXX  , XXXXXXX  , KC_VOLU  ,                                    KC_WFWD  , XXXXXXX  , SW_WHEEL , SCRL_DVI , RESET    ,\
    MY_ALTTAB, XXXXXXX  , XXXXXXX  , XXXXXXX  , KC_VOLD  ,                                    KC_WBAK  , KC_BTN1  , KC_BTN2  , SCRL_DVD , XXXXXXX  ,\
    XXXXXXX  , XXXXXXX  , XXXXXXX  , TMS_MICMT, KC_MUTE  ,                                    XXXXXXX  , SET_MAC  , XXXXXXX  , XXXXXXX  , WM_ZHTG  ,\
    KC_LSFT  , KC_LCTL  , KC_LALT  , XXXXXXX  , _______  , _______  ,              _______ ,  XXXXXXX  ,                                  XXXXXXX   \
  ),

  /* ADJUST 1(RGB)
   *                     ,---------.                                                                                  ,---------.
   *           ,---------|  SAT+   |---------.                                                              ,---------|MdRainbow|---------.
   * ,---------|  HUE+   |---------| Bright+ |---------.                                          ,---------|MdBreath |---------| MdSwirl |---------.
   * |MdForward|---------|  SAT-   |---------|         |                                          |MdStatic |---------| MdGrad  |---------| MdSnake |
   * |---------|  HUE-   |---------| Bright- |---------|                                          |---------| MdXmac  |---------|MdRGBTest|---------|
   * |MdReverce|---------|         |---------|         |                                          |MdKnightR|---------|         |---------|MdTwinkle|
   * |---------|         |---------|         |---------|                                          |---------|         |---------|         |---------|
   * |         |---------|         |---------|         |                                          |         |---------'         `---------|         |
   * |---------|         |---------',--------`.--------'                                          `---------'                             |---------|
   * |         |---------'          |         |,---------.                                     ,---------.                                | LED Tog |
   * `---------'                    `---------'|  MOUSE  |,---------.               ,---------.|         |                                `---------'
   *                                           `---------'|  NUMS   |               |  FUNCS  |`---------'
   *                                                      `---------'               `---------'
   */
  /*
  [ADJUST1] = LAYOUT_right_ball(
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , XXXXXXX  ,                                   RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN ,\
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , XXXXXXX  ,                                   RGB_M_K  , RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW ,\
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                   XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,\
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , _______  , _______  ,             _______ ,  XXXXXXX  ,                                  RGB_TOG   \
  ),
  */

  /* ADJUST 2(Config)
   *                     ,---------.                                                                                  ,---------.
   *           ,---------|         |---------.                                                              ,---------|         |---------.
   * ,---------|         |---------|         |---------.                                          ,---------|         |---------|         |---------.
   * |         |---------|         |---------|         |                                          |         |---------|         |---------|         |
   * |---------|         |---------|         |---------|                                          |---------|         |---------|         |---------|
   * |         |---------|         |---------|         |                                          |         |---------| CPI+1k  |---------|         |
   * |---------|         |---------|         |---------|                                          |---------| CPI-100 |---------| CPI+100 |---------|
   * |SaveConf |---------|         |---------|         |                                          | CPI-1k  |---------'         `---------|SaveConf |
   * |---------|         |---------',--------`.--------'                                          `---------'                             |---------|
   * |ResetConf|---------'          |         |,---------.                                     ,---------.                                |ResetConf|
   * `---------'                    `---------'|  MOUSE  |,---------.               ,---------.|         |                                `---------'
   *                                           `---------'|  NUMS   |               |  FUNCS  |`---------'
   *                                                      `---------'               `---------'
   */
  /*
  [ADJUST2] = LAYOUT_right_ball(
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                   XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,\
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                   XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,\
    KBC_SAVE , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                   CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,\
    KBC_RST  , XXXXXXX  , XXXXXXX  , XXXXXXX  , _______  , _______  ,             _______ ,  XXXXXXX  ,                                  KBC_RST   \
  )
  */

};
// clang-format on

// Layers Setting
layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is MOUSE
    keyball_set_scroll_mode(get_highest_layer(state) == _ADJUST2);  // highestはADJUST2になる気がするけど、動くのかね...
    return state;
}

// Setting ADJUST layer back to default
void update_layer_to_adjust(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

// 全角/半角切り替え用(Mac)
bool TOG_STATUS_ZENHAN = false;   // true: 全角, false: 半角


// Custom Keycodes Setting
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /*****************************
     * Keymap Layer              *
     *****************************/
    // MAIN
    case MAIN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MAIN);
      }
      return false;
      break;
    // NUMBERS
    case NUMS:
      if (record->event.pressed) {
        layer_on(_NUMBERS);
        update_layer_to_adjust(_NUMBERS, _FUNCTIONS, _ADJUST1);
      } else {
        layer_off(_NUMBERS);
        update_layer_to_adjust(_NUMBERS, _FUNCTIONS, _ADJUST1);
      }
      return false;
      break;
    // FUNCTIONS
    case FUNCS:
      if (record->event.pressed) {
        layer_on(_FUNCTIONS);
        update_layer_to_adjust(_NUMBERS, _FUNCTIONS, _ADJUST1);
        update_layer_to_adjust(_MOUSE  , _FUNCTIONS, _ADJUST2);
      } else {
        layer_off(_FUNCTIONS);
        update_layer_to_adjust(_NUMBERS, _FUNCTIONS, _ADJUST1);
        update_layer_to_adjust(_MOUSE  , _FUNCTIONS, _ADJUST2);
      }
      return false;
      break;
    // MOUSE
    case MOUSE:
      if (record->event.pressed) {
        layer_on(_MOUSE);
        update_layer_to_adjust(_MOUSE  , _FUNCTIONS, _ADJUST2);
      } else {
        layer_off(_MOUSE);
        update_layer_to_adjust(_MOUSE  , _FUNCTIONS, _ADJUST2);
      }
      return false;
      break;

    /**********************************
     * Set Key Layout for Windows/Mac *
     **********************************/
    // Set Windows Layout
    case SET_WIN:
      if (record->event.pressed) {
        tap_code16(AG_SWAP);    // Change Key Layout for Windows
      }
      return false;
      break;
    // Set Mac Layout
    case SET_MAC:
      if (record->event.pressed) {
        tap_code16(AG_NORM);    // Change Key Layout for Mac
      }
      return false;
      break;

    /*****************************
     * Same Key on Windows & Mac *
     *****************************/
    // Winows:全角/半角キー, Mac:かなキー/英数キー
    case WM_ZHTG:
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
    // Winows:Windowsキー, Mac:Controlキー
    case WM_LGUI:
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
    // Windows: Control, Mac: Command
    case WM_LCTL:
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
     * JIS One-Symbol Keys       *
     *****************************/
    // Always JIS (
    case JS_LPRN:
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));  // shifted
        if (is_mod_shift) tap_code(KC_8);
        else              tap_code16(S(KC_8));
        // else              {register_code16(S(KC_8));unregister_code16(S(KC_8));}
        // else              {register_mods(KC_LSFT);register_code(KC_8);unregister_code(KC_8);unregister_mods(KC_LSFT);}
      }
      return false;
      break;
    // Always JIS )
    case JS_RPRN:
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));  // shifted
        if (is_mod_shift) tap_code(KC_9);
        else              tap_code16(S(KC_9));
      }
      return false;
      break;
    // Always JIS {
    case JS_LCBR:
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));  // shifted
        if (is_mod_shift) tap_code(KC_RBRC);
        else              tap_code16(S(KC_RBRC));
      }
      return false;
      break;
    // Always JIS }
    case JS_RCBR:
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));  // shifted
        if (is_mod_shift) tap_code(KC_BSLS);
        else              tap_code16(S(KC_BSLS));
      }
      return false;
      break;
    // Always JIS [
    case JS_LBRC:
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));  // shifted
        if (is_mod_shift) unregister_mods(KC_LSFT);
        tap_code(KC_RBRC);
        if (is_mod_shift) register_mods(KC_LSFT);
      }
      return false;
      break;
    // Always JIS ]
    case JS_RBRC:
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));  // shifted
        if (is_mod_shift) unregister_mods(KC_LSFT);
        tap_code(KC_BSLS);
        if (is_mod_shift) register_mods(KC_LSFT);
      }
      return false;
      break;
    // Always JIS _
    case JS_UNDS:
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));  // shifted
        if (is_mod_shift) unregister_mods(KC_LSFT);
        if(keymap_config.swap_lalt_lgui) tap_code16(S(KC_INT1));  // for Windows
        else                             tap_code16(S(KC_MINS));  // for Mac
        if (is_mod_shift) register_mods(KC_LSFT);
      }
      return false;
      break;

    /*****************************
     * like US key on JIS leyout *
     *****************************/
    // ; and : on JIS
    case JU_SCLN:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {  // shifted
          unregister_mods(KC_LSFT);
          tap_code(JP_COLN);     // :
          register_mods(KC_LSFT);
        } else {
          tap_code(JP_SCLN);     // ;
        }
      }
      return false;
      break;
    // ' and " on JIS
    case JU_QUOT:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {  // shifted
          tap_code(JP_2);      // "
        } else {
          tap_code16(S(JP_7));  // '
        }
      }
      return false;
      break;

    /*****************************
     * Original key              *
     *****************************/
    // / and *
    case MY_CLCDM:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {  // shifted
          tap_code(KC_PAST);   // *
        } else {
          tap_code(KC_PSLS);   // /
        }
      }
      return false;
      break;
    // - and +
    case MY_CLCDI:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {  // shifted
          tap_code(KC_PPLS);     // +
        } else {
          tap_code(KC_PMNS);     // -
        }
      }
      return false;
      break;
    // 0 and =
    case MY_CLCZE:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {  // shifted
          unregister_mods(KC_LSFT);
          tap_code(KC_PEQL);     // =
          register_mods(KC_LSFT);
        } else {
          tap_code(KC_0);        // 0
        }
      }
      return false;
      break;
    // | and &
    case MY_ORAND:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {  // shifted
          unregister_mods(KC_LSFT);
          tap_code16(S(KC_6));     // &
          register_mods(KC_LSFT);
        } else {
          tap_code16(S(KC_INT3));  // |
        }
      }
      return false;
      break;
    // $ and BackSlash
    case MY_DRYN:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {  // shifted
          unregister_mods(KC_LSFT);
          tap_code(KC_INT3);     // \ .
          register_mods(KC_LSFT);
        } else {
          tap_code16(S(KC_4));   // $
        }
      }
      return false;
      break;
    // % and #
    case MY_PRSH:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {  // shifted
          unregister_mods(KC_LSFT);
          tap_code16(S(KC_3));   // #
          register_mods(KC_LSFT);
        } else {
          tap_code16(S(KC_5));   // %
        }
      }
      return false;
      break;
    // ! and ?
    case MY_EXQW:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {  // shifted
          unregister_mods(KC_LSFT);
          tap_code16(S(KC_SLSH));  // ?
          register_mods(KC_LSFT);
        } else {
          tap_code16(S(KC_1));     // !
        }
      }
      return false;
      break;
    // Alt + Tab
    case MY_ALTTAB:
      if (record->event.pressed) {
        register_mods(KC_LALT);
        register_mods(KC_TAB);
      }
      else {
        unregister_mods(KC_TAB);
        unregister_mods(KC_LALT);
      }
      return false;
      break;

    /*********************************
     * Microsoft Teams short cut key *
     *********************************/
    // Mic Mute on Microsoft Teams: Control + Shift + M
    case TMS_MICMT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT("m")));
      }
      return false;
      break;

    /*****************************
     * Swipe Gesture             *
     *****************************/
    // Tab Gesture:  ↑:Non, ↓:Non, ←:Control+Shift+Tab, →:Control+Tab
    case SW_TAB:
      if (record->event.pressed) {}
      return false;
      break;
    // Wheel Gesture:  ↑:Whell Up ↓:Wheel Down, ←:Wheel Left, →:Wheel Right  // SCRL_TO として純正が用意されている
    case SW_WHEEL:
      if (record->event.pressed) {}
      return false;
      break;

  // End of switch(keycode)
  }
  return true;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
}
#endif
