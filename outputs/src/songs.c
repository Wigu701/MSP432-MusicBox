#include <outputs/include/songs.h>


// Mario Death
uint16_t Death_Length[] = {12};
uint16_t Death1_Notes[12] = {C6, 0, G5, 0, E5, A5, B5, A5, Ab5, Bb5, Ab5, G5};
uint8_t Death1_Times[12] = {E, E, E, E, Q, T, T, T, Q, Q, Q, 3*Q};
uint16_t* Death_Notes[] = {Death1_Notes};
uint8_t* Death_Times[] = {Death1_Times};

// Here Comes the sun
uint16_t HCTS_Length[] = {32};
uint16_t HCTS1_Notes[32] = {Db6, A5, B5, Db6, A5, Db6, B5, A5, Gb5, A5, B5, A5, Gb5, Ab5, Gb5, Ab5, A5, B5, 0, Db6, A5, B5, Db6, A5, Db6, B5, A5, Gb5, Db6, B5, A5, Ab5};
uint8_t HCTS1_Times[32] = {E, E, E, Q, DQ, E, Q, Q, Q, Q, Q, Q, E, E, E, E, Q, DQ, Q, E, E, E, Q, DQ, E, Q, Q, Q, Q, Q, Q, H};
uint16_t* HCTS_Notes[] = {HCTS1_Notes};
uint8_t* HCTS_Times[] = {HCTS1_Times};

// Bach Little Fugue in G Minor
uint16_t FGM_Length[] = {139, 74};
uint16_t FGM1_Notes[139] = {G5, D6, Bb5, A5, G5, Bb5, A5, G5, Gb5, A5, D5, G5, D5, A5, D5, Bb5, A5, G5, A5, D5, G5, D5, G5, A5, D5, A5, Bb5, A5, G5, A5, D5, D6, C6, Bb5, A5, G5, Bb5, A5, G5, Gb5, A5, G5, D5, G5, A5, Bb5, C6, D6, E6,
                          F6, E6, D6, F6, E6, D6, Db6, E6, D6, 0, A5, 0, D6, 0, E6, 0, F6, G6, F6, G6, G6, A6, G6, F6, G6, A6, G6, A6, Bb6, A6, G6, F6, E6, F6, A6, G6, A6, Db6, A6, D6, A6, D6, A6, G6, A6, Db6, A6, G6, A6, F6, D6, Db6, D6, G6, D6, Db6, D6, A6, D6, Db6, D6, G6, D6, Db6, D6,
                          A5, F6, G6, E6, F5, A5, D6, F6, Eb6, A6, 0, Eb6, D6, G6, 0, D6, C6, Bb5, C6, D6, C6, D6, E6, Gb6, G6};
uint8_t FGM1_Times[139] = {H, H, 72, Q, Q, Q, Q, Q, Q, Q, H, Q, Q, Q, Q, Q, E, E, Q, Q, Q, E, E, Q, E, E, Q, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                         E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, S, S, Q, S, S, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                         Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, E, E, E, E, E, E, E, E, H};

uint16_t FGM2_Notes[74] = {0, 0, 0, 0, G5, D6, Bb5, A5, G5, Bb5, A5, G5, Gb5, A5, D5, G5, D5, A5, D5, Bb5, A5, G5, A5, D5, G5, D5, G5, A5, D5, A5, Bb5, A5, G5, A5, D5, D6, C6, Bb5, A5, G5, Bb5, A5, G5, Gb5, A5, G5, D5, G5, A5, Bb5, C6, D6, E6,
                           F6, E6, F6, G6, F5, E6, D6, F6, E6, D6, E6, F6, E6, D6, C6, E6, D6, C6, B5, G5, C6};
uint8_t FGM2_Times[74] = {255, 255, 255, 195, H, H, 72, Q, Q, Q, Q, Q, Q, Q, H, Q, Q, Q, Q, Q, E, E, Q, Q, Q, E, E, Q, E, E, Q, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                          E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, Q, Q, Q, Q, H};
uint16_t* FGM_Notes[] = {FGM1_Notes, FGM2_Notes};
uint8_t* FGM_Times[] = {FGM1_Times, FGM2_Times};


