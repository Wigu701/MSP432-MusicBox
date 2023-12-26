#ifndef __MUSIC_ENUMS_H__
#define __MUSIC_ENUMS_H__

#include <stdint.h>

// Note durations
#define W 96        // Whole
#define DH 72       // Dotted half
#define H 48        // Half
#define DQ 36       // Dotted quarter
#define Q 24        // Quarter
#define DE 18       // Dotted eighth
#define T 16        // Triplet
#define E 12        // Eighth
#define ET 8        // Eighth triplet
#define S 6         // Sixteenth

// Notes
#define Bb4 466
#define B4 494
#define C5 523
#define Db5 554
#define D5 587
#define Eb5 622
#define E5 659
#define F5 698
#define Gb5 740
#define G5 784
#define Ab5 831
#define A5 880
#define Bb5 932
#define B5 988
#define C6 1047
#define Db6 1109
#define D6 1175
#define Eb6 1245
#define E6 1319
#define F6 1397
#define Gb6 1480
#define G6 1568
#define Ab6 1662
#define A6 1760
#define Bb6 1865
#define C7 2093
#define Db7 2218
#define D7 2349
#define Eb7 2490
#define E7 2637

#define MAX_TRACKS 3

// Format for all songs
typedef struct Song_Data {
    char* title;            // Name of song
    char* author;           // Composer/artist name
    uint16_t** notes;      // Pointers to note tracks
    uint8_t** durations;   // Pointers to durations for each note track
    uint16_t* length;      // Length of notes arrays
    uint8_t tempo;          // Tempo for notes
    uint8_t tracks;         // How many different tracks in notes/duration arrays.
                            // Should be less than MAX_TRACKs macro above
} Song_Data;

#endif // __MUSIC_ENUMS_H__
