/*
JISキーボード
*/

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "keymap_japanese.h"    // Japanese key-mapping
#include "keycode_revival.h"    // 失われたキーに復活の呪文

#define _FNC _FUNCTIONS
#define LT_NUMBERS_MOUSE LT(_NUMBERS, KC_F23)
#define LT_NM_MS LT_NUMBERS_MOUSE
// #define LT_NUMBERS_MAIN  LT(_NUMBERS, KC_F24)
// #define LT_NM_MN LT_NUMBERS_MAIN
#define CT(kc) LCTL_T(kc)
#define ST(kc) LSFT_T(kc)
#define CTL_SCLN RCTL_T(KC_SCLN)
// #define SET_WIN AG_SWAP
// #define SET_MAC AG_NORM

enum layer_number {
    _MAIN = 0,
    _MOUSE,
    _NUMBERS,
    _FUNCTIONS,
    _ADJUST1,
    _ADJUST2,
};

enum custom_keycodes {
  // Keymap Layer
  // MAIN = SAFE_RANGE,  // _MAIN: Main Layer
  MAIN = KEYBALL_SAFE_RANGE,  // _MAIN: Main Layer
  // MOUSE,                      // _MOUSE: Mouse Layer
  // NUMS,                       // _NUMS: Numbers Layer
  // FUNCS,                      // _FUNCS: Functions Layer
  // ADJUST1,                    // _ADJUST1: Active by _NUMBERS & _FUNCTIONS
  // ADJUST2,                    // _ADJUST2: DUMMY
  // // L-ayer, T-ap for Layers
  // LT_NM_MS,            // Tap:Move Layer to _MOUSE, Hold:Layer On _NUMBERS
  // LT_NM_MN,            // Tap:Move Layer to _MAIN, Hold:Layer On _NUMBERS
  // Set Key Layout for Windows/Mac
  SET_WIN,
  SET_MAC,
  // Same Key on Windows & Mac
  WM_ZHTG,  // Win:全角/半角, Mac:かな/英数
  WM_LGUI,  // Win:Windows, Mac:Control
  WM_LCTL,  // Win:Control, Mac:Command
  WM_WBAK,  // Win:Alt+←, Mac:Command+[
  WM_WFWD,  // Win:Alt+→, Mac:Command+]
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
  // MY_CLCME, // - and =
  MY_CLCPB, // + and *
  // Microsoft Teams short cut key
  TMS_MICMT,// Mic Mute on Microsoft Teams: Control + Shift + M

};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* MAIN
   *                     ,---------.                                                                                  ,---------.
   *           ,---------|    E    |---------.                                                              ,---------|    I    |---------.
   * ,---------|    W    |---------|    R    |---------.                                          ,---------|    U    |---------|    O    |---------.
   * |    Q    |---------|    D    |---------|    T    |                                          |    Y    |---------|    K    |---------|    P    |
   * |---------|    S    |---------|    F    |---------|                                          |---------|    J    |---------|    L    |---------|
   * | A /Ctrl |---------|    C    |---------|    G    |                                          |    H    |---------|   , <   |---------| ;: /Ctrl|
   * |---------|    X    |---------|    V    |---------|                                          |---------|    M    |---------|   . >   |---------|
   * | Z /Shft |---------|   Win   |---------|    B    |                                          |    N    |---------'         `---------| /? /Shft|
   * |---------|         |---------',--------`.--------'                                          `---------'                             |---------|
   * |         |---------'          |   Alt   |,---------.                                     ,---------.                                |  全-半  |
   * `---------'                    `---------'|MOUSE/NUM|,---------.               ,---------.| Ent/FNC |                                `---------'
   *                                           `---------'|  Bkspc  |               |  Space  |`---------'
   *                                                      `---------'               `---------'
   */
  [_MAIN] = LAYOUT_right_ball(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                    KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,\
    CT(KC_A) , KC_S     , KC_D     , KC_F     , KC_G     ,                                    KC_H     , KC_J     , KC_K     , KC_L     , CTL_SCLN ,\
    ST(KC_Z) , KC_X     , KC_C     , KC_V     , KC_B     ,                                    KC_N     , KC_M     , KC_COMM  , KC_DOT   , ST(KC_SLSH) ,\
    XXXXXXX  , XXXXXXX  , WM_LGUI  , KC_LALT  , LT_NM_MS , KC_BSPC  ,              KC_SPC   , LT(_FNC,KC_ENT),                            WM_ZHTG   \
  ),

  /* MOUSE  
   *                     ,---------.                                                                                  ,---------.
   *           ,---------|CPI-1000 |---------.                                                              ,---------|         |---------.
   * ,---------|         |---------|CPI+1000 |---------.                                          ,---------|         |---------|         |---------.
   * |ResetConf|---------| CPI-100 |---------|SaveConf |                                          |         |---------| ClickLt |---------|         |
   * |---------|         |---------| CPI+100 |---------|                                          |---------| Forward |---------| ClickRt |---------|
   * |  Ctrl   |---------|         |---------|         |                                          |         |---------|ScrlMode |---------|         |
   * |---------|         |---------|         |---------|                                          |---------|  Back   |---------|         |---------|
   * |  Shift  |---------|    v    |---------|         |                                          |         |---------'         `---------|         |
   * |---------|         |---------',--------`.--------'                                          `---------'                             |---------|
   * |         |---------'          |    v    |,---------.                                     ,---------.                                |         |
   * `---------'                    `---------'|  MAIN   |,---------.               ,---------.|  MAIN   |                                `---------'
   *                                           `---------'|         |               |         |`---------'
   *                                                      `---------'               `---------'
   */
  [_MOUSE] = LAYOUT_right_ball(
    KBC_RST  , XXXXXXX  , CPI_D1K  , CPI_I1K  , KBC_SAVE ,                                    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,\
    WM_LCTL  , XXXXXXX  , CPI_D100 , CPI_I100 , XXXXXXX  ,                                    XXXXXXX  , WM_WFWD  , MS_BTN1  , MS_BTN2  , XXXXXXX  ,\
    KC_LSFT  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                    XXXXXXX  , WM_WBAK  , SCRL_MO  , XXXXXXX  , XXXXXXX  ,\
    XXXXXXX  , XXXXXXX  , _______  , _______  , MAIN     , XXXXXXX  ,              XXXXXXX ,  MAIN     ,                                  XXXXXXX   \
  ),

  /* NUMBERS
   *                     ,---------.                                                                                  ,---------.
   *           ,---------|    (    |---------.                                                              ,---------|   8 (   |---------.
   * ,---------|   Tab   |---------|    )    |---------.                                          ,---------|   7 '   |---------|   9 )   |---------.
   * |   Esc   |---------|    {    |---------|    $    |                                          |   \ |   |---------|   5 %   |---------|   Del   |
   * |---------|    _    |---------|    }    |---------|                                          |---------|   4 $   |---------|   6 &   |---------|
   * |  Ctrl   |---------|    [    |---------|   @ `   |                                          |   - =   |---------|   2 "   |---------|   + *   |
   * |---------|         |---------|    ]    |---------|                                          |---------|   1 !   |---------|   3 #   |---------|
   * |  Shift  |---------|         |---------|    %    |                                          |    0    |---------'         `---------|   ^ ~   |
   * |---------|         |---------',--------`.--------'                                          `---------'                             |---------|
   * |         |---------'          |         |,---------.                                     ,---------.                                |   @ `   |
   * `---------'                    `---------'|    v    |,---------.               ,---------.|    v    |                                `---------'
   *                                           `---------'|         |               |    v    |`---------'
   *                                                      `---------'               `---------'
   */
  [_NUMBERS] = LAYOUT_right_ball(
    KC_ESC   , KC_TAB   , JS_LPRN  , JS_RPRN  , KC_DLR   ,                                    JP_YEN   , KC_7     , KC_8     , KC_9     , KC_DEL   ,\
    WM_LCTL  , JS_UNDS  , JS_LCBR  , JS_RCBR  , JP_AT    ,                                    JP_MINS  , KC_4     , KC_5     , KC_6     , MY_CLCPB ,\
    KC_LSFT  , XXXXXXX  , JS_LBRC  , JS_RBRC  , KC_PERC  ,                                    KC_0     , KC_1     , KC_2     , KC_3     , JP_CIRC  ,\
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , _______  , XXXXXXX  ,              _______ ,  _______  ,                                  JP_AT     \
  ),

  /* FUNCTIONS
   *                     ,---------.                                                                                  ,---------.
   *           ,---------|   F2    |---------.                                                              ,---------|   ↑    |---------.
   * ,---------|   Tab   |---------|   F3    |---------.                                          ,---------|  PgUp   |---------|  PgDw   |---------.
   * |   Esc   |---------|   F6    |---------|   F4    |                                          |   F1    |---------|   ↓    |---------|   Del   |
   * |---------|   F5    |---------|   F7    |---------|                                          |---------|   ←    |---------|   →    |---------|
   * |  Ctrl   |---------|   F10   |---------|   F8    |                                          |  Home   |---------|   App   |---------|   End   |
   * |---------|   F9    |---------|   F11   |---------|                                          |---------|         |---------|         |---------|
   * |  Shift  |---------|    v    |---------|   F12   |                                          |         |---------'         `---------|         |
   * |---------|         |---------',--------`.--------'                                          `---------'                             |---------|
   * |         |---------'          |    v    |,---------.                                     ,---------.                                |         |
   * `---------'                    `---------'|    v    |,---------.               ,---------.|    v    |                                `---------'
   *                                           `---------'|    v    |               |         |`---------'
   *                                                      `---------'               `---------'
   */
  [_FUNCTIONS] = LAYOUT_right_ball(
    KC_ESC   , KC_TAB   , KC_F2    , KC_F3    , KC_F4    ,                                    KC_F1    , KC_PGUP  , KC_UP    , KC_PGDN  , KC_DEL   ,\
    WM_LCTL  , KC_F5    , KC_F6    , KC_F7    , KC_F8    ,                                    KC_HOME  , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_END   ,\
    KC_LSFT  , KC_F9    , KC_F10   , KC_F11   , KC_F12   ,                                    XXXXXXX  , XXXXXXX  , KC_APP   , XXXXXXX  , XXXXXXX  ,\
    XXXXXXX  , XXXXXXX  , _______  , _______  , _______  , _______  ,              _______ ,  _______  ,                                  XXXXXXX   \
  ),

  /* ADJUST-1(NUMBERS+FUNCTIONS)
   *                     ,---------.                                                                                  ,---------.
   *           ,---------|  HUE-   |---------.                                                              ,---------|MdRainbow|---------.
   * ,---------| WinMap  |---------|  HUE+   |---------.                                          ,---------|MdBreath |---------| MdSwirl |---------.
   * |MdForward|---------|  SAT-   |---------|         |                                          |MdStatic |---------| MdGrad  |---------| MdSnake |
   * |---------|         |---------|  SAT+   |---------|                                          |---------| MdXmac  |---------|MdRGBTest|---------|
   * |MdReverce|---------| Bright- |---------|         |                                          |MdKnightR|---------|         |---------|MdTwinkle|
   * |---------|         |---------| Bright+ |---------|                                          |---------| MacMap  |---------|         |---------|
   * |         |---------|         |---------|         |                                          |         |---------'         `---------|         |
   * |---------|         |---------',--------`.--------'                                          `---------'                             |---------|
   * |         |---------'          |         |,---------.                                     ,---------.                                | LED Tog |
   * `---------'                    `---------'|    v    |,---------.               ,---------.|    v    |                                `---------'
   *                                           `---------'|         |               |         |`---------'
   *                                                      `---------'               `---------'
   */
  [_ADJUST1] = LAYOUT_right_ball(
    UG_NEXT  , SET_WIN  , UG_HUED  , UG_HUEU  , XXXXXXX  ,                                    RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN ,\
    UG_PREV  , XXXXXXX  , UG_SATD  , UG_SATU  , XXXXXXX  ,                                    RGB_M_K  , RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW ,\
    XXXXXXX  , XXXXXXX  , UG_VALD  , UG_VALU  , XXXXXXX  ,                                    XXXXXXX  , SET_MAC  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,\
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , _______  , XXXXXXX  ,              XXXXXXX ,  _______  ,                                  UG_TOGG   \
  ),

};
// clang-format on

