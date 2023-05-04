/*
 * KEY_PAD_interface.h
 *
 *  Created on: Oct 24, 2022
 *      Author: abdullah
 */

#ifndef HAL_KEY_PAD_KEY_PAD_INTERFACE_H_
#define HAL_KEY_PAD_KEY_PAD_INTERFACE_H_

#include"../DIO/DIO_interface.h"

#include"../SERVICES/STD_TYPES.h"
#include"../SERVICES/BIT_math.h"


#define TRUE  1
#define FLASE 0



void KEY_pad_voidinit(void);
u8 Key_Pad_u8GetButtonPressed(void);









#endif /* HAL_KEY_PAD_KEY_PAD_INTERFACE_H_ */