// Brody Quest
uint16_t BQ_Length[] = {173};
uint16_t BQ1_Notes[173] = {C6, C6, C6, A5, G5, C6, 0, E6, F6, Gb6, G6, C6, C6, C6, A5, G5, C6, 0, E6, F6, Gb6, G6, A6, A6, A6, G6, E6, F6, 0, F6, G6, A6, C7, C6, C6, C6, A5, G5, C6, // Chorus
                         G6, A6, C7, D7, E7, C7, G6, 0, G6, A6, G6, F6, E6, 0, F6, E6, D6, C6, 0, C6, D6, E6, D6, C6, A5, C6, E6, 0, F6, E6, D6, D6, E6, C6, A5, G5, E5, D5, C5, D5, E5, 0, // Bridge
                         G5, A5, C6, C6, D6, F6, E6, D6, C6, G6, E6, A6, G6, C7, A6, C7, D7, E7, 0, E7, D7, C7, D7, E7, C7, A6, G6, A6, C7, E6, G6, E6, D6, C6, C6, D6, E6, D6, C6, 0,
                         E5, E5, D5, E5, E6, A6, G6, G6, A6, G6, E6, D6, E6, D6, C6, C6, 0, C6, B5, C6, 0, C6, A5, G5, C5, A5, G5, E5, A5, G5, E5, G5, A5, C6, D6, C6, A5, E5, G5, A5, G5, E5, G5, A5, G5, E5, 0, D5, C5, D5, E5};
uint8_t BQ1_Times[173] = {Q, Q, Q, E, E, Q, E, Q, E, E, E, Q, Q, Q, E, E, Q, E, Q, E, E, E, Q, Q, Q, E, E, Q, E, Q, E, E, E, Q, Q, Q, E, E, E,
                         E, E, Q, Q, Q, Q, H, Q, E, E, E, E, E, E, Q, Q, Q, DQ + S, S, E, E, E, E, Q, Q, Q, Q, E, Q, E, Q, E, Q, DQ, E, DQ, E, Q, Q, E, DE, S, Q, E, DQ, E, E, Q, Q, E, Q, Q, Q, Q, Q, Q, E, E, E, E + S, S,
                         Q, E, E, E, Q, Q, E, Q, Q, Q, Q, E, Q, E, Q, Q, E, Q, E, Q, E, Q, Q, Q, S, S, DQ, E, Q, E, E, Q, Q, Q, E, Q, Q + S, S, Q, Q, Q, E, E, E, E, E, E, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, H, E, DQ, Q, E, E, E, Q};
uint16_t* BQ_Notes[] = {BQ1_Notes};
uint8_t* BQ_Times[] = {BQ1_Times};

// LoZ Theme
uint16_t LoZ_Length[] = {82, 84};
uint16_t LoZ1_Notes[82] = {Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, Ab5, Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, Ab5, Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, F5, F5, F5, F5, F5, F5, F5, F5, F5, F5,
                          Bb5, F5, Bb5, Bb5, C6, D6, Eb6, F6, 0, F6, F6, Gb6, Ab6, Bb6, 0, Bb6, Bb6, Ab6, Gb6, Ab6, Gb6, F6, 0, F6, Eb6, Eb6, F6, Gb6, F6, Eb6, Db6, Db6, Eb6, F6, Eb6, Db6,
                          C6, C6, D6, E6, G6, F6, F5, F5, F5, F5, F5, F5, F5, F5, F5, F5};
uint8_t LoZ1_Times[82] = {H+DE, S, ET, ET, ET, 2*ET, ET, Q+DE, S, ET, ET, ET, 2*ET, ET, Q+DE, S, ET, ET, ET, E, S, S, E, S, S, E, S, S, E, E,
                          Q, DQ, E, S, S, S, S, H, E, E, ET, ET, ET, H, E, E, ET, ET, ET, DE, S, DQ, E, Q, E, S, S, H, E, E, E, S, S, H, E, E,
                          E, S, S, H, Q, E, S, S, E, S, S, E, S, S, E, E};

