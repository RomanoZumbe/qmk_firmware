#include QMK_KEYBOARD_H
#include "../../../../quantum/keymap_extras/keymap_german.h"
#include "../../../../quantum/keymap_extras/sendstring_german.h"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    Qwerty,
    Nav,
    Mouse,
    Button,
    Fun,
    Sym,
    Media,
    Num,
    Emoji
};

enum custom_keycodes { KC_QWERTY = SAFE_RANGE, KC_COLEMAK, KC_LOWER, KC_RAISE, KC_ADJUST, KC_EMOJI, KC_PRVWD, KC_NXTWD, KC_LSTRT, KC_LEND, KC_DLINE, SS_CRYPT, SS_CIRC };

enum unicode_names {
    // German keycodes
    AUM,
    OUM,
    UUM,
    AUM_S,
    OUM_S,
    UUM_S,
    ESZ,
    EUR,
    // Emoticons
    BANG,
    IRONY,
    SNEK,
    LARGE_SMILE,
    GRIN,
    BIG_GRIN,
    SWEAT,
    ROFL,
    SMILE,
    WINK,
    PLEASED,
    LOVE,
    WINK_TONGUE,
    UNPLEASANT,
    SAD,
    VOMIT,
    COOL,
    FROWN,
    FEAR,
    CRY,
    SCREAM,
    CURSE,
    DEVIL_HAPPY,
    SHIT,
    CLOWN,
    SEE_NO_EVIL,
    THUMBS_UP,
    FOLDED_HANDS,
    BICEPS
};

const uint32_t PROGMEM unicode_map[] = {
    // German keycodes
    [AUM]   = 0x00E4,
    [OUM]   = 0x00F6,
    [UUM]   = 0x00FC,
    [AUM_S] = 0x00C4,
    [OUM_S] = 0x00D6,
    [UUM_S] = 0x00DC,
    [ESZ]   = 0x00DF,
    [EUR]   = 0x20AC,
    // Emoticons
    [BANG]         = 0x203D,
    [LARGE_SMILE]  = 0x1F603,
    [GRIN]         = 0x1F604,
    [BIG_GRIN]     = 0x1F601,
    [SWEAT]        = 0x1F605,
    [ROFL]         = 0x1F602,
    [SMILE]        = 0x1F642,
    [WINK]         = 0x1F609,
    [PLEASED]      = 0x1F60A,
    [LOVE]         = 0x1F60D,
    [WINK_TONGUE]  = 0x1F61C,
    [UNPLEASANT]   = 0x1F62C,
    [SAD]          = 0x1F614,
    [VOMIT]        = 0x1F922,
    [COOL]         = 0x1F60E,
    [FROWN]        = 0x1F641,
    [FEAR]         = 0x1F628,
    [CRY]          = 0x1F62D,
    [SCREAM]       = 0x1F631,
    [CURSE]        = 0x1F92C,
    [DEVIL_HAPPY]  = 0x1F608,
    [SHIT]         = 0x1F4A9,
    [CLOWN]        = 0x1F921,
    [SEE_NO_EVIL]  = 0x1F649,
    [THUMBS_UP]    = 0x1F44D,
    [FOLDED_HANDS] = 0x1F64F,
    [BICEPS]       = 0x1F4AA};

enum {
    TD_LOWER_EMOJI,
    TD_LOCK_LAYER,
};

