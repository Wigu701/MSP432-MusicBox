/*
 * enums.h
 *
 * Defines global enums for ACTION and DIRECTION
 * Also defines struct container for messages to put in the Message Queue
 *
 *  Created on: Apr 26, 2022
 *      Author: pnowa
 */

#ifndef __ENUMS_H__
#define __ENUMS_H__

typedef enum {FLICK, CLICK, DUET} ACTION;
typedef enum {UP, DOWN, LEFT, RIGHT} DIRECTION;

typedef struct {
    ACTION action;
    DIRECTION direction;
} MESSAGE_t;

#endif /* __ENUMS_H__ */
