#include QMK_KEYBOARD_H
#include "keymap_slovak.h"
#include "process_unicode_common.h"
#include "process_leader.h"
#include "quantum_keycodes.h"

enum layers {
    BASE = 0,
    SYMBOLS,
    NUMLOCK,
    LOWER,
    RANDOM,
};

// Tap Dance Declarations
enum tap_dance_codes {
    DANCE_0 = 0,
    DANCE_1,
    DANCE_2,
    DANCE_3,
};

// For macro
enum custom_keycodes {
    VIM_QUIT_MACRO = SAFE_RANGE,
    VIM_WRITE_MACRO,
    VIM_WRITE_QUIT_MACRO,
    VIM_ENEW_MACRO,
    VIM_QUIT_ALL_MACRO,
    VIM_SPLIT_MACRO,
    VIM_VSPLIT_MACRO,
    VIM_TABNEW_MACRO,
    SHRUG_MACRO,
    LOOK_MACRO,
};
// Debug
// void keyboard_post_init_user(void) {
//   // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
//   //debug_keyboard=true;
//   //debug_mouse=true;
// };
// #include "print.h"
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
// #endif
//   return true;
// }
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT(
	TD(DANCE_0), KC_Q,              KC_W,    KC_E,        KC_R,           KC_T,               KC_Y,        KC_U,           KC_I,    KC_O,   KC_P,                 KC_BSLS,
	KC_ESC,      MT(MOD_LSFT,KC_A), KC_S,    KC_D,        LT(LOWER,KC_F), KC_G,               KC_H,        LT(LOWER,KC_J), KC_K,    KC_L,   MT(MOD_RSFT,KC_SCLN), KC_QUOTE,
	KC_LSFT,     KC_Z,              KC_X,    KC_C,        KC_V,           KC_B,               KC_N,        KC_M,           KC_COMM, KC_DOT, KC_SLASH,             KC_BSLS,
	                                                      KC_LEFT,        KC_RIGHT,           KC_DOWN,     KC_UP,
	                                         KC_SPACE,    KC_LCTL,        KC_LALT,            TD(DANCE_2), OSL(SYMBOLS),   KC_ENTER,
	                                                      KC_RGUI,     MO(RANDOM),            KC_LGUI,     KC_DEL
    ),

    [LOWER] = LAYOUT(
	KC_GRV,       KC_1,    KC_2,    KC_3,    KC_4,     KC_5,               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QK_LEADER,
	LSFT(KC_GRV), KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC,            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, QK_LOCK,
	_______,      _______, _______, _______, _______,  _______,            _______, _______, _______, _______, _______, _______,
											 _______,  _______,            _______, _______,
							   KC_BACKSPACE, _______,  _______,            _______, TO(BASE), _______,
								             _______,  _______,            _______, _______
    ),

    [SYMBOLS] = LAYOUT(
	_______,          VIM_QUIT_MACRO,       VIM_WRITE_MACRO,        VIM_ENEW_MACRO,   _______,            VIM_TABNEW_MACRO,                  _______,   KC_LBRC,   KC_RBRC,   KC_MINUS,   KC_EQUAL,   KC_PIPE,
	_______,          VIM_QUIT_ALL_MACRO,   VIM_SPLIT_MACRO,        _______,          LALT(LCTL(KC_F)),   _______,                           KC_PIPE,   KC_LPRN,   KC_RPRN,   KC_UNDS,    KC_PLUS,    KC_DQUO,
	_______,          _______,              VIM_WRITE_QUIT_MACRO,   _______,          VIM_VSPLIT_MACRO,   _______,                           _______,   KC_LCBR,   KC_RCBR,   _______,    _______,    _______,
	                                                                                  KC_HOME,            KC_END,                            KC_PGDN,   KC_PGUP,
	                                                                LALT(KC_SPACE),   _______,            _______,                           _______,   TO(BASE),  _______,
	                                                                                  _______,            _______,                           _______,   _______

                       ),

    [NUMLOCK] = LAYOUT(
	_______, _______, _______, _______, _______, _______,            _______,          KC_KP_7,          KC_KP_8,          KC_KP_9,          KC_KP_EQUAL,         _______,
	_______, _______, _______, _______, _______, _______,            _______,          KC_KP_4,          KC_KP_5,          KC_KP_6,          KC_KP_PLUS,          _______,
	_______, _______, _______, _______, _______, _______,            KC_NUM_LOCK,      KC_KP_1,          KC_KP_2,          KC_KP_3,          KC_KP_ENTER,         _______,
	                           _______, _______,                                       KC_KP_0,          KC_KP_DOT,
	                           _______, _______, _______,            _______,          TO(BASE),          _______,
	                           _______, _______,                     _______,          _______

                       ),

    [RANDOM] = LAYOUT(
	KC_F1,            KC_F2,            KC_F3,            KC_F4,            KC_F5,            KC_F6,                  KC_F7,            KC_F8,           KC_F9,          KC_F10,          KC_F11,          KC_F12,
	_______,          _______,          _______,          _______,          _______,          _______,                _______,          RGB_MODE_FORWARD,_______,       _______,         _______,         _______,
	QK_BOOT,          _______,          _______,          _______,          _______,          _______,                _______,          _______,         _______,        _______,         _______,         QK_BOOT,
														  _______,          _______,                                                    _______,         _______,
													      _______,          _______,          _______,                _______,          _______,         _______,
																			_______,          BASE,                   _______,          KC_PRINT_SCREEN
    )};

