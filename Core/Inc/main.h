/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SPDIF_OUT_Pin GPIO_PIN_3
#define SPDIF_OUT_GPIO_Port GPIOE
#define ACTIVITY_Pin GPIO_PIN_5
#define ACTIVITY_GPIO_Port GPIOE
#define SIGIN2_Pin GPIO_PIN_0
#define SIGIN2_GPIO_Port GPIOC
#define SIGIN3_Pin GPIO_PIN_1
#define SIGIN3_GPIO_Port GPIOC
#define SIGIN0_Pin GPIO_PIN_2
#define SIGIN0_GPIO_Port GPIOC
#define SIGIN1_Pin GPIO_PIN_0
#define SIGIN1_GPIO_Port GPIOA
#define SIGIN4_Pin GPIO_PIN_2
#define SIGIN4_GPIO_Port GPIOA
#define SIGIN5_Pin GPIO_PIN_3
#define SIGIN5_GPIO_Port GPIOA
#define ANLG0_Pin GPIO_PIN_4
#define ANLG0_GPIO_Port GPIOA
#define ANLG1_Pin GPIO_PIN_5
#define ANLG1_GPIO_Port GPIOA
#define ANLG2_Pin GPIO_PIN_6
#define ANLG2_GPIO_Port GPIOA
#define ANLG3_Pin GPIO_PIN_7
#define ANLG3_GPIO_Port GPIOA
#define OPAPMP_DAC1_Pin GPIO_PIN_4
#define OPAPMP_DAC1_GPIO_Port GPIOC
#define ANLG4_Pin GPIO_PIN_5
#define ANLG4_GPIO_Port GPIOC
#define ANLG5_Pin GPIO_PIN_0
#define ANLG5_GPIO_Port GPIOB
#define OPAMP_DAC2_Pin GPIO_PIN_7
#define OPAMP_DAC2_GPIO_Port GPIOE
#define SPI4_SS_Pin GPIO_PIN_11
#define SPI4_SS_GPIO_Port GPIOE
#define SD_CD_Pin GPIO_PIN_7
#define SD_CD_GPIO_Port GPIOC
#define DIGITAL2_Pin GPIO_PIN_1
#define DIGITAL2_GPIO_Port GPIOD
#define SPI1_SS_Pin GPIO_PIN_6
#define SPI1_SS_GPIO_Port GPIOD
#define DIGITAL0_Pin GPIO_PIN_6
#define DIGITAL0_GPIO_Port GPIOB
#define DIGITAL1_Pin GPIO_PIN_8
#define DIGITAL1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
