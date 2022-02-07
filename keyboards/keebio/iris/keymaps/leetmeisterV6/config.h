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

#ifndef RGBLIGHT_ENABLE
#    undef RGBLIGHT_ANIMATIONS
#    undef RGBLIGHT_EFFECT_BREATHING
#    undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#    undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    undef RGBLIGHT_EFFECT_SNAKE
#    undef RGBLIGHT_EFFECT_KNIGHT
#    undef RGBLIGHT_EFFECT_CHRISTMAS
#    undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#    undef RGBLIGHT_EFFECT_RGB_TEST
#    undef RGBLIGHT_EFFECT_ALTERNATING
#    undef RGBLIGHT_EFFECT_TWINKLE
#endif

#ifdef RGB_MATRIX_ENABLE
// Data sharing definitions used for custom RGB Matrix indicators
#    define SPLIT_LAYER_STATE_ENABLE
#    define SPLIT_LED_STATE_ENABLE
#    define SPLIT_MODS_ENABLE

#    define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BAND_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS

// #    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #    define ENABLE_RGB_MATRIX_TYPING_HEATMAP

// #    define RGB_MATRIX_KEYPRESSES
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #    define ENABLE_RGB_MATRIX_SPLASH
// #    define ENABLE_RGB_MATRIX_SOLID_SPLASH
#endif

#ifdef TAP_DANCE_ENABLE
#    define TAPPING_TERM 200
#    define ONESHOT_TAP_TOGGLE 2 /* Tapping this number of times holds the key until tapped once again. */
#    define ONESHOT_TIMEOUT 5000 /* Time (in ms) before the one shot key is released */
#endif