void lock_layer(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 2:
            if (IS_LAYER_ON(Num)) {
                layer_clear();
            } else {
                layer_move(Num);
            }
            break;
        case 3:
            if (IS_LAYER_ON(Sym)) {
                layer_clear();
            } else {
                layer_move(Sym);
            }
            break;
        case 5:
            reset_keyboard();
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_LOCK_LAYER] = ACTION_TAP_DANCE_FN(lock_layer),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────┬──────────────────┬───────────────────┬───────────┬────────────────┬──────────────┐                                   ┌───────────────┬──────────────┬───────────┬───────────┬─────────┬──────────┐
//    │   esc   │        1         │         2         │     3     │       4        │      5       │                                   │       6       │      7       │     8     │     9     │    0    │ SS_CRYPT │
//    ├─────────┼──────────────────┼───────────────────┼───────────┼────────────────┼──────────────┤                                   ├───────────────┼──────────────┼───────────┼───────────┼─────────┼──────────┤
//    │   esc   │        q         │         w         │     e     │       r        │      t       │                                   │     DE_Y      │      u       │     i     │ ALGR_T(o) │    p    │   lgui   │
//    ├─────────┼──────────────────┼───────────────────┼───────────┼────────────────┼──────────────┤                                   ├───────────────┼──────────────┼───────────┼───────────┼─────────┼──────────┤
//    │  lgui   │        a         │         s         │ LCTL_T(d) │   LSFT_T(f)    │  LALT_T(g)   │                                   │       h       │  LSFT_T(j)   │ LCTL_T(k) │     l     │ DE_QUOT │   lalt   │
//    ├─────────┼──────────────────┼───────────────────┼───────────┼────────────────┼──────────────┼────────────────┐   ┌──────────────┼───────────────┼──────────────┼───────────┼───────────┼─────────┼──────────┤
//    │ SS_CIRC │ LT(Button, DE_Z) │         x         │     c     │       v        │      b       │      mute      │   │      no      │       n       │      m       │  DE_COMM  │  DE_DOT   │ DE_SLSH │    $     │
//    └─────────┴──────────────────┼───────────────────┼───────────┼────────────────┼──────────────┼────────────────┤   ├──────────────┼───────────────┼──────────────┼───────────┼───────────┼─────────┴──────────┘
//                                 │ TD(TD_LOCK_LAYER) │   lalt    │ LT(Media, esc) │ LT(Nav, ent) │ LT(Mouse, tab) │   │ LT(Sym, spc) │ LT(Num, bspc) │ LT(Fun, del) │   ralt    │   rgui    │                     
//                                 └───────────────────┴───────────┴────────────────┴──────────────┴────────────────┘   └──────────────┴───────────────┴──────────────┴───────────┴───────────┘                     
[Qwerty] = LAYOUT(
  KC_ESC  , KC_1             , KC_2              , KC_3         , KC_4              , KC_5            ,                                           KC_6             , KC_7            , KC_8         , KC_9         , KC_0    , SS_CRYPT,
  KC_ESC  , KC_Q             , KC_W              , KC_E         , KC_R              , KC_T            ,                                           DE_Y             , KC_U            , KC_I         , ALGR_T(KC_O) , KC_P    , KC_LGUI ,
  KC_LGUI , KC_A             , KC_S              , LCTL_T(KC_D) , LSFT_T(KC_F)      , LALT_T(KC_G)    ,                                           KC_H             , LSFT_T(KC_J)    , LCTL_T(KC_K) , KC_L         , DE_QUOT , KC_LALT ,
  SS_CIRC , LT(Button, DE_Z) , KC_X              , KC_C         , KC_V              , KC_B            , KC_MUTE           ,     XXXXXXX         , KC_N             , KC_M            , DE_COMM      , DE_DOT       , DE_SLSH , KC_DLR  ,
                               TD(TD_LOCK_LAYER) , KC_LALT      , LT(Media, KC_ESC) , LT(Nav, KC_ENT) , LT(Mouse, KC_TAB) ,     LT(Sym, KC_SPC) , LT(Num, KC_BSPC) , LT(Fun, KC_DEL) , KC_RALT      , KC_RGUI                          
),

//    ┌─────────┬──────────────────┬───────────────────┬───────────┬────────────────┬──────────────┐                          ┌──────┬──────┬──────┬──────┬─────────┬──────────┐
//    │   esc   │        1         │         2         │     3     │       4        │      5       │                          │  6   │  7   │  8   │  9   │    0    │ SS_CRYPT │
//    ├─────────┼──────────────────┼───────────────────┼───────────┼────────────────┼──────────────┤                          ├──────┼──────┼──────┼──────┼─────────┼──────────┤
//    │   esc   │    LGUI_T(q)     │         w         │     e     │       r        │     pscr     │                          │ DE_Y │  u   │  i   │  o   │    p    │   esc    │
//    ├─────────┼──────────────────┼───────────────────┼───────────┼────────────────┼──────────────┤                          ├──────┼──────┼──────┼──────┼─────────┼──────────┤
//    │ SS_CIRC │        a         │         s         │ LCTL_T(d) │   LSFT_T(f)    │      g       │                          │ left │ down │  up  │ rght │ DE_QUOT │    $     │
//    ├─────────┼──────────────────┼───────────────────┼───────────┼────────────────┼──────────────┼────────────────┐   ┌─────┼──────┼──────┼──────┼──────┼─────────┼──────────┤
//    │   esc   │ LT(Button, DE_Z) │     LALT_T(x)     │     c     │       v        │      b       │      mute      │   │ no  │ home │ pgdn │ pgup │ end  │   ins   │   esc    │
//    └─────────┴──────────────────┼───────────────────┼───────────┼────────────────┼──────────────┼────────────────┤   ├─────┼──────┼──────┼──────┼──────┼─────────┴──────────┘
//                                 │ TD(TD_LOCK_LAYER) │   lalt    │ LT(Media, esc) │ LT(Nav, ent) │ LT(Mouse, tab) │   │ spc │ bspc │ del  │ ralt │ rgui │                     
//                                 └───────────────────┴───────────┴────────────────┴──────────────┴────────────────┘   └─────┴──────┴──────┴──────┴──────┘                     
[Nav] = LAYOUT(
  KC_ESC  , KC_1             , KC_2              , KC_3         , KC_4              , KC_5            ,                                   KC_6    , KC_7    , KC_8    , KC_9     , KC_0    , SS_CRYPT,
  KC_ESC  , LGUI_T(KC_Q)     , KC_W              , KC_E         , KC_R              , KC_PSCR         ,                                   DE_Y    , KC_U    , KC_I    , KC_O     , KC_P    , KC_ESC  ,
  SS_CIRC , KC_A             , KC_S              , LCTL_T(KC_D) , LSFT_T(KC_F)      , KC_G            ,                                   KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , DE_QUOT , KC_DLR  ,
  KC_ESC  , LT(Button, DE_Z) , LALT_T(KC_X)      , KC_C         , KC_V              , KC_B            , KC_MUTE           ,     XXXXXXX , KC_HOME , KC_PGDN , KC_PGUP , KC_END   , KC_INS  , KC_ESC  ,
                               TD(TD_LOCK_LAYER) , KC_LALT      , LT(Media, KC_ESC) , LT(Nav, KC_ENT) , LT(Mouse, KC_TAB) ,     KC_SPC  , KC_BSPC , KC_DEL  , KC_RALT , KC_RGUI                      
),

