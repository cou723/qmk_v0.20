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
#include "os_detection.h"

#include "layers.h"
#include "rev1_inverted.h"

#define TOTAL_LAYERS 5

enum custom_keycodes {
    RGBRST = SAFE_RANGE,
    KC_NWIN,
    KC_BWIN,
    KC_WSS,
    PAREN,
    EMAIL_1,
    EMAIL_2,
    EMAIL_3,
    UNI_NUM,
    L_RESET,
    KC_RNWIN,
    NAME,
    BIRTH,
    P_SHIFT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
  [DEFAULT_LAYER] = LAYOUT( /* default layer */
/* LEFT-------------------------------------------------------------------------------- */
                    KC_1,   KC_2,   KC_3,   KC_4,
    KC_ESC, KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_5,   KC_6,
S(KC_LCTL), KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_N,   C(A(KC_T)),
            KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LWIN,
                                            LALT_T(KC_LNG2),MO(CL), KC_SPC, P_SHIFT,
                                                                /* RIGHT------------------------------------------------------------------------------- */
                                                                            KC_MUTE,KC_7,  KC_8,   KC_9,   KC_0,   KC_MINS,
                                                                    KC_VOLU,KC_7,   KC_Y,  KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_BSLS,
                                                                    KC_VOLD,KC_B,   KC_H,  KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_ENT,
                                                                            KC_BSPC,KC_N,  KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_EQL,
                                                                    KC_MINS,KC_UNDS,MO(NL),A(KC_LNG1)
                                                                /* ----------------------------------------------------------------------------------- */
    ),

    [CONTROL_LAYER] = LAYOUT(
/* LEFT-------------------------------------------------------------------------------- */
                    KC_F1,  KC_F2,  KC_F3,  KC_F4,
    _______,_______,_______,_______,KC_UP,  _______,_______,KC_F5,  KC_F6,
    _______,_______,_______,KC_DEL, KC_DOWN,KC_ENT, _______,_______,S(RGUI(KC_S)),
            _______,_______,_______,_______,_______,_______,_______,
                                            _______,XXXXXXX,_______,_______,
                                                                /* RIGHT--------------------------------------------------------------------------------- */
                                                                             _______,_______,KC_F8,  KC_F9,  KC_F10, KC_F11,
                                                                   C(KC_TAB),KC_F7,  _______,KC_HOME,KC_UP,  KC_END, KC_GRV, PAREN,  KC_F12,
                                                                S(C(KC_TAB)),DF(RL), _______,KC_LEFT,KC_DOWN,KC_RGHT,KC_ENT, KC_EQL, KC_CAPS,
                                                                             KC_LWIN,KC_BSPC,KC_DEL, KC_PGUP,KC_PGDN,_______,KC_APP,
                                                                     _______,KC_NWIN,MO(MCL),_______
                                                                /* --------------------------------------------------------------------------------------- */
  ),


    [NUMBER_LAYER] = LAYOUT( /* MACHINE CTRL */
/* LEFT-------------------------------------------------------------------------------- */
                    _______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   _______,_______,
            _______,_______,_______,_______,_______,_______,_______,
                                            _______,_______,_______,_______,
                                                                /* RIGHT------------------------------------------------------------------------------- */
                                                                            DF(GL) ,_______,_______,_______,_______,_______,
                                                                    _______,_______,_______,_______,_______,_______,_______,_______,_______,
                                                                    _______,_______,KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   _______,_______,
                                                                            _______,_______,_______,_______,_______,_______,_______,
                                                                    _______,_______,_______,_______
                                                                /* ----------------------------------------------------------------------------------- */
 ),

