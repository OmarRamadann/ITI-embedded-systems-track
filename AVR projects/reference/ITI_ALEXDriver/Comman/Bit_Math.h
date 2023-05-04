/*
 * Bit_Math.h
 *
 *  Created on: Mar 22, 2023
 *      Author: hisha
 */

#ifndef COMMAN_BIT_MATH_H_
#define COMMAN_BIT_MATH_H_

#define Set_Bit(Reg,Bit)   Reg|=(1<<Bit)

#define Clr_Bit(Reg,Bit)   Reg&=~(1<<Bit)

#define Tog_Bit(Reg,Bit)   Reg^=(1<<Bit)

#define Get_Bit(Reg,Bit)   ((Reg>>Bit)&0x01)

#endif /* COMMAN_BIT_MATH_H_ */
