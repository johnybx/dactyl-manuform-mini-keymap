# Bootloader selection
BOOTLOADER = rp2040

SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys - disabled to lower firmware size
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
UNICODE_ENABLE = yes        # Unicode support
SPLIT_KEYBOARD = yes
AUTO_SHIFT_ENABLE = yes
TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes

# TODO: check this
# RP2040-specific options
# PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS.
