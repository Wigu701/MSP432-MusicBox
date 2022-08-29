/*
 * images.c
 *
 *  Created on: Apr 22, 2022
 *      Author: pnowakowski
 */

//
//  Image data for clickIt
//

#include "bop_it_images.h"

//
//  Image data for zero
//

const uint8_t zeroBitmap[] =
{
    0x03, 0x80, //       ###
    0x0F, 0xE0, //     #######
    0x3F, 0xF8, //   ###########
    0x78, 0x3C, //  ####     ####
    0x70, 0x1C, //  ###       ###
    0xE0, 0x0E, // ###         ###
    0xE0, 0x0E, // ###         ###
    0xC0, 0x06, // ##           ##
    0xC0, 0x06, // ##           ##
    0xC0, 0x06, // ##           ##
    0xC0, 0x06, // ##           ##
    0xE0, 0x0E, // ###         ###
    0xE0, 0x0E, // ###         ###
    0x70, 0x1C, //  ###       ###
    0x78, 0x3C, //  ####     ####
    0x3F, 0xF8, //   ###########
    0x0F, 0xE0, //     #######
    0x03, 0x80, //       ###
};

// Bitmap sizes for zero
const uint8_t zeroWidthPixels = 15;
const uint8_t zeroHeightPixels = 18;

//
//  Image data for one
//

const uint8_t oneBitmap[] =
{
    0x1C, //    ###
    0x18, //    ##
    0x18, //    ##
    0xF8, // #####
    0xF8, // #####
    0x98, // #  ##
    0x18, //    ##
    0x18, //    ##
    0x18, //    ##
    0x18, //    ##
    0x18, //    ##
    0x18, //    ##
    0x18, //    ##
    0x18, //    ##
    0x18, //    ##
    0x18, //    ##
    0x18, //    ##
    0x1C, //    ###
};

// Bitmap sizes for one
const uint8_t oneWidthPixels = 6;
const uint8_t oneHeightPixels = 18;

//
//  Image data for two
//

const uint8_t twoBitmap[] =
{
    0x01, 0xC0, //        ###
    0x0F, 0xF0, //     ########
    0x3F, 0xF8, //   ###########
    0xF0, 0x1C, // ####       ###
    0x60, 0x0C, //  ##         ##
    0x00, 0x0C, //             ##
    0x00, 0x1C, //            ###
    0x00, 0x1C, //            ###
    0x00, 0x78, //          ####
    0x01, 0xF8, //        ######
    0x07, 0xE0, //      ######
    0x1F, 0x80, //    ######
    0x3E, 0x00, //   #####
    0x78, 0x00, //  ####
    0x60, 0x00, //  ##
    0xFF, 0xFE, // ###############
    0xFF, 0xFE, // ###############
    0xFF, 0xFE, // ###############
};

// Bitmap sizes for two
const uint8_t twoWidthPixels = 15;
const uint8_t twoHeightPixels = 18;

//
//  Image data for three
//

const uint8_t threeBitmap[] =
{
    0x01, 0xC0, //        ###
    0x1F, 0xF8, //    ##########
    0x7F, 0xFC, //  #############
    0x70, 0x0C, //  ###        ##
    0x00, 0x0E, //             ###
    0x00, 0x0C, //             ##
    0x00, 0x0C, //             ##
    0x03, 0xF8, //       #######
    0x03, 0xF8, //       #######
    0x03, 0xFC, //       ########
    0x00, 0x0E, //             ###
    0x00, 0x06, //              ##
    0x00, 0x06, //              ##
    0x00, 0x06, //              ##
    0xE0, 0x0E, // ###         ###
    0xFF, 0xFC, // ##############
    0x7F, 0xF8, //  ############
    0x03, 0xC0, //       ####
};

// Bitmap sizes for three
const uint8_t threeWidthPixels = 15;
const uint8_t threeHeightPixels = 18;

//
//  Image data for four
//

const uint8_t fourBitmap[] =
{
    0x00, 0x7C, //          #####
    0x00, 0x78, //          ####
    0x00, 0xF8, //         #####
    0x01, 0xF8, //        ######
    0x01, 0x98, //        ##  ##
    0x03, 0x18, //       ##   ##
    0x06, 0x18, //      ##    ##
    0x0E, 0x18, //     ###    ##
    0x1C, 0x18, //    ###     ##
    0x38, 0x18, //   ###      ##
    0x70, 0x18, //  ###       ##
    0xE0, 0x18, // ###        ##
    0xFF, 0xFF, // ################
    0xFF, 0xFF, // ################
    0xFF, 0xFF, // ################
    0x00, 0x18, //            ##
    0x00, 0x18, //            ##
    0x00, 0x1C, //            ###
};

// Bitmap sizes for four
const uint8_t fourWidthPixels = 16;
const uint8_t fourHeightPixels = 18;

//
//  Image data for five
//

