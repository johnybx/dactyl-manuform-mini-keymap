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
    NORMAL,
    GAME,
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
    PRINT_UNICODE_MODE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT(
	TD(DANCE_0), KC_Q,              KC_W,    KC_E,        KC_R,           KC_T,               KC_Y,        KC_U,           KC_I,    KC_O,   KC_P,                 KC_BSLS,
	KC_ESC,      MT(MOD_LSFT,KC_A), KC_S,    KC_D,        LT(LOWER,KC_F), KC_G,               KC_H,        LT(LOWER,KC_J), KC_K,    KC_L,   MT(MOD_RSFT,KC_SCLN), KC_QUOTE,
	KC_LSFT,     KC_Z,              KC_X,    KC_C,        KC_V,           KC_B,               KC_N,        KC_M,           KC_COMM, KC_DOT, KC_SLASH,             KC_BSLS,
	                                KC_LEFT, KC_RIGHT,                                                                     KC_DOWN, KC_UP,
	                                         KC_SPACE,    KC_LCTL,        KC_LALT,            TD(DANCE_2), OSL(SYMBOLS),   KC_ENTER,
	                                                      KC_RGUI,     MO(RANDOM),            KC_LGUI,     KC_DEL
    ),

    [LOWER] = LAYOUT(
	KC_GRV,       KC_1,    KC_2,    KC_3,    KC_4,     KC_5,               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QK_LEADER,
	LSFT(KC_GRV), KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC,            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, QK_LOCK,
	_______,      _______, _______, _______, _______,  _______,            _______, _______, _______, _______, _______, _______,
                           _______, _______,                                                 _______, _______,
							   KC_BACKSPACE, _______,  _______,            _______, TO(BASE),_______,
								             _______,  _______,            _______, _______
    ),

    [SYMBOLS] = LAYOUT(
	_______,          VIM_QUIT_MACRO,       VIM_WRITE_MACRO,        VIM_ENEW_MACRO,   _______,            VIM_TABNEW_MACRO,                  _______,   KC_LBRC,   KC_RBRC,   KC_MINUS,   KC_EQUAL,   KC_PIPE,
	_______,          VIM_QUIT_ALL_MACRO,   VIM_SPLIT_MACRO,        _______,          LALT(LCTL(KC_F)),   _______,                           KC_PIPE,   KC_LPRN,   KC_RPRN,   KC_UNDS,    KC_PLUS,    KC_DQUO,
	_______,          _______,              VIM_WRITE_QUIT_MACRO,   _______,          VIM_VSPLIT_MACRO,   _______,                           _______,   KC_LCBR,   KC_RCBR,   _______,    _______,    _______,
	                                        KC_HOME,                KC_END,                                                                                        KC_PGDN,   KC_PGUP,
	                                                                LALT(KC_SPACE),   _______,            _______,                           _______,   TO(BASE),  _______,
	                                                                                  _______,            _______,                           _______,   _______

    ),

    [NUMLOCK] = LAYOUT(
	_______, _______, _______, _______, _______, _______,            _______,          KC_KP_7,          KC_KP_8,          KC_KP_9,          KC_KP_EQUAL,         _______,
	_______, _______, _______, _______, _______, _______,            _______,          KC_KP_4,          KC_KP_5,          KC_KP_6,          KC_KP_PLUS,          _______,
	_______, _______, _______, _______, _______, _______,            KC_NUM_LOCK,      KC_KP_1,          KC_KP_2,          KC_KP_3,          KC_KP_ENTER,         _______,
	                  _______, _______,                                                                  KC_KP_0,          KC_KP_DOT,
	                           _______, _______, _______,            _______,          TO(BASE),         _______,
	                           _______, _______,                     _______,          _______

    ),

    [RANDOM] = LAYOUT(
	KC_F1,            KC_F2,            KC_F3,            KC_F4,            KC_F5,            KC_F6,                  KC_F7,            KC_F8,             KC_F9,           KC_F10,          KC_F11,          KC_F12,
	_______,          _______,          _______,          _______,          _______,          _______,                _______,          UG_NEXT,           UG_HUEU,         UG_SPDU,         RGB_TOG,         _______,
	QK_BOOT,          _______,          _______,          _______,          _______,          _______,                _______,          PRINT_UNICODE_MODE,UC_NEXT,         UC_PREV,         UC(0x30C4),      QK_BOOT,
										_______,          _______,                                                                                         SHRUG_MACRO,     LOOK_MACRO,
													      _______,          _______,          TO(GAME),               _______,          _______,           _______,
																			TO(NORMAL),       TO(BASE),               _______,          KC_PRINT_SCREEN
    ),
    [NORMAL] = LAYOUT(
	_______, _______, _______, _______, _______, _______,            _______, _______,  _______, _______, _______, _______,
	_______, KC_A,    _______, _______, KC_F,    _______,            _______, KC_J,     _______, _______, KC_SCLN, _______,
	_______, _______, _______, _______, _______, _______,            _______, _______,  _______, _______, _______, _______,
	                  _______, _______,                                                 _______, _______,
	                           _______, _______, _______,            _______, TO(BASE), _______,
	                           KC_LSFT, _______,                     _______, _______

    ),
    [GAME] = LAYOUT(
	KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,               _______, _______,  _______, _______, _______, _______,
	_______, KC_F,    KC_A,    KC_W,    KC_D,    _______,            _______, KC_J,     _______, _______, KC_SCLN, _______,
	_______, _______, _______, KC_S,    _______, _______,            _______, _______,  _______, _______, _______, _______,
	                  _______, _______,                                                 _______, _______,
	                           _______, _______, _______,            _______, TO(BASE), _______,
	                           KC_LSFT, _______,                     _______, _______

    ),
};

 /* [EMPTY] = LAYOUT( */
	/* _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, */
	/* _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, */
	/* _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, */
	/*                   _______, _______,                                                _______, _______, */
	/*                            _______, _______, _______,            _______, _______, _______,  */
	/*                            _______, _______,                     _______, _______ */
	/**/
 /*                       ), */

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
            layer_move(NUMLOCK);
            break;
        case SINGLE_HOLD:
            layer_move(SYMBOLS);
            break;
        case DOUBLE_TAP:
            layer_move(NUMLOCK);
            break;
        case DOUBLE_SINGLE_TAP:
            layer_move(NUMLOCK);
            break;
        case DOUBLE_HOLD:
            layer_move(RANDOM);
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
    if (record->event.pressed) {
        switch (keycode) {
            case VIM_QUIT_MACRO:
                SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(50) SS_TAP(X_Q) SS_TAP(X_ENTER));
                break;
            case VIM_WRITE_MACRO:
                SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(50) SS_TAP(X_W) SS_TAP(X_ENTER));
                break;
            case VIM_WRITE_QUIT_MACRO:
                SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(50) SS_TAP(X_X) SS_TAP(X_ENTER));
                break;
            case VIM_ENEW_MACRO:
                SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(50) "enew" SS_TAP(X_ENTER));
                break;
            case VIM_QUIT_ALL_MACRO:
                SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(50) "qa" SS_TAP(X_ENTER));
                break;
            case VIM_SPLIT_MACRO:
                SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(50) "split" SS_TAP(X_ENTER));
                break;
            case VIM_VSPLIT_MACRO:
                SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(50) "vsplit" SS_TAP(X_ENTER));
                break;
            case VIM_TABNEW_MACRO:
                SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(50) "tabnew" SS_TAP(X_ENTER));
                break;
            case SHRUG_MACRO:
                send_unicode_string("¯\\_(ツ)_/¯");
                break;
            case LOOK_MACRO:
                send_unicode_string("ಠ_ಠ");
                break;
            case PRINT_UNICODE_MODE:
                switch (get_unicode_input_mode()){
                    case UNICODE_MODE_MACOS:
                        SEND_STRING("MACOS");
                        break;
                    case UNICODE_MODE_LINUX:
                        SEND_STRING("LINUX");
                        break;
                    case UNICODE_MODE_WINDOWS:
                        SEND_STRING("WINDOWS");
                        break;
                    case UNICODE_MODE_BSD:
                        SEND_STRING("BSD");
                        break;
                    case UNICODE_MODE_WINCOMPOSE:
                        SEND_STRING("WINCOMPOSE");
                        break;
                    case UNICODE_MODE_EMACS:
                        SEND_STRING("EMACS");
                        break;
                    }
                break;
        }
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
#define HSV_ORANGE_SOFT 21, 255, 80
#define HSV_CYAN_SOFT 128, 255, 80
#define HSV_OTHER_TURQUOISE   123,  180, 125

