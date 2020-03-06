/*
 * ControlTask.c
 *
 *  Created on: Sep 9, 2019
 *      Author: fil
 *  Data structure in the mailbox ( 32 bits ) :
 *  	31-24 : pot left
 *  	23-16 : pot right
 *  	15	  : button pressed
 *  	14-8  : joy up
 *  	7	  : button pressed copy
 *  	6-0   : joy down
 */
#include "ControlLoop.h"

#include "main.h"
s_control_buf	control_buf[CONTROLBUF_SAMPLES];

extern		ADC_HandleTypeDef 	hadc2;
extern 		LPTIM_HandleTypeDef hlptim1;
	/*
	SIGNALIN4 = CV for SIGNALIN0
	SIGNALIN5 = CV for SIGNALIN1
	POT_LEFT  = ANLG0
	POT_RIGHT = ANLG1
	JOY_X = ANLG2
	JOY_Y = ANLG3
	JOY_BTN = ANLG4
	*/

uint32_t	wpot_left,wpot_right,wjoy_y,wjoy_x;
uint32_t	pot_left,pot_right,joy_y,joy_x;
uint32_t	data_available;

void ControlInit(void)
{
	uint32_t *ptr = (uint32_t* )&control_buf[0];
	pot_left = pot_right = joy_y = joy_x = data_available = 0;
	wpot_left = wpot_right = wjoy_y = wjoy_x = 0;
	HAL_ADCEx_Calibration_Start(&hadc2, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED);
	HAL_ADC_Start_DMA(&hadc2, ptr , CONTROLBUF_LEN);
	HAL_LPTIM_Counter_Start_IT(&hlptim1,5000);
}


void ControlStoreHalf(void)
{
int i;

	for (i=0; i<CONTROLBUF_SAMPLES/2;i++ )
	{
		wpot_left 	+= control_buf[i].anlgin0;
		wpot_right 	+= control_buf[i].anlgin1;
		wjoy_y 		+= control_buf[i].anlgin2;
		wjoy_x 		+= control_buf[i].anlgin3;
	}
}

void ControlStoreComplete(void)
{
int i;
	for (i=CONTROLBUF_LEN/2; i<CONTROLBUF_LEN;i+=4 )
	{
		wpot_left 	+= control_buf[i].anlgin0;
		wpot_right 	+= control_buf[i].anlgin1;
		wjoy_y 		+= control_buf[i].anlgin2;
		wjoy_x 		+= control_buf[i].anlgin3;
	}
	pot_left = wpot_left / CONTROLBUF_SAMPLES;
	pot_right = wpot_right / CONTROLBUF_SAMPLES;
	joy_y = wjoy_y / CONTROLBUF_SAMPLES;
	joy_y >>= 1;
	joy_x = wjoy_x / CONTROLBUF_SAMPLES;
	joy_x >>= 1;
	wpot_left = wpot_right = wjoy_y = wjoy_x = 0;
	data_available ++;
}

void ControlStoreError(void)
{
	HAL_ADC_Stop_DMA(&hadc2);
	HAL_ADC_Start_DMA(&hadc2, (uint32_t* )control_buf , CONTROLBUF_LEN);
	wpot_left = wpot_right = wjoy_y = wjoy_x = 0;
}


