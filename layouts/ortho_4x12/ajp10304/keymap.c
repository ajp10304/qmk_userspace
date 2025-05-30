/* Copyright 2021 Alan Pocklington
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

#include "ajp10304.h"
#include "keymap_uk.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * Tab: when held, operates as shift.
 * Enter: when held, operates as shift.
 * MENU: perform right-click
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,<  |  .>  |  /?  | Shft |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn   | Ctrl | Alt  | GUI  |Lower | Bksp |Space |Raise | Shift| MENU | Ctrl | Fn2  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  LT(_NUMPAD, KC_ESC),   KC_Q,       KC_W,        KC_E,      KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,      KC_O,      KC_P,       KC_BSPC             ,
  MT(MOD_LSFT, KC_TAB),  KC_A,       KC_S,        KC_D,      KC_F,    KC_G,    KC_H,    KC_J,    KC_K,      KC_L,      KC_SCLN,    MT(MOD_RSFT, KC_ENT),
  KC_LSFT,               KC_Z,       KC_X,        KC_C,      KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,    KC_RSFT             ,
  MO(_FUNC),             KC_LCTL,    KC_LALT,     KC_LGUI,   LOWER,   KC_BSPC, KC_SPC,  RAISE,   KC_LSFT,   KC_BTN2,   KC_RCTL,    MO(_FUNC2)
),

/* Colemak-DHm
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |  ;:  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |  ,<  |  .>  |  /?  | Shft |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn   | Ctrl | Alt  | GUI  |Lower | Bksp |Space |Raise | Shift| MENU | Ctrl | Fn2  |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12(
  LT(_NUMPAD, KC_ESC),   KC_Q,       KC_W,        KC_F,      KC_P,    KC_B,    KC_J,    KC_L,    KC_U,      KC_Y,      KC_SCLN,   KC_BSPC             ,
  MT(MOD_LSFT, KC_TAB),  KC_A,       KC_R,        KC_S,      KC_T,    KC_G,    KC_M,    KC_N,    KC_E,      KC_I,      KC_O,      MT(MOD_RSFT, KC_ENT),
  KC_LSFT,               KC_Z,       KC_X,        KC_C,      KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT             ,
  MO(_FUNC),             KC_LCTL,    KC_LALT,     KC_LGUI,   LOWER,   KC_BSPC, KC_SPC,  RAISE,   KC_LSFT,   KC_BTN2,   KC_RCTL,   MO(_FUNC2)
),

/* Function
 * Activated when fn held in the above qwerty/colemak layer.
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  1!  |  2"  |  3£  |  4$  |  5%  |  6^  |  7&  |  8*  |  9(  |  0)  |  ~   |INSERT|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  \|  |  `¬  |  #~  |   *  |  -_  |  =+  |  \|  |  [{  |  ]}  |  '@  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn   | Ctrl | Alt  | GUI  |Lower | Bksp |Space |Mouse | MENU | Alt  | Ctrl | Fn   |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = LAYOUT_ortho_4x12(
  KC_F1,     KC_F2,           KC_F3,    KC_F4,         KC_F5,   KC_F6,   KC_F7,   KC_F8,      KC_F9,    KC_F10,  KC_F11,  KC_F12             ,
  KC_1,      KC_2,            KC_3,     KC_4,          KC_5,    KC_6,    KC_7,    KC_8,       KC_9,     KC_0,    UK_TILD, KC_INSERT          ,
  KC_LSFT,   KC_NUBS,         KC_GRAVE, KC_NONUS_HASH, KC_PAST, KC_MINS, KC_EQL,  KC_BSLS,    KC_LBRC,  KC_RBRC, KC_QUOT, MT(MOD_RSFT, KC_ENT) ,
  _______,   _______,         _______,  _______,       _______, _______, _______, MO(_MOUSE), _______,  _______, _______, _______
),

/* Lower
 * Activated when Lower is held in the above qwerty/colemak layer.
 * Numbers are along the top row, their shifted counterparts are on row 2.
 * WrdBks: backspace with ctrl applied. I.e. delete a word.
 * WrdDel: delete with ctrl applied. I.e. forward delete a word.
 * ,-----------------------------------------------------------------------------------.
 * |  1!  |  2"  |  3£  |  4$  |  5%  |  6^  |  7&  |  8*  |  9(  |  0)  | DEL  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  !   |   "  |   £  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |WrdDel|WrdBks|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  \|  |  `¬  |  #~  |  '@  |  -_  |  =+  |  #~  |  [{  |  ]}  |  '@  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower | Del  |Space |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_1,        KC_2,            KC_3,           KC_4,           KC_5,          KC_6,          KC_7,           KC_8,            KC_9,           KC_0,          KC_DEL,          KC_BSPC            ,
  LSFT(KC_1),  LSFT(KC_2),      LSFT(KC_3),     LSFT(KC_4),     LSFT(KC_5),    LSFT(KC_6),    LSFT(KC_7),     LSFT(KC_8),      LSFT(KC_9),     LSFT(KC_0),    LCTL(KC_DEL),    LCTL(KC_BSPC)      ,
  KC_LSFT,     KC_NUBS,         KC_GRAVE,       KC_NONUS_HASH,  KC_QUOT,       KC_MINS,       KC_EQL,         KC_NONUS_HASH,   KC_LBRC,        KC_RBRC,       KC_QUOT,         MT(MOD_RSFT, KC_ENT) ,
  _______,     _______,         _______,        _______,        _______,       KC_DEL,        _______,        _______,         KC_MNXT,        KC_VOLD,       KC_VOLU,         KC_MPLY
),

/* Raise
 * Activated when Raise is held in the above qwerty/colemak layer.
 * Preferred layer for typing brackets.
 * Allows for cursor navigation to be used solely with the right hand.
 * WRDSEL: Select the word where the cursor is.
 * |< and >|: Apply ctrl to left and right respectively for word jumping.
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |WRDSEL|  [   |   ]  |      |      | PGUP | HOME |PGDOWN|      |PRNTSC|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |      |      |  (   |   )  |      |      | HOME |  UP  | END  |      |ZOOM +|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |  {   |   }  |      |  |<  | LEFT | DOWN |RIGHT |  >|  |ZOOM -|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Mouse|      |      |      |      |  Alt | Enter|Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_GRV,     XXXXXXX, M_WORD_SEL, KC_LBRC,       KC_RBRC,       XXXXXXX,   XXXXXXX,       KC_PGUP,  KC_HOME,  KC_PGDN,    XXXXXXX,        KC_PSCR           ,
  KC_GRV,     XXXXXXX, XXXXXXX,    LSFT(KC_9),    LSFT(KC_0),    XXXXXXX,   XXXXXXX,       KC_HOME,  KC_UP,    KC_END,     XXXXXXX,        LCTL(LSFT(KC_EQL)),
  _______,    XXXXXXX, XXXXXXX,    LSFT(KC_LBRC), LSFT(KC_RBRC), XXXXXXX,   LCTL(KC_LEFT), KC_LEFT,  KC_DOWN,  KC_RIGHT,   LCTL(KC_RIGHT), LCTL(KC_MINS)     ,
  MO(_MOUSE), _______, _______,    _______,       _______,       KC_LALT,   KC_ENT,        _______,  XXXXXXX,  _______,    _______,        _______
),

/* Adjust (Lower + Raise)
 * Activated when Lower and Raise are held together in the above qwerty/colemak layer.
 * Audio controls in the same position as cursor keys from the Raise layer.
 * ????: Runs a macro for outputting a text string. Do not use this store passwords.
 * Reset: Enter bootloader for flashing firmware to the keyboard.
 * CWTOGG: Toggle caps word (see qmk docs) (Also by pressing both L&R shifts)
 * CAPS: Toggle caps lock.
 * Macro functions: Allows recording of macros. To start recording the macro, press either REC1 or REC2. To finish the recording, press STOP. To replay the macro, press either PLAY1 or PLAY2.
 * MAC: Toggle MAC OS extensions to layers. This allows MLWR to be enabled with LOWER, MRSE with RAISE, MFNC with FUNC and MFNC2 with FUNC2 respectively.
 * ,--------------------------------------------------------------------------------------.
 * | ???? | Reset|Qwerty|      | TERM+| REC1 | REC2 |      |      |      | PC/MC|  Del    |
 * |------+------+------+------+------+-------------+------+------+------+------+---------|
 * |CWTOGG| CAPS |      |      | PTERM| PLAY1| PLAY2| Mute | Vol+ | Play |      | OSZOOM+ |
 * |------+------+------+------+------+------|------+------+------+------+------+---------|
 * |      |      |      |      | TERM-| STOP | STOP | Prev | Vol- | Next |      | OSZOOM- |
 * |------+------+------+------+------+------+------+------+------+------+------+---------|
 * |      |      |      |      |      |             |      |      |      |      |         |
 * `--------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
  M_CUSTOM, QK_BOOT, QWERTY,  _______, DT_UP,   DM_REC1, DM_REC2, _______,             _______,           _______,              TG(_MAC), KC_DEL,
  CW_TOGG,  KC_CAPS, _______, _______, DT_PRNT, DM_PLY1, DM_PLY2, KC_AUDIO_MUTE,       KC_AUDIO_VOL_UP,   KC_MEDIA_PLAY_PAUSE,  _______,  LAG(KC_EQL),
  _______,  _______, _______, _______, DT_DOWN, DM_RSTP, DM_RSTP, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK,  _______,  LAG(KC_MINS),
  _______,  _______, _______, _______, _______, _______, _______, _______,             _______,           _______,              _______,  _______
),

/* Mouse
 * Activated when fn and raise held together.
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |      |      |      |      |      | WH_L | WH_UP| BTN3 | WH_D | WH_R |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ACC0 | ACC1 | ACC2 |      |      |      |      | BTN1 |  UP  | BTN2 |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | ACC0 | ACC1 | ACC2 |      |      |      |      | LEFT | DOWN |RIGHT |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_ortho_4x12(
    KC_ESC ,      _______,      _______,      _______, _______, _______,   KC_MS_WH_LEFT, KC_MS_WH_UP, KC_MS_BTN3, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, _______,
    KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, _______, _______, _______,   _______,       KC_MS_BTN1,  KC_MS_UP,   KC_MS_BTN2,    _______,        _______,
    KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, _______, _______, _______,   _______,       KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,   _______,        _______,
    _______,      _______,      _______,      _______, _______, _______,   _______,       _______,     _______,    _______,       _______,        _______
),

/* Num Pad
 * Activated when holding Esc key.
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |      |      |      |      |      |NMLOCK|   7  |   8  |   9  |   /  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   *  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   +  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |   .  |   ,  |   -  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, KC_NUM , KC_KP_7, KC_KP_8,   KC_KP_9,     KC_KP_SLASH,    _______,
    _______, RGB_TOG, RGB_MOD, RGB_VAD, RGB_VAI, _______, _______, KC_KP_4, KC_KP_5,   KC_KP_6,     KC_KP_ASTERISK, _______,
    _______, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, _______, _______, KC_KP_1, KC_KP_2,   KC_KP_3,     KC_KP_PLUS,     _______,
    _______, _______, _______, _______, _______, _______, _______, KC_KP_0, KC_KP_DOT, KC_COMM,     KC_KP_MINUS,    _______
),

/* Function 2 (Right hand side)
 * Activated when fn held in the above qwerty layer.
 * WRDSEL: Select the word where the cursor is.
 * LNDEL: Delete the line where the cursor is.
 * LNSEL: Select the line where the cursor is.
 * DUP: Duplicate the selected text.
 * LNJOIN: Join the line where the cursor is with the following line.
 * MODE: Print either PC or OSX depending on what layer mode is active.
 * ,--------------------------------------------------------------------------------------.
 * |      |      |WRDSEL|      |      |      | LNDEL|      |      |      |      | MODE    |
 * |------+------+------+------+------+-------------+------+------+------+------+---------|
 * |      |      | LNSEL| DUP  |      |      |      |      |LNJOIN|      |      | QWERTY  |
 * |------+------+------+------+------+------|------+------+------+------+------+---------|
 * |      | UNDO | CUT  | COPY | PASTE|      |      |      |      |      |      | COLEMAK |
 * |------+------+------+------+------+------|------+------+------+------+------+---------|
 * |      |      |      |      |      |      |      |      |      |      |      |         |
 * `--------------------------------------------------------------------------------------'
 */