const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_ORANGE_SOFT},
    {6, 6, HSV_CYAN_SOFT},
    {25, 6, HSV_ORANGE_SOFT},
    {31, 6, HSV_CYAN_SOFT}
);

const rgblight_segment_t PROGMEM numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {26, 4, HSV_TEAL},
    {32, 4, HSV_TEAL},
    {37, 1, HSV_RED},
    {38, 4, HSV_TEAL},
    {45, 2, HSV_GOLD}
);

const rgblight_segment_t PROGMEM numlock_active_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {12 +25, 1, HSV_GREEN}
);

const rgblight_segment_t PROGMEM normal_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_AZURE},
    {1, 1, HSV_BLACK},
    {2, 1, HSV_BLUE},
    {3, 1, HSV_BLACK},
    {4, 1, HSV_GOLD},
    {5, 1, HSV_RED},
    {31, 1, HSV_AZURE},
    {32, 1, HSV_BLACK},
    {33, 1, HSV_BLUE},
    {34, 1, HSV_BLACK},
    {35, 1, HSV_GOLD},
    {36, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM game_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_AZURE},
    {0, 6, HSV_BLUE},
    {7, 3, HSV_RED},
    {14, 1, HSV_RED}
);

const rgblight_segment_t PROGMEM symbols_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_AZURE},
    {2, 3, HSV_AZURE},
    {7, 1, HSV_GREEN},
    {9, 2, HSV_AZURE},
    {13, 1, HSV_AZURE},
    {15, 1, HSV_AZURE},
    {26, 11, HSV_OTHER_TURQUOISE},
    {38, 2, HSV_OTHER_TURQUOISE},
    {20, 2, HSV_GOLDENROD},
    {45, 2, HSV_GOLDENROD}
);

