/*
 * CLCD_interface.h
 *
 *  Created on: Oct 11, 2022
 *      Author: abdullah
 */

#ifndef HAL_CLCD_CLCD_INTERFACE_H_
#define HAL_CLCD_CLCD_INTERFACE_H_

#include "../../SERVICES/BIT_math.h"
#include"../../SERVICES/STD_TYPES.h"
#include"CLCD_Pcfg.h"


#define CLCD_ROW1       0
#define CLCD_ROW2       1
void CLCD_SendCommand(u8 Command);
void CLCD_voidInit(void);
void CLCD_voidSendData(u8 Number);

void CLCD_voidSendNumber(u32 Copy_u64Number);
void CLCD_voidSendString(u8* ptr);
void CLCD_voidSetPosition(u8 Copy_u8Row, u8 Copy_u8Col);
void CLCD_voidClearDisplay(void);
void CLCD_voidSendExtraCharAndDiplay(u8*ptr,u8 Copy_u8NumberOfChar,u8 Copy_u8row, u8 Copy_u8Col);
void CLCD_voidSendFloatNumber(f32 number);


#endif /* HAL_CLCD_CLCD_INTERFACE_H_ */