//    ┌─────────┬──────────────────┬───────────────────┬───────────┬────────────────┬──────────────┐                           ┌──────┬─────────┬──────┬─────────┬─────────┬──────────┐
//    │   esc   │        1         │         2         │     3     │       4        │      5       │                           │  6   │    7    │  8   │    9    │    0    │ SS_CRYPT │
//    ├─────────┼──────────────────┼───────────────────┼───────────┼────────────────┼──────────────┤                           ├──────┼─────────┼──────┼─────────┼─────────┼──────────┤
//    │   esc   │    LGUI_T(q)     │         w         │     e     │       r        │      t       │                           │ DE_Y │ DE_UDIA │ ms_u │ DE_ODIA │    p    │   esc    │
//    ├─────────┼──────────────────┼───────────────────┼───────────┼────────────────┼──────────────┤                           ├──────┼─────────┼──────┼─────────┼─────────┼──────────┤
//    │ SS_CIRC │     DE_ADIA      │       DE_SS       │ LCTL_T(d) │   LSFT_T(f)    │      g       │                           │ left │  ms_l   │ ms_d │  ms_r   │ DE_QUOT │    $     │
//    ├─────────┼──────────────────┼───────────────────┼───────────┼────────────────┼──────────────┼────────────────┐   ┌──────┼──────┼─────────┼──────┼─────────┼─────────┼──────────┤
//    │   esc   │ LT(Button, DE_Z) │     LALT_T(x)     │     c     │       v        │      b       │      mute      │   │  no  │ wh_l │  wh_d   │ wh_u │  wh_r   │   ins   │   esc    │
//    └─────────┴──────────────────┼───────────────────┼───────────┼────────────────┼──────────────┼────────────────┤   ├──────┼──────┼─────────┼──────┼─────────┼─────────┴──────────┘
//                                 │ TD(TD_LOCK_LAYER) │   lalt    │ LT(Media, esc) │ LT(Nav, ent) │ LT(Mouse, tab) │   │ btn2 │ btn1 │  btn3   │ ralt │  rgui   │                     
//                                 └───────────────────┴───────────┴────────────────┴──────────────┴────────────────┘   └──────┴──────┴─────────┴──────┴─────────┘                     
[Mouse] = LAYOUT(
  KC_ESC  , KC_1             , KC_2              , KC_3         , KC_4              , KC_5            ,                                   KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , SS_CRYPT,
  KC_ESC  , LGUI_T(KC_Q)     , KC_W              , KC_E         , KC_R              , KC_T            ,                                   DE_Y    , DE_UDIA , KC_MS_U , DE_ODIA , KC_P    , KC_ESC  ,
  SS_CIRC , DE_ADIA          , DE_SS             , LCTL_T(KC_D) , LSFT_T(KC_F)      , KC_G            ,                                   KC_LEFT , KC_MS_L , KC_MS_D , KC_MS_R , DE_QUOT , KC_DLR  ,
  KC_ESC  , LT(Button, DE_Z) , LALT_T(KC_X)      , KC_C         , KC_V              , KC_B            , KC_MUTE           ,     XXXXXXX , KC_WH_L , KC_WH_D , KC_WH_U , KC_WH_R , KC_INS  , KC_ESC  ,
                               TD(TD_LOCK_LAYER) , KC_LALT      , LT(Media, KC_ESC) , LT(Nav, KC_ENT) , LT(Mouse, KC_TAB) ,     KC_BTN2 , KC_BTN1 , KC_BTN3 , KC_RALT , KC_RGUI                     
),

