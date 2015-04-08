// Author: Jesse Haubrich <jesse.haubrich@gmail.com>
// http://www.keyboard-layout-editor.com/#/layouts/5a5cf55c1fb2fd767ffcb39f70fbb17f

#include "keymap_common.h"

#ifndef KEYMAP_GRID
/* Planck keymap definition macro for the 'grid' layout
* ,-----------------------------------------------------------------------.
* |  `  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |     |
* | TAB |  Q  |  W  |  F  |  P  |  G  |  J  |  L  |  U  |  Y  |  ;  | DEL |
* | ESC | quit|close|find |     |     |     |     |PgUp |  [  |  ]  |fDEL |
* |-----------------------------------------------------------------------|
* |     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  |  |
* |  ^  |  A  |  R  |  S  |  T  |  D  |  H  |  N  |  E  |  I  |  O  |  "  |
* |     | sel |     | save|     |     | Lf  | Dn  | Up  | Rt  | home| end |
* |-----------------------------------------------------------------------|
* |     |  \  |  =  |  -  |  +  |  ~  | SPC |  _  |     |     |     |     |
* |shift|  Z  |  X  |  C  |  V  |  B  |  K  |  M  |  ,  |  .  |  /  |Shift|
* |     | undo| cut | copy|paste|     |     |PgDn |     |  {  |  }  |     |
* |-----------------------------------------------------------------------|
* |     |     |     |     |     |     |     |     |     | mute| VolU| VolD|
* |     |Fkeys|  ^  | alt | Low | ENT | SPC | Rai |     |     |qwrty| GUI |
* |     |     |     |     |     |     |  _  |     |     | mute| VolU| VolD|
* `-----------------------------------------------------------------------'
*/

#define KEYMAP_GRID(				       			\
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
    LCTL, A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT,
    LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH, LSFT,
    ESC,  FN5,  LCTL, LALT, FN2,  SPC,  ENT,  FN1,  FN5,  FN4,  FN3,  LGUI),

  [1] = KEYMAP_GRID( /* Base Colemak */
    TAB,  Q,    W,    F,    P,    G,    J,    L,    U,    Y,    SCLN, BSPC,
    LCTL, A,    R,    S,    T,    D,    H,    N,    E,    I,    O,    QUOT,
    LSFT, Z,    X,    C,    V,    B,    K,    M,    COMM, DOT,  SLSH, LSFT,
    ESC,  FN5,  LCTL, LALT, FN2,  SPC,  ENT,  FN1,  FN5,  FN4,  FN3,  LGUI),

  [2] = KEYMAP_GRID( /* Space-Enter Swap */
    TAB,  Q,    W,    F,    P,    G,    J,    L,    U,    Y,    SCLN, BSPC,
    LCTL, A,    R,    S,    T,    D,    H,    N,    E,    I,    O,    QUOT,
    LSFT, Z,    X,    C,    V,    B,    K,    M,    COMM, DOT,  SLSH, LSFT,
    ESC,  FN5,  LCTL, LALT, FN2,  ENT,  SPC,  FN1,  FN5,  FN4,  FN3,  LGUI),

  [2] = KEYMAP_GRID( /* Base QWERTY */
    TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    BSPC,
    LCTL, A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT,
    LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH, LSFT,
    ESC,  FN5,  LCTL, LALT, FN2,  ENT,  SPC,  FN1,  FN5,  FN4,  FN3,  LGUI),

  [3] = KEYMAP_GRID( /* Lower / Movement Layer*/
    ESC,  FN7,  FN8,  FN9,  TRNS, TRNS, TRNS, FN6,  PGUP, LBRC, RBRC, DEL,
    TRNS, FN10, TRNS, TRNS, TRNS, TRNS, LEFT, DOWN, UP,   RGHT, HOME, END,
    TRNS, FN27, FN28, FN29, FN30, BTN3, TRNS, PGDN, TRNS, FN24, FN25, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, FN21, TRNS, TRNS, MUTE, VOLD, VOLU),

  [4] = KEYMAP_GRID( /* Raise / Number-sym layer
  * ,-----------------------------------------------------------------------.
  * |  `  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  | del |
  * |-----------------------------------------------------------------------|
  * |     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  |  |
  * |-----------------------------------------------------------------------|
  * |     |  \  |  =  |  -  |  +  |  ~  | SPC |  _  |     |     |     |     |
  * |-----------------------------------------------------------------------|
  * |     |     |     |     |     |     |     |     |     |     |     |     |
  * `-----------------------------------------------------------------------'
  */
    GRV,  FN11, FN12, FN13, FN14, FN15, FN16, FN17, FN18, FN19, FN20, TRNS,
    TRNS, 1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    FN26,
    TRNS, BSLS, EQL,  MINS, FN22, FN23, SPC,  FN21, TRNS, TRNS, TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, MUTE, VOLD, VOLU),

  [9] = KEYMAP_GRID( /* Symbol Layer - Depricated */
    FN23, FN11, FN12, FN13, FN14, FN15, FN16, FN17, FN18, FN19, FN20, TRNS,
    TRNS, GRV,  EQL,  MINS, FN22, TRNS, TRNS, LBRC, RBRC, FN24, FN25, FN26,
    TRNS, TRNS, TRNS, FN21, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, BSLS, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),


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

const uint16_t PROGMEM fn_actions[] = {
   [1] = ACTION_LAYER_TAP_TOGGLE(4), // Raise
   [2] = ACTION_LAYER_MOMENTARY(3), // Lower

   [3] = ACTION_LAYER_TAP_TOGGLE(2),  // spc-ent
   [4] = ACTION_LAYER_TAP_TOGGLE(1),  // Colemak
   [5] = ACTION_LAYER_MOMENTARY(5), // F-keys

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
  [24] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),
  [25] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),
  [26] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),

  [27] = ACTION_MODS_KEY(MOD_LCTL, KC_Z),  // undo
  [28] = ACTION_MODS_KEY(MOD_LCTL, KC_X),  // cut
  [29] = ACTION_MODS_KEY(MOD_LCTL, KC_C),  // copy
  [30] = ACTION_MODS_KEY(MOD_LCTL, KC_V),  // paste
  [6] = ACTION_MODS_KEY(MOD_LCTL, KC_L),  // ctl L
  [7] = ACTION_MODS_KEY(MOD_LCTL, KC_Q),   // quit
  [8] = ACTION_MODS_KEY(MOD_LCTL, KC_W),   // close
  [9] = ACTION_MODS_KEY(MOD_LCTL, KC_F),   // find
  [10] = ACTION_MODS_KEY(MOD_LCTL, KC_A),  // sel

};
