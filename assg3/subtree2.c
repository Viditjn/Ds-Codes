#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	long long int data;
	struct	node* link;
}node;
node* arry[1000005];
long long int visited[1000005],x,y;
long long int cost[1000005];
long long int m=1000000007;
void push(node** head,long long int dat)
{
	node* temp =(node*)malloc(sizeof(node));
	temp->data=dat;
	temp->link=*head;
	*head=temp;
	return;
}
void dfs(long long int i,node** b)
{
	node* temp;
	temp=b[i];
	visited[i]=1;
	while(temp!=NULL)
	{
		long long int t;
		t=temp->data;
		if(visited[t]!=1)
		{
			dfs(t,b);
			x=(cost[i])%m;
			y=(cost[t]+1)%m;
			//cost[i]=((cost[i]%m)*((cost[t]+1)%m))%m;
			cost[i]=(x*y)%m;
		}
		temp=temp->link;
	}
	return;
}
int main()
{
	long long int T;
	scanf("%lld",&T);
	while(T--)
	{
		long long int n,i,j,temp,t;
		long long int sum=0;
		scanf("%lld",&n);
		for(i=0;i<=n;i++)
		{
			arry[i]=NULL;
			cost[i]=1;
			visited[i]=0;
		}
		for (i=0;i<n-1;i++)
		{
			long long int a,b,c;
			scanf("%lld%lld",&a,&b);
			push(&arry[a],b);
			push(&arry[b],a);
		}
		dfs(1,arry);
		for(i=1;i<=n;i++)
			sum=((sum%m)+(cost[i]%m))%m;
		printf("%lld\n",sum%m);
	}
	return 0;
}
