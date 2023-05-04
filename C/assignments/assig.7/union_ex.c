#include<stdio.h>
typedef union{
	struct
	{
		unsigned char reg0:1;
		unsigned char reg1:1;
		unsigned char reg2:1;
		unsigned char reg3:1;
		unsigned char reg4:1;
		unsigned char reg5:1;
		unsigned char reg6:1;
		unsigned char reg7:1;
	}reg_bit;
	unsigned char reg_byte;
}reg;

void main(){
	reg ADC;
	ADC.reg_byte=131;
	printf("reg_byte= %d",ADC.reg_byte);
	ADC.reg_bit.reg3=1;
		printf("reg_byte after= %d",ADC.reg_byte);//will ADD 8 TO IT

}