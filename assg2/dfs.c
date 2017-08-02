#include<stdio.h>
#include<stdlib.h>
int visited[100005];
typedef struct node {
	int data;
	struct node* link;
}node;
void push(node** head,int dat)
{
	node* temp =(node*)malloc(sizeof(node));
	temp->data=dat;
	temp->link=*head;
	*head=temp;
	return;
}
void pop(node** head)
{
	node* temp;
	temp=*head;
	if(head==NULL)
	{
		printf("error!!\n");
		return;
	}
	*head=(*head)->link;
	free(temp);
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
	while(temp!=NULL)
	{
		int t;
		t=temp->data;
		if(visited[t]!=1)
			dfs(t,b);
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
		int n,m,i,k,t=0;
		scanf("%d %d",&n,&m);
		node* arry[n+1];
		int countf[n+1],countb[n+1];
		for(i=0;i<=n;i++)
		{
			arry[i]=NULL;
			countf[i]=0;
			countb[i]=0;
		}
		for(i=0;i<m;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			push(&arry[a],b);
			countf[a]=countf[a]+1;
			countb[b]=countb[b]+1;
		}
		for(i=0;i<100005;i++)
			visited[i]=0;
		dfs(1,arry);
		for(i=0;i<=n;i++)
		{
			if(visited[n]==0)
			{
				t++;
				printf("No\n");
				break;
			}
			if(countf[i]!=countb[i])
			{
				t++;
				printf("No\n");
				break;
			}
			else if(countf[i]==countb[i] && countf[i]!=0)
			{
				if(visited[i]!=1)
				{
					t++;
					printf("No\n");
					break;
				}
			}
		}
		if(t==0)
			printf("Yes\n");
	}
	return 0;
}
