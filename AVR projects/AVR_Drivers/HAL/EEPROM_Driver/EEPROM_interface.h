/*
 * EEPROM_interface.h
 *
 *  Created on: Apr 13, 2023
 *      Author: hp
 */

#ifndef HAL_EEPROM_DRIVER_EEPROM_INTERFACE_H_
#define HAL_EEPROM_DRIVER_EEPROM_INTERFACE_H_

void EEPROM_voidInit(void);
void EEPROM_voidWriteData(u8 data,u16 address);
u8 EEPROM_voidReadData(u16 address);

void EEPROM_Write_Byte(u16 Address , u8 Data);
u8 EEPROM_Read_Byte(u16 Address);

#endif /* HAL_EEPROM_DRIVER_EEPROM_INTERFACE_H_ */