//    ┌─────────┬──────────────────┬───────────────────┬───────────┬────────────────┬──────────────┐                           ┌─────────┬─────────┬─────────┬─────────┬─────────┬──────────┐
//    │   esc   │        1         │         2         │     3     │       4        │      5       │                           │    6    │    7    │    8    │    9    │    0    │ SS_CRYPT │
//    ├─────────┼──────────────────┼───────────────────┼───────────┼────────────────┼──────────────┤                           ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │   esc   │    LGUI_T(q)     │         w         │     e     │       r        │      t       │                           │ RGB_MOD │ RGB_HUI │ RGB_SAI │ RGB_VAI │ RGB_TOG │   esc    │
//    ├─────────┼──────────────────┼───────────────────┼───────────┼────────────────┼──────────────┤                           ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │ SS_CIRC │     DE_ADIA      │       DE_SS       │ LCTL_T(d) │   LSFT_T(f)    │      g       │                           │  mprv   │  vold   │  volu   │  mnxt   │   esc   │   esc    │
//    ├─────────┼──────────────────┼───────────────────┼───────────┼────────────────┼──────────────┼────────────────┐   ┌──────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │   esc   │ LT(Button, DE_Z) │     LALT_T(x)     │     c     │       v        │      b       │      mute      │   │  no  │  wh_l   │  wh_d   │  wh_u   │  wh_r   │   ins   │   esc    │
//    └─────────┴──────────────────┼───────────────────┼───────────┼────────────────┼──────────────┼────────────────┤   ├──────┼─────────┼─────────┼─────────┼─────────┼─────────┴──────────┘
//                                 │ TD(TD_LOCK_LAYER) │   lalt    │ LT(Media, esc) │ LT(Nav, ent) │ LT(Mouse, tab) │   │ mstp │  mply   │  mute   │  ralt   │  rgui   │                     
//                                 └───────────────────┴───────────┴────────────────┴──────────────┴────────────────┘   └──────┴─────────┴─────────┴─────────┴─────────┘                     
[Media] = LAYOUT(
  KC_ESC  , KC_1             , KC_2              , KC_3         , KC_4              , KC_5            ,                                   KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , SS_CRYPT,
  KC_ESC  , LGUI_T(KC_Q)     , KC_W              , KC_E         , KC_R              , KC_T            ,                                   RGB_MOD , RGB_HUI , RGB_SAI , RGB_VAI , RGB_TOG , KC_ESC  ,
  SS_CIRC , DE_ADIA          , DE_SS             , LCTL_T(KC_D) , LSFT_T(KC_F)      , KC_G            ,                                   KC_MPRV , KC_VOLD , KC_VOLU , KC_MNXT , KC_ESC  , KC_ESC  ,
  KC_ESC  , LT(Button, DE_Z) , LALT_T(KC_X)      , KC_C         , KC_V              , KC_B            , KC_MUTE           ,     XXXXXXX , KC_WH_L , KC_WH_D , KC_WH_U , KC_WH_R , KC_INS  , KC_ESC  ,
                               TD(TD_LOCK_LAYER) , KC_LALT      , LT(Media, KC_ESC) , LT(Nav, KC_ENT) , LT(Mouse, KC_TAB) ,     KC_MSTP , KC_MPLY , KC_MUTE , KC_RALT , KC_RGUI                     
),

//    ┌─────────┬─────────┬───────────────────┬──────┬────────┬─────────┐                   ┌─────────┬─────────┬─────────┬─────────┬─────────┬──────────┐
//    │   esc   │    1    │         2         │  3   │   4    │    5    │                   │    6    │    7    │    8    │    9    │    0    │ SS_CRYPT │
//    ├─────────┼─────────┼───────────────────┼──────┼────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │   esc   │ DE_LBRC │         7         │  8   │   9    │ DE_RBRC │                   │ RGB_MOD │ RGB_HUI │ RGB_SAI │ RGB_VAI │ RGB_TOG │   esc    │
//    ├─────────┼─────────┼───────────────────┼──────┼────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │ SS_CIRC │ DE_SCLN │         4         │  5   │   6    │ DE_EQL  │                   │ DM_RSTP │ DM_REC1 │ DM_REC2 │  mnxt   │   esc   │   esc    │
//    ├─────────┼─────────┼───────────────────┼──────┼────────┼─────────┼─────────┐   ┌─────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │   esc   │ DE_GRV  │         1         │  2   │   3    │ DE_BSLS │  mute   │   │ no  │  wh_l   │ DM_PLY1 │ DM_PLY2 │  wh_r   │   ins   │   esc    │
//    └─────────┴─────────┼───────────────────┼──────┼────────┼─────────┼─────────┤   ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┴──────────┘
//                        │ TD(TD_LOCK_LAYER) │ lalt │ DE_DOT │    0    │ DE_MINS │   │ spc │  bspc   │   del   │   ent   │  rgui   │                     
//                        └───────────────────┴──────┴────────┴─────────┴─────────┘   └─────┴─────────┴─────────┴─────────┴─────────┘                     
[Num] = LAYOUT(
  KC_ESC  , KC_1    , KC_2              , KC_3    , KC_4   , KC_5    ,                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , SS_CRYPT,
  KC_ESC  , DE_LBRC , KC_7              , KC_8    , KC_9   , DE_RBRC ,                         RGB_MOD , RGB_HUI , RGB_SAI , RGB_VAI , RGB_TOG , KC_ESC  ,
  SS_CIRC , DE_SCLN , KC_4              , KC_5    , KC_6   , DE_EQL  ,                         DM_RSTP , DM_REC1 , DM_REC2 , KC_MNXT , KC_ESC  , KC_ESC  ,
  KC_ESC  , DE_GRV  , KC_1              , KC_2    , KC_3   , DE_BSLS , KC_MUTE ,     XXXXXXX , KC_WH_L , DM_PLY1 , DM_PLY2 , KC_WH_R , KC_INS  , KC_ESC  ,
                      TD(TD_LOCK_LAYER) , KC_LALT , DE_DOT , KC_0    , DE_MINS ,     KC_SPC  , KC_BSPC , KC_DEL  , KC_ENT  , KC_RGUI                     
),

