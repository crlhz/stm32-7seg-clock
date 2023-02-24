/*
 * 7seg_4056.c
 *
 *  Created on: 4 lis 2022
 *      Author: kamil
 */

#include "7seg_4056.h"

//**LOCAL VARIABLES**//
uint8_t seg_select = 0;
//*******************//


//**PRIVATE FUNCTIONS DECLARATIONS**//
void seg_control(uint8_t value, GPIO_TypeDef *port_to_reset, uint16_t pin_to_reset,
					GPIO_TypeDef *port_to_set, uint16_t pin_to_set);
//**********************************//


//**PUBLIC FUNCTIONS**//
void seg_display(uint8_t disp_seg0, uint8_t disp_seg1, uint8_t disp_seg2, uint8_t disp_seg3){

	switch (seg_select){
		case 0:
			seg_control(disp_seg0, seg3_GPIO_Port, seg3_Pin, seg0_GPIO_Port, seg0_Pin);
			seg_select++;
			break;

		case 1:
			seg_control(disp_seg1, seg0_GPIO_Port, seg0_Pin, seg1_GPIO_Port, seg1_Pin);
			seg_select++;
			break;

		case 2:
			seg_control(disp_seg2, seg1_GPIO_Port, seg1_Pin, seg2_GPIO_Port, seg2_Pin);
			seg_select++;
			break;

		case 3:
			seg_control(disp_seg3, seg2_GPIO_Port, seg2_Pin, seg3_GPIO_Port, seg3_Pin);
			seg_select = 0;
			break;

		default:
			seg_select = 0;
			break;
	}

}
//********************//


//**PRIVATE FUNCTIONS**//
//function to control each display independently
void seg_control(uint8_t value, GPIO_TypeDef *port_to_reset, uint16_t pin_to_reset,
					GPIO_TypeDef *port_to_set, uint16_t pin_to_set){

	HAL_GPIO_WritePin(port_to_reset, pin_to_reset, GPIO_PIN_RESET);
	GPIOB->ODR = value;
	HAL_GPIO_WritePin(port_to_set, pin_to_set, GPIO_PIN_SET);
}
//********************//

