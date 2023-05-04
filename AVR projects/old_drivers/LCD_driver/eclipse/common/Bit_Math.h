/*
 * Bit_Math.h
 *
 *  Created on: Mar 23, 2023
 *      Author: hp
 */

#ifndef COMMON_BIT_MATH_H_
#define COMMON_BIT_MATH_H_
#define Set_Bit(Reg,Bit)   Reg|=(1<<Bit)

#define Clr_Bit(Reg,Bit)   Reg&=~(1<<Bit)

#define Tog_Bit(Reg,Bit)   Reg^=(1<<Bit)

#define Get_Bit(Reg,Bit)   ((Reg>>Bit)&0x01)


#endif /* COMMON_BIT_MATH_H_ */