//    ┌─────────┬─────────┬───────────────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬──────────┐
//    │   esc   │    1    │         2         │    3    │    4    │    5    │                    │    6    │    7    │    8    │    9    │    0    │ SS_CRYPT │
//    ├─────────┼─────────┼───────────────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │   esc   │ DE_LCBR │      DE_AMPR      │ DE_ASTR │ DE_LPRN │ DE_RCBR │                    │ RGB_MOD │ RGB_HUI │ RGB_SAI │ RGB_VAI │ RGB_TOG │   esc    │
//    ├─────────┼─────────┼───────────────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │ SS_CIRC │ DE_COLN │      DE_DLR       │ DE_PERC │ DE_CIRC │ DE_PLUS │                    │  mprv   │  vold   │  volu   │  mnxt   │   esc   │   esc    │
//    ├─────────┼─────────┼───────────────────┼─────────┼─────────┼─────────┼─────────┐   ┌──────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │   esc   │ DE_TILD │      DE_EXLM      │  DE_AT  │ DE_HASH │ DE_PIPE │  mute   │   │  no  │  wh_l   │  wh_d   │  wh_u   │  wh_r   │   ins   │   esc    │
//    └─────────┴─────────┼───────────────────┼─────────┼─────────┼─────────┼─────────┤   ├──────┼─────────┼─────────┼─────────┼─────────┼─────────┴──────────┘
//                        │ TD(TD_LOCK_LAYER) │  lalt   │ DE_LPRN │ DE_RPRN │ DE_UNDS │   │ mstp │  mply   │  mute   │  ralt   │  rgui   │                     
//                        └───────────────────┴─────────┴─────────┴─────────┴─────────┘   └──────┴─────────┴─────────┴─────────┴─────────┘                     
[Sym] = LAYOUT(
  KC_ESC  , KC_1    , KC_2              , KC_3    , KC_4    , KC_5    ,                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , SS_CRYPT,
  KC_ESC  , DE_LCBR , DE_AMPR           , DE_ASTR , DE_LPRN , DE_RCBR ,                         RGB_MOD , RGB_HUI , RGB_SAI , RGB_VAI , RGB_TOG , KC_ESC  ,
  SS_CIRC , DE_COLN , DE_DLR            , DE_PERC , DE_CIRC , DE_PLUS ,                         KC_MPRV , KC_VOLD , KC_VOLU , KC_MNXT , KC_ESC  , KC_ESC  ,
  KC_ESC  , DE_TILD , DE_EXLM           , DE_AT   , DE_HASH , DE_PIPE , KC_MUTE ,     XXXXXXX , KC_WH_L , KC_WH_D , KC_WH_U , KC_WH_R , KC_INS  , KC_ESC  ,
                      TD(TD_LOCK_LAYER) , KC_LALT , DE_LPRN , DE_RPRN , DE_UNDS ,     KC_MSTP , KC_MPLY , KC_MUTE , KC_RALT , KC_RGUI                     
),

//    ┌─────────┬─────┬───────────────────┬──────┬─────┬─────────────┐                 ┌─────────┬─────────┬─────────┬─────────┬─────────┬──────────┐
//    │   esc   │  1  │         2         │  3   │  4  │      5      │                 │    6    │    7    │    8    │    9    │    0    │ SS_CRYPT │
//    ├─────────┼─────┼───────────────────┼──────┼─────┼─────────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │   esc   │ f12 │        f7         │  f8  │ f9  │    pscr     │                 │ RGB_MOD │ RGB_HUI │ RGB_SAI │ RGB_VAI │ RGB_TOG │   esc    │
//    ├─────────┼─────┼───────────────────┼──────┼─────┼─────────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │ SS_CIRC │ f11 │        f4         │  f5  │ f6  │ sCROLL_LOCK │                 │  mprv   │  vold   │  volu   │  mnxt   │   esc   │   esc    │
//    ├─────────┼─────┼───────────────────┼──────┼─────┼─────────────┼──────┐   ┌──────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │   esc   │ f10 │        f1         │  f2  │ f3  │    paus     │ mute │   │  no  │  wh_l   │  wh_d   │  wh_u   │  wh_r   │   ins   │   esc    │
//    └─────────┴─────┼───────────────────┼──────┼─────┼─────────────┼──────┤   ├──────┼─────────┼─────────┼─────────┼─────────┼─────────┴──────────┘
//                    │ TD(TD_LOCK_LAYER) │ lalt │ app │     spc     │ tab  │   │ mstp │  mply   │  mute   │  ralt   │  rgui   │                     
//                    └───────────────────┴──────┴─────┴─────────────┴──────┘   └──────┴─────────┴─────────┴─────────┴─────────┘                     
[Fun] = LAYOUT(
  KC_ESC  , KC_1   , KC_2              , KC_3    , KC_4   , KC_5           ,                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , SS_CRYPT,
  KC_ESC  , KC_F12 , KC_F7             , KC_F8   , KC_F9  , KC_PSCR        ,                         RGB_MOD , RGB_HUI , RGB_SAI , RGB_VAI , RGB_TOG , KC_ESC  ,
  SS_CIRC , KC_F11 , KC_F4             , KC_F5   , KC_F6  , KC_SCROLL_LOCK ,                         KC_MPRV , KC_VOLD , KC_VOLU , KC_MNXT , KC_ESC  , KC_ESC  ,
  KC_ESC  , KC_F10 , KC_F1             , KC_F2   , KC_F3  , KC_PAUS        , KC_MUTE ,     XXXXXXX , KC_WH_L , KC_WH_D , KC_WH_U , KC_WH_R , KC_INS  , KC_ESC  ,
                     TD(TD_LOCK_LAYER) , KC_LALT , KC_APP , KC_SPC         , KC_TAB  ,     KC_MSTP , KC_MPLY , KC_MUTE , KC_RALT , KC_RGUI                     
),

