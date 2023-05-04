/*
 * private.h
 *
 *  Created on: Mar 30, 2023
 *      Author: hp
 */

#ifndef MCAL_EXT_INT_INT1_INT1_PRIVATE_H_
#define MCAL_EXT_INT_INT1_INT1_PRIVATE_H_

typedef enum
{
	INT1_RisingEdge,
	INT1_FallingEdge,
	INT1_OnChange,
	INT1_LowLevel
}Event;

typedef enum
{
	INT1_Polling,
	INT1_Interrupt
}INT_Usage;
typedef enum
{
	ISC00,
	ISC01,
	ISC10,
	ISC11
}MCUCR_Bits;
typedef enum
{
	INT2=5,
	INT0,
	INT1
}GICR_Bits;
typedef enum
{
	I=7
}SREG_Bits;
typedef enum
{
	INTF2=5,
	INTF0,
	INTF1
}GIFR_Bits;

#endif /* MCAL_EXT_INT_INT1_INT1_PRIVATE_H_ */