uint16_t LoZ2_Notes[84] = {Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, Ab5, Ab5, Ab5, Ab5, Ab5, Ab5, Ab5, Ab5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, F5, F5, F5, G5, A5,
                           Bb5, Bb5, Bb5, Ab5, Bb5, Bb5, Ab5, Ab5, Ab5, Gb5, Ab5, Ab5, Gb5, Gb5, Gb5, E5, Gb5, Gb5, Db6, Db6, Db6, B5, Db6, Db6,
                           B5, B5, B5, Bb5, B5, B5, B5, B5, Bb5, Bb5, Bb5, Ab5, Bb5, Bb5, Bb5, Bb5, C6, C6, C6, C6, C6, C6, C6, C6, F5, F5, F5, F5, F5, G5, A5};
uint8_t LoZ2_Times[84] = {Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, Q, Q, E, E, Q, ET, ET, ET, Q, Q, Q, ET, ET, ET, Q, Q,
                          Q, ET, ET, ET, Q, Q, Q, ET, ET, ET, Q, Q, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, E, E};
uint16_t* LoZ_Notes[2] = {LoZ1_Notes, LoZ2_Notes};
uint8_t* LoZ_Times[2] = {LoZ1_Times, LoZ2_Times};


// Megalovania
uint16_t Mega_Length[] = {208, 160};
uint16_t Mega1_Notes[208] = {D5, D5, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5, C5, C5, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5,
                           B4, B4, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5, Bb4, Bb4, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5,
                           D5, D5, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5, C5, C5, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5,
                           B4, B4, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5, Bb4, Bb4, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5,
                           D6, D6, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6, C6, C6, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6,
                           B5, B5, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6, Bb5, Bb5, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6,
                           D6, D6, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6, C6, C6, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6,
                           B5, B5, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6, Bb5, Bb5, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6};

uint8_t Mega1_Times[208] = {S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S};

uint16_t Mega2_Notes[160] = {0, 0, 0, 0,
                             D5, D5, D5, D5, 0, D5, 0, D5, 0, D5, D5, D5, D5, C5, C5, C5, C5, 0, C5, 0, C5, 0, C5, C5, C5, C5,
                             B4, B4, B4, B4, 0, B4, 0, B4, 0, B4, B4, B4, B4, Bb4, Bb4, Bb4, Bb4, 0, C5, 0, C5, 0, C5, C5, C5, C5,
                             D5, D5, D5, D5, 0, D5, 0, D5, 0, D5, D5, D5, D5, C5, C5, C5, C5, 0, C5, 0, C5, 0, C5, C5, C5, C5,
                             B4, B4, B4, B4, 0, B4, 0, B4, 0, B4, B4, B4, B4, Bb4, Bb4, Bb4, Bb4, 0, C5, 0, C5, 0, C5, C5, C5, C5,
                             D5, D5, D5, D5, 0, D5, 0, D5, 0, D5, D5, D5, D5, C5, C5, C5, C5, 0, C5, 0, C5, 0, C5, C5, C5, C5,
                             B4, B4, B4, B4, 0, B4, 0, B4, 0, B4, B4, B4, B4, Bb4, Bb4, Bb4, Bb4, 0, C5, 0, C5, 0, C5, C5, C5, C5};

uint8_t Mega2_Times[160] = {W, W, W, W,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E};
uint16_t* Mega_Notes[2] = {Mega1_Notes, Mega2_Notes};
uint8_t* Mega_Times[2] = {Mega1_Times, Mega2_Times};


