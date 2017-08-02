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
//node heap[1000005];
node heap2[1000005],arry[1000005];
int count[1000005],visited[1000005];
node2* list[1000005];
int tail2=1;
int tail=1;
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
void print(node2** head)
{
	node2* temp;
	temp=*head;
	if(head==NULL)
		return;
	while(temp!=NULL)
	{
		printf("%d,%d,%d; ",temp->data.x,temp->data.co,temp->data.len);
		temp=temp->link;
	}
	printf("\n");
	return;
}
void insertdown(int p,int cod,int data)
{
	int temp,var,temp2,temp3;
	var=tail2;
	heap2[var].len=data;
	heap2[var].co=cod;
	heap2[var].x=p;
	while(heap2[var/2].len > heap2[var].len && var>=1)
	{
		temp3=heap2[var/2].x;
		temp=heap2[var/2].len;
		temp2=heap2[var/2].co;
		heap2[var/2].len=heap2[var].len;
		heap2[var/2].co=heap2[var].co;
		heap2[var/2].x=heap2[var].x;
		heap2[var].len=temp;
		heap2[var].co=temp2;
		heap2[var].x=temp3;
		var=var/2;
	}
	tail2++;
	return;
}
void buildup(node arry[],int N)
{
	int t,i,temp,var,j,count=0,var2,var3;
	t=N-(int)pow(2,(int)(log(N)/log(2)))+1;
	for(i=0;i<t;i++)
	{
		heap2[N-i].x=arry[i].x;
		heap2[N-i].co=arry[i].co;
		heap2[N-i].len=arry[i].len;
	}
	while(i!=N)
	{
		heap2[N-i].x=arry[i].x;
		heap2[N-i].co=arry[i].co;
		heap2[N-i].len=arry[i].len;
		temp=N-i;
		count=0;
		while(((2*temp))<=N && (heap2[temp*2].len<heap2[temp].len || heap2[(temp*2)+1].len<heap2[temp].len))
		{
			if((2*temp)+1<=N)
				j=heap2[2*temp].len<=heap2[(2*temp)+1].len?(2*temp):((2*temp)+1);
			else
				j=2*temp;
			var=heap2[temp].len;
			var2=heap2[temp].co;
			var3=heap2[temp].x;
			heap2[temp].len=heap2[j].len;
			heap2[temp].co=heap2[j].co;
			heap2[temp].x=heap2[j].x;
			heap2[j].x=var3;
			heap2[j].len=var;
			heap2[j].co=var2;
			temp=j;
			count++;
		}
		i++;
	}
	tail2=i+1;
	return;
}
void delete()
{
	int temp,var,j,var2,var3;
	heap2[1].len=heap2[tail2-1].len;
	heap2[1].co=heap2[tail2-1].co;
	heap2[1].x=heap2[tail2-1].x;
	temp=1;
	tail2--;
	while(((2*temp))<=tail2 && (heap2[temp*2].len<heap2[temp].len || heap2[(temp*2)+1].len<heap2[temp].len))
	{
		if((2*temp)+1<=tail2)
			j=heap2[2*temp].len<=heap2[(2*temp)+1].len?(2*temp):((2*temp)+1);
		else
			j=2*temp;
		var=heap2[temp].len;
		var2=heap2[temp].co;
		var3=heap2[temp].x;
		heap2[temp].len=heap2[j].len;
		heap2[temp].co=heap2[j].co;
		heap2[temp].x=heap2[j].x;
		heap2[j].len=var;
		heap2[j].co=var2;
		heap2[j].x=var3;
		temp=j;
	}
	return;
}
int minofmax(int a,int b,int c)
{
	int d;
	d=(b>=c)?b:c;
	d=(d>=a)?a:d;
	return d;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		tail2=1;
		int N,M;
		//printf("No. of initial entries\n");
		scanf("%d %d",&N,&M);
		//int count[N+1],visited[N+1];
		int i,j,t;
		//node arry[M];
		//node2* list[N+1];
		for(i=0;i<=N;i++)
		{
			count[i]=1000000009;
			list[i]=NULL;
			visited[i]=0;
			arry[i].x=0;
			arry[i].len=0;
			arry[i].co=0;
			heap2[i].x=0;
			heap2[i].len=0;
			heap2[i].co=0;
		}
		for(i=0;i<M;i++)
		{
			arry[i].x=0;
			arry[i].len=0;
			arry[i].co=0;
			heap2[i].x=0;
			heap2[i].len=0;
			heap2[i].co=0;
		}
		for(i=0;i<M;i++)
		{
			node b;
			scanf("%d %d %d",&b.x,&b.co,&b.len);
			arry[i].x=b.x;
			arry[i].co=b.co;
			arry[i].len=b.len;
			push(&list[b.x],b);
		}
		int s,d;
		scanf("%d %d",&s,&d);
		node arry1[1];
		count[s]=0;
		arry1[0].co=s;
		arry1[0].len=0;
		arry1[0].x=0;
		//buildup(arry1,1);
		insertdown(0,s,0);
	//	printf("@%d\n",tail2);
		while(tail2>1 && s!=d)
		{
			delete();
			node2* temp;
			temp=list[s];
			if(visited[s]!=1)
			{
				while(temp!=NULL)
				{
					count[temp->data.co]=minofmax(count[temp->data.co],count[temp->data.x],temp->data.len);
					if(visited[temp->data.co]!=1)
						insertdown(temp->data.x,temp->data.co,temp->data.len);
					temp=temp->link;
				}
			}
		//	for(i=1;i<tail2;i++)
		//		printf("%d,%d,%d=>%d; ",heap2[i].x,heap2[i].co,heap2[i].len,count[heap2[i].co]);
		//	printf("\n");
			visited[s]=1;
			s=heap2[1].co;
		}
		if(count[d]!=1000000009)
			printf("%d\n",count[d]);
		else
			printf("NO PATH\n");
	}
	return 0;
}
