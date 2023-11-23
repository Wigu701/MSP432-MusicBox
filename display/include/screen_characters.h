#ifndef __SCREEN_CHARACTERS_H__
#define __SCREEN_CHARACTERS_H__

#include <stdint.h>


// Subtract from character ASCII code to get library index
//
// ex. Want to get character a
//
// aCharacter = CHARACTER_LIBRARY[(char)'a' - CHARACTER_LIBRARY_OFFSET];
// aBitmap = aCharacter.bitmap;
// aWidth = aCharacter.width;
// aHeight = CHARACTER_LIBRARY_HEIGHT
#define CHARACTER_LIBRARY_OFFSET 0x20
#define CHARACTER_LIBRARY_HEIGHT 21
#define CHARACTER_LIBRARY_LENGTH 95     // Total number of characters in library


typedef struct ScreenCharacter {
    uint8_t* bitmap;
    uint8_t width;
} ScreenCharacter;


// Contains image bitmaps for ASCII characters ' ' to '~' (16pt Verdana font)
extern ScreenCharacter CHARACTER_LIBRARY[CHARACTER_LIBRARY_LENGTH];


// Initializes members of CHARACTER_LIBRARY array
void initCharacters(void);


#endif // __SCREEN_CHARACTERS_H__
