#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node{
    int x;
    int co;
    int len;
}node;

typedef struct node2{
	node data;
	struct node2* link;
}node2;

node heap2[1000005];
int visited[1000005];
node2* list[1000005];
int tail2=1;

void push(node2** head,node dat)
{
	node2* temp =(node2*)malloc(sizeof(node2));
	temp->data.x=dat.x;
	temp->data.co=dat.co;
	temp->data.len=dat.len;
	temp->link=*head;
	*head=temp;
	return;
}

void insertdown(int p,int cod,int data)
{
	int var;
	node temp;
	var=tail2;
	heap2[var].len=data;
	heap2[var].co=cod;
	heap2[var].x=p;
	while(heap2[var/2].len > heap2[var].len && var>=1)
	{
		temp=heap2[var/2];
		heap2[var/2]=heap2[var];
		heap2[var]=temp;
		var=var/2;
	}
	tail2++;
	return;
}
void del()
{
	int temp,j;
	node var;
	heap2[1]=heap2[tail2-1];
	temp=1;
	tail2--;
	while(((2*temp))<=tail2 && (heap2[temp*2].len<heap2[temp].len || heap2[(temp*2)+1].len<heap2[temp].len))
	{
		if((2*temp)+1<=tail2)
			j=heap2[2*temp].len<=heap2[(2*temp)+1].len?(2*temp):((2*temp)+1);
		else
			j=2*temp;
		var=heap2[temp];
		heap2[temp]=heap2[j];
		heap2[j]=var;
		temp=j;
	}
	return;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,M,i,count=0;
        long long int sum=0;
        scanf("%d %d",&N,&M);
        tail2=1;
        for(i=0;i<=N;i++)
		{
			list[i]=NULL;
			visited[i]=0;
			heap2[i].x=0;
			heap2[i].len=0;
			heap2[i].co=0;
		}
		for(i=0;i<M;i++)
		{
			heap2[i].x=0;
			heap2[i].len=0;
			heap2[i].co=0;
		}
        for(i=0;i<M;i++)
		{
			node b,c;
			scanf("%d %d %d",&b.x,&b.co,&b.len);
            c.x=b.co;
            c.co=b.x;
            c.len=b.len;
			push(&list[b.x],b);
            push(&list[c.x],c);
            sum+=b.len;
		}
        int s = N;
        insertdown(0,N,0);
        while(tail2>1 && count!=N-1)
		{
			del();
			node2* temp;
			temp=list[s];
			if(visited[s]!=1)
			{
				while(temp!=NULL)
				{
					if(visited[temp->data.co]!=1)
                    {
						insertdown(temp->data.x,temp->data.co,temp->data.len);
                    }
					temp=temp->link;
				}
			}
			visited[s]=1;
			s=heap2[1].co;
            if(visited[s]==0)
            {
                sum-=heap2[1].len;
                count++;
            }
		}
        printf("%lld\n",sum);
    }
}
