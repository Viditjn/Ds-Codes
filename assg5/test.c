#include<stdio.h>
int main(){
	int x=1000;
	printf("1000\n");
	while(x--){
		int a=rand()%4,b=rand()%1000+1;
		if(a==0){
			printf("I %d\n",b);
		}	
		if(a==1){
			printf("D %d\n",b);
		}	
		if(a==2){
			printf("K %d\n",b);
		}	
		if(a==3){
			printf("C %d\n",b);
		}	
	}
	return 0;
}