const uint8_t fiveBitmap[] =
{
    0x7F, 0xFC, //  #############
    0x7F, 0xFC, //  #############
    0x7F, 0xFC, //  #############
    0x60, 0x00, //  ##
    0x60, 0x00, //  ##
    0x60, 0x00, //  ##
    0xE1, 0xC0, // ###    ###
    0x7F, 0xF8, //  ############
    0x3F, 0xFC, //   ############
    0x10, 0x0E, //    #        ###
    0x00, 0x06, //              ##
    0x00, 0x06, //              ##
    0x00, 0x06, //              ##
    0x40, 0x06, //  #           ##
    0xF0, 0x0E, // ####        ###
    0x7F, 0xFC, //  #############
    0x1F, 0xF8, //    ##########
    0x03, 0xC0, //       ####
};

// Bitmap sizes for five
const uint8_t fiveWidthPixels = 15;
const uint8_t fiveHeightPixels = 18;

//
//  Image data for six
//

const uint8_t sixBitmap[] =
{
    0x01, 0xC0, //        ###
    0x0F, 0xF8, //     #########
    0x1F, 0xFE, //    ############
    0x38, 0x04, //   ###        #
    0x70, 0x00, //  ###
    0x60, 0x00, //  ##
    0xC1, 0xC0, // ##     ###
    0xC7, 0xF8, // ##   ########
    0xFF, 0xFC, // ##############
    0xF8, 0x0E, // #####       ###
    0xF0, 0x0E, // ####        ###
    0xE0, 0x06, // ###          ##
    0xE0, 0x06, // ###          ##
    0x70, 0x0E, //  ###        ###
    0x78, 0x0E, //  ####       ###
    0x3F, 0xFC, //   ############
    0x1F, 0xF0, //    #########
    0x03, 0x80, //       ###
};

// Bitmap sizes for six
const uint8_t sixWidthPixels = 15;
const uint8_t sixHeightPixels = 18;

//
//  Image data for seven
//

const uint8_t sevenBitmap[] =
{
    0xFF, 0xFE, // ###############
    0xFF, 0xFE, // ###############
    0xFF, 0xFE, // ###############
    0x00, 0x0E, //             ###
    0x00, 0x1C, //            ###
    0x00, 0x18, //            ##
    0x00, 0x38, //           ###
    0x00, 0x70, //          ###
    0x00, 0x70, //          ###
    0x00, 0xE0, //         ###
    0x00, 0xC0, //         ##
    0x01, 0xC0, //        ###
    0x03, 0x80, //       ###
    0x03, 0x80, //       ###
    0x07, 0x00, //      ###
    0x06, 0x00, //      ##
    0x0E, 0x00, //     ###
    0x1E, 0x00, //    ####
};

// Bitmap sizes for seven
const uint8_t sevenWidthPixels = 15;
const uint8_t sevenHeightPixels = 18;

//
//  Image data for eight
//

const uint8_t eightBitmap[] =
{
    0x03, 0x80, //       ###
    0x1F, 0xF0, //    #########
    0x7F, 0xFC, //  #############
    0x70, 0x1C, //  ###       ###
    0x60, 0x0C, //  ##         ##
    0x60, 0x0C, //  ##         ##
    0x70, 0x1C, //  ###       ###
    0x3F, 0xF8, //   ###########
    0x0F, 0xE0, //     #######
    0x3F, 0xF8, //   ###########
    0xF0, 0x1E, // ####       ####
    0xE0, 0x0E, // ###         ###
    0xC0, 0x06, // ##           ##
    0xE0, 0x0E, // ###         ###
    0xF0, 0x1E, // ####       ####
    0x7F, 0xFC, //  #############
    0x3F, 0xF8, //   ###########
    0x03, 0x80, //       ###
};

// Bitmap sizes for eight
const uint8_t eightWidthPixels = 15;
const uint8_t eightHeightPixels = 18;

//
//  Image data for nine
//

const uint8_t nineBitmap[] =
{
    0x03, 0x80, //       ###
    0x1F, 0xF0, //    #########
    0x7F, 0xF8, //  ############
    0xE0, 0x3C, // ###       ####
    0xE0, 0x1C, // ###        ###
    0xC0, 0x0E, // ##          ###
    0xC0, 0x0E, // ##          ###
    0xE0, 0x1E, // ###        ####
    0xE0, 0x3E, // ###       #####
    0x7F, 0xFE, //  ##############
    0x3F, 0xC6, //   ########   ##
    0x07, 0x06, //      ###     ##
    0x00, 0x0C, //             ##
    0x00, 0x1C, //            ###
    0x40, 0x38, //  #        ###
    0xFF, 0xF0, // ############
    0x3F, 0xE0, //   #########
    0x07, 0x00, //      ###
};

// Bitmap sizes for nine
const uint8_t nineWidthPixels = 15;
const uint8_t nineHeightPixels = 18;

