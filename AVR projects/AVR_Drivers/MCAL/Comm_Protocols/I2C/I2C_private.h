/*
 * I2C_private.h
 *
 *  Created on: Apr 9, 2023
 *      Author: hp
 */

#ifndef MCAL_COMM_PROTOCOLS_I2C_I2C_PRIVATE_H_
#define MCAL_COMM_PROTOCOLS_I2C_I2C_PRIVATE_H_


#define TWBR 	*((volatile u8 *)0x20)
#define TWSR 	*((volatile u8 *)0x21)
#define TWAR 	*((volatile u8 *)0x22)
#define TWDR 	*((volatile u8 *)0x23)
#define TWCR 	*((volatile u8 *)0x56)



typedef enum
{
	NOK,
	OK,
	ArbitLost_NACk,
	OK_NACK,
	ArbitLost,
	OK_ACK_ArbitLost
}I2C_ERROR_STATUS;

#endif /* MCAL_COMM_PROTOCOLS_I2C_I2C_PRIVATE_H_ */
