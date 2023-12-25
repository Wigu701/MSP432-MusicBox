#include <outputs/include/songs.h>


// Mario Death
#define DEATH_NOTES_LENGTH 12
uint16_t Death_Notes[DEATH_NOTES_LENGTH] = {C6, 0, G5, 0, E5, A5, B5, A5, Ab5, Bb5, Ab5, G5};
uint8_t Death_Times[DEATH_NOTES_LENGTH] = {E, E, E, E, Q, T, T, T, Q, Q, Q, 3*Q};

// Here Comes the sun
#define HCTS_LENGTH 32
uint16_t HCTS_Notes[HCTS_LENGTH] = {Db6, A5, B5, Db6, A5, Db6, B5, A5, Gb5, A5, B5, A5, Gb5, Ab5, Gb5, Ab5, A5, B5, 0, Db6, A5, B5, Db6, A5, Db6, B5, A5, Gb5, Db6, B5, A5, Ab5};
uint8_t HCTS_Times[HCTS_LENGTH] = {E, E, E, Q, DQ, E, Q, Q, Q, Q, Q, Q, E, E, E, E, Q, DQ, Q, E, E, E, Q, DQ, E, Q, Q, Q, Q, Q, Q, H};

// Bach Little Fugue in G Minor
#define FGM1_LENGTH 139
#define FGM2_LENGTH 72
uint16_t FGM1_Notes[FGM1_LENGTH] = {G5, D6, Bb5, A5, G5, Bb5, A5, G5, Gb5, A5, D5, G5, D5, A5, D5, Bb5, A5, G5, A5, D5, G5, D5, G5, A5, D5, A5, Bb5, A5, G5, A5, D5, D6, C6, Bb5, A5, G5, Bb5, A5, G5, Gb5, A5, G5, D5, G5, A5, Bb5, C6, D6, E6,
                          F6, E6, D6, F6, E6, D6, Db6, E6, D6, 0, A5, 0, D6, 0, E6, 0, F6, G6, F6, G6, G6, A6, G6, F6, G6, A6, G6, A6, Bb6, A6, G6, F6, E6, F6, A6, G6, A6, Db6, A6, D6, A6, D6, A6, G6, A6, Db6, A6, G6, A6, F6, D6, Db6, D6, G6, D6, Db6, D6, A6, D6, Db6, D6, G6, D6, Db6, D6,
                          A5, F6, G6, E6, F5, A5, D6, F6, Eb6, A6, 0, Eb6, D6, G6, 0, D6, C6, Bb5, C6, D6, C6, D6, E6, Gb6, G6};
uint8_t FGM1_Times[FGM1_LENGTH] = {H, H, 24, Q, Q, Q, Q, Q, Q, Q, H, Q, Q, Q, Q, Q, E, E, Q, Q, Q, E, E, Q, E, E, Q, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                         E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, S, S, Q, S, S, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                         Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, E, E, E, E, E, E, E, E, H};

uint16_t FGM2_Notes[FGM2_LENGTH] = {0, 0, G5, D6, Bb5, A5, G5, Bb5, A5, G5, Gb5, A5, D5, G5, D5, A5, D5, Bb5, A5, G5, A5, D5, G5, D5, G5, A5, D5, A5, Bb5, A5, G5, A5, D5, D6, C6, Bb5, A5, G5, Bb5, A5, G5, Gb5, A5, G5, D5, G5, A5, Bb5, C6, D6, E6,
                           F6, E6, F6, G6, F5, E6, D6, F6, E6, D6, E6, F6, E6, D6, C6, E6, D6, C6, B5, G5, C6};
uint8_t FGM2_Times[FGM2_LENGTH] = {160, 160, H, H, 24, Q, Q, Q, Q, Q, Q, Q, H, Q, Q, Q, Q, Q, E, E, Q, Q, Q, E, E, Q, E, E, Q, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                          E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, Q, Q, Q, Q, H};

