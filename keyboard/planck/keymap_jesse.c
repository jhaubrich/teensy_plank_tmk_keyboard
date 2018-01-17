// Author: Jesse Haubrich <jesse.haubrich@gmail.com>
// http://www.keyboard-layout-editor.com/#/layouts/5a5cf55c1fb2fd767ffcb39f70fbb17f

// make clean
// make KEYMAP=jesse
// teensy-loader-cli -w --mcu=atmega32u4 planck_lufa.hex

#include "keymap_common.h"

#ifndef KEYMAP_GRID
/* Planck keymap definition macro for the 'grid' layout
* ,-----------------------------------------------------------------------.
* |  `  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |     |
* | TAB |  Q  |  W  |  F  |  P  |  G  |  J  |  L  |  U  |  Y  |  ;  | DEL |
* |     |     | gui | gui | gui |     |     |     |PgUp |  [  |  ]  |fDEL |
* |-----------------------------------------------------------------------|
* |     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  |  |
* | ctl |  A  |  R  |  S  |  T  |  D  |  H  |  N  |  E  |  I  |  O  | '/^ |
* |     |     | gui | gui | gui |     | Lf  | Dn  | Up  | Rt  | home| end |
* |-----------------------------------------------------------------------|
* |     |  \  |  =  |  -  |  +  |  ~  |     |  _  |     |     |     |     |
* |shift|  Z  |  X  |  C  |  V  |  B  |  K  |  M  |  ,  |  .  |  /  |Shift|
* |     | gui | gui | gui | gui |     |     |PgDn |     |     |     |     |
* |-----------------------------------------------------------------------|
* |     |     |     |     | Lo  |     |     |  se |macro| mute| VolD| VolU|
* | ESC | GUI | alt | ctl |  w  | ENT | SPC |  i  | alt | CLMK|FKeys| GUI |
* |     |     |     |     |  er |     |     | Ra  |     | mute| VolD| VolU|
* `-----------------------------------------------------------------------'
*/

#define KEYMAP_GRID(                                                          \
       K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B, \
       K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B, \
       K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B, \
       K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B  \
) { \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07, KC_##K08, KC_##K09, KC_##K0A, KC_##K0B }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17, KC_##K18, KC_##K19, KC_##K1A, KC_##K1B }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27, KC_##K28, KC_##K29, KC_##K2A, KC_##K2B }, \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37, KC_##K38, KC_##K39, KC_##K3A, KC_##K3B }  \
}
#endif

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = KEYMAP_GRID( /* Base QWERTY */
    TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    BSPC,
    RCTL, A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT,
    LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH, LSFT,
    ESC,  LGUI, LALT, LCTL, FN2,  FN5,  SPC,  FN1,  LALT, FN3,  FN4,  LGUI),

  [1] = KEYMAP_GRID( /* Base Colemak */
    TRNS, Q,    W,    F,    P,    G,    J,    L,    U,    Y,    SCLN, TRNS,
    TRNS, A,    R,    S,    T,    D,    H,    N,    E,    I,    O,    QUOT,
    TRNS, Z,    X,    C,    V,    B,    K,    M,    COMM, DOT,  SLSH, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),

  [3] = KEYMAP_GRID( /* Lower / Movement Layer*/
    TRNS, TRNS, TRNS, FN6,  FN7,  TRNS, TRNS, TRNS, PGUP, LBRC, RBRC, DEL,
    TRNS, TRNS, FN8,  FN9,  FN10, TRNS, LEFT, DOWN, UP,   RGHT, HOME, END,
    TRNS, FN27, FN28, FN29, FN30, BTN3, TRNS, PGDN, TRNS, TRNS, TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, MUTE, VOLD, VOLU),

  [4] = KEYMAP_GRID( /* Raise / Number-sym layer
  * ,-----------------------------------------------------------------------.
  * |  `  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  | del |
  * |-----------------------------------------------------------------------|
  * |     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  |  |
  * |-----------------------------------------------------------------------|
  * |     |  \  |  =  |  -  |  +  |  ~  |     |  _  |     |     |     |     |
  * |-----------------------------------------------------------------------|
  * |     |     |     |     |     |     |     |     |macro|     |     |     |
  * `-----------------------------------------------------------------------'
  */
    GRV,  FN11, FN12, FN13, FN14, FN15, FN16, FN17, FN18, FN19, FN20, TRNS,
    TRNS, 1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    FN26,
    TRNS, BSLS, MINS,  EQL, FN22, FN23, TRNS, FN21, TRNS, TRNS, TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, FN24,  MUTE, VOLD, VOLU),

  [5] = KEYMAP_GRID( /* FKeys
* ,-----------------------------------------------------------------------.
* |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 |     |
* |-----------------------------------------------------------------------|
* |     | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 |     |
* |-----------------------------------------------------------------------|
* |     | F21 | F22 | F23 | F24 |     |     |print|     |     |     |     |
* |-----------------------------------------------------------------------|
* |     |     |     |     |     |     |     |     |     |     |     |     |
* `-----------------------------------------------------------------------'
*/
    TRNS, F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  TRNS,
    TRNS, F11,  F12,  F13,  F14,  F15,  F16,  F17,  F18,  F19,  F20,  TRNS,
    TRNS, F21,  F22,  F23,  F24,  TRNS, TRNS, PSCR, TRNS, TRNS, TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),

  };

