#ifndef BH1750_H
#define BH1750_H

#include "stm32f7xx_hal.h"

#define BH1750_ADDR (0x23 << 1)

void BH1750_Init(I2C_HandleTypeDef *hi2c);
float BH1750_ReadLux(I2C_HandleTypeDef *hi2c);

#endif
