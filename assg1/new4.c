#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,k;
		scanf("%d %d",&N,&k);
		int arry[N],temp,i,j,add[N],head=0,tail=0;
		for(i=0;i<N;i++)
		{
			scanf("%d",&arry[i]);
			add[i]=0;
		}
		for(i=0;i<k;i++)
		{
			while(head!=0 && arry[i]>=arry[add[head-1]])
			{
				head=head-1;
				add[head]=0;
			}
			add[head]=i;
			head++;
		}
		for(;i<N;i++)
		{
			printf("%d ",arry[add[tail]]);
			while(head!=0 && add[tail]<=i-k && head>tail)
			{
				add[tail]=0;
				tail++;
			}
			while(head>tail && arry[i]>=arry[add[head-1]])
			{
				head=head-1;
				add[head]=0;
			}
			add[head]=i;
			head++;
		}
		printf("%d\n",arry[add[tail]]);
	}
	return 0;
}
