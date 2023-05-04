/*
 * LCD_Register.h
 *
 *  Created on: Mar 25, 2023
 *      Author: hp
 */

#ifndef HAL_LCD_REGISTER_H_
#define HAL_LCD_REGISTER_H_

#define LCD_FirstLine 0x00
#define LCD_SecondLine 0x40


/*Set CG RAM Address*/
#define  LCD_SetAddressCGRAM      0x40
/*Set DDRAM Address*///command line to change the address odf ddram
#define  LCD_SetAddressDDRAM      0x80


#endif /* HAL_LCD_REGISTER_H_ */