// Spongebob Theme
uint16_t SB_Length[] = {116};
uint16_t SB1_Notes[116] = {Eb6, D6, D6, E6, D6, B5, G5, B5, D6, E6, D6, B5, D6, 0, D6, 0, D6, 0, D6, G6, G6, A6, G6, E6, C6, E6, G6, A6, G6, E6, E6, 0, E6, 0, E6, 0, E6,
                          D6, D6, E6, D6, B5, G5, B5, D6, E6, D6, B5, D6, 0, D6, 0, D6, 0, D6, G6, G6, A6, G6, E6, C6, E6, G6, A6, G6, E6, E6, 0, E6, 0, E6, 0, E6, 0,
                          G6, E6, D6, B5, G6, E6, D6, B5, G6, E6, D6, B5, D6, E6, Gb6, G6,
                          G6, Gb6, G6, E6, D6, G6, D6, B5, A5, B5, A5, G5, A5, B5, G5, G6, A6, B6, A6, 0, B6, G6, 0, D6, G6};
uint8_t SB1_Times[116] = {H + E, E, ET, ET, ET, ET, ET, ET, ET, ET, ET, Q, E, E, E, E, E, E, 2*ET, ET, ET, ET, ET, ET, ET, ET, ET, ET, ET, Q, 2*ET, ET, 2*ET, ET, 2*ET, ET, 2*ET,
                         ET, ET, ET, ET, ET, ET, ET, ET, ET, ET, Q, 2*ET, ET, 2*ET, ET, 2*ET, ET, 2*ET, ET, ET, ET, ET, ET, ET, ET, ET, ET, ET, Q, 2*ET ,ET, 2*ET, ET, 2*ET, ET, 2*ET, ET,
                         Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, H, Q, E,
                         E, E, S, S, E, E, E, E, ET, ET, ET, 2*ET, ET, Q, Q, ET, ET, ET, ET, ET, ET, ET, ET, ET, ET, E};
uint16_t* SB_Notes[1] = {SB1_Notes};
uint8_t* SB_Times[1] = {SB1_Times};


// Emerald Hill Zone
uint16_t EHZ_Length[] = {251, 353};
uint16_t EHZ1_Notes[251] =  {F5, G5, E5, F5,

                            0, G5, A5, G5, C6, C6, D6, E6, 0, D6, A5, C6, C6, D6, 0, Bb5, C6, Bb5, D6, C6, Bb5, C6, A5,
                            0, G5, A5, G5, C6, C6, D6, E6, 0, D6, A5, C6    , D6, 0, Bb5, C6, Bb5, D6, C6, Bb5, C6, A5,
                            0, G5, G5, A5, C6, C6, D6, C6, E6, D6, A5, 0, Bb5, Bb5, C6, D6, C6, Bb5, C6, A5,
                            0, G5    , A5, C6, C6, D6, C6, E6, D6, A5, 0, Bb5, Bb5, C6, D6, C6, Bb5, C6, A5,
                            C6, A5, G5, A5, C6, B5, C6, B5, 0, B5, C6, B5, 0, 0, B5, C6, D6, C6, B5, D6, C6, C6, A5, E5,
                            C6, A5, G5, A5, C6, B5, C6, B5, 0, B5, C6, B5, 0, D6, E6, A5,

                            // REPEAT

                            0, G5, A5, G5, C6, C6, D6, E6, 0, D6, A5, C6, C6, D6, 0, Bb5, C6, Bb5, D6, C6, Bb5, C6, A5,
                            0, G5, A5, G5, C6, C6, D6, E6, 0, D6, A5, C6    , D6, 0, Bb5, C6, Bb5, D6, C6, Bb5, C6, A5,
                            0, G5, G5, A5, C6, C6, D6, C6, E6, D6, A5, 0, Bb5, Bb5, C6, D6, C6, Bb5, C6, A5,
                            0, G5    , A5, C6, C6, D6, C6, E6, D6, A5, 0, Bb5, Bb5, C6, D6, C6, Bb5, C6, A5,
                            C6, A5, G5, A5, C6, B5, C6, B5, 0, B5, C6, B5, 0, 0, B5, C6, D6, C6, B5, D6, C6, C6, A5, E5,
                            C6, A5, G5, A5, C6, B5, C6, B5, 0, B5, C6, B5, 0, D6, E6,

                            };

