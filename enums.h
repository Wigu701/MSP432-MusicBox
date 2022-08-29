/*
 * enums.h
 *
 * Defines global enums for ACTION and DIRECTION
 * Also defines struct container for messages to put in the Message Queue
 *
 *  Created on: Apr 26, 2022
 *      Author: pnowa
 */

#ifndef ENUMS_H_
#define ENUMS_H_

typedef enum {FLICK, CLICK} ACTION;
typedef enum {UP, DOWN} DIRECTION;

typedef struct {
    ACTION action;
    DIRECTION direction;
} MESSAGE_t;

#endif /* ENUMS_H_ */
