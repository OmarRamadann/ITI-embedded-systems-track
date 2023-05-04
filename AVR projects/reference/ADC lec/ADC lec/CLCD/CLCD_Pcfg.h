/*
 * CLCD_Pcfg.h
 *
 *  Created on: Oct 11, 2022
 *      Author: abdullah
 */

#ifndef HAL_CLCD_CLCD_PCFG_H_
#define HAL_CLCD_CLCD_PCFG_H_
#include "../../SERVICES/BIT_math.h"
#include"../../SERVICES/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_interface.h"
#define CLCD_DATA_PORT      DIO_PORTA
#define CLCD_CONTROL_PORT   DIO_PORTD
#define CLCD_RS             DIO_PIN0
#define CLCD_RW             DIO_PIN1
#define CLCD_EN             DIO_PIN2

#endif /* HAL_CLCD_CLCD_PCFG_H_ */
