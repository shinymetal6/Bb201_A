/*
 * FlashOps.c
 *
 *  Created on: Jan 24, 2020
 *      Author: fil
 */

#include "main.h"
#include "FlashOps.h"
#include "Spi25W_Driver.h"
#include <stdio.h>
extern	uint32_t	flash_present;

s_flash_config FConfig =
{
	.Header 				= "B201_a  ",
	.Version 				= "0.0.1   ",
	.function 				= "VCO     ",
	.samplerate02_text 		= "88200   ",
	.samplerate13_text 		= "88200   ",
	.samplerate02 			= 88200,
	.samplerate13 			= 88200,
};
s_flash_config 			rFConfig;
s_img_descriptor_config	ImgDescriptor[MAX_NUM_IMAGES];

uint8_t	*FlashConfig , *rFlashConfig;
uint8_t	*rImgDescriptor;

#define	TIMER_CLOCK	240000000

static uint32_t compare_area(uint8_t *area1 , uint8_t *area2, uint32_t count)
{
int	i;
	for(i=0;i<count;i++)
		if ( area1[i] != area2[i]  )
			return 0;
	return 1;
}

uint16_t FlashOps_Setup(void)
{
	uint32_t	div_factor = TIMER_CLOCK;
	FlashConfig = (uint8_t *)&FConfig;
	rFlashConfig = (uint8_t *)&rFConfig;

	if ( (W25qxx_ReadID() & 0xffff) == W25Q128JVSIM_ID)
	{
		W25qxx_ReadID();
		W25qxx_setup();
		W25qxx_ReadPage(rFlashConfig,0,0,PAGE_SIZE);
		if ( compare_area(FlashConfig,rFlashConfig,VALID_BYTES_IN_FLASH_STRUCT) == 0 )
		{
			W25qxx_EraseSector(W25qxx_PageToSector(0));
			FConfig.timer02_val = TIMER_CLOCK / FConfig.samplerate02;
			FConfig.timer13_val = TIMER_CLOCK / FConfig.samplerate13;
			snprintf((char *)FConfig.samplerate02_text,8,"%07x",(unsigned int)FConfig.timer02_val);
			snprintf((char *)FConfig.samplerate13_text,8,"%07x",(unsigned int)FConfig.timer13_val);
			W25qxx_WritePage(FlashConfig,0,0,PAGE_SIZE);
			W25qxx_ReadPage(rFlashConfig,0,0,PAGE_SIZE);
			return compare_area(FlashConfig,rFlashConfig,VALID_BYTES_IN_FLASH_STRUCT);
		}
		return 1;
	}
	FConfig.timer02_val = div_factor / FConfig.samplerate02;
	FConfig.timer13_val = div_factor / FConfig.samplerate13;
	return 0; // Default is flash not present
}

uint16_t FlashOpsFormatImages(void)
{
int i;

	for(i=0;i<MAX_NUM_IMAGES;i++)
	{
		ImgDescriptor[i].id = i;
		ImgDescriptor[i].page_ptr = IMAGE_START_PAGE + i;
		ImgDescriptor[i].size = NUM_PAGE_IMAGE;
		ImgDescriptor[i].flags = IMAGE_NOT_PRESENT_FLAG;
	}
	W25qxx_WritePage((uint8_t *)&ImgDescriptor[0],DESCRIPTOR_PAGE,0,PAGE_SIZE);
	return IMAGE_NOT_PRESENT_FLAG;
}

uint16_t FlashOpsCheckImages(void)
{
int i;

	for(i=0;i<MAX_NUM_IMAGES;i++)
		W25qxx_ReadPage((uint8_t *)&ImgDescriptor[i],DESCRIPTOR_PAGE,0,PAGE_SIZE);
	if (ImgDescriptor[0].id != 0 )
		return FlashOpsFormatImages();
	else
	{
		for(i=0;i<MAX_NUM_IMAGES;i++)
		{
			if ( ImgDescriptor[i].flags == IMAGE_NOT_PRESENT_FLAG)
				return i;
		}
	}
	return 0;
}

