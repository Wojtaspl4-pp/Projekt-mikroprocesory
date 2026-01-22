#include "bh1750.h"
#include <stdio.h>
#include <string.h>


void BH1750_Init(I2C_HandleTypeDef *hi2c)
{
    uint8_t cmd = 0x10; // Continuous High Resolution Mode
    HAL_I2C_Master_Transmit(hi2c, BH1750_ADDR, &cmd, 1, HAL_MAX_DELAY);
}

float BH1750_ReadLux(I2C_HandleTypeDef *hi2c)
{
    uint8_t data[2];
    HAL_I2C_Master_Receive(hi2c, BH1750_ADDR, data, 2, HAL_MAX_DELAY);

    uint16_t raw = (data[0] << 8) | data[1];
    return raw / 1.2f;

}