// Brody Quest
#define BRODY_QUEST_LENGTH 170
uint16_t BQ_Notes[BRODY_QUEST_LENGTH] = {C6, C6, C6, A5, G5, C6, E6, F6, Gb6, G6, C6, C6, C6, A5, G5, C6, E6, F6, Gb6, G6, A6, A6, A6, G6, E6, F6, F6, G6, A6, C7, C6, C6, C6, A5, G5, C6, // Chorus
                         G6, A6, C7, D7, E7, C7, G6, 0, G6, A6, G6, F6, E6, 0, F6, E6, D6, C6, 0, C6, D6, E6, D6, C6, A5, C6, E6, 0, F6, E6, D6, D6, E6, C6, A5, G5, E5, D5, C5, D5, E5, 0, // Bridge
                         G5, A5, C6, C6, D6, F6, E6, D6, C6, G6, E6, A6, G6, C7, A6, C7, D7, E7, 0, E7, D7, C7, D7, E7, C7, A6, G6, A6, C7, E6, G6, E6, D6, C6, C6, D6, E6, D6, C6, 0,
                         E5, E5, D5, E5, E6, A6, G6, G6, A6, G6, E6, D6, E6, D6, C6, C6, 0, C6, B5, C6, 0, C6, A5, G5, C5, A5, G5, E5, A5, G5, E5, G5, A5, C6, D6, C6, A5, E5, G5, A5, G5, E5, G5, A5, G5, E5, 0, D5, C5, D5, E5};
uint8_t BQ_Times[BRODY_QUEST_LENGTH] = {Q, Q, Q, E, E, DQ, Q, E, E, E, Q, Q, Q, E, E, DQ, Q, E, E, E, Q, Q, Q, E, E, DQ, Q, E, E, E, Q, Q, Q, E, E, E,
                         E, E, Q, Q, Q, Q, 2*Q, Q, E, E, E, E, E, E, Q, Q, Q, DQ + S, S, E, E, E, E, Q, Q, Q, Q, E, DQ, E, Q, E, Q, DQ, E, DQ, E, Q, Q, E, Q, S, Q, E, Q, E, E, Q, Q, E, Q, Q, Q, Q, Q, Q, E, E, E, E + S, S,
                         Q, E, E, E, Q, Q, E, Q, Q, Q, Q, E, Q, Q, Q, Q, E, Q, E, Q, E, Q, Q, Q, S, S, DQ, E, Q, E, E, Q, Q, Q, E, Q, Q + S, S, Q, Q, Q, E, E, E, E, E, E, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, H, E, 2*Q, Q, E, E, E, Q};

// LoZ Theme
#define LOZ1_LENGTH 82
#define LOZ2_LENGTH 84
uint16_t LoZ1_Notes[LOZ1_LENGTH] = {Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, Ab5, Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, Ab5, Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, F5, F5, F5, F5, F5, F5, F5, F5, F5, F5,
                          Bb5, F5, Bb5, Bb5, C6, D6, Eb6, F6, 0, F6, F6, Gb6, Ab6, Bb6, 0, Bb6, Bb6, Ab6, Gb6, Ab6, Gb6, F6, 0, F6, Eb6, Eb6, F6, Gb6, F6, Eb6, Db6, Db6, Eb6, F6, Eb6, Db6,
                          C6, C6, D6, E6, G6, F6, F5, F5, F5, F5, F5, F5, F5, F5, F5, F5};
uint8_t LoZ1_Times[LOZ1_LENGTH] = {H+DE, S, ET, ET, ET, 2*ET, ET, Q+DE, S, ET, ET, ET, 2*ET, ET, Q+DE, S, ET, ET, ET, E, S, S, E, S, S, E, S, S, E, E,
                          Q, DQ, E, S, S, S, S, H, E, E, ET, ET, ET, H, E, E, ET, ET, ET, DE, S, DQ, E, Q, E, S, S, H, E, E, E, S, S, H, E, E,
                          E, S, S, H, Q, E, S, S, E, S, S, E, S, S, E, E};

uint16_t LoZ2_Notes[LOZ2_LENGTH] = {Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, Ab5, Ab5, Ab5, Ab5, Ab5, Ab5, Ab5, Ab5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, F5, F5, F5, G5, A5,
                           Bb5, Bb5, Bb5, Ab5, Bb5, Bb5, Ab5, Ab5, Ab5, Gb5, Ab5, Ab5, Gb5, Gb5, Gb5, E5, Gb5, Gb5, Db6, Db6, Db6, B5, Db6, Db6,
                           B5, B5, B5, Bb5, B5, B5, B5, B5, Bb5, Bb5, Bb5, Ab5, Bb5, Bb5, Bb5, Bb5, C6, C6, C6, C6, C6, C6, C6, C6, F5, F5, F5, F5, F5, G5, A5};
uint8_t LoZ2_Times[LOZ2_LENGTH] = {Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, Q, Q, E, E, Q, ET, ET, ET, Q, Q, Q, ET, ET, ET, Q, Q,
                          Q, ET, ET, ET, Q, Q, Q, ET, ET, ET, Q, Q, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, E, E};


