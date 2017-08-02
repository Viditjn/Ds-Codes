#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int stack[200000]={0},i,j;
		char query[200000];
		scanf("%s",query);
		for(i=0,j=0;i<strlen(query);i++)
		{
			if(stack[0]==0)
			{
				stack[0]=query[i];
				j++;
			}
			else if(query[i]-stack[j-1]==2||query[i]-stack[j-1]==1)
			{
				stack[j-1]=0;
				j--;
			}
			else
			{
				stack[j]=query[i];
				j++;
			}
		}
		if(stack[0]==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
