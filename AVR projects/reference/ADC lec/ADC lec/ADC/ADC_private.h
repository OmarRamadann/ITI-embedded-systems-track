/*
 * ADC_private.h
 *
 *  Created on: Nov 22, 2022
 *      Author: abdullah
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_
#define NULL 0
#define GIFR   *((volatile u8 *)0x5A)
#define GICR   *((volatile u8 *)0x5B)
#define SREG   *((volatile u8 *)0x5F)
///////
#define ADMUX   *((volatile u8 *)0x27)
#define ADCSRA   *((volatile u8 *)0x26)
#define ADCL   *((volatile u8 *)0x24)
#define ADCH   *((volatile u8 *)0x25)
#define SFIOR   *((volatile u8 *)0x50)



#define ADC0    0
#define ADC1    1
#define ADC2    2
#define ADC3    3
#define ADC4    4
#define ADC5    5
#define ADC6    6
#define ADC7    7

#define ADC_VREF_AREF   0   //TAKE  externally  FROM AREF
#define ADC_VREF_AVCC   1 //INTERAL VCC
#define ADC_VREF_256V  2 //internal 2.56v

#define ADC_SINGLE_ENDED  0
#define ADC_DIFFRENTIAL   1


#define ADC_SINGLE_COVERSION   0
#define ADC_FREE_RUNNING  1

#define ADC_RIGHT_ADJUSTMENT 0
#define ADC_LEFT_ADJUSTMENT 1

#define POLLING   0
#define INTERRUPT  1

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
