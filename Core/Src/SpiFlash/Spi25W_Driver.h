/*
 * Spi25W_Driver.h
 *
 *  Created on: Jan 22, 2020
 *      Author: fil
 */

#ifndef INC_SPI25W_DRIVER_H_
#define INC_SPI25W_DRIVER_H_
typedef enum
{
	W25Q10=1,
	W25Q20,
	W25Q40,
	W25Q80,
	W25Q16,
	W25Q32,
	W25Q64,
	W25Q128,
	W25Q256,
	W25Q512,

}W25QXX_ID_t;

typedef struct
{
	W25QXX_ID_t	ID;
	uint8_t		UniqID[8];
	uint16_t	PageSize;
	uint32_t	PageCount;
	uint32_t	SectorSize;
	uint32_t	SectorCount;
	uint32_t	BlockSize;
	uint32_t	BlockCount;
	uint32_t	CapacityInKiloByte;
	uint8_t		StatusRegister1;
	uint8_t		StatusRegister2;
	uint8_t		StatusRegister3;
	uint8_t		Lock;

}w25qxx_t;

#define  	_W25QXX_CS_PIN	SPI4_SS_Pin
#define  	_W25QXX_CS_GPIO	SPI4_SS_GPIO_Port
#define 	W25QXX_DUMMY_BYTE 0xA5
#define 	W25Q128JVSIM_ID	 0x7018

extern	uint32_t W25qxx_ReadID(void);
extern	void W25qxx_setup(void);

extern	void 	W25qxx_ReadPage(uint8_t *pBuffer,uint32_t Page_Address,uint32_t OffsetInByte,uint32_t NumByteToRead_up_to_PageSize);
extern	void	W25qxx_WritePage(uint8_t *pBuffer	,uint32_t Page_Address,uint32_t OffsetInByte,uint32_t NumByteToWrite_up_to_PageSize);
extern	void 	W25qxx_EraseSector(uint32_t SectorAddr);
extern	uint32_t 	W25qxx_PageToSector(uint32_t PageAddress);
extern	void 	W25qxx_WriteEnable(void);
extern	void 	W25qxx_WriteDisable(void);

#endif /* INC_SPI25W_DRIVER_H_ */