uint8_t EHZ1_Times[251] =   {DE, 78, H, H,

                            E, E, E, E, E, E, S, DE,     E, Q, E, S, E, 30,         30, S, S, S, E, E, S, E,     102,
                            E, E, E, E, E, E, S, DE,     E, Q, E, DE,   30,         30, S, S, S, E, E, S, E,     102,
                            E, E, E, E, E, E, E, E,      E, Q, 60,                  E, E, E, E, E, E, S, DE,     W,
                            E, Q   , E, E, E, E, E,      E, Q, 60,                  E, E, E, E, E, E, S, DE,     W,
                            DQ, E, Q,  E, E,             E, S, S, Q, E, S, S, Q,    Q, E, E, E, E, E, E,         E, Q, E, H,
                            DQ, E, 30, S, E,             E, S, S, Q, E, S, S, Q,    DE, 78,                      W,
                            
                            // REPEAT

                            E, E, E, E, E, E, S, DE,     E, Q, E, S, E, 30,         30, S, S, S, E, E, S, E,     102,
                            E, E, E, E, E, E, S, DE,     E, Q, E, DE,   30,         30, S, S, S, E, E, S, E,     102,
                            E, E, E, E, E, E, E, E,      E, Q, 60,                  E, E, E, E, E, E, S, DE,     W,
                            E, Q   , E, E, E, E, E,      E, Q, 60,                  E, E, E, E, E, E, S, DE,     W,
                            DQ, E, Q,  E, E,             E, S, S, Q, E, S, S, Q,    Q, E, E, E, E, E, E,         E, Q, E, H,
                            DQ, E, 30, S, E,             E, S, S, Q, E, S, S, Q,    DE, 78+96,

                            };

uint16_t EHZ2_Notes[455] = {0, B6, G6, E6, C6, G6, E6, C6, A5, G6, E6, C6, A5, G6, E6, C6, A5, A6, F6, D6, Bb5, A6, F6, D6, Bb5, 

                            C5, C6, C6, A5, D6, C6, G5, A5, C6,     D5, D6, D6, A5, E6, D6, A5, B5, D6,    Bb4, Bb5, Bb5, F5, C6, Bb5, F5, G5, Bb5,    A4, A5, A4, B4, B5, B4, C5, C6, C5, A4, A5, A4,
                            C5, C6, C6, A5, D6, C6, G5, A5, C6,     D5, D6, D6, A5, E6, D6, A5, B5, D6,    Bb4, Bb5, Bb5, F5, C6, Bb5, F5, G5, Bb5,    A4, A5, A4, B4, B5, B4, C5, C6, C5, A4, A5, A4,
                            C5, C6, C6, A5, D6, C6, G5, A5, C6,     D5, D6, D6, A5, E6, D6, A5, B5, D6,    Bb4, Bb5, Bb5, F5, C6, Bb5, F5, G5, Bb5,    A4, A5, A4, B4, B5, B4, C5, C6, C5, A4, A5, A4,
                            C5, C6, C6, A5, D6, C6, G5, A5, C6,     D5, D6, D6, A5, E6, D6, A5, B5, D6,    Bb4, Bb5, Bb5, F5, C6, Bb5, F5, G5, Bb5,    A4, A5, A4, B4, B5, B4, C5, C6, C5, A4, A5, A4,
                            F5, F6, C5, C6, F5, F6, C5, C6,         E5, E6, B4, B5, E5, E6, B4, B5,        E5, E6, B4, B5, Ab4, Ab5, E4, E5,           A4, A5, B4, B5, C5, C6, A4, A5,
                            F5, F6, C5, C6, F5, F6, C5, C6,         E5, E6, B4, B5, E5, E6, B4, B5,        G5, G5, A5,                                 C7, G6, E6, C6,   G6, E6, C6, G5,   E6, C6, G5, E5,   C6, G5, E5, C5,

                            // REPEAT

                            C5, C6, C6, A5, D6, C6, G5, A5, C6,     D5, D6, D6, A5, E6, D6, A5, B5, D6,    Bb4, Bb5, Bb5, F5, C6, Bb5, F5, G5, Bb5,    A4, A5, A4, B4, B5, B4, C5, C6, C5, A4, A5, A4,
                            C5, C6, C6, A5, D6, C6, G5, A5, C6,     D5, D6, D6, A5, E6, D6, A5, B5, D6,    Bb4, Bb5, Bb5, F5, C6, Bb5, F5, G5, Bb5,    A4, A5, A4, B4, B5, B4, C5, C6, C5, A4, A5, A4,
                            C5, C6, C6, A5, D6, C6, G5, A5, C6,     D5, D6, D6, A5, E6, D6, A5, B5, D6,    Bb4, Bb5, Bb5, F5, C6, Bb5, F5, G5, Bb5,    A4, A5, A4, B4, B5, B4, C5, C6, C5, A4, A5, A4,
                            C5, C6, C6, A5, D6, C6, G5, A5, C6,     D5, D6, D6, A5, E6, D6, A5, B5, D6,    Bb4, Bb5, Bb5, F5, C6, Bb5, F5, G5, Bb5,    A4, A5, A4, B4, B5, B4, C5, C6, C5, A4, A5, A4,
                            F5, F6, C5, C6, F5, F6, C5, C6,         E5, E6, B4, B5, E5, E6, B4, B5,        E5, E6, B4, B5, Ab4, Ab5, E4, E5,           A4, A5, B4, B5, C5, C6, A4, A5,
                            F5, F6, C5, C6, F5, F6, C5, C6,         E5, E6, B4, B5, E5, E6, B4, B5,        G5, G5, A5,
                            };