    [MACHINE_CTRL_LAYER] = LAYOUT( /* MACHINE CTRL */
/* LEFT-------------------------------------------------------------------------------- */
                    _______,_______,_______,_______,
    L_RESET,  _______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,
            _______,_______,_______,_______,_______,_______,_______,
                                            _______,_______,_______,_______,
                                                                /* RIGHT------------------------------------------------------------------------------- */
                                                                            DF(GL) ,_______,_______,_______,_______,_______,
                                                                    _______,_______,_______,_______,KC_PGUP,_______,_______,_______,KC_SLEP,
                                                                    _______,_______,NAME   ,EMAIL_1,KC_PGDN,EMAIL_3,UNI_NUM,_______,LGUI(KC_L),
                                                                            _______,BIRTH  ,_______,_______,_______,_______,_______,
                                                                    _______,_______,_______,_______
                                                                /* ----------------------------------------------------------------------------------- */
 ),

[RL] = LAYOUT(
/* LEFT-------------------------------------------------------------------------------- */
                      _______, _______, _______, _______,
    KC_F13 , _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______, KC_F14,
                                                 _______, MO(RCL), _______, _______,
                                                                /* RIGHT------------------------------------------------------------------------------- */
                                                                             _______, L_RESET, _______, _______, _______, _______,
                                                                    _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                                                    _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                                                             _______, _______, _______, _______, _______, _______, _______,
                                                                    _______, _______, MO(RCL), _______
                                                                /* ----------------------------------------------------------------------------------- */
                                                                  ),

    [RCL] = LAYOUT(
/* LEFT-------------------------------------------------------------------------------- */
                    KC_F1,  KC_F2,  KC_F3,  KC_F4,
    _______,_______,_______,_______,_______,_______,_______,KC_F5,  KC_F6,
    _______,_______,_______,KC_DEL, KC_UP,  KC_ENT, _______,_______,_______,
            _______,_______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,
                                            _______,XXXXXXX,_______,_______,
                                                                /* RIGHT--------------------------------------------------------------------------------- */
                                                                             EMAIL_1,L_RESET,KC_F8,  KC_F9,  KC_F10, KC_F11,
                                                                   C(KC_TAB),KC_F7,  _______,KC_HOME,KC_UP,  KC_END, KC_GRV, PAREN,  KC_F12,
                                                                S(C(KC_TAB)),_______,_______,KC_LEFT,KC_DOWN,KC_RGHT,KC_ENT,  KC_EQL, KC_CAPS,
                                                                             KC_LWIN,KC_BSPC,KC_DEL, _______,_______,_______,KC_MENU,
                                                                     _______,KC_RNWIN,MO(REMOTE_4),A(KC_LNG1)
                                                                /* --------------------------------------------------------------------------------------- */
                                                                  ),

    [REMOTE_4] = LAYOUT( /* MACHINE CTRL */
/* LEFT-------------------------------------------------------------------------------- */
                    _______,_______,_______,_______,
    L_RESET,  _______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,
            _______,_______,_______,_______,_______,_______,_______,
                                            _______,_______,_______,_______,
                                                                /* RIGHT------------------------------------------------------------------------------- */
                                                                            DF(GL) ,_______,_______,_______,_______,_______,
                                                                    _______,_______,_______,_______,KC_PGUP,_______,_______,_______,KC_SLEP,
                                                                    _______,_______,NAME   ,EMAIL_1,KC_PGDN,EMAIL_3,UNI_NUM,_______,LGUI(KC_L),
                                                                            _______,BIRTH  ,_______,_______,_______,_______,_______,
                                                                    _______,_______,_______,_______
                                                                /* ----------------------------------------------------------------------------------- */
 ),
};

// clang-format on

void open_window_changer(void) {
    register_code(KC_LALT);
    tap_code(KC_TAB);
}

void open_window_changer_remote(void) {
    register_code(KC_LALT);
    tap_code(KC_F15);
}

void launch_snipping_tool(void) {
    register_code(KC_LCTL);
    register_code(KC_LWIN);
    register_code(KC_S);
    unregister_code(KC_LCTL);
    unregister_code(KC_LWIN);
    unregister_code(KC_S);
}

void reset_layer(void) {
    for (int i = 0; i < TOTAL_LAYERS; i++) {
        layer_off(i);
    }
    default_layer_set(0);
}

