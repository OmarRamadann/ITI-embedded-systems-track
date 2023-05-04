#include<stdio.h>
void main(){
	int a;
	int b;
	printf("enter letter: ");
	scanf(" %c",&a);
	printf(" %c is ",a);
	//scanf(" %c",&b);  //problem??
	if ((a=='a') ||(a=='e')||(a=='i')||(a=='o')||(a=='u')){
		printf("vowel\n");
	}
	else{
		printf("constant");
	}
	
}