/*
 * ADC_pcfg.h
 *
 *  Created on: Nov 22, 2022
 *      Author: abdullah
 */

#ifndef MCAL_ADC_ADC_PCFG_H_
#define MCAL_ADC_ADC_PCFG_H_
#include"ADC_private.h"

#define ADC_PIN     ADC0
/*options:
 * ADC0--->ADC7
 */


#define ADC_CONVERSION_MODE  ADC_SINGLE_COVERSION
/*options:
 * ADC_SINGLE_COVERSION
 * ADC_FREE_RUNNING
 */
#define ADC_MODE          ADC_SINGLE_ENDED
/*options :
 *  ADC_SINGLE_ENDED
 *  ADC_DIFFRENTIAL
 */
#define ADC_ADJUSTMENT    ADC_RIGHT_ADJUSTMENT
/*options:
 * ADC_RIGHT_ADJUSTMENT
 * ADC_LEFT_ADJUSTMENT
 */
#define ADC_VREF        ADC_VREF_AVCC
/*options
 * ADC_VREF_AREF      //TAKE  externally  FROM AREF
 ADC_VREF_AVCC    //INTERAL VCC
 ADC_VREF_2.56V
 */

#define ADC_TYPE    POLLING
/*options :
 * POLLING
 * INTERRUPT
 */
#define ADC_PRESCALER  2
/*options :
 * 2
 * 4
 * 8
 * 16
 * 32
 * 64
 * 128
 */
#endif /* MCAL_ADC_ADC_PCFG_H_ */
