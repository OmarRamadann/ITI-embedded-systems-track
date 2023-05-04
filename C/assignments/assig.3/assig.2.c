#include<stdio.h>
void main(){
	int id,pass,count;
	printf("please enter your ID: ");
	scanf(" %d",&id);
	switch (id){
		default:
		printf("you are not registered");
		break;
		case 1234:
		count=1;
		printf("please enter your password\n");
		scanf(" %d",&pass);
		while(count!=3){
		
		if (pass==7788){
			printf("welcome Ahmed\n");
			break;
		}
		else{
			
				++count;
				printf("Try again: ");
				scanf(" %d",&pass);
				
			}
			
		}
		break;
		case 5678:
		count=1;
		printf("please enter your password\n");
		scanf(" %d",&pass);
		while(count!=3){
		scanf(" %d",&pass);
		if (pass==5566){
			printf("welcome Amr\n");
			break;
		}
		else{
			
				++count;
				printf("Try again: ");
				scanf(" %d",&pass);
				
			}
			
		}
		break;
		case 9870:
		count=1;
		printf("please enter your password\n");
		scanf(" %d",&pass);
		while(count!=3){
		
		if (pass==1122){
			printf("welcome Wael\n");
			break;
		}
		else{
			
				++count;;
				printf("Try again: ");
				scanf(" %d",&pass);
				
			}
			
		}
		break;
		
		
	}
	if (count==3){
			printf("no more tries");
			
		}
}