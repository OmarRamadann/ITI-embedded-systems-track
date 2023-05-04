int set_bit(int reg,int bit){
	int power=pow(2,(double)bit);
	return reg | (int)power;
}
int clear_bit(int reg,int bit){
	int power=pow(2,(double)bit);
	return reg & (int)power;
}
int toggle_bit(int reg,int bit){
	int power=pow(2,(double)bit);
	return reg ^ (int)power;
}
int get_bit(int reg,int bit){
	(reg&(1<<bit)>>bit);
}