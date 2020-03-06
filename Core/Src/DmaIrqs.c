/*
 * DmaIrqs.c
 *
 *  Created on: Sep 11, 2019
 *      Author: fil
 */

#include "main.h"


/* Externals for Control Task */
extern	ADC_HandleTypeDef hadc2;
extern	void ControlStoreHalf(void);
extern	void ControlStoreComplete(void);
extern	void ControlStoreError(void);


void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
	if ( hadc == &hadc2)
	{
		ControlStoreHalf();
	}
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	if ( hadc == &hadc2)
	{
		ControlStoreComplete();
	}
}

void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc)
{
	if ( hadc == &hadc2)
	{
		ControlStoreError();
	}
}
