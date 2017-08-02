#include<stdio.h>
#include<stdlib.h>
typedef struct ver {
	int no;
	int in;
	int out;
}ver;
typedef struct node {
	int data;
	struct node* link;
}node;
int cmpfunc(const void * a, const void * b)
{
	ver *var1 = (ver *) a;
	ver *var2 = (ver *) b;
	return (var1->out > var2->out) - (var1->out < var2->out);
}
int visited[100005];
int visitedre[100005];
ver vertex[100005];
int ti=1;
int count=0;
int tcost=1000000005;
int cost[100005];
void push(node** head,int dat)
{
	node* temp =(node*)malloc(sizeof(node));
	temp->data=dat;
	temp->link=*head;
	*head=temp;
	return;
}
void print(node** head)
{
	node* temp;
	temp=*head;
	if(head==NULL)
		return;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
	return;
}
void dfs(int i,node** b) // node *b[]
{
	node* temp;
	temp=b[i];
	visited[i]=1;
	vertex[i-1].in=ti;
	ti++;
	while(temp!=NULL)
	{
		int t;
		t=temp->data;
		if(visited[t]!=1)
			dfs(t,b);
		temp=temp->link;
	}
	vertex[i-1].out=ti;
	ti++;
	return;
}
void dfsnew(int i,node** b) // node *b[]
{
//	printf("%d ",i);
	if(cost[i]<tcost)
	{
		tcost=cost[i];
		count=1;
	}
	else if(cost[i]==tcost)
		count++;
	node* temp;
	temp=b[i];
	visitedre[i]=1;
	while(temp!=NULL)
	{
		int t;
		t=temp->data;
		if(visitedre[t]!=1)
			dfsnew(t,b);
		temp=temp->link;
	}
	return;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int sum=0,ways=1;
		ti=1;sum=0;count=0;
		int n,m,i,k;
		scanf("%d %d",&n,&m);
		node* arry[n+1];
		node* reverse[n+1];
		for(i=1;i<=n;i++)
			scanf("%d",&cost[i]);
		for(i=0;i<n+1;i++)
		{
			vertex[i].no=i+1;
			arry[i]=NULL;
			reverse[i]=NULL;
			visited[i]=0;
			visitedre[i]=0;
		}
		for(i=0;i<m;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			push(&arry[a],b);
			push(&reverse[b],a);
		}
		for(i=0;i<100005;i++)
			visited[i]=0;
		for(i=1;i<=n;i++)
			if(visited[i]==0)
				dfs(i,arry);
		qsort(vertex,n,sizeof(ver),cmpfunc);
		for(i=n-1;i>=0;i--)
		{
			if(visitedre[vertex[i].no]==0)
			{
				dfsnew(vertex[i].no,reverse);
				sum=sum+tcost;
				ways=(ways*count)%1000000007;
				count=0;
				tcost=1000000005;
			}
		}
		printf("%d %d\n",sum,ways);
	}
	return 0;
}
