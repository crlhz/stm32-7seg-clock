/*
 * 7seg_4056.h
 *
 *  Created on: 4 lis 2022
 *      Author: kamil
 */

#ifndef INC_7SEG_4056_H_
#define INC_7SEG_4056_H_

#include "stdio.h"
#include "stdint.h"
#include "gpio.h"

#define	BLANK_SEGMENT 15


//**GLOBAL VARIABLES**//
//structure that represents each of the four displays
typedef struct Segments{

	uint8_t seg0;
	uint8_t seg1;
	uint8_t seg2;
	uint8_t seg3;

} segments;
//*******************//


//**PUBLIC FUNCTIONS DECLARATIONS**//
//function to provide values on the four displays
void seg_display(uint8_t disp_seg0, uint8_t disp_seg1, uint8_t disp_seg2, uint8_t disp_seg3);
//*********************************//


#endif /* INC_7SEG_4056_H_ */
