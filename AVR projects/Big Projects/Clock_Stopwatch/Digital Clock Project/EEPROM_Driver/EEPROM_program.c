/*
 * EEPROM_program.c

 *
 *  Created on: Apr 13, 2023
 *      Author: hp
 */
#include "../../MCAL/Comm_Protocols/I2C/I2C_interface.h"
#include "EEPROM_private.h"
#include "../../Common/STD_types.h"
#include <util/delay.h>

void EEPROM_voidInit(void)
{
	I2C_voidInitMaster();
}

void EEPROM_Write_Byte(u16 Address , u8 Data){

	I2C_ERROR_STATUS State = NOK;
	State= I2C_StartCondition();
//_delay_ms(200);
	if(State == OK){
		State=  I2C_Master_Send_Slave_Address_With_Write( 0x50 | ( ( Address & 0x0700 ) >> 8 ) );
//		_delay_ms(200);
		if(State == OK){
			//_delay_ms(100);
			State= 	 I2C_Maste_Write_Byte_To_Slave((u8)Address);

			if(State == OK){
//				_delay_ms(200);
				State= I2C_Maste_Write_Byte_To_Slave(Data);
//				_delay_ms(200);
				if(State == OK){
					I2C_StopCondition();
				}
			}
		}
	}

}

u8 EEPROM_Read_Byte(u16 Address){
	u8 LOC_u8Data;
I2C_ERROR_STATUS State = NOK;
State= I2C_StartCondition();
//	_delay_ms(100);
	if(State == OK){
		State=I2C_Master_Send_Slave_Address_With_Write( 0x50 | ( ( Address & 0x0700 ) >> 8 ) );
//		_delay_ms(100);
		if(State == OK){
			State= I2C_Maste_Write_Byte_To_Slave((u8)Address);
//			_delay_ms(100);

			if(State == OK){
				State=	 I2C_RepeatedStart();
				if(State == OK){
//					_delay_ms(100);
					State=	 I2C_Master_Send_Slave_Address_With_Read( 0x50 | ( ( Address & 0x0700 ) >> 8 ) );
//					_delay_ms(100);
					if( State == OK ){
					//	_delay_ms(100);
						State=	 I2C_Master_Read_Byte_From_Slave_NACK(&LOC_u8Data);
//						_delay_ms(100);
						if(State == OK){
							I2C_StopCondition();
						}
					}
				}
			}
		}
	}
	return LOC_u8Data;
}



















//void EEPROM_voidWriteData(u8 data,u16 address)
//{
//	I2C_StartCondition();
//	_delay_ms(100);
//
//	I2C_Master_Send_Slave_Address_With_Write( 0x50 | ( ( address & 0x0700 ) >> 8 ) );
//	_delay_ms(100);
//	I2C_Maste_Write_Byte_To_Slave((u8)address);
//	//_delay_ms(100);
//	I2C_Maste_Write_Byte_To_Slave(data);
//	_delay_ms(100);
//	I2C_StopCondition();
//
//}
//u8 EEPROM_voidReadData(u16 address)
//{
//	u8 ptr;
//	I2C_StartCondition();
//	_delay_ms(100);
//
//	I2C_Master_Send_Slave_Address_With_Write( 0x50 | ( ( address & 0x0700 ) >> 8 ) );
//	_delay_ms(100);
//	I2C_Maste_Write_Byte_To_Slave((u8)address);
//	_delay_ms(100);
//	I2C_RepeatedStart();
//	//_delay_ms(100);
//	I2C_Master_Send_Slave_Address_With_Read(( 0x50 | ( ( address & 0x0700 )>>8 ) ));
//	_delay_ms(100);
//	I2C_Master_Read_Byte_From_Slave_NACK(&ptr);
//	//_delay_ms(100);
//	I2C_StopCondition();
//	return ptr;
//}
