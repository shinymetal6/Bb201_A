/*
 * FlashOps.h
 *
 *  Created on: Jan 24, 2020
 *      Author: fil
 */

#ifndef INC_FLASHOPS_H_
#define INC_FLASHOPS_H_

#define	PAGE_SIZE	256
#define	VALID_BYTES_IN_FLASH_STRUCT	16
#define	PAD_NUMBER PAGE_SIZE-VALID_BYTES_IN_FLASH_STRUCT
typedef struct {
	uint8_t		Header[8];
	uint8_t		Version[8];
	uint8_t 	function[8];
	uint8_t 	samplerate02_text[8];
	uint8_t 	samplerate13_text[8];
	uint32_t 	samplerate02;
	uint32_t 	samplerate13;
	uint32_t	timer02_val;
	uint32_t	timer13_val;
	uint8_t		pad[PAD_NUMBER];
} s_flash_config;

typedef struct {
	uint32_t	id;
	uint32_t 	page_ptr;
	uint32_t	size;
	uint32_t	flags;
} s_img_descriptor_config;
#define	MAX_NUM_IMAGES		16
#define	NUM_PAGE_IMAGE		128
#define	DESCRIPTOR_PAGE		1
#define	IMAGE_START_PAGE	2
#define	IMAGE_NOT_PRESENT_FLAG	0x00000000
#define	IMAGE_PRESENT_FLAG		0x00000001

uint16_t FlashOps_ReadHeaders(void);
uint16_t FlashOps_Setup(void);
uint16_t FlashOpsCheckImages(void);
uint16_t FlashOpsFormatImages(void);

#endif /* INC_FLASHOPS_H_ */