// Layers Setting
layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is MOUSE
    keyball_set_scroll_mode(get_highest_layer(state) == _ADJUST2);  // highestはADJUST2になる気がするけど、動くのかね...
    return update_tri_layer_state(state, _NUMBERS, _FUNCTIONS, _ADJUST1);;
}

// 全角/半角切り替え用(Mac)
bool TOG_STATUS_ZENHAN = false;   // true: 全角, false: 半角

// キーレイアウト(Windows/Mac)切り替え用
bool TOG_STATUS_WINMAC = false;   // true: Mac, false: Windows


// Custom Keycodes Setting
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /*****************************
     * Keymap Layer              *
     *****************************/
    // MAIN
    case MAIN:
      if (record->event.pressed) {
        // set_single_persistent_default_layer(_MAIN);
        layer_move(_MAIN);  // MAINだけにする（恒久）
      }
      return false;
      break;
    // // NUMBERS
    // case NUMS:
    //   if (record->event.pressed) {
    //     layer_on(_NUMBERS);
    //     update_tri_layer(_NUMBERS, _FUNCTIONS, _ADJUST1);
    //   } else {
    //     layer_off(_NUMBERS);
    //     update_tri_layer(_NUMBERS, _FUNCTIONS, _ADJUST1);
    //   }
    //   return false;
    //   break;
    // // FUNCTIONS
    // case FUNCS:
    //   if (record->event.pressed) {
    //     layer_on(_FUNCTIONS);
    //     update_tri_layer(_NUMBERS, _FUNCTIONS, _ADJUST1);
    //   } else {
    //     layer_off(_FUNCTIONS);
    //     update_tri_layer(_NUMBERS, _FUNCTIONS, _ADJUST1);
    //   }
    //   return false;
    //   break;
    // // MOUSE
    // case MOUSE:
    //   if (record->event.pressed) layer_move(_MOUSE);  // MOUSEだけにする（恒久）
    //   return false;
    //   break;
    // LT(_NUMS._MOUSE)
    case LT_NM_MS:
      if (record->tap.count) {
        if (record->event.pressed) layer_move(_MOUSE);
        return false;
      }
      break;
    // // LT(_NUMS._MAIN)
    // case LT_NM_MN:
    //   if (record->tap.count) {
    //     if (record->event.pressed) layer_move(_MAIN);
    //   }
    //   return false;
    //   break;

    /**********************************
     * Set Key Layout for Windows/Mac *
     **********************************/
    // Set Windows Layout
    case SET_WIN:
      if (record->event.pressed) {
        TOG_STATUS_WINMAC = false;    // Change Key Layout for Windows
      }
      return false;
      break;
    // Set Mac Layout
    case SET_MAC:
      if (record->event.pressed) {
        TOG_STATUS_WINMAC =  true;    // Change Key Layout for Mac
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
        uint8_t mods = get_mods();
        clear_mods();
        // Windows/Macのキーマップが切り替わっているか判断し、全角/英数切替する
        // if(!TOG_STATUS_WINMAC) SEND_STRING(SS_LALT("`")); // for Windows
        if(!TOG_STATUS_WINMAC)    tap_code(JP_ZKHK);   // for Windows
        else {                                        // for Mac
          TOG_STATUS_ZENHAN = !TOG_STATUS_ZENHAN;
          if (TOG_STATUS_ZENHAN) tap_code(KC_LNG1);   // KANA: 全角
          else                   tap_code(KC_LNG2);   // EISU：半角
        }
        set_mods(mods);
        send_keyboard_report();
      }
      return false;
      break;
    // Winows:Windowsキー, Mac:Controlキー
    case WM_LGUI:
      if (record->event.pressed) {
        if(!TOG_STATUS_WINMAC) register_code(KC_LGUI);    // for Windows
        else                   register_code(KC_LCTL);    // for Mac
      }
      else {
        if(!TOG_STATUS_WINMAC) unregister_code(KC_LGUI);  // for Windows
        else                   unregister_code(KC_LCTL);  // for Mac
      }
      return false;
      break;
    // Windows: Control, Mac: Command
    case WM_LCTL:
      if (record->event.pressed) {
        if(!TOG_STATUS_WINMAC) register_code(KC_LCTL);    // for Windows
        else                   register_code(KC_LGUI);    // for Mac
      }
      else {
        if(!TOG_STATUS_WINMAC) unregister_code(KC_LCTL);  // for Windows
        else                   unregister_code(KC_LGUI);  // for Mac
      }
      return false;
      break;
    /// Win:Alt+←, Mac:Command+[
    case WM_WBAK:
      if (record->event.pressed) {
        if(!TOG_STATUS_WINMAC) tap_code16(A(KC_LEFT));    // for Windows
        else                   tap_code16(G(KC_RBRC));    // for Mac
      }
      return false;
      break;
    // Win:Alt+→, Mac:Command+]
    case WM_WFWD:
      if (record->event.pressed) {
        if(!TOG_STATUS_WINMAC) tap_code16(A(KC_RGHT));    // for Windows
        else                  tap_code16(G(KC_BSLS));    // for Mac
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
        // else              {register_mods(MOD_BIT(KC_LSFT));register_code(KC_8);unregister_code(KC_8);unregister_mods(MOD_BIT(KC_LSFT));}
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
        if (is_mod_shift) unregister_mods(MOD_BIT(KC_LSFT));
        tap_code(KC_RBRC);
        if (is_mod_shift)   register_mods(MOD_BIT(KC_LSFT));
      }
      return false;
      break;
    // Always JIS ]
    case JS_RBRC:
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));  // shifted
        if (is_mod_shift) unregister_mods(MOD_BIT(KC_LSFT));
        tap_code(KC_BSLS);
        if (is_mod_shift)   register_mods(MOD_BIT(KC_LSFT));
      }
      return false;
      break;
    // Always JIS _
    case JS_UNDS:
      if (record->event.pressed) {
        bool is_mod_shift = (keyboard_report->mods & MOD_BIT(KC_LSFT));  // shifted
        if (is_mod_shift) unregister_mods(MOD_BIT(KC_LSFT));
        if(!TOG_STATUS_WINMAC) tap_code16(S(KC_INT1));  // for Windows
        else                   tap_code16(S(KC_MINS));  // for Mac
        if (is_mod_shift)   register_mods(MOD_BIT(KC_LSFT));
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
          unregister_mods(MOD_BIT(KC_LSFT));
          tap_code(JP_COLN);     // :
        register_mods(MOD_BIT(KC_LSFT));
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
    // // - and =
    // case MY_CLCME:
    //   if (record->event.pressed) {
    //     if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {  // shifted
    //       tap_code(KC_PEQL);     // =
    //     } else {
    //       tap_code(KC_PMNS);     // -
    //     }
    //   }
    //   return false;
    //   break;
    // + and *
    case MY_CLCPB:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {  // shifted
          tap_code(KC_PAST);     // *
        } else {
          tap_code(KC_PPLS);     // +
        }
      }
      return false;
      break;

    /*********************************
     * M-od, T-ap                    *
     *********************************/
    // CTL_SCLN,            // Tap:Move Layer to _MOUSE, Hold:Layer On _NUMBERS
    case CTL_SCLN:
      if (record->tap.count) return process_record_user(JU_SCLN, record);  // タップ時はJU_SCLNの処理に任せる
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
