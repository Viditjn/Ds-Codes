#include<stdio.h>
int prime[500005]={0};
int num[8000000]={0};
void primeno()
{
	int i,j,k;
	for(i=2,k=1;k<=500005;i++)
	{
		if(num[i]==0)
		{
			prime[k]=i;
			k++;
			for(j=1;j*i<8000000;j++)
				num[j*i]=1;
		}
	}
	return;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	primeno();
	for(i=0;i<=n;i++)
		printf("%d ",prime[i]);
	return 0;
}
