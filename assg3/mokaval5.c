#include<stdio.h>
#include<stdlib.h>
typedef struct node2{
	int start;
	int end;
	int val;
}node2;
typedef struct node{
	node2 data;
	struct node* link;
}node;
node2 heap2[1000005],arry[1000005];
int tail2=1;
node* list[1000005];
void push(node** head,node2 dat)
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
		printf("%d,%d,%d; ",temp->data.start,temp->data.end,temp->data.val);
		temp=temp->link;
	}
	printf("\n");
	return;
}
void insertdown(node2 data)
{
	int var;
	node2 temp;
	var=tail2;
	heap2[var]=data;
	while(heap2[var/2].val < heap2[var].val && var>1)  //
	{
		temp=heap2[var/2];
		heap2[var/2]=heap2[var];
		heap2[var]=temp;
		var=var/2;
	}
	tail2++;
	return;
}
void delete()
{
	int temp,j;
	node2 var;
	heap2[1]=heap2[tail2-1];
	temp=1;
	tail2--;
	while(((2*temp))<=tail2 && (heap2[temp*2].val>heap2[temp].val || heap2[(temp*2)+1].val>heap2[temp].val))
	{
		if((2*temp)+1<=tail2)
			j=heap2[2*temp].val>=heap2[(2*temp)+1].val?(2*temp):((2*temp)+1);
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
		int i,j,l,r,v,n,max=0;
		scanf("%d",&n);
		for(i=0;i<1000005;i++)
		{
			list[i]=NULL;
			heap2[i].start=0;
			heap2[i].end=0;
			heap2[i].val=0;
			arry[i].start=0;
			arry[i].end=0;
			arry[i].val=0;
		}
		for(i=0;i<n;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			arry[i].start=a;
			arry[i].end=b;
			arry[i].val=c;
			push(&list[arry[i].start],arry[i]);
			if(arry[i].end>max)
				max=arry[i].end;
		}
		//	printf("*%d\n",max);
		//qsort(arry,n,sizeof(node),cmpfunc);
		int ans=1,var=0;
		for(i=0;i<=max;i++)
		{
			//if(tail2!=1)
			//	var=heap2[1].val;
			while(tail2>1 && i>=heap2[1].end)
				delete();
			node* temp;
			temp=list[i];
			while(temp!=NULL)
			{
				insertdown(temp->data);
				temp=temp->link;
			}
			//for(j=1;j<tail2;j++)
			//	printf("%d=>%d,%d,%d; ",i,heap2[j].start,heap2[j].end,heap2[j].val);
			if(tail2>1 && ans!=tail2)
			{
				if(var!=heap2[1].val)
					printf("%d %d\n",i,heap2[1].val);
				ans=tail2;
				var=heap2[1].val;
			}
			else if(tail2==1 && ans!=tail2)
			{
				printf("%d %d\n",i,0);
				ans=tail2;
			}
		}
	}
	return 0;
}
