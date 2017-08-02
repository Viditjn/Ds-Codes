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
int visited[1000005];
int visitedre[1000005];
ver vertex[1000005];
int ti=1;
int count=0;
int indeg[1000005];
int stack[1000005];
int order[1000005];
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

void push(node** head,int dat)
{
	node* temp =(node*)malloc(sizeof(node));
	temp->data=dat;
	temp->link=*head;
	*head=temp;
	return;
}
void dfs(int i,node** b) // node *b[]
{
	node* temp;
	temp=b[i];
	visited[i]=1;
	vertex[i].in=ti;
	ti++;
	while(temp!=NULL)
	{
		int t;
		t=temp->data;
		if(visited[t]!=1)
			dfs(t,b);
		temp=temp->link;
	}
	vertex[i].out=ti;
	ti++;
	return;
}
void dfsnew(int i,node** b) // node *b[]
{
	count++;
//		printf("%d ",i);
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
	primeno();
	while(T--)
	{
		//int sum=0,ways=1;
		ti=1,count=0;
		int n,m,i,k,j,condition=0,sum=0;
		long long int ans=0;
		scanf("%d %d",&n,&m);
		node* arry[n+1];
		node* reverse[n+1];
		//	for(i=1;i<=n;i++)
		//		scanf("%d",&cost[i]);
		for(i=0;i<n+1;i++)
		{
			vertex[i].no=i;
			arry[i]=NULL;
			reverse[i]=NULL;
			visited[i]=0;
			visitedre[i]=0;
			order[i]=0;
			indeg[i]=0;
			stack[i]=0;
		}
		for(i=0;i<m;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			push(&arry[b],a);
			push(&reverse[a],b);
			indeg[a]=indeg[a]+1;
		}
		//for(i=0;i<100005;i++)
		//	visited[i]=0;
		for(i=0;i<n;i++)
			if(visited[i]==0)
				dfs(i,arry);
		qsort(vertex,n,sizeof(ver),cmpfunc);
		for(i=n-1;i>=0;i--)
		{
			if(visitedre[vertex[i].no]==0)
			{
				count=0;
				dfsnew(vertex[i].no,reverse);
			//	printf("%d\n",count);
				if(count>1)
				{
					condition=1;
					printf("evil emperor loses\n");
				}
			}
		}
		if(condition!=1)
		{
			for(i=0,j=0;i<n;i++)
			{
				if(indeg[i]==0)
				{
					stack[j]=i;
					j++;
				}
			}
			int l=0;
			int x=j,y=0,rank=0;
			while(j!=l)
			{
				//printf("%d ",stack[l]);
				node* temp;
				if(x==0)
				{
					x=y;
					y=0;
					rank++;
				}
				x--;
				temp = arry[stack[l]];
				while(temp!=NULL)
				{
					indeg[temp->data]-=1;
					if(indeg[temp->data]==0)
					{
						order[temp->data]=prime[rank+1];
						stack[j]=temp->data;
						j++;
						y++;
					}
					temp=temp->link;
				}
				l++;
			}
			//printf("\n");
			for(i=0;i<n;i++)
			{
			//	printf("%d ",order[i]);
				ans+=order[i];
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