typedef enum { NONE, HOLD, HOLD_PULSED_KEY, RELEASE } MOD_STATE;
typedef struct {
    int   keycode;
    char *str;
} SEND_STRING;

typedef struct s_send_command {
    int keycode;
    void (*command)(void);
} SEND_COMMAND;

bool send_text(uint16_t keycode, keyrecord_t *record) {
    SEND_STRING send_strings[] = {{EMAIL_1, "mymail"}, {EMAIL_2, "mymail2"}, {EMAIL_3, "mymail3"}, {UNI_NUM, "uni num"}, {BIRTH, "1111 11 11"}};
    for (int i = 0; i < sizeof(send_strings) / sizeof(send_strings[0]); i++) {
        if (keycode != send_strings[i].keycode) continue;

        if (record->event.pressed) send_string(send_strings[i].str);
        return true;
    }
    return false;
}

/**
 * @param keycode
 * @param record
 * @return is sent command
 */
bool send_command(uint16_t keycode, keyrecord_t *record) {
    SEND_COMMAND send_commands[] = {
        {KC_WSS, launch_snipping_tool},
        {L_RESET, reset_layer},
    };

    for (int i = 0; i < sizeof(send_commands) / sizeof(send_commands[0]); i++) {
        if (keycode != send_commands[i].keycode) continue;

        if (record->event.pressed) send_commands[i].command();
        return true;
    }
    return false;
}

void send_code_with_mod(uint16_t keycode, uint16_t mod) {
    register_code(mod);
    tap_code(keycode);
    unregister_code(mod);
}

static bool      ctrl_pressed = false;
static MOD_STATE shift_state  = NONE;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // bool is_sent = false;
    switch (keycode) {
        case KC_NWIN:
            if (record->event.pressed)
                open_window_changer();
            else
                unregister_code(KC_LALT);
            break;
        case KC_RNWIN:
            if (record->event.pressed)
                open_window_changer_remote();
            else
                unregister_code(KC_LALT);
            break;
        case PAREN:
            if (record->event.pressed) {
                register_code(KC_LBRC);
                unregister_code(KC_LBRC);
                register_code(KC_RBRC);
                unregister_code(KC_RBRC);
            }
            break;
        case KC_LCTL:
            ctrl_pressed = !!record->event.pressed;
            break;
        case P_SHIFT:
            if (record->event.pressed) {
                shift_state = HOLD;
            } else {
                if (shift_state == HOLD_PULSED_KEY) {
                    shift_state = NONE;
                    return false;
                }
                shift_state = RELEASE;
                register_code(KC_LSFT);
                unregister_code(KC_LSFT);
            }
            return false;
        case KC_U:
            if (!ctrl_pressed) break;
            if (record->event.pressed) {
                if (shift_state == HOLD || shift_state == HOLD_PULSED_KEY) register_code(KC_LSFT);
                register_code(KC_Z);
            } else {
                if (shift_state == HOLD || shift_state == HOLD_PULSED_KEY) unregister_code(KC_LSFT);
                unregister_code(KC_Z);
            }
            return false;
            break;
    }

    if (send_text(keycode, record)) return false;
    if (send_command(keycode, record)) return false;

    if ((shift_state == HOLD || shift_state == HOLD_PULSED_KEY) && record->event.pressed) {
        send_code_with_mod(keycode, KC_LSFT);
        shift_state = HOLD_PULSED_KEY;
        return false;
    }

    if (shift_state == RELEASE && record->event.pressed) {
        send_code_with_mod(keycode, KC_LSFT);
        shift_state = NONE;
        return false;
    }
    return true;
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(KC_LNG2):
            return true;
        case RALT_T(KC_LNG1):
            return true;
        default:
            return false;
    }
}

void matrix_init_user(void) {
    wait_ms(400);
    if (detected_host_os() == OS_IOS || detected_host_os() == OS_MACOS) {
        tap_code16(QK_MAGIC_SWAP_LCTL_LGUI);
    }
}

void matrix_scan_user(void) {}
