#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	long long int data;
	struct node* link;
}node;

node* list[1000000];
node* level[1000000];

void push(node** head,long long int dat)
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
	temp = *head;
	while(temp!=NULL)
	{
		printf("%lld ",temp->data);
		temp=temp->link;
	}
	printf("\n");
	return;
}

long long int main()
{
	long long int T;
	scanf("%lld",&T);
	while(T--)
	{
		long long int n,i,j;
		scanf("%lld",&n);
		long long int value[n+1],stack[n+1],height[n+1],parent[n+1],order[n+1];
		for(i=0;i<=n;i++)
		{
			list[i]=NULL;
			value[i]=0;
			level[i]=NULL;
			parent[i]=0;
			order[i]=0;
			height[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			long long int a,b;
			scanf("%lld %lld",&a,&b);
			push(&list[a],b);
			parent[b]=a;
			order[i]=b;
		}
		stack[1]=1;
		height[1]=0;
		i=1;
		j=2;
		while(i!=n)
		{
			node* temp;
			temp = list[stack[i]];
			while(temp!=NULL)
			{
				stack[j]=temp->data;
				height[temp->data]=1+height[stack[i]];
				temp=temp->link;
				j++;
			}
			i++;
		}
		for(i=0;i<=n;i++)
			push(&level[height[i]],i);
		for(i=n;i>=0;i--)
		{
			node* temp;
			temp=level[i];
			while(temp!=NULL)
			{
				value[parent[temp->data]]+=(value[temp->data]+1);
				temp=temp->link;
			}
		}
		for(i=0;i<n-1;i++)
		{
			long long int ans;
			ans=(value[order[i]]+1)*(n-1-value[order[i]]);
			printf("%lld ",ans);
		}
		printf("\n");
	}
	return 0;
}
