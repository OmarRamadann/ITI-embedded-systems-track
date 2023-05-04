/*
 * I2C_interface.h
 *
 *  Created on: Apr 9, 2023
 *      Author: hp
 */


#ifndef MCAL_COMM_PROTOCOLS_I2C_I2C_INTERFACE_H_
#define MCAL_COMM_PROTOCOLS_I2C_I2C_INTERFACE_H_
#include "../../../Common/STD_types.h"
#include "I2C_private.h"
void I2C_voidInitMaster(void);
void I2C_voidInitSlave(void);
I2C_ERROR_STATUS I2C_StartCondition(void);
I2C_ERROR_STATUS I2C_RepeatedStart(void);//New
void I2C_StopCondition(void);
I2C_ERROR_STATUS I2C_Master_Send_Slave_Address_With_Write(u8 Address);
I2C_ERROR_STATUS I2C_Master_Send_Slave_Address_With_Read(u8 Address);
I2C_ERROR_STATUS I2C_Maste_Write_Byte_To_Slave(u8 Data);
I2C_ERROR_STATUS I2C_Master_Read_Byte_From_Slave_NACK(u8 * ptr);//New
I2C_ERROR_STATUS I2C_Slave_Check_About_His_Addr_With_Write(void);
I2C_ERROR_STATUS I2C_Slave_Check_About_His_Addr_With_Read(void);//New
I2C_ERROR_STATUS I2C_Slave_Read_Byte_From_Master(u8 * ptr);
I2C_ERROR_STATUS I2C_Slave_Write_Byte_To_Master(u8 Data);//New

#endif /* MCAL_COMM_PROTOCOLS_I2C_I2C_INTERFACE_H_ */
