# Bootloader selection


# Build Options
#   change yes to no to disable
#
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
UNICODE_ENABLE = yes        # Unicode support
AUTO_SHIFT_ENABLE = yes
TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes
KEY_LOCK_ENABLE = yes

# TODO: check this
# RP2040-specific options
# PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS.
