# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu

# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
AUDIO_ENABLE = no           # Audio output on port C6
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
COMBO_ENABLE = no           # Combos feature
COMMAND_ENABLE = no         # Commands for debug and configuration
CONSOLE_ENABLE = no         # Console for debug(+400)
ENCODER_ENABLE = no         # Enable support for rotary encoders
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
KEY_LOCK_ENABLE = yes       # Key lock (KC_LOCK)
LEADER_ENABLE = no          # Leader key (KC_LEAD)
MIDI_ENABLE = no            # MIDI controls
MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
RGB_MATRIX_ENABLE = yes     # Enable per key RGB matrix (includes underglow LEDs for Iris rev6)
RGB_MATRIX_DRIVER = WS2812  # Specify driver for RGB matrix
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow (Use RGB_MATRIX instead and check for individual g_led_config.flags[] & LED_FLAG_UNDERGLOW)
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend. DO NOT ENABLE as it uses the same timer as BACKLIGHT_ENABLE.
SPLIT_KEYBOARD = yes        # Enable split keyboard support
SWAP_HANDS_ENABLE = no      # Enable swap hands action (ACTION_SWAP_HANDS)
TAP_DANCE_ENABLE = yes      # Tap Dance feature(+1000)
UNICODE_ENABLE = no         # Unicode

# Enable link time optimization to reduce firmware size
LTO_ENABLE = yes
