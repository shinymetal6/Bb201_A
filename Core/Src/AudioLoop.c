/*
 * AudioTask.c
 *
 *  Created on: Sep 11, 2019
 *      Author: fil
 */

#include "AudioLoop.h"

#include "main.h"


extern	TIM_HandleTypeDef htim6;
extern	ADC_HandleTypeDef hadc1;
extern	ADC_HandleTypeDef hadc3;
extern	DAC_HandleTypeDef hdac1;

uint16_t  	audio0_bufin[AUDIOBUF_LEN];
uint16_t  	audio1_bufin[AUDIOBUF_LEN];
uint16_t  	audio0_bufout[AUDIOBUF_LEN];
uint16_t  	audio1_bufout[AUDIOBUF_LEN];

void AudioInit(void)
{
	HAL_ADCEx_Calibration_Start(&hadc1, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED);
	HAL_ADCEx_Calibration_Start(&hadc3, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED);
	HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_1,(uint32_t* )audio0_bufout, AUDIOBUF_LEN, DAC_ALIGN_12B_R);
	HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_2,(uint32_t* )audio1_bufout, AUDIOBUF_LEN, DAC_ALIGN_12B_R);
	HAL_ADC_Start_DMA(&hadc1, (uint32_t* )audio1_bufin , AUDIOBUF_LEN);
	HAL_ADC_Start_DMA(&hadc3, (uint32_t* )audio0_bufin , AUDIOBUF_LEN);
	HAL_TIM_Base_Start(&htim6);
}

void AudioTaskStoreBuf0Half(void)
{
}

void AudioTaskStoreBuf0Complete(void)
{
}

void AudioTaskStoreBuf0Error(void)
{
}

void AudioTaskStoreBuf1Half(void)
{
}

void AudioTaskStoreBuf1Complete(void)
{
}

void AudioTaskStoreBuf1Error(void)
{
}