[_FUNC2] = LAYOUT_ortho_4x12(
    _______,  _______,    M_WORD_SEL, _______,    _______,    _______, M_JOIN,     _______, M_CASE,  M_LINE_DEL, _______, M_MODE,
    _______,  _______,    M_LINE_SEL, M_DUP,      _______,    _______, _______,    M_JOIN,  _______, _______,    _______, QWERTY,
    _______,  LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______, _______,    _______, _______, _______,    _______, COLEMAK,
    _______,  _______,    _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______, _______
),

[_MAC]= LAYOUT_ortho_4x12(
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    MFNC,     _______, _______, _______, MLWR,    _______, _______, MRSE,    _______, _______, _______, MFNC2
),

[_MLWR] = LAYOUT_ortho_4x12(
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MRSE] = LAYOUT_ortho_4x12(
    _______,  _______,  M_WORD_SEL_MAC, _______, _______, _______, _______,       _______,    _______, _______,    _______,        _______   ,
    _______,  _______,  _______,        _______, _______, _______, _______,       LCTL(KC_A), _______, LCTL(KC_E), _______,        LGUI(KC_EQL),
    _______,  _______,  _______,        _______, _______, _______, LALT(KC_LEFT), _______,    _______, _______,    LALT(KC_RIGHT), LGUI(KC_MINS) ,
    _______,  _______,  _______,        _______, _______, _______, _______,       _______,    _______, _______,    _______,        _______
),

[_MFNC]= LAYOUT_ortho_4x12(
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______   ,
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, LGUI(KC_PENT) ,
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______   ,
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MFNC2] = LAYOUT_ortho_4x12(
    _______,  _______,    M_WORD_SEL_MAC, _______,    _______,    _______, M_LINE_DEL_MAC, _______,    _______, _______, _______, _______,
    _______,  _______,    M_LINE_SEL_MAC, M_DUP_MAC,  _______,    _______, _______,        M_JOIN_MAC, _______, _______, _______, _______,
    _______,  LGUI(KC_Z), LGUI(KC_X),     LGUI(KC_C), LGUI(KC_V), _______, _______,        _______,    _______, _______, _______, M_MODE_MAC,
    _______,  _______,    _______,        _______,    _______,    _______, _______,        _______,    _______, _______, _______, _______
)

};
