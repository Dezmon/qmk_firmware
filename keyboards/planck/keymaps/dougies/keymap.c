//this used to be in ../keyboard/planck/config.h
#include "planck.h"
#include "keymap.h"
#include "keymap_colemak.h"

#define TAPPING_TOGGLE 2
//Tap Dance Declarations
enum {
  TD_BKSP= 0
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = { /* Doug hard-coded colemak */
  {KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_GRV},
  {TD(TD_BKSP),  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,   KC_ENT },
  {FUNC(0), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, FUNC(0)},
  {KC_TAB, KC_ESC, FUNC(3), FUNC(1),  OSL(2),    KC_SPC,   KC_SPC,    OSL(1),  FUNC(1), FUNC(3),  KC_TAB, KC_ESC}
},
[1] = { /* Doug RAISE */
  {KC_TRNS,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS},
  {KC_TRNS,  KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS, KC_MINS, KC_EQL,  KC_PLUS, KC_UNDS, KC_TRNS},
  {KC_TRNS, KC_BSLS,  KC_PIPE,  KC_GRAVE,  KC_QUOT,  S(KC_QUOT),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS}	,
  {KC_TRNS, FUNC(2), FUNC(4), KC_TRNS, KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS}
},
[2] = { /* Doug LOWER */
  {KC_TRNS,  S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), RESET},
  {KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,  KC_ESC, KC_TRNS},
  {KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS},
  {KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_BTN1,   KC_BTN1,   KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R}
}
};


void betterBKSP_finished(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code (KC_BSPC);
    break;
  case 2:
    register_code (KC_LALT);
    register_code (KC_BSPC);
  }
}
void betterBKSP_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    unregister_code (KC_BSPC);
    break;
  case 2:
    unregister_code (KC_LALT);
    unregister_code (KC_BSPC);
  }
}
//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_BKSP]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, betterBKSP_finished, betterBKSP_reset)
// Other declarations would go here, separated by commas, if you have them
};


const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_MODS_ONESHOT(MOD_LSFT),
    [1] = ACTION_MODS_ONESHOT(MOD_LCTL),
    [2] = ACTION_MODS_TAP_TOGGLE(MOD_LCTL),
    [3] = ACTION_MODS_ONESHOT(MOD_LALT),
    [4] = ACTION_MODS_TAP_TOGGLE(MOD_LALT),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
    switch(id) {
      case 0:
        return MACRODOWN(T(CM_T), END);
      break;
    }
    return MACRO_NONE;
};
