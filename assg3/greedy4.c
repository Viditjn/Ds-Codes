#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	int len;
	struct node* link;
}node;
int visited[1000000]={0},visitedre[1000000]={0},visitnet[1000000]={0};
int y=1000000009;
node* arry[100005];
node* arrynet[100005];
node* reverse[100005];
void push(node** head,int dat,int l)
{
	node* temp =(node*)malloc(sizeof(node));
	temp->data=dat;
	temp->len=l;
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
		printf("%d %d; ",temp->data,temp->len);
		temp=temp->link;
	}
	printf("\n");
	return;
}
void dfs(int i,node** b) // node *b[]
{
	node* temp;
	temp=b[i];
	//	printf("%d\n",i);
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
void dfsnew(int i,int x,int des,node** b) // node *b[]
{
	if(y>x && i==des)
		y=x;
	if(i!=des)
	{
		node* temp;
		int q;
		visited[i]=1;
		temp=b[i];
		q=x;
		while(temp!=NULL)
		{
			int t;
			if(q<temp->len)
				x=temp->len;
			t=temp->data;
			if(visited[t]!=1)
				dfsnew(t,x,des,b);
			temp=temp->link;
		}
	}
	visited[i]=0;
	return;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,i,j,s,d;
		scanf("%d %d",&n,&m);
		y=1000000009;
		for(i=0;i<=n;i++)
		{
			arry[i]=NULL;
			visited[i]=0;
			visitedre[i]=0;
			visitnet[i]=0;
			arrynet[i]=NULL;
			reverse[i]=NULL;
		}
		for(i=0;i<m;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			push(&arry[a],b,c);
			push(&reverse[b],a,c);
		}
		scanf("%d %d",&s,&d);
		dfs(s,arry);
		for(i=0;i<=n;i++)
		{
			visitedre[i]=visited[i];
			visited[i]=0;
		}
		dfs(d,reverse);
		for(i=0;i<=n;i++)
			if(visited[i]==visitedre[i] && visited[i]==1)
				visitnet[i]=1;
		if(visitnet[d]==0)
			printf("NO PATH\n");
		else
		{
			for(i=0;i<=n;i++)
			{
				//printf("%d ",visitnet[i]);
				visited[i]=0;
				if(visitnet[i]==0)
					arrynet[i]=NULL;
				else
				{
					node* temp=arry[i];
					while(temp!=NULL)
					{
						if(visitnet[temp->data]==1)
							push(&arrynet[i],temp->data,temp->len);
						temp=temp->link;
					}
				}
			}
			//	for(i=1;i<=n;i++)
			//		print(&arrynet[i]);
			dfsnew(s,0,d,arrynet);
			printf("%d\n",y);
		}
	}
	return 0;
}
