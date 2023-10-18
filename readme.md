# VOID Ergo S

A 3d printed, handwired, split keyboard with a layout similar to the Iris/Corne/Kyria by [Victor Lucachi](https://github.com/victorlucachi).

My QMK keycap with Tap Dance, Key Combos and more.

<pre>
    [_BASE] = LAYOUT_split_3x6_5(
        TD(X_CTL),      KC_Q,  KC_W,     KC_E,     KC_R,              KC_T,                                     KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,             LSA_T(KC_MINS),
        KC_LSFT,        KC_A,  KC_S,     KC_D,     KC_F,              KC_G,                                     KC_H,    KC_J,    KC_K,     KC_L,    RSFT_T(KC_SCLN),  LSG_T(KC_QUOT),
        CTL_T(KC_GRV),  KC_Z,  KC_X,     KC_C,     KC_V,              KC_B,                                     KC_N,    KC_M,    KC_COMM,  KC_DOT,  RGUI_T(KC_SLSH),  C_S_T(KC_BSLS),
                               KC_LEFT,  KC_RGHT,  LT(LOWER, KC_TAB), KC_BSPC, KC_DEL,     LT(RAISE, KC_RGUI),  KC_SPC,  KC_ENT,  KC_UP,    KC_DOWN  
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
</pre>