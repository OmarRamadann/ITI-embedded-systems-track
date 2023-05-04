/*
 * SevSeg_Interface.h
 *
 *  Created on: Mar 23, 2023
 *      Author: hisha
 */

#ifndef HAL_SEVSEG_SEVSEG_INTERFACE_H_
#define HAL_SEVSEG_SEVSEG_INTERFACE_H_

#include  "SevSeg_Private.h"
#include  "SevSeg_Configuration.h"
#include"../../Common/STD_types.h"

SevErrState SevSeg_SevErrStateSetNumber(u8 Copy_Number , SevSeg_info * SevenSegment1);//if we add more than one SevSeg

SevErrState SevSeg_SevErrStateDisplayRange(SevSeg_info * SevenSegment1 , u8 Copy_start , u8 Copy_End );//show first and last number

SevErrState SevSeg_SevErrStateDisplayMax(SevSeg_info * SevenSegment1);//count from start to max


#endif /* HAL_SEVSEG_SEVSEG_INTERFACE_H_ */
