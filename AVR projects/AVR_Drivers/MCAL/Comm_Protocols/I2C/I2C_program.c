/*
 * I2C_program.c
 *
 *  Created on: Apr 9, 2023
 *      Author: hp
 */
#include "I2C_private.h"
#include "../../../Common/Bit_Math.h"
#include "../../../Common/STD_types.h"
/**********************Master &slave Driver************************************/
void I2C_voidInitMaster(void)
{
	//adjust clk freq by adding a certain value to TWBR
	TWBR=0x32;
	//choose prescaler 1
	Set_Bit(TWCR,2);
//	TWSR=0x00;
	Clr_Bit(TWSR,0);
	Clr_Bit(TWSR,1);
	//TWAR=0b00000010;
	//enable the the TW protocol

	//give an address to the master incase it is used as slave
	//TWAR=0b11110100;//disabled the general call
}

void I2C_voidInitSlave(void)
{

TWAR=0b00000010;
Set_Bit(TWCR,2);
}

I2C_ERROR_STATUS I2C_StartCondition(void)
{
	//enable the the TW protocol
//	TWCR = (1 << 7) | (1 << 5) | (1 << 2);
//	TWCR=0b10100100;
//	Set_Bit(TWCR,2);
//	//set start condition
		Set_Bit(TWCR,5);
//	//clear the INT flag
	Set_Bit(TWCR,7);

	//set enable Ack bit
	//Set_Bit(TWCR,6);

	//check for the flag that means that start condition is
	//transmitted
	while(Get_Bit(TWCR,7)==0);
	//clear the start condition bit
	//Clr_Bit(TWCR,5);
	//check the value of status reg TWSR for the status code
	//for sent start condition
	//status check for master transmission mode
	if(((TWSR&0xF8))==0x08)
	{
		return OK;
	}
	else
	{
		return NOK;
	}
}

	I2C_ERROR_STATUS I2C_RepeatedStart(void)
	{
		//set start condition
		//TWCR=0b10100100;

		Set_Bit(TWCR,5);
		//clear the INT flag
			Set_Bit(TWCR,7);
			//enable the the TW protocol
//			Set_Bit(TWCR,2);
			//set enable Ack bit
			//Set_Bit(TWCR,6);

			//check for the flag that means that start condition is
			//transmitted
			while(Get_Bit(TWCR,7)==0);
			//clear the start condition bit
				//Clr_Bit(TWCR,5);
			//check the value of status reg TWSR for the status code
			//for sent start condition
			//status check for master transmission mode
			if(((TWSR&0xF8))==0x10)
				{
					return OK;
				}
				else
				{
					return NOK;
				}

	}





void I2C_StopCondition(void)
{
	//TWCR = (1 << 7) | (1 << 4) | (1 << 2);
//	TWCR=0b10010100;
	//set stop condition
		Set_Bit(TWCR,4);
//	//clear the INT flag
	Set_Bit(TWCR,7);
//	//enable the the TW protocol
//	Set_Bit(TWCR,2);
	//Clr_Bit(TWCR,5);
	//set enable Ack bit
	//Set_Bit(TWCR,6);

	//stop bit clrd auto
}

I2C_ERROR_STATUS I2C_Master_Send_Slave_Address_With_Write(u8 Address)
{
	//load slave address in TWDR (address to be called)
		TWDR=(Address<<1);
		//Clr_Bit(TWDR,0);
		//clear the start condition bit

//		TWCR=0b10000100;

		Clr_Bit(TWCR,5);
	//enable the the TW protocol
//		Set_Bit(TWCR,2);
		//Set_Bit(TWCR,6);
		//clear the INT flag
		Set_Bit(TWCR,7);

		//check for the flag
		while(Get_Bit(TWCR,7)==0);
		//compare to the status word
		//if SLA+W received &ACK received
		if (((TWSR&0xF8))==0x18)
		{
				return OK;
			}
//		else if(((TWSR&0xF8))==0x20)
//		{
//			return OK_NACK;
//		}
//		//check for arbitration lost or NACK
//			else if(((TWSR&0xF8))==0x38)
//			{
//				return ArbitLost_NACk;
//			}
		else
		{
			return NOK;
		}
}

I2C_ERROR_STATUS I2C_Master_Send_Slave_Address_With_Read(u8 Address)
{
	//load slave address in TWDR (address to be called)
			TWDR=(Address<<1);
			Set_Bit(TWDR,0);//SET R/W Bit To Read From Slave
		//	TWCR=0b10000100;

			//clear the start condition bit
			Clr_Bit(TWCR,5);
			//clear the INT flag
			Set_Bit(TWCR,7);
			//Set_Bit(TWCR,6);
			//enable the the TW protocol
//				Set_Bit(TWCR,2);
			//check for the flag
			while(Get_Bit(TWCR,7)==0);
			//compare to the status word
			//if SLA+W received &ACK received
			if (((TWSR&0xF8))==0x40)
			{
					return OK;
				}
//			else if(((TWSR&0xF8))==0x48)
//					{
//						return OK_NACK;
//					}
//			//check for arbitration lost or NACK
//				else if(((TWSR&0xF8))==0x38)
//				{
//					return ArbitLost_NACk;
//				}
			else
			{
				return NOK;
			}


}

