#include<stdio.h>
#define model 3
void main(){
	#if model ==1
	printf("bmwx5");
	#elif model==2
	printf("bmwx7");
	#else
	#error "wrong version"
	#endif
	
	
}