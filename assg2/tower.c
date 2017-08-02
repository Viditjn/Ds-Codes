#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
	int data;
	struct node* link;
} node;
int visited[100005];
void add(node** head,node** tail,int dat)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data=dat;
	temp->link=NULL;
	if(*head==NULL)
		*head=temp;
	else 
		(*tail)->link=temp;
	*tail=temp;
	return;
}
void print(node** head)
{
	node* temp;
	temp=*head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
	return;
}
int main()
{
	int n;
	scanf("%d",&n);
	int t,count[n],i,j,k,l,counter,ti,co,flag=0;
	int  arry[n];
	node* headalp[27];
	node* temp[27];
	node* tailalp[27];
	node* point[n];
	node* pointer[n];
	int pri[n];
	for(i=0;i<27;i++)
	{
		headalp[i]=NULL;
		tailalp[i]=NULL;
		temp[i]=NULL;
	}
	char fl;
	for(i=0;i<n;i++)
	{
		char arr[100005];
	//	scanf("%c",&fl);
		scanf(" %[^\n]s",arr);
		t=arr[0]-'a';
		arry[i]=t;
		add(&headalp[t],&tailalp[t],i);
		point[i]=NULL;
		pointer[i]=NULL;
		count[i]=0;
		pri[i]=0;
		visited[i]=0;
	}
	for(i=0;i<26;i++)
		temp[i]=headalp[i];
	for(i=0;i<n;i++)
	{
		node* temp3=(node*)malloc(sizeof(node));
		node* temp2=(node*)malloc(sizeof(node));
		temp2->data=-1;
		temp3->data=-1;
		if(i<n-1)
		{
			temp2->data=i+1;
			point[i]=temp2;
		}
		if(i>0)
		{
			temp3->data=i-1;
			if(point[i]==NULL)
				point[i]=temp3;
			else
				temp2->link=temp3;
		}
		if(temp3->data==-1)
		{
			int y1=arry[i];
			if(temp[y1]!=NULL)
			{
				temp2->link=temp[y1];
				temp[y1]=temp[y1]->link;
			}
		}
		else
		{
			int y2=arry[i];
			if(temp[y2]!=NULL)
			{
				temp3->link=temp[y2];
				temp[y2]=temp[y2]->link;
			}
		}
	}
	visited[0]=1;
	pointer[0]=point[0];
	counter=0;
	for(i=0,j=1,k=1,ti=0,co=0;i<n;i++)
	{
		node* tem;
		tem=pointer[i];
	//	print(&tem);
		while(tem!=NULL)
		{
			int t=tem->data;
			if(t==n-1)
			{
				flag=1;
				break;
			}
			if(visited[t]!=1)
			{
				pointer[j]=point[t];
				pri[j]=t;
				j++;
				co++;
			}
			visited[t]=1;
			tem=tem->link;
	//		count[k]=count[k]+1;
		}
		if(flag==1)
		{
			counter++;
			break;
		}
		if(i==ti)
		{
			counter++;
			ti=co;
	//		co=0;
		}
	//	if(i==count[l]-1)
	//		counter++;
	}
//	for(i=0;i<n;i++)
//		print(&point[i]);
//	for(i=0;i<n;i++)
//		printf("%d ",pri[i]);
	printf("%d\n",counter);
	return 0;
}
