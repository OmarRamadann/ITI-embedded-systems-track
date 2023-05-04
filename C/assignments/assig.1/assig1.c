#include<stdio.h>
int main(void){//need 11 base
	
	int base=11;
	int inc=1;
	
	for (int a=0;a<(base+1)/2;a++){
		int k=(base-inc)/2;
		int flag=0;
	for(int j=0;j<2;j++){
		
	for(int i=0;i<k;i++){
		printf(" ");
		
		
	}
	
	for(int p=0;p<inc;p++){
	if(flag==1){
		break;
	}
	printf("*");
	
	}
	printf("\n");
	flag=1;
	
	}inc+=2;
	}
	return 0;
}