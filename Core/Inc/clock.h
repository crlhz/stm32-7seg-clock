/*
 * clock.h
 *
 *  Created on: 4 lis 2022
 *      Author: kamil
 */

#ifndef INC_CLOCK_H_
#define INC_CLOCK_H_

#include "stdio.h"
#include "stdint.h"
#include "gpio.h"
#include "7seg_4056.h"

//**GLOBAL VARIABLES**//
//variable to control if time is set
extern uint8_t clock_time_set;

//variable to control which button is pressed
extern uint8_t clock_active_button;

//structure of displayed time
typedef struct mytime{
	uint8_t d_hours;
	uint8_t u_hours;
	uint8_t d_minutes;
	uint8_t u_minutes;
}mytime;
//*******************//


//**PUBLIC FUNCTIONS DECLARATIONS**//
//function to blink the display in set mode
segments clock_set_mode(uint8_t d_hours, uint8_t u_hours, uint8_t d_minutes, uint8_t u_minutes);

//function to handle button in set mode
mytime clock_button_handler();

//function to get time for rtc
mytime get_local_time();
//*********************************//

#endif /* INC_CLOCK_H_ */