//    ┌─────────┬─────────┬───────────────────┬──────┬──────┬─────────────┐                 ┌─────────┬─────────┬─────────┬─────────┬─────────┬──────────┐
//    │   esc   │    1    │         2         │  3   │  4   │      5      │                 │    6    │    7    │    8    │    9    │    0    │ SS_CRYPT │
//    ├─────────┼─────────┼───────────────────┼──────┼──────┼─────────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │   esc   │ C(DE_Z) │       C(x)        │ C(c) │ C(v) │   C(DE_Y)   │                 │ RGB_MOD │ RGB_HUI │ RGB_SAI │ RGB_VAI │ RGB_TOG │   esc    │
//    ├─────────┼─────────┼───────────────────┼──────┼──────┼─────────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │ SS_CIRC │   f11   │        f4         │  f5  │  f6  │ sCROLL_LOCK │                 │  mprv   │  vold   │  volu   │  mnxt   │   esc   │   esc    │
//    ├─────────┼─────────┼───────────────────┼──────┼──────┼─────────────┼──────┐   ┌──────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │   esc   │   f10   │        f1         │  f2  │  f3  │    paus     │ mute │   │  no  │  wh_l   │  wh_d   │  wh_u   │  wh_r   │   ins   │   esc    │
//    └─────────┴─────────┼───────────────────┼──────┼──────┼─────────────┼──────┤   ├──────┼─────────┼─────────┼─────────┼─────────┼─────────┴──────────┘
//                        │ TD(TD_LOCK_LAYER) │ lalt │ app  │     spc     │ tab  │   │ mstp │  mply   │  mute   │  ralt   │  rgui   │                     
//                        └───────────────────┴──────┴──────┴─────────────┴──────┘   └──────┴─────────┴─────────┴─────────┴─────────┘                     
[Button] = LAYOUT(
  KC_ESC  , KC_1    , KC_2              , KC_3    , KC_4    , KC_5           ,                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , SS_CRYPT,
  KC_ESC  , C(DE_Z) , C(KC_X)           , C(KC_C) , C(KC_V) , C(DE_Y)        ,                         RGB_MOD , RGB_HUI , RGB_SAI , RGB_VAI , RGB_TOG , KC_ESC  ,
  SS_CIRC , KC_F11  , KC_F4             , KC_F5   , KC_F6   , KC_SCROLL_LOCK ,                         KC_MPRV , KC_VOLD , KC_VOLU , KC_MNXT , KC_ESC  , KC_ESC  ,
  KC_ESC  , KC_F10  , KC_F1             , KC_F2   , KC_F3   , KC_PAUS        , KC_MUTE ,     XXXXXXX , KC_WH_L , KC_WH_D , KC_WH_U , KC_WH_R , KC_INS  , KC_ESC  ,
                      TD(TD_LOCK_LAYER) , KC_LALT , KC_APP  , KC_SPC         , KC_TAB  ,     KC_MSTP , KC_MPLY , KC_MUTE , KC_RALT , KC_RGUI                     
),