I2C_ERROR_STATUS I2C_Maste_Write_Byte_To_Slave(u8 Data)
{
	TWDR=Data;
//	TWCR=0b10100100;
	//enable the the TW protocol
//	Set_Bit(TWCR,2);
//	//clear the INT flag
////	TWCR=0b10000100;
	//Clr_Bit(TWCR,5);
	Set_Bit(TWCR,7);
////	Set_Bit(TWCR,6);
	//check for the flag
	while(Get_Bit(TWCR,7)==0);
	//compare to the status word
	//if data transmitted and ACK
	if (((TWSR&0xF8))==0x28)
	{
		return OK;
	}
//	else if(((TWSR&0xF8))==0x30)
//	{
//		return OK_NACK;
//	}
//	else if(((TWSR&0xF8))==0x38)
//	{
//		return ArbitLost;
//
//	}
	else
	{
		return NOK;
	}

}

I2C_ERROR_STATUS I2C_Master_Read_Byte_From_Slave_NACK(u8 * ptr)
{
	//TWCR=0b10010100;
	//enable the the TW protocol
//	Set_Bit(TWCR,2);
//	Clr_Bit(TWCR,5);
	//clear the INT flag
	Set_Bit(TWCR,7);
	//Set_Bit(TWCR,6);
	//check for the flag
	while(Get_Bit(TWCR,7)==0);
	//compare to the status word
	//if data received and ACK
	if ((TWSR&0xF8)==0x58)
	{
		*ptr=TWDR;
		return OK;

	}
//	else if((TWSR&0xF8)==0x58)
//	{
//		return OK_NACK;
//	}
	else
	{
		return NOK;
	}


}
/*******************************************************SLAVE*******************************************************************/

I2C_ERROR_STATUS I2C_Slave_Check_About_His_Addr_With_Write(void)
{

	//clear the INT flag
		Set_Bit(TWCR,7);
		//enable the the TW protocol
			Set_Bit(TWCR,2);
			//enable ACK bit
			Set_Bit(TWCR,6);
		//check for the flag
		while(Get_Bit(TWCR,7)==0);
		//compare to the status word
		//if Own Address received and ACK
		if ((TWSR&0xF8)==0x60)
		{
			return OK;
		}
		else if((TWSR&0xF8)==0x68)
		{
			return OK_ACK_ArbitLost;
		}
		else
		{
			return NOK;
		}


}

I2C_ERROR_STATUS I2C_Slave_Check_About_His_Addr_With_Read(void)
{


	//clear the INT flag
		Set_Bit(TWCR,7);
		//enable the the TW protocol
			Set_Bit(TWCR,2);
			//enable ACK bit
			Set_Bit(TWCR,6);
		//check for the flag
		while(Get_Bit(TWCR,7)==0);
		//compare to the status word
		//if Own Address received and ACK
		if ((TWSR&0xF8)==0xA8)
		{
			return OK;
		}
		else if((TWSR&0xF8)==0xB0)
		{
			return OK_ACK_ArbitLost;
		}
		else
		{
			return NOK;
		}


}

I2C_ERROR_STATUS I2C_Slave_Read_Byte_From_Master(u8 * ptr)
{

			//clear the INT flag
	TWCR=0b11000100;
//			Set_Bit(TWCR,7);
//			//enable the the TW protocol
//				Set_Bit(TWCR,2);
//				//enable ACK bit
//				Set_Bit(TWCR,6);
			//check for the flag
			while(Get_Bit(TWCR,7)==0);
			//compare to the status word
			//if Own Address  ,DATA received and ACK
			if ((TWSR&0xF8)==0x80)
			{
				return OK;
			}
			else if((TWSR&0xF8)==0x88)
			{
				return OK_NACK;
			}
			else
			{
				return NOK;
			}


}
I2C_ERROR_STATUS I2C_Slave_Write_Byte_To_Master(u8 Data)
{
TWCR=0b11000100;
	//clear the INT flag
		Set_Bit(TWCR,7);
		//enable the the TW protocol
			//Set_Bit(TWCR,2);
			//enable ACK bit
			Set_Bit(TWCR,6);
		//check for the flag
		while(Get_Bit(TWCR,7)==0);
		//compare to the status word
		//if Own Address  ,DATA received and ACK
		if ((TWSR&0xF8)==0xB8)
		{
			return OK;
		}
		else if((TWSR&0xF8)==0xC0)
		{
			return OK_NACK;
		}
		else
		{
			return NOK;
		}


}