uint8_t  EHZ2_Times[455] = {H, S, S, S, S, S, S, S, S,    S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, 

                            E, E, E, E, DE, E, S, S, S,   E, E, E, E, DE, E, S, S, S,   E, E, E, E, DE, E, S, S, S,   E, S, S, E, S, S, E, S, S, E, S, S,
                            E, E, E, E, DE, E, S, S, S,   E, E, E, E, DE, E, S, S, S,   E, E, E, E, DE, E, S, S, S,   E, S, S, E, S, S, E, S, S, E, S, S,
                            E, E, E, E, DE, E, S, S, S,   E, E, E, E, DE, E, S, S, S,   E, E, E, E, DE, E, S, S, S,   E, S, S, E, S, S, E, S, S, E, S, S,
                            E, E, E, E, DE, E, S, S, S,   E, E, E, E, DE, E, S, S, S,   E, E, E, E, DE, E, S, S, S,   E, S, S, E, S, S, E, S, S, E, S, S,
                            E, E, E, E, E, E, E, E,       E, E, E, E, E, E, E, E,       E, E, E, E, E, E, E, E,       E, E, E, E, E, E, E, E,
                            E, E, E, E, E, E, E, E,       E, E, E, E, E, E, E, E,       S, E, 78,                     S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S,

                            // REPEAT

                            E, E, E, E, DE, E, S, S, S,   E, E, E, E, DE, E, S, S, S,   E, E, E, E, DE, E, S, S, S,   E, S, S, E, S, S, E, S, S, E, S, S,
                            E, E, E, E, DE, E, S, S, S,   E, E, E, E, DE, E, S, S, S,   E, E, E, E, DE, E, S, S, S,   E, S, S, E, S, S, E, S, S, E, S, S,
                            E, E, E, E, DE, E, S, S, S,   E, E, E, E, DE, E, S, S, S,   E, E, E, E, DE, E, S, S, S,   E, S, S, E, S, S, E, S, S, E, S, S,
                            E, E, E, E, DE, E, S, S, S,   E, E, E, E, DE, E, S, S, S,   E, E, E, E, DE, E, S, S, S,   E, S, S, E, S, S, E, S, S, E, S, S,
                            E, E, E, E, E, E, E, E,       E, E, E, E, E, E, E, E,       E, E, E, E, E, E, E, E,       E, E, E, E, E, E, E, E,
                            E, E, E, E, E, E, E, E,       E, E, E, E, E, E, E, E,       S, E, 78+96,
                            };
                            
                            