const rgblight_segment_t PROGMEM random_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {22, 1, HSV_CORAL},
    {24, 1, HSV_CORAL},
    {32, 1, HSV_ORANGE},
    {33, 1, HSV_BLUE},
    {34, 1, HSV_YELLOW},
    {35, 1, HSV_WHITE},
    {38, 3, HSV_PINK},
    {41, 1, HSV_SPRINGGREEN},
    {45, 2, HSV_SPRINGGREEN},
    {49, 1, HSV_CHARTREUSE},
    {0, 6, HSV_PURPLE},
    {25, 6, HSV_PURPLE},
    {17,1, HSV_RED},
    {42,1, HSV_RED}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    lower_layer,
    numlock_layer,
    game_layer,
    normal_layer,
    numlock_active_layer,
    symbols_layer,
    random_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
    // Debugging
    /* debug_enable=true; */
    /* debug_matrix=true; */
    /* debug_keyboard=true; */
    /* debug_mouse=true; */
}

/* #include "print.h" */
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
// #endif
//   return true;
// }

layer_state_t default_layer_state_set_user(layer_state_t state) {
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(4, led_state.num_lock && IS_LAYER_ON(NUMLOCK));
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, get_highest_layer(state) == LOWER);
    led_t led_state = host_keyboard_led_state();
    bool numlock_state = get_highest_layer(state) == NUMLOCK;
    rgblight_set_layer_state(1, numlock_state);
    rgblight_set_layer_state(4, numlock_state && led_state.num_lock);
    rgblight_set_layer_state(2, get_highest_layer(state) == GAME);
    rgblight_set_layer_state(3, get_highest_layer(state) == NORMAL);
    rgblight_set_layer_state(5, get_highest_layer(state) == SYMBOLS);
    rgblight_set_layer_state(6, get_highest_layer(state) == RANDOM);
/* #ifdef CONSOLE_ENABLE */
/*     uprintf("SET CUSTOM color range!\n"); */
/*     rgblight_sethsv_range(HSV_RED, 0, 10); */
/*     rgblight_sethsv_range(HSV_GREEN, 20, 30); */
/*     rgblight_sethsv_range(HSV_PINK, 30, 40); */
/* #endif */
    return state;
}
