/* Copyright 2020 e3w2q
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
#include "stdbool.h"
#include "action.h"
#include "quantum_keycodes.h"
#include "rev1_inverted.h"
#include "quantum_keycodes.h"

#define DEFAULT_LAYER 0
#define DL DEFAULT_LAYER

#define CONTROL_LAYER 1
#define CL CONTROL_LAYER

#define GAMING_LAYER 3
#define GL GAMING_LAYER

#define GAMING_INPUT_LAYER 4
#define GIL GAMING_INPUT_LAYER

#define GAMING_INPUT_CTL_LAYER 5
#define GICL GAMING_INPUT_CTL_LAYER

#define REMOTE_LAYER 6
#define RL REMOTE_LAYER

#define REMOTE_CTL_LAYER 7
#define RCL REMOTE_CTL_LAYER

#define MACHINE_CTRL_LAYER 2
#define MCL MACHINE_CTRL_LAYER

#define TOTAL_LAYERS 5

enum custom_keycodes { RGBRST = SAFE_RANGE, KC_NWIN, KC_BWIN, KC_WSS, PAREN, EMAIL, G_T, G_SLSH, G_ENT, G_ESC, L_RESET, INDICATOR };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
  [DEFAULT_LAYER] = LEFT_LAYOUT( /* default layer */
    KC_5, KC_0, KC_0, KC_0, KC_7, KC_8, KC_9, KC_PAST,
    KC_0, KC_0, KC_0, KC_TAB, KC_4, KC_5, KC_6, KC_PPLS,
    KC_0, KC_0, KC_0, KC_0, KC_1, KC_2, KC_3, KC_PMNS,
    KC_0, KC_0, KC_0, KC_PSLS, KC_0, KC_0, KC_0, KC_0,
    KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_ENT,0


    KC_4, KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_TAB,

    KC_6, KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_1,
    KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_0,
    KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_0,
    KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_0,
    KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_0,
    KC_7, KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_9
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    return true;
}
void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
