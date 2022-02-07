/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_I2C

#define EE_HANDS

#ifdef LEADER_ENABLE
#    define LEADER_PER_KEY_TIMING
#    define LEADER_TIMEOUT 300
#endif

#ifdef MOUSEKEY_ENABLE
#    define MOUSEKEY_DELAY 100
#    define MOUSEKEY_INTERVAL 16
#    define MOUSEKEY_MAX_SPEED 10
#    define MOUSEKEY_TIME_TO_MAX 100
#    define MOUSEKEY_WHEEL_DELAY 100
#    define MOUSEKEY_WHEEL_INTERVAL 50
#    define MOUSEKEY_WHEEL_MAX_SPEED 24
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 40
#endif

#ifdef NKRO_ENABLE
#    define FORCE_NKRO
#endif

#ifdef RGBLIGHT_ENABLE
// #define RGBLIGHT_ANIMATIONS // Enables all effects
// #define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_HUE_STEP 4
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#endif

#ifdef TAP_DANCE_ENABLE
#    define TAPPING_TERM 200
#    define ONESHOT_TAP_TOGGLE 2 /* Tapping this number of times holds the key until tapped once again. */
#    define ONESHOT_TIMEOUT 5000 /* Time (in ms) before the one shot key is released */
#endif
