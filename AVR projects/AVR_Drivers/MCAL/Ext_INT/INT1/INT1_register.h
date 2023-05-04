/*
 * INT1_register.h
 *
 *  Created on: Mar 30, 2023
 *      Author: hp
 */

#ifndef MCAL_EXT_INT_INT1_INT1_REGISTER_H_
#define MCAL_EXT_INT_INT1_INT1_REGISTER_H_


//pins INT1,INT2,INT0
//these pins are specific interrupt enable
#define GICR_Reg  *((volatile u8*)(0x5B))
//has the 3 pins that get set when flag rises
#define GIFR_Reg  *((volatile u8*)(0x5A))
//general interrupt enable
#define SREG_Reg  *((volatile u8*)(0x5F))
//those two decide the level or edge trigger for the 3 interrupts
#define MCUCR_Reg  *((volatile u8*)(0x55))
#define MCUCSR_Reg  *((volatile u8*)(0x54))


#endif /* MCAL_EXT_INT_INT1_INT1_REGISTER_H_ */
