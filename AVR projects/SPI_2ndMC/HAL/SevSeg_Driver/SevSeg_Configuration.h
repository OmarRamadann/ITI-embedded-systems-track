/*
 * SevSeg_Configuration.h
 *
 *  Created on: Mar 23, 2023
 *      Author: hisha
 */

#ifndef HAL_SEVSEG_SEVSEG_CONFIGURATION_H_
#define HAL_SEVSEG_SEVSEG_CONFIGURATION_H_
typedef struct
{
	u8 SevSeg_Type       ;//CA or CC
	u8 SevSeg_Group      ;//
	u8 SevSeg_EnablePort ;//common pin in which group
	u8 SevSeg_EnablePin  ;//common pin in which pin
}SevSeg_info;


#endif /* HAL_SEVSEG_SEVSEG_CONFIGURATION_H_ */