//    ┌──────┬──────┬───────────────────┬──────┬──────┬─────┐                             ┌───────┬──────────┬─────────┬──────────────┬─────────┬──────┐
//    │  `   │  1   │         2         │  3   │  4   │  5  │                             │   6   │    7     │    8    │      9       │    0    │  `   │
//    ├──────┼──────┼───────────────────┼──────┼──────┼─────┤                             ├───────┼──────────┼─────────┼──────────────┼─────────┼──────┤
//    │ esc  │  q   │         w         │  e   │  r   │  t  │                             │ DE_Y  │    u     │    i    │      o       │    p    │ bspc │
//    ├──────┼──────┼───────────────────┼──────┼──────┼─────┤                             ├───────┼──────────┼─────────┼──────────────┼─────────┼──────┤
//    │ tab  │  a   │         s         │  d   │  f   │  g  │                             │   h   │ X(SWEAT) │ X(GRIN) │ X(THUMBS_UP) │ X(ROFL) │  '   │
//    ├──────┼──────┼───────────────────┼──────┼──────┼─────┼───────────────────┐   ┌─────┼───────┼──────────┼─────────┼──────────────┼─────────┼──────┤
//    │ lsft │ DE_Z │         x         │  c   │  v   │  b  │       mute        │   │ no  │   n   │    m     │    ,    │      .       │    /    │ rsft │
//    └──────┴──────┼───────────────────┼──────┼──────┼─────┼───────────────────┤   ├─────┼───────┼──────────┼─────────┼──────────────┼─────────┴──────┘
//                  │ TD(TD_LOCK_LAYER) │ lalt │ lctl │     │ MT(MOD_LSFT, ent) │   │ spc │ rAISE │   rctl   │  ralt   │     rgui     │                 
//                  └───────────────────┴──────┴──────┴─────┴───────────────────┘   └─────┴───────┴──────────┴─────────┴──────────────┘                 
[Emoji] = LAYOUT(
  KC_GRV  , KC_1 , KC_2              , KC_3    , KC_4    , KC_5    ,                                      KC_6     , KC_7     , KC_8    , KC_9         , KC_0    , KC_GRV ,
  KC_ESC  , KC_Q , KC_W              , KC_E    , KC_R    , KC_T    ,                                      DE_Y     , KC_U     , KC_I    , KC_O         , KC_P    , KC_BSPC,
  KC_TAB  , KC_A , KC_S              , KC_D    , KC_F    , KC_G    ,                                      KC_H     , X(SWEAT) , X(GRIN) , X(THUMBS_UP) , X(ROFL) , KC_QUOT,
  KC_LSFT , DE_Z , KC_X              , KC_C    , KC_V    , KC_B    , KC_MUTE              ,     XXXXXXX , KC_N     , KC_M     , KC_COMM , KC_DOT       , KC_SLSH , KC_RSFT,
                   TD(TD_LOCK_LAYER) , KC_LALT , KC_LCTL , _______ , MT(MOD_LSFT, KC_ENT) ,     KC_SPC  , KC_RAISE , KC_RCTL  , KC_RALT , KC_RGUI                         
)
};

// const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CAPSWRD, KC_CAPS);
const key_override_t slsh_ques_override = ko_make_basic(MOD_MASK_SHIFT, DE_SLSH, DE_QUES);
const key_override_t slsh_scln_coln     = ko_make_basic(MOD_MASK_SHIFT, DE_SCLN, DE_COLN);
const key_override_t slsh_comm_labk     = ko_make_basic(MOD_MASK_SHIFT, DE_COMM, DE_LABK);
const key_override_t slsh_dot_rabk      = ko_make_basic(MOD_MASK_SHIFT, DE_DOT, DE_RABK);
const key_override_t slsh_quot_dquo     = ko_make_basic(MOD_MASK_SHIFT, DE_QUOT, DE_DQUO);

const key_override_t **key_overrides = (const key_override_t *[]){&slsh_ques_override, &slsh_ques_override, &slsh_scln_coln, &slsh_comm_labk, &slsh_dot_rabk, &slsh_quot_dquo, NULL};

#ifdef OLED_ENABLE

static void render_logo_inq(void) {
    static const char PROGMEM inq_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0xf8, 0xf8, 0xe0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x40, 0x78, 0x78, 0x78, 0x00, 0x7c, 0x7c, 0x7c, 0x00, 0x78, 0x78, 0x78, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x80, 0x80, 0xc0, 0xe0, 0xf8, 0xf8, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x87, 0xf3, 0xf9, 0x3c, 0x0e, 0x1e, 0x83, 0x83, 0xfd, 0x7d, 0xff, 0x03, 0x05, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x04, 0x09, 0xf3, 0x87, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xe1, 0xcf, 0xbf, 0x79, 0x70, 0xf0, 0xc1, 0x81, 0xbd, 0xbe, 0xff, 0xc0, 0xa0, 0xa0, 0x80, 0x80, 0x80, 0x80, 0x40, 0x60, 0xb0, 0xce, 0xe3, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x1e, 0x1e, 0x1c, 0x00, 0x7e, 0x7e, 0x7e, 0x00, 0x1e, 0x1e, 0x1e, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    // char line[16][32];
    // char PROGMEM out[512];
    // for(int y=0;y<=15;y++)
    //   {
    //     for(int z=0;z<=31;z++)
    //       {
    //         line[y][z]=qmk_logo[y+(z*16)];
    //       }
    //   }
    //
    // for(int y=0;y<=15;y++)
    //   {
    //     for(int z=0;z<=31;z++)
    //       {
    //         out[y+(z*16)] = line[y][z];
    //       }
    //   }

    // static const char PROGMEM logo[] = out;
    // oled_write_P(qmk_logo, false);
    oled_write_raw_P(inq_logo, sizeof(inq_logo));
}

