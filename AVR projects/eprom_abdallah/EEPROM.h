

#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_VidInit(void);
void EEPROM_Write_Byte(u16 Address , u8 Data);
u8 EEPROM_Read_Byte(u16 Address);

#endif /* EEPROM_H_ */
