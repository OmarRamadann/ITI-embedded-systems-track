/*
 * ADC_interface.h
 *
 *  Created on: Nov 22, 2022
 *      Author: abdullah
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_
#include"../../SERVICES/BIT_math.h"
#include"../../SERVICES/STD_TYPES.h"
#include"../DIO/DIO_interface.h"
#include"ADC_pcfg.h"
#include"ADC_private.h"


void ADC_voidInit(void);

u16 ADC_u16getSTEPS(void);
void ADC_voidDisable(void);



void ADC_voidStartConversion(void);
#if ADC_TYPE ==POLLING
void ADC_voidClearFlag(void);
u8 ADC_u8CheckFLAG(void);
#endif
#if ADC_TYPE==INTERRUPT
void ADC_voidSetCallBackFN(void(*ptr_fn)(void));
#endif


#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
