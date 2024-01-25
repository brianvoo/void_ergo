/* References
https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
https://github.com/qmk/qmk_firmware/blob/master/docs/mod_tap.md
https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes_basic.md
*/

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _RAISE,
    _LOWER,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
 

// Alt Tab
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum custom_keycodes {
  ALT_TAB = SAFE_RANGE,
};


// Tap Dance
enum {
    TD_0,
    TD_1,
    TD_2,
    TD_3,
    TD_4,
    TD_5,
    TD_6,
    TD_7,
    TD_8,
    TD_9,
    TD_F1,
    TD_F2,
    TD_F3,
    TD_F4,
    TD_F5,
    TD_F6,
    TD_F7,
    TD_F8,
    TD_F9,
    TD_TAB,
    TD_ESC,
    //X_CTL,
    // TD_RGHT_TAB,
};


typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;
 
td_state_t cur_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(tap_dance_state_t *state, void *user_data);
void x_reset(tap_dance_state_t *state, void *user_data);


// Combos
enum combos {
  // Left hand
  LR_SPC, 
  EQLQ_ESC,
  QW_ALTTAB,
  
  // Right hand
  COMMDOT_WIN,
  UD_BSPC,
};

const uint16_t PROGMEM lr_combo[] = {KC_LEFT, KC_RGHT, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_Q, TD(X_CTL), COMBO_END};
//const uint16_t PROGMEM alttab_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM win_combo[] = {RSFT_T(KC_SCLN), LSG_T(KC_QUOT), COMBO_END};
const uint16_t PROGMEM ud_combo[] = {KC_UP, KC_DOWN, COMBO_END};

combo_t key_combos[] = {
  [LR_SPC] = COMBO(lr_combo, KC_SPC),             // Left + Right = Space
  [EQLQ_ESC] = COMBO(esc_combo, KC_ESC),          // Equal + Q = Escape
  //[QW_ALTTAB] = COMBO(alttab_combo, ALT_TAB),     // Q + W = Alt + Tab Combo
  [COMMDOT_WIN] = COMBO(win_combo, KC_RGUI),     // Semicolon + Quote = Win
  [UD_BSPC] = COMBO(ud_combo, KC_BSPC),           // Up + Down = Backspace
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_3x6_5(
        TD(TD_ESC),      KC_Q,  KC_W,     KC_E,     KC_R,              KC_T,                                     KC_Y,    KC_U,    KC_I,     KC_O,    RCTL_T(KC_P),     LSA_T(KC_MINS),
        KC_LSFT,        KC_A,  KC_S,     KC_D,     KC_F,              KC_G,                                     KC_H,    KC_J,    KC_K,     KC_L,    RSFT_T(KC_SCLN),  LSG_T(KC_QUOT),
        CTL_T(KC_GRV),  KC_Z,  KC_X,     KC_C,     KC_V,              KC_B,                                     KC_N,    KC_M,    KC_COMM,  KC_DOT,  RGUI_T(KC_SLSH),  C_S_T(KC_BSLS),
                               KC_LEFT,  KC_RGHT,  LT(LOWER, KC_TAB), KC_BSPC, LALT_T(KC_DEL),     LT(RAISE, KC_RGUI),  KC_SPC,  KC_ENT,  KC_UP,    KC_DOWN
    ),

    [_LOWER] = LAYOUT_split_3x6_5(
        KC_HOME,    TD(TD_1),   TD(TD_2),   TD(TD_3),   TD(TD_4),   TD(TD_5),                        KC_TRNS,  KC_7,    KC_8,     KC_9,     KC_PPLS,   KC_TRNS,
        KC_END,     TD(TD_6),   TD(TD_7),   TD(TD_8),   TD(TD_9),   TD(TD_0),                        KC_TRNS,  KC_4,    KC_5,     KC_6,     KC_RSFT,   KC_PAST,
        KC_CAPS,    KC_INS,     KC_LBRC,    KC_RBRC,    KC_LCBR,    KC_RCBR,                         KC_TRNS,  KC_1,    KC_2,     KC_3,     KC_TRNS,   KC_DOT,
                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,     KC_BSPC,  KC_0,     KC_ENT,  KC_TRNS,  KC_TRNS
    ),

    [_RAISE] = LAYOUT_split_3x6_5(
        KC_TAB,         KC_HOME,  KC_UP,    KC_END,    KC_PGUP,   KC_TRNS,                        KC_TRNS,  TD(TD_F7),    TD(TD_F8),    TD(TD_F9),  KC_F10,  KC_TRNS,
        RCS_T(KC_LSFT), KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_PGDN,   KC_TRNS,                        KC_TRNS,  TD(TD_F4),    TD(TD_F5),    TD(TD_F6),  KC_F11,  KC_TRNS,
        KC_PSCR,        KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                        KC_TRNS,  TD(TD_F1),    TD(TD_F2),    TD(TD_F3),  KC_F12,  KC_TRNS,
                                  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    )

};


// Alt + Tab Special Macro
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) { 
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) { 
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}


// Quad Tap
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void x_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_EQL); break;
        case TD_SINGLE_HOLD: register_code(KC_LALT); break;
        case TD_DOUBLE_TAP: register_code(KC_TAB); break;
        case TD_DOUBLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_EQL); register_code(KC_EQL); break;
        default: break;
    }
}

void x_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_EQL); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LALT); break;
        case TD_DOUBLE_TAP: unregister_code(KC_TAB); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LCTL); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_EQL); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_0] = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_0),       // Single tap for '0', double tap for '('
    [TD_1] = ACTION_TAP_DANCE_DOUBLE(KC_EXLM, KC_1),       // Single tap for '1', double tap for '!'
    [TD_2] = ACTION_TAP_DANCE_DOUBLE(KC_AT, KC_2),         // Single tap for '2', double tap for '@'
    [TD_3] = ACTION_TAP_DANCE_DOUBLE(KC_HASH, KC_3),       // Single tap for '3', double tap for '#'
    [TD_4] = ACTION_TAP_DANCE_DOUBLE(KC_DLR, KC_4),        // Single tap for '4', double tap for '$'
    [TD_5] = ACTION_TAP_DANCE_DOUBLE(KC_PERC, KC_5),       // Single tap for '5', double tap for '%'
    [TD_6] = ACTION_TAP_DANCE_DOUBLE(KC_CIRC, KC_6),       // Single tap for '6', double tap for '^'
    [TD_7] = ACTION_TAP_DANCE_DOUBLE(KC_AMPR, KC_7),       // Single tap for '7', double tap for '&'
    [TD_8] = ACTION_TAP_DANCE_DOUBLE(KC_ASTR, KC_8),       // Single tap for '8', double tap for '*'
    [TD_9] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_9),       // Single tap for '9', double tap for '('
    [TD_F1] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_1),       
    [TD_F2] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_2),      
    [TD_F3] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_3),       
    [TD_F4] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_4),      
    [TD_F5] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_5),       
    [TD_F6] = ACTION_TAP_DANCE_DOUBLE(KC_F6, KC_6),       
    [TD_F7] = ACTION_TAP_DANCE_DOUBLE(KC_F7, KC_7),       
    [TD_F8] = ACTION_TAP_DANCE_DOUBLE(KC_F8, KC_8),       
    [TD_F9] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_9),       
    [TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_ESC),    
    // [TD_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_TAB),  // Single tap for Shift, double tap for Tab
    // [TD_RGHT_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_RGHT, KC_TAB),  // Single tap for Shift, double tap for Tab
};