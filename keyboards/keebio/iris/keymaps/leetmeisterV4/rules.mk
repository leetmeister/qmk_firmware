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
BOOTLOADER = qmk-dfu

# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
AUDIO_ENABLE = no           # Audio output on port C6
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
COMBO_ENABLE = no           # Combos feature
COMMAND_ENABLE = no         # Commands for debug and configuration
CONSOLE_ENABLE = no         # Console for debug(+400)
ENCODER_ENABLE = yes        # Enable support for rotary encoders
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
KEY_LOCK_ENABLE = no        # Key lock (KC_LOCK)
LEADER_ENABLE = yes         # Leader key (KC_LEAD)
MIDI_ENABLE = no            # MIDI controls
MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend. DO NOT ENABLE as it uses the same timer as BACKLIGHT_ENABLE.
SPLIT_KEYBOARD = yes        # Enable split keyboard support
SWAP_HANDS_ENABLE = no      # Enable swap hands action (ACTION_SWAP_HANDS)
TAP_DANCE_ENABLE = no       # Tap Dance feature(+1000)
UNICODE_ENABLE = no         # Unicode
