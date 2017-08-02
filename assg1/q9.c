#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,k;
		scanf("%d %d",&N,&k);
		int arry[N],temp,i,j,add[N],head=1,tail=0;
		for(i=0;i<N;i++)
		{
			scanf("%d",&arry[i]);
			add[i]=0;
		}
		for(i=1;i<=k;i++)
		{
			while(head!=0 && ((arry[i]+arry[add[tail]]) <= arry[add[head-1]]))
			{
				head=head-1;
				add[head]=0;
			}
			add[head]=i;
			head++;
			arry[i]=arry[i]+arry[0];
		}
		for(;i<N;i++)
		{
			//printf("%d ",arry[add[tail]]);
			while(head!=0 && add[tail]<i-k && head>tail)
			{
				add[tail]=0;
				tail++;
			}
			while(head>tail && (arry[i]+arry[add[tail]])<=arry[add[head-1]])
			{
				head=head-1;
				add[head]=0;
			}
			add[head]=i;
			head++;
			arry[i]=arry[i]+arry[add[tail]];
		}
//		for(i=0;i<N;i++)
//		printf("%d ",arry[i]);
		printf("%d\n",arry[N-1]);
	}
	return 0;
}