uint16_t* EHZ_Notes[2] = {EHZ1_Notes, EHZ2_Notes};
uint8_t* EHZ_Times[2] = {EHZ1_Times, EHZ2_Times};


// Duck Tales Moon Song
uint16_t DT_Length[] = {118, 240};
uint16_t DT1_Notes[118] = {Gb5, Db6, Gb6, Ab6, Db6, Gb6, Ab6, Db6, B6, Db6, B6, Bb6, Db6, Bb6, Ab6, Gb6,
                           Db6, Gb6, Ab6, B6, B6, Bb6, Bb6, Ab6, Gb6, Db7, Gb6, Gb7, Ab7, Gb7, Db8,
                           0, Bb5, B5, Db6, Db6, Gb6, F6, Gb6, Ab6, Bb6, Gb6, F6, Gb6, Db7, Gb6, Gb6, Gb6, Gb6, Gb6, Ab6, Gb6, F6,
                           Bb5, Ab5, Gb5, Db6, Gb6, Ab6, B6, Bb6, Bb6, Db7, B6, Bb6, B6, Bb6, Gb6, Db6, Ab6, Gb6, F6, Eb6, F6, Gb6, Gb6, Gb6,
                           0, Gb6, Gb6, 0, Ab6, Ab6, 0, E6, Db6, E6, B5, Db6, B5, A5, B5, B5, A5, B5, 0, A5, 0, Db6,
                           Gb6, Gb6, 0, Ab6, Ab6, 0, A6, E6, E6, E6, A6, B6, A6, Db7, Db7, Db7, Db7, 0, Gb6};

uint8_t DT1_Times[118] = {E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                          W + Q, Q, Q, Q, DQ, E, W, Q, Q, DH, DH, 2*W + E, Q, E, 2*W,
                          H, E, E, E, DQ, Q, Q, Q, Q, E, W + DQ, E, E, DQ, E, W + Q, E, E, H + E, E, E, W + E,
                          H + E, E, E, H + E, Q, Q, DQ, E, W, Q, Q, E, E, E, Q, H, E, E, E, E, DQ, DQ, DQ, Q,
                          W, E, E, Q, E, E, E, H, Q, E, 3, 3, S, E, E, E, E, E, E, E, E, W + E,
                          E, E, Q, E, E, E, Q, Q, Q, E, E, DH + E, E, DH, E, E, E + W + H, H, W};

uint16_t DT2_Notes[240] = {Gb5, Db6, Gb6, Ab6, Db6, Gb6, Ab6, Db6, B6, Db6, B6, Bb6, Db6, Bb6, Ab6, Gb6,
                           Gb5, Db6, Gb6, E5, B5, E6, Db5, Bb5, Eb6, D5, A5, D6, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5,
                           Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, F5, F5, F5, F5, F5, F5, F5, F5, Eb5, Eb5, Eb5, Eb5, Eb5, Eb5, Eb5, Eb5, Db5, Db5, Db5, Db5, Db5, Db5, Db5, Db5,
                           B4, B4, B4, B4, B4, B4, B4, B4, C5, C5, C5, C5, C5, C5, C5, C5, Db5, Db5, Db5, Db5, Db5, Db5, Db5, Db5, Db5, Db5, Db5, Db5, Db5, Db5, Db5, Db5,
                           Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, E5, E5, E5, E5, E5, E5, E5, E5, Eb5, Eb5, Eb5, Eb5, Eb5, Eb5, Eb5, Eb5, D5, D5, D5, D5, D5, D5, D5, D5,
                           Db5, Db5, Db5, Db5, Db5, Db5, Db5, Db5, B4, B4, B4, B4, Db5, Db5, Db5, Db5, D5, E5, Gb5, Gb6, Db6, B5, Bb5, Gb5, Db5, B4, Bb4,
                           B4, B4, 0, E5, E5, 0, A4, A4, A4, A4, A4, A4, A4, A4, B4, B4, B4, B4, B4, B4, B4, B4, Db5, Db5, Db5, Db5, Db5, Db5, Db5, Db5,
                           B4, B4, 0, E5, E5, 0, A4, A4, A4, A4, A4, A4, A4, A4, B4, B4, B4, B4, B4, B4, B4, B4, Db5, Db5, Db5, Db5, Db5, Db5, Db5, Db5,
                           D5, D5, D5, D5, D5, D5, D5, D5, D5, 0, D5, E5, Gb5};

