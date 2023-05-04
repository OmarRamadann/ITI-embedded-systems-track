#include<stdio.h>
#include<math.h>
void main(){
int a,chk1,chk2 ;
int j=0;
int size,msb;
char exit = 0;
int count=0;
int max=(pow(2,23))+1;
do{
	printf("enter number:");
	scanf("%d",&a);
	size=(sizeof(a)-1)*8;
	//printf("size of a:%d",sizeof(a));
	
	for(int i=0;i<size;i++){
	chk1=a&(max>>i);
	//printf("size= %d\n",max>>i);
	//printf("chk1= %d\n",chk1);
	if(chk1==(max>>i)){
		msb=(max>>i);
		//printf("msb= %d\n",msb);
		break;
	}
	}
	//while(!=1){
		for( ; ; ){
			j++;
				chk2=a&(msb>>j);
		//printf("chk2= %d\n",chk2);
		if(chk2==0){
			count+=1;
		//printf("count= %d\n",count);}
		//j++;
	}
		if((msb>>j)==1){
			break;
		
		}
	}
	/*for(int j=0;j<msb;j++){
		chk2=a&(msb>>j);
		printf("chk2= %d\n",chk2);
		if(chk2==0){
			count+=1;
			printf("count= %d\n",count);
		}
	}*/
	printf("number of zeros equal: %d\n",count);
	printf("press 1 to exit: ");
	scanf(" %c",&exit);
	
	}while(exit!='e');

}