// static void render_logo_cyb(void) {
//     static const char PROGMEM cyb_logo[] = {// 'cyb', 128x32px
//                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0x70, 0x70, 0x70, 0x78, 0x70, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0x78, 0x3c, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                                             0x00, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0xf8, 0xfc, 0xfc, 0xde, 0xce, 0xcf, 0xe7, 0xe7, 0xe3, 0xe3, 0xe1, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x7c, 0x7c, 0xe0, 0xf0, 0xf0, 0xf8, 0xfc, 0xfc, 0xec, 0xf0, 0x78, 0xbe, 0xdf, 0xdf, 0xff, 0x7d, 0x7c, 0xf8, 0xf8, 0xf8, 0x7c, 0x7c, 0x7c, 0x7c, 0xfc, 0xac, 0x3c, 0x8c, 0xec, 0xfc, 0xfc, 0xcc, 0xec, 0xec, 0xec, 0xec, 0xfc, 0x7c, 0x7c, 0x3c, 0x3c, 0x3c, 0x1c, 0x18, 0x80, 0xe0, 0xf8, 0xfc, 0xfc, 0xdc, 0xdc, 0xdc, 0xec, 0xec, 0x7c, 0x7c, 0xfc, 0xfc, 0xfc, 0x3c, 0x1e, 0x9e, 0xce, 0xe0, 0xf8, 0x3c, 0xdf, 0xf0, 0xf8, 0xf8, 0xe0, 0x80, 0xe0, 0xf8, 0x7c, 0xdc, 0xe0, 0xf8, 0xfe, 0xfe, 0xf6, 0xf0, 0xf8, 0x98, 0x9c, 0x0c, 0x0e, 0x06, 0x07, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                                             0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xc1, 0xe1, 0xf1, 0x79, 0x3e, 0x1f, 0x07, 0x03, 0x05, 0x0e, 0x1f, 0x1f, 0x1f, 0x0f, 0x07, 0x03, 0x03, 0x01, 0x00, 0x02, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x03, 0x19, 0x3e, 0x1f, 0x07, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x0e, 0x9e, 0xee, 0xff, 0xff, 0x3f, 0x0f, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x1f, 0x0f, 0x0e, 0x06, 0x0f, 0x1f, 0x0f, 0x03, 0x0c, 0x07, 0x07, 0x03, 0x00, 0x07, 0x0f, 0x0f, 0x03, 0x00, 0x0e, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x07, 0x0e, 0x0c, 0x1c, 0x18, 0x30, 0x30, 0x60, 0x60, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00,
//                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x04, 0x02, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x38, 0x0e, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x02, 0x00};
//
//     // char line[16][32];
//     // char PROGMEM out[512];
//     // for(int y=0;y<=15;y++)
//     //   {
//     //     for(int z=0;z<=31;z++)
//     //       {
//     //         line[y][z]=qmk_logo[y+(z*16)];
//     //       }
//     //   }
//     //
//     // for(int y=0;y<=15;y++)
//     //   {
//     //     for(int z=0;z<=31;z++)
//     //       {
//     //         out[y+(z*16)] = line[y][z];
//     //       }
//     //   }
//
//     // static const char PROGMEM logo[] = out;
//     // oled_write_P(qmk_logo, false);
//     oled_write_raw_P(cyb_logo, sizeof(cyb_logo));
// }

// static void print_status_narrow(void) {
//     // Print current mode
//     oled_write_P(PSTR("\n\n"), false);
//     oled_write_ln_P(PSTR("MODE"), false);
//     oled_write_ln_P(PSTR(""), false);
//     // if (keymap_config.swap_lctl_lgui) {
//     //     oled_write_ln_P(PSTR("MAC"), false);
//     // } else {
//     //     oled_write_ln_P(PSTR("WIN"), false);
//     // }
//
//     // switch (get_highest_layer(default_layer_state)) {
//     //     case _QWERTY:
//     //         oled_write_ln_P(PSTR("Qwrt"), false);
//     //         break;
//     //     case _COLEMAK:
//     //         oled_write_ln_P(PSTR("Clmk"), false);
//     //         break;
//     //     default:
//     //         oled_write_P(PSTR("Undef"), false);
//     // }
//     // oled_write_P(PSTR("\n\n"), false);
//     // Print current layer
//     // oled_write_ln_P(PSTR("LAYER"), false);
//     // switch (get_highest_layer(layer_state)) {
//     //     case U_BASE:
//     //         oled_write_P(PSTR("Base\n"), false);
//     //         break;
//     //     case U_SYM:
//     //         oled_write_P(PSTR("Sym\n"), false);
//     //         break;
//     //     case U_NUM:
//     //         oled_write_P(PSTR("Num\n"), false);
//     //         break;
//     //     case U_NAV:
//     //         oled_write_P(PSTR("Nav\n"), false);
//     //         break;
//     //     default:
//     //         oled_write_ln_P(PSTR("Undef\n"), false);
//     // }
// }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // if (is_keyboard_master()) {
    //     return OLED_ROTATION_270;
    // }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // print_status_narrow();
        // render_logo_cyb();
        render_logo_inq();
    } else {
        render_logo_inq();
        // render_logo_cyb();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SS_CRYPT:
            if (record->event.pressed) {
                SEND_STRING("3NV1jY~-PO@n70J=");
            }
            return false;
        case SS_CIRC:
            if (record->event.pressed) {
                SEND_STRING("^");
            }
            return false;
    }

    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
