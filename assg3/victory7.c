#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	int len;
	struct	node* link;
}node;
int visited[100005];
int cost[100005];
int size[100005];
void push(node** head,int dat,int le)
{
	node* temp =(node*)malloc(sizeof(node));
	temp->data=dat;
	temp->len=le;
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
		printf("%d %d ;",temp->data,temp->len);
		temp=temp->link;
	}
	printf("\n");
	return;
}
void dfs(int i,node** b)
{
	node* temp;
	temp=b[i];
	visited[i]=1;
	while(temp!=NULL)
	{
		int t;
		cost[i]+=temp->len;
		t=temp->data;
		if(visited[t]!=1)
			dfs(t,b);
		temp=temp->link;
		cost[i]+=cost[t];
	}
	return;
}
void svertex(int i,node** b)
{
	node* temp;
	temp=b[i];
	visited[i]=1;
	while(temp!=NULL)
	{
		int t;
		t=temp->data;
		if(visited[t]!=1)
		{
			size[t]+=temp->len;
			size[t]+=size[i];
			svertex(t,b);
		}
		temp=temp->link;
	}
	return;
}
int main()
{
	int n,i,j,temp,t;
	long long int sum=0;
	scanf("%d",&n);
	node* arry[n+1];
	node* reverse[n+1];
	for(i=0;i<=n;i++)
	{
		arry[i]=NULL;
		reverse[i]=NULL;
		cost[i]=0;
		visited[i]=0;
	}
	for (i=0;i<n-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		push(&arry[a],b,c);
		push(&arry[b],a,c);
	//	push(&reverse[b],a,c);
		sum+=c;
		//outdeg[a]+=1;
	}
	size[1]=0;
	dfs(1,arry);
	for(i=0;i<=n;i++)
		visited[i]=0;
	svertex(1,arry);
	int temp1;
	for(i=1,temp=0,temp1=1;i<=n;i++)
	{
		if(size[i]>temp)
		{
			temp=size[i];
			//temp1=i;
		}
	}
	/*node* temp2;
	temp2=reverse[temp1];
	int t1=temp1;
	while(temp2!=NULL)
	{
		int t;
		t=temp2->data;
		sum+=(cost[t]-(temp2->len)-cost[t1]);
		t1=t;
		temp2=reverse[t];
	}
	sum+=cost[1];*/
	sum=2*sum-temp;
	printf("%lld\n",sum);
	return 0;
}
