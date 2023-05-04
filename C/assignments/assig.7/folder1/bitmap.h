#define set_bit(reg,bit) 	reg|=(1<<bit)
#define clearbit(reg,bit)  	reg& =~(1<<bit)
#define toggle_bit(reg,bit)	reg^ =(1<<bit)
#define get_bit(reg,bit)	reg& =(1<<bit)