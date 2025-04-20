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

#include <ctype.h>
#include "ajp10304.h"

#define MAX_WORD_LENGTH 32

char last_word[MAX_WORD_LENGTH] = {0};
uint8_t word_index = 0;

char keycode_to_char(uint16_t keycode, uint8_t mods) {
    bool shift = mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));

    if (keycode >= KC_A && keycode <= KC_Z) {
        return shift ? ('A' + (keycode - KC_A)) : ('a' + (keycode - KC_A));
    }

    if (keycode >= KC_1 && keycode <= KC_9) {
        return '1' + (keycode - KC_1);
    }

    if (keycode == KC_0) {
        return '0';
    }

    if (keycode == KC_MINS) {
        return shift ? '_' : '-';
    }

    return '?';  // fallback
}

bool is_alpha_numeric(uint16_t keycode) {
    return (keycode >= KC_A && keycode <= KC_Z)
        || (keycode >= KC_1 && keycode <= KC_0)
        || keycode == KC_MINS;
}

bool is_terminating_keycode(uint16_t keycode) {
  switch (keycode) {
    case KC_SPACE:
    case KC_ENTER:
    case MT(MOD_RSFT, KC_ENT):
    case KC_DOT:
    case KC_COMMA:
    case KC_SCLN:
    case KC_SLSH:
    case KC_TAB:
        return true;
    default:
        return false;
  }
}

void delete_last_word(void) {
    for (uint8_t i = 0; i < word_index; i++) {
        tap_code(KC_BSPC);
    }
}

void toggle_last_word_case(void) {
    if (word_index == 0) return;

    bool first_letter_is_uppercase = isupper((unsigned char)last_word[0]);

    for (uint8_t i = 0; i < word_index; i++) {
        if (first_letter_is_uppercase) {
            last_word[i] = (char)tolower((unsigned char)last_word[i]);
        } else {
            last_word[i] = (char)toupper((unsigned char)last_word[i]);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (record->event.pressed) {
    if (is_alpha_numeric(keycode)) {

        if (word_index < MAX_WORD_LENGTH - 1) {
            last_word[word_index++] = (char) keycode_to_char(keycode, get_mods());
            last_word[word_index] = '\0';
        }

    } else if (is_terminating_keycode(keycode)) {
            word_index = 0;
            last_word[0] = '\0';

    } else if (keycode == KC_BSPC && word_index > 0) {
        word_index--;
        last_word[word_index] = '\0';
    }
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case MLWR:
      if (record->event.pressed) {
        layer_on(_LOWER);
        layer_on(_MLWR);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        layer_off(_MLWR);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case MRSE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        layer_on(_MRSE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        layer_off(_MRSE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case MFNC:
      if (record->event.pressed) {
        layer_on(_FUNC);
        layer_on(_MFNC);
      } else {
        layer_off(_FUNC);
        layer_off(_MFNC);
      }
      return false;
    case MFNC2:
      if (record->event.pressed) {
        layer_on(_FUNC2);
        layer_on(_MFNC2);
      } else {
        layer_off(_FUNC2);
        layer_off(_MFNC2);
      }
      return false;
    case M_CUSTOM:
        if (record->event.pressed) {
            SEND_STRING("Custom text here");
        }
        break;
    case M_CASE:
        if (record->event.pressed) {
            delete_last_word();
            toggle_last_word_case();
            SEND_STRING(last_word);
        }
        break;
    case M_WORD_SEL:
        if (record->event.pressed) {
            register_mods(MOD_LCTL);
            tap_code(KC_RGHT);
            tap_code16(S(KC_LEFT));
            unregister_mods(MOD_LCTL);
        }
        break;
    case M_WORD_SEL_MAC:
        if (record->event.pressed) {
            register_mods(MOD_LALT);
            tap_code(KC_RGHT);
            tap_code16(S(KC_LEFT));
            unregister_mods(MOD_LALT);
        }
        break;
    case M_LINE_SEL:
        if (record->event.pressed) {
            tap_code(KC_HOME);
            tap_code16(S(KC_END));
        }
        break;
    case M_LINE_SEL_MAC:
        if (record->event.pressed) {
            tap_code16(C(KC_A));
            tap_code16(C(S(KC_E)));
        }
        break;
    case M_LINE_DEL:
        if (record->event.pressed) {
            tap_code(KC_HOME);
            tap_code16(S(KC_END));
            tap_code(KC_BSPC);
        }
        break;
    case M_LINE_DEL_MAC:
        if (record->event.pressed) {
            tap_code16(C(KC_A));
            tap_code16(C(S(KC_E)));
            tap_code(KC_BSPC);
        }
        break;
    case M_DUP:
        if (record->event.pressed) {
            tap_code16(C(KC_C));
            tap_code(KC_RGHT);
            tap_code16(C(KC_V));
         }
         break;
    case M_DUP_MAC:
        if (record->event.pressed) {
            tap_code16(G(KC_C));
            tap_code(KC_RGHT);
            tap_code16(G(KC_V));
        }
        break;
    case M_JOIN:
        if (record->event.pressed) {
            tap_code(KC_END);
            tap_code(KC_DEL);
        }
        break;
    case M_JOIN_MAC:
        if (record->event.pressed) {
            tap_code16(C(KC_E));
            tap_code(KC_DEL);
        }
        break;
    case M_MODE:
        if (record->event.pressed) {
            send_string("PC ");
            send_string(get_highest_layer(default_layer_state) == _COLEMAK ? "COLEMAK" : "QWERTY");
        }
        break;
    case M_MODE_MAC:
        if (record->event.pressed) {
            send_string("OSX ");
            send_string(get_highest_layer(default_layer_state) == _COLEMAK ? "COLEMAK" : "QWERTY");
        }
        break;
  }
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT, KC_TAB):
            return 200;
        default:
            return TAPPING_TERM;
    }
}