// Tap Dance Definitions

typedef struct {
    bool    is_press_action;
    uint8_t step;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };

static tap dance_state[4];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if (state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            register_code16(KC_TAB);
            break;
        case SINGLE_HOLD:
            register_code16(KC_TAB);
            break;
        case DOUBLE_TAP:
            register_code16(KC_TAB);
            register_code16(KC_TAB);
            break;
        case DOUBLE_HOLD:
            register_code16(LSFT(KC_TAB));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_TAB);
            register_code16(KC_TAB);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            unregister_code16(KC_TAB);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_TAB);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_TAB);
            break;
        case DOUBLE_HOLD:
            unregister_code16(LSFT(KC_TAB));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_TAB);
            break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
    }
    if (state->count > 3) {
        tap_code16(KC_SLASH);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            register_code16(KC_SLASH);
            break;
        case SINGLE_HOLD:
            register_code16(KC_QUES);
            break;
        case DOUBLE_TAP:
            register_code16(KC_SLASH);
            register_code16(KC_SLASH);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_RCTL);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_SLASH);
            register_code16(KC_SLASH);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            unregister_code16(KC_SLASH);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_QUES);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_SLASH);
            break;
        case DOUBLE_HOLD:
            unregister_code16(KC_RCTL);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_SLASH);
            break;
    }
    dance_state[1].step = 0;
}
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            layer_move(2);
            break;
        case SINGLE_HOLD:
            layer_move(3);
            break;
        case DOUBLE_TAP:
            layer_move(2);
            break;
        case DOUBLE_SINGLE_TAP:
            layer_move(2);
            break;
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {}
    dance_state[2].step = 0;
}

void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_LALT);
        tap_code16(KC_LALT);
        tap_code16(KC_LALT);
    }
    if (state->count > 3) {
        tap_code16(KC_LALT);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            register_code16(KC_LALT);
            break;
        case SINGLE_HOLD:
            register_code16(KC_LALT);
            break;
        case DOUBLE_TAP:
            register_code16(KC_LGUI);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_LGUI);
            break;
        case DOUBLE_SINGLE_TAP:
            register_code16(KC_LALT);
            break;
            // case DOUBLE_SINGLE_TAP: tap_code16(KC_LALT); register_code16(KC_LALT); break;
    }
}
void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            unregister_code16(KC_LALT);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_LALT);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_LGUI);
            break;
        case DOUBLE_HOLD:
            unregister_code16(KC_LGUI);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_LALT);
            break;
    }
    dance_state[3].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
    [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
    [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
    [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_2_finished, dance_2_reset),
    [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
};

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VIM_QUIT_MACRO:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(50) SS_TAP(X_Q) SS_TAP(X_ENTER));
            }
            break;
        case VIM_WRITE_MACRO:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(50) SS_TAP(X_W) SS_TAP(X_ENTER));
            }
            break;
        case VIM_WRITE_QUIT_MACRO:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(50) SS_TAP(X_X) SS_TAP(X_ENTER));
            }
            break;
        case VIM_ENEW_MACRO:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(50) "enew" SS_TAP(X_ENTER));
            }
            break;
        case VIM_QUIT_ALL_MACRO:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(50) "qa" SS_TAP(X_ENTER));
            }
            break;
        case VIM_SPLIT_MACRO:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(50) "split" SS_TAP(X_ENTER));
            }
            break;
        case VIM_VSPLIT_MACRO:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(50) "vsplit" SS_TAP(X_ENTER));
            }
            break;
        case VIM_TABNEW_MACRO:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(50) "tabnew" SS_TAP(X_ENTER));
            }
            break;
            // Unicode support - disabled to lower firmware size
            // case SHRUG_MACRO:
            // if (record->event.pressed) {
            //     send_unicode_string("¯\\_(ツ)_/¯");
            // }
            // break;
            // case LOOK_MACRO:
            // if (record->event.pressed) {
            //     send_unicode_string("ಠ_ಠ");
            // }
            // break;
    }
    return true;
}

// LEADER
void leader_start_user(void) {
    // Do something when the leader key is pressed
}
void leader_end_user(void) {
    if (leader_sequence_one_key(KC_SCLN)) {
        tap_code16(KC_CAPS);
    } else if (leader_sequence_one_key(KC_Q)) {
        SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_Q))));
    } else if (leader_sequence_two_keys(KC_S, KC_T)) {
        SEND_STRING(SS_TAP(X_ESC) SS_RCTL(SS_TAP(X_GRAVE)) SS_DELAY(50) "./startup.sh");
    }
}
