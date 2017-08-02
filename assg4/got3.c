#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}node;

node* list[1000000];
node* level[1000000];

void push(node** head,int dat)
{
	node* temp =(node*)malloc(sizeof(node));
	temp->data=dat;
	temp->link=*head;
	*head=temp;
	return;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,i,j;
        scanf("%d",&n);
		int val[n+1],stack[n+1],height[n+1];
		for(i=0;i<=n;i++)
		{
			stack[i]=height[i]=0;
			list[i]=NULL;
			level[i]=NULL;
		}
        for(i=0;i<n-1;i++)
        {
			int a,b;
			scanf("%d %d",&a,&b);
			push(&list[a],b);
        }
		for(i=1;i<=n;i++)
		{
			scanf("%d",&val[i]);
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
			int ans;
			while(temp!=NULL)
			{
				if(val[temp->data]==-1)
				{
					node* temp1;
					temp1=list[temp->data];
					if(i%2==1)
					{
						ans = 1000000009;
						while(temp1!=NULL)
						{
							if(ans>val[temp1->data])
								ans=val[temp1->data];
							temp1=temp1->link;
						}
					}
					if(i%2==0)
					{
						ans = -5;
						while(temp1!=NULL)
						{
							if(ans<val[temp1->data])
								ans=val[temp1->data];
							temp1=temp1->link;
						}
					}
					val[temp->data]=ans;
				}
				temp=temp->link;
			}
		}
		//for(i=1;i<=n;i++)
		//	printf("%d ",val[i]);
		printf("%d\n",val[1]);
    }
	return 0;
}
