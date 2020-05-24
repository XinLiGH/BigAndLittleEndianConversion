/**
  ******************************************************************************
  * @file    main.c
  * @author  XinLi
  * @version v1.0
  * @date    24-May-2020
  * @brief   Main program body.
  ******************************************************************************
  * @attention
  *
  * <h2><center>Copyright &copy; 2020 XinLi</center></h2>
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <https://www.gnu.org/licenses/>.
  *
  ******************************************************************************
  */

/* Header includes -----------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>

/* Macro definitions ---------------------------------------------------------*/
/* Type definitions ----------------------------------------------------------*/
/* Variable declarations -----------------------------------------------------*/
/* Variable definitions ------------------------------------------------------*/
/* Function declarations -----------------------------------------------------*/
static void BigAndLittleEndianConversion(void *data, uint32_t size);

/* Function definitions ------------------------------------------------------*/

/**
  * @brief  Big and little endian conversion.
  * @param  [in] data: The pointer of the data to be converted.
  * @param  [in] size: The size of the data to be converted.
  * @return None.
  */
static void BigAndLittleEndianConversion(void *data, uint32_t size)
{
  for(uint32_t i = 1; i < size; i++)
  {
    for(uint32_t j = 1; j < size - i + 1; j++)
    {
      uint8_t c = *(((uint8_t *)data) + j - 1);
      *(((uint8_t *)data) + j - 1) = *(((uint8_t *)data) + j);
      *(((uint8_t *)data) + j) = c;
    }
  }
}

/**
  * @brief  Main program.
  * @param  None.
  * @return None.
  */
int main(void)
{
  uint8_t  littleEndianDataBuffer[4] = {(uint8_t)(123456789>>0),  (uint8_t)(123456789>>8),  (uint8_t)(123456789>>16), (uint8_t)(123456789>>24)};
  uint8_t  bigEndianDataBuffer[4]    = {(uint8_t)(123456789>>24), (uint8_t)(123456789>>16), (uint8_t)(123456789>>8),  (uint8_t)(123456789>>0)};
  uint32_t littleEndianData          = *(uint32_t *)littleEndianDataBuffer;
  uint32_t bigEndianData             = *(uint32_t *)bigEndianDataBuffer;
  
  BigAndLittleEndianConversion(&bigEndianData, sizeof(bigEndianData));
  
  if(littleEndianData == bigEndianData)
  {
    printf("bigEndianData = %u", bigEndianData);
  }
  
  while(1)
  {
  }
}
