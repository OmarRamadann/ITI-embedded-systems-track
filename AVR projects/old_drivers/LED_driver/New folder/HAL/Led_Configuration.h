/*
 * Led_Configuration.h
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */

#ifndef HAL_LED_LED_CONFIGURATION_H_
#define HAL_LED_LED_CONFIGURATION_H_
#include"Led_Private.h"
#include"../MCAL/DIO_private.h"
typedef struct
{
DIO_GroupNumber        Led_Group ;
DIO_PinNumber          Led_Pin ;
Led_ConnectionType     ConnectionType ;
}Led_info;


#endif /* HAL_LED_LED_CONFIGURATION_H_ */
