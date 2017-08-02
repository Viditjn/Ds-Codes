#include<stdio.h>
void morfin(int arry[],int n)
{
	int left[n+1],right[n+1],stack[n+1],head=0;
	int i;
	for(i=0;i<n;i++)
	{
		left[i]=-1;
		right[i]=n;
		stack[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		while(head!=0 && arry[stack[head-1]]>=arry[i])
		{
			head=head-1;
			stack[head]=-1;
		}
		if(head!=0)
			left[i]=stack[head-1];
		stack[head]=i;
		head++;
	}
	for(i=0;i<n;i++)
		stack[i]=-1;
	head=0;
	for(i=n-1;i>=0;i--)
	{
		while(head!=0&&arry[stack[head-1]]>=arry[i])
		{
			head=head-1;
			stack[head]=-1;
		}
		if(head!=0)
			right[i]=stack[head-1];
		stack[head]=i;
		head++;
	}
	int ans[n+1];
	for(i=0;i<=n;i++)
		ans[i]=0;
	for(i=0;i<n;i++)
	{
		int len = right[i] - left[i] -1;
		if(ans[len]>=arry[i])
			ans[len]=ans[len];
		else
			ans[len]=arry[i];
	}
	for(i=n-1;i>=1;i--)
	{
		if(ans[i]>=ans[i+1])
			ans[i]=ans[i];
		else
			ans[i]=ans[i+1];
	}
	for(i=1;i<n;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
	return;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,i;
		scanf("%d",&N);
		int arry[N];
		for(i=0;i<N;i++)
			scanf("%d",&arry[i]);
		morfin(arry,N);
	}
	return 0;
}
