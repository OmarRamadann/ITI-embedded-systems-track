#include<stdio.h>
int main(){
unsigned int a,b;
printf("please enter number a:");
scanf("%i",&a);
printf("please enter number b:");
scanf("%i",&b);
printf("a+b = %i\n",a+b);
printf("a-b = %i\n",a-b);
printf("a&b = %i\n",a&b);
printf("a|b = %i\n",a|b);
printf("a^b = %i\n",a^b);
printf("a/b = %f\n",(float)a/b);
}