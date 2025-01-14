#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    #define GOODBYE_SONG SONG(GOODBYE_SOUND)
#endif
#define AUDIO_INIT_DELAY
#define RGBLIGHT_ANIMATIONS
#define MUSIC_MAP

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

#define TAPPING_TERM 200

#define IGNORE_MOD_TAP_INTERRUPT

#define TAPPING_FORCE_HOLD

#define COMBO_COUNT 2

#define COMBO_TERM 35