/*
 * Macro definition
 */
enum macro_id {
    TEST,
    SUPERSECRETPASSWORD,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;
    //uint8_t tap_count = record->tap_count;

    switch (id) {
        case TEST:
            return (event.pressed ?
                    MACRO( T(T), T(E), T(S), T(T), END ) :
                    MACRO( END ) );
        case SUPERSECRETPASSWORD:
            return (event.pressed ?
                    MACRO( T(S), T(U), T(P), T(E), T(P), END ) :
                    MACRO( END ) );
    }
    return MACRO_NONE;
}


const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(4), // Raise
  [2] = ACTION_LAYER_MOMENTARY(3), // Lower
  [3] = ACTION_LAYER_TAP_TOGGLE(1),  // Colemak
  [4] = ACTION_LAYER_MOMENTARY(5), // F-keys
  [5] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_ENT),

  [11] = ACTION_MODS_KEY(MOD_LSFT, KC_1),
  [12] = ACTION_MODS_KEY(MOD_LSFT, KC_2),
  [13] = ACTION_MODS_KEY(MOD_LSFT, KC_3),
  [14] = ACTION_MODS_KEY(MOD_LSFT, KC_4),
  [15] = ACTION_MODS_KEY(MOD_LSFT, KC_5),
  [16] = ACTION_MODS_KEY(MOD_LSFT, KC_6),
  [17] = ACTION_MODS_KEY(MOD_LSFT, KC_7),
  [18] = ACTION_MODS_KEY(MOD_LSFT, KC_8),
  [19] = ACTION_MODS_KEY(MOD_LSFT, KC_9),
  [20] = ACTION_MODS_KEY(MOD_LSFT, KC_0),
  [21] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS),
  [22] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL),
  [23] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),
  [24] = ACTION_MACRO(TEST),
  [25] = ACTION_MACRO(SUPERSECRETPASSWORD),
  [26] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),

   // Awesome Lefthand
   // [5] = ACTION_MODS_KEY(MOD_LGUI, KC_W), //
   [6] = ACTION_MODS_KEY(MOD_LGUI, KC_E), // F
   [7] = ACTION_MODS_KEY(MOD_LGUI, KC_R), // P
   [8] = ACTION_MODS_KEY(MOD_LGUI, KC_S), // R
   [9] = ACTION_MODS_KEY(MOD_LGUI, KC_D), // S
  [10] = ACTION_MODS_KEY(MOD_LGUI, KC_F), // T

  [27] = ACTION_MODS_KEY(MOD_LGUI, KC_Z), //
  [28] = ACTION_MODS_KEY(MOD_LGUI, KC_X), //
  [29] = ACTION_MODS_KEY(MOD_LGUI, KC_C), //
  [30] = ACTION_MODS_KEY(MOD_LGUI, KC_V), //

};