// Megalovania
#define MEGA1_LENGTH 208
#define MEGA2_LENGTH 160
uint16_t Mega1_Notes[MEGA1_LENGTH] = {D5, D5, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5, C5, C5, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5,
                           B4, B4, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5, Bb4, Bb4, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5,
                           D5, D5, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5, C5, C5, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5,
                           B4, B4, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5, Bb4, Bb4, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5,
                           D6, D6, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6, C6, C6, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6,
                           B5, B5, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6, Bb5, Bb5, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6,
                           D6, D6, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6, C6, C6, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6,
                           B5, B5, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6, Bb5, Bb5, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6};

uint8_t Mega1_Times[MEGA1_LENGTH] = {S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S};

uint16_t Mega2_Notes[MEGA2_LENGTH] = {0, 0, 0, 0,
                             D5, D5, D5, D5, 0, D5, 0, D5, 0, D5, D5, D5, D5, C5, C5, C5, C5, 0, C5, 0, C5, 0, C5, C5, C5, C5,
                             B4, B4, B4, B4, 0, B4, 0, B4, 0, B4, B4, B4, B4, Bb4, Bb4, Bb4, Bb4, 0, C5, 0, C5, 0, C5, C5, C5, C5,
                             D5, D5, D5, D5, 0, D5, 0, D5, 0, D5, D5, D5, D5, C5, C5, C5, C5, 0, C5, 0, C5, 0, C5, C5, C5, C5,
                             B4, B4, B4, B4, 0, B4, 0, B4, 0, B4, B4, B4, B4, Bb4, Bb4, Bb4, Bb4, 0, C5, 0, C5, 0, C5, C5, C5, C5,
                             D5, D5, D5, D5, 0, D5, 0, D5, 0, D5, D5, D5, D5, C5, C5, C5, C5, 0, C5, 0, C5, 0, C5, C5, C5, C5,
                             B4, B4, B4, B4, 0, B4, 0, B4, 0, B4, B4, B4, B4, Bb4, Bb4, Bb4, Bb4, 0, C5, 0, C5, 0, C5, C5, C5, C5};

uint8_t Mega2_Times[MEGA2_LENGTH] = {W, W, W, W,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E};

// Conslidated array
Song_Data songs[TOTAL_SONGS] = {
    {
        .title = "0. Mario Death",
        .author = "Guy at Nintendo",
        .notes = Death_Notes,
        .durations = Death_Times,
        .length = DEATH_NOTES_LENGTH,
        .tempo = 110
    },
    {
        .title = "1. Here Comes the Sun",
        .author = "The Beatles",
        .notes = HCTS_Notes,
        .durations = HCTS_Times,
        .length = HCTS_LENGTH,
        .tempo = 110
    },
    {
        .title = "2. Fugue in G Minor 1",
        .author = "Johann Bach",
        .notes = FGM1_Notes,
        .durations = FGM1_Times,
        .length = FGM1_LENGTH,
        .tempo = 200
    },
    {
        .title = "3. Fugue in G Minor 2",
        .author = "Johann Bach",
        .notes = FGM2_Notes,
        .durations = FGM2_Times,
        .length = FGM2_LENGTH,
        .tempo = 200
    },
    {
        .title = "4. Brody Quest",
        .author = "Lemon Demon",
        .notes = BQ_Notes,
        .durations = BQ_Times,
        .length = BRODY_QUEST_LENGTH,
        .tempo = 200
    },
    {
        .title = "5. The Legend of Zelda Main Theme 1",
        .author = "Koji Kondo",
        .notes = LoZ1_Notes,
        .durations = LoZ1_Times,
        .length = LOZ1_LENGTH,
        .tempo = 130
    },
    {
        .title = "6. The Legend of Zelda Main Theme 2",
        .author = "Koji Kondo",
        .notes = LoZ2_Notes,
        .durations = LoZ2_Times,
        .length = LOZ2_LENGTH,
        .tempo = 130
    },
    {
        .title = "7. Megalovania 1",
        .author = "Toby Fox",
        .notes = Mega1_Notes,
        .durations = Mega1_Times,
        .length = MEGA1_LENGTH,
        .tempo = 120
    },
    {
        .title = "8. Megalovania 2",
        .author = "Toby Fox",
        .notes = Mega2_Notes,
        .durations = Mega2_Times,
        .length = MEGA2_LENGTH,
        .tempo = 120
    }
};