uint8_t DT2_Times[240] = {E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                          DQ, DQ, W + Q, DQ, DQ, W + Q, DQ, DQ, W + Q, DQ, DQ, W + Q, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                          E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                          E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                          E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                          E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, DQ, DQ, Q, E, E, E, E, E, E, E, E,
                          E, E, Q, E, E, E, Q, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                          E, E, Q, E, E, E, Q, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                          E, E, E, E, E, E, E, E, E, DQ, Q, Q, W};

uint16_t* DT_Notes[2] = {DT1_Notes, DT2_Notes};
uint8_t* DT_Times[2] = {DT1_Times, DT2_Times};

// Conslidated array
Song_Data songs[TOTAL_SONGS] = {
    {
        .title = "1: Mario Death",
        .author = "Koji Kondo",
        .notes = (uint16_t**)Death_Notes,
        .durations = (uint8_t**)Death_Times,
        .length = Death_Length,
        .tempo = 110,
        .tracks = 1
    },
    {
        .title = "2: Here Comes the Sun",
        .author = "The Beatles",
        .notes = (uint16_t**)HCTS_Notes,
        .durations = (uint8_t**)HCTS_Times,
        .length = HCTS_Length,
        .tempo = 140,
        .tracks = 1
    },
    {
        .title = "3: Fugue in G Minor",
        .author = "Johann Bach",
        .notes = (uint16_t**)FGM_Notes,
        .durations = (uint8_t**)FGM_Times,
        .length = FGM_Length,
        .tempo = 200,
        .tracks = 2
    },
    {
        .title = "4: Brody Quest",
        .author = "Lemon Demon",
        .notes = (uint16_t**)BQ_Notes,
        .durations = (uint8_t**)BQ_Times,
        .length = BQ_Length,
        .tempo = 200,
        .tracks = 1
    },
    {
        .title = "5: The Legend of Zelda Main Theme",
        .author = "Koji Kondo",
        .notes = (uint16_t**)LoZ_Notes,
        .durations = (uint8_t**)LoZ_Times,
        .length = LoZ_Length,
        .tempo = 130,
        .tracks = 2
    },
    {
        .title = "6: Megalovania",
        .author = "Toby Fox",
        .notes = (uint16_t**)Mega_Notes,
        .durations = (uint8_t**)Mega_Times,
        .length = Mega_Length,
        .tempo = 120,
        .tracks = 2
    },
    {
         .title = "7: The Spongebob SquarePants Theme Song",
         .author = "Stephen Hillenburg",
         .notes = (uint16_t**)SB_Notes,
         .durations = (uint8_t**)SB_Times,
         .length = SB_Length,
         .tempo = 120,
         .tracks = 1
    },
    {
         .title = "8: Emerald Hill Zone",
         .author = "Masato Nakamura",
         .notes = (uint16_t**)EHZ_Notes,
         .durations = (uint8_t**)EHZ_Times,
         .length = EHZ_Length,
         .tempo = 136,
         .tracks = 2
    },
    {
         .title = "9. Duck Tales Moon Theme",
         .author = "Hiroshige Tonomura",
         .notes = (uint16_t**)DT_Notes,
         .durations = (uint8_t**)DT_Times,
         .length = DT_Length,
         .tempo = 200,
         .tracks = 2
    }
};
