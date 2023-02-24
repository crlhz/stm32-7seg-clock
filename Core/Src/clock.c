/*
 * clock.c
 *
 *  Created on: 4 lis 2022
 *      Author: kamil
 */

#include "clock.h"

//**GLOBAL VARIABLES**//
uint8_t clock_time_set = 0;
uint8_t clock_active_button = 255;
//********************//


//**LOCAL VARIABLES**//
uint8_t active_set = 0;
uint8_t n = 0;
segments set_values;
mytime local_time = {0, 0, 0, 0};
//******************//


//**PUBLIC FUNCTIONS**//
segments clock_set_mode(uint8_t d_hours, uint8_t u_hours, uint8_t d_minutes, uint8_t u_minutes){

	//display blinking method -> the currently modified display is blinking, the others are operating continuously
	switch(active_set){
		case 0:
			if(set_values.seg0 != BLANK_SEGMENT){
				set_values.seg0 = BLANK_SEGMENT;
			}else{
				set_values.seg0 = d_hours;
			}
			break;

		case 1:
			set_values.seg0 = d_hours;
			if(set_values.seg1 != BLANK_SEGMENT){
				set_values.seg1 = BLANK_SEGMENT;
			}else{
				set_values.seg1 = u_hours;
			}
			break;

		case 2:
			set_values.seg1 = u_hours;
			if(set_values.seg2 != BLANK_SEGMENT){
				set_values.seg2 = BLANK_SEGMENT;
			}else{
				set_values.seg2 = d_minutes;
			}
			break;

		case 3:
			set_values.seg2 = d_minutes;
			if(set_values.seg3 != BLANK_SEGMENT){
				set_values.seg3 = BLANK_SEGMENT;
			}else{
				set_values.seg3 = u_minutes;
			}
			break;

		default:
			clock_time_set = 1;
			break;
	}

	return set_values;
}

mytime clock_button_handler(){
	//function returns the desired values, used to set the RTC

	switch(clock_active_button){
		case 0:
			//here we choose which display we'd like to modify
			n++;
			if(n>10 && HAL_GPIO_ReadPin(s0_GPIO_Port, s0_Pin)){
				active_set++;
				clock_active_button = 255;
				n = 0;
			}
			break;

		case 1:
			//here we choose specific values
			n++;
			if(n>10 && HAL_GPIO_ReadPin(s1_GPIO_Port, s1_Pin)){
				switch (active_set){
					case 0:
						if(local_time.d_hours < 2){
							local_time.d_hours++;
						}else{
							local_time.d_hours = 0;
						}
						break;

					case 1:
						if(local_time.d_hours != 2){
							if(local_time.u_hours < 9){
								local_time.u_hours++;
							}else{
								local_time.u_hours = 0;
							}
						}else{
							if(local_time.u_hours < 3){
								local_time.u_hours++;
							}else{
								local_time.u_hours = 0;
							}
						}
						break;

					case 2:
						if(local_time.d_minutes < 5){
							local_time.d_minutes++;
						}else{
							local_time.d_minutes = 0;
						}
						break;

					case 3:
						if(local_time.u_minutes < 9){
							local_time.u_minutes++;
						}else{
							local_time.u_minutes = 0;
						}
						break;
				}
				clock_active_button = 255;
				n = 0;
			}

		default:
			break;
	}

	return local_time;
}

mytime get_local_time(){
	return local_time;
}
//********************//
