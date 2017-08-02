#include<stdio.h>
int min(int N,int k,int arry[N])
{
	int temp=arry[0],i,j,add[N],head=0,tail=0;
	for(i=0;i<N;i++)
	{
		add[i]=0;
		if(temp>=arry[i])
			temp=arry[i];
	}
	for(i=0;i<k;i++)
	{
		while(head!=0 && arry[i]<=arry[add[head-1]])
		{
			head=head-1;
			add[head]=0;
		}
		add[head]=i;
		head++;
	}
	for(;i<N;i++)
	{
		if(temp<=arry[add[tail]])
			temp=arry[add[tail]];
	//	printf("%d ",arry[add[tail]]);
		while(head!=0 && add[tail]<=i-k && head>tail)
		{
			add[tail]=0;
			tail++;
		}
		while(head>tail && arry[i]<=arry[add[head-1]])
		{
			head=head-1;
			add[head]=0;
		}
		add[head]=i;
		head++;
	}
	if(temp<=arry[add[tail]])
		temp=arry[add[tail]];
	return temp;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		int i,ans,arry[N];
		for(i=0;i<N;i++)
			scanf("%d",&arry[i]);
		for(i=1;i<N;i++)
			printf("%d ",min(N,i,arry));
		printf("%d\n",min(N,N,arry));
	}
	return 0;
}
