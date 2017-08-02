#include <stdio.h>
#include <math.h>
#include <limits.h>
#include<stdlib.h>

typedef struct node {
    int data;
	struct node* link;
}node;

typedef struct info{
    int start;
    int end;
    int val;
}info;

node* list[1000000];
info array[1000000];
int visited[1000000],value[2000000],time=-1;

void push(node** head,int dat)
{
	node* temp =(node*)malloc(sizeof(node));
	temp->data=dat;
	temp->link=*head;
	*head=temp;
	return;
}

void dfs(node** b,int x)
{
    node* temp;
    temp=list[x];
    visited[x]=1;
    time++;
    array[x].start=time;
    value[time]=array[x].val;
    while(temp!=NULL)
    {
        int t=temp->data;
        if(visited[t]==0)
            dfs(b,t);
        temp=temp->link;
    }
    time++;
    array[x].end=time;
    value[time]=array[x].val;
    return;
}

int segment[8000000];

int minVal(int x, int y) { return (x < y)? x: y; }

int search(int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return segment[index];
    if (se < qs || ss > qe)
        return INT_MAX;
    int mid = ss+(se-ss)/2;
    return minVal(search(ss, mid, qs, qe, 2*index+1),
                  search(mid+1, se, qs, qe, 2*index+2));
}

int constructSTUtil(int arr[], int ss, int se, int si)
{
    if (ss == se)
    {
        segment[si] = arr[ss];
        return arr[ss];
    }
    int mid = ss+(se-ss)/2;
    segment[si] =  minVal(constructSTUtil(arr, ss, mid, si*2+1),
                     constructSTUtil(arr, mid+1, se, si*2+2));
    return segment[si];
}

void update(int value,int ss, int se, int qs, int qe, int index)
{
    /*if (qs <= ss && qe >= se)
    {
        segment[index]=minVal(segment[index],value);
        return segment[index];
    }
    if (se < qs || ss > qe)
        return INT_MAX;
    int mid = ss+(se-ss)/2;
    return minVal(update(value,ss, mid, qs, qe, 2*index+1),
                  update(value,mid+1, se, qs, qe, 2*index+2));*/
    if(ss==se)
    {
        segment[index]=minVal(segment[index],value);
        return;
    }
    int mid = ss+(se-ss)/2;
    if(qs<=mid)
    {
        update(value,ss, mid, qs, qe, 2*index+1);
        segment[index]=minVal(segment[2*index+1],segment[2*index+2]);
    }
    else
    {
        update(value,mid+1,se,qs,qe,2*index+2);
        segment[index]=minVal(segment[2*index+1],segment[2*index+2]);
    }
    return;
}

int main()
{
    int N,Q,i;
    scanf("%d %d",&N,&Q);
    for(i=0;i<=2*N;i++)
    {
        visited[i]=value[i]=array[i].val=array[i].start=array[i].end=0;
        list[i]=NULL;
    }
    for(i=0;i<N-1;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        push(&list[a],b);
        push(&list[b],a);
    }
    for(i=1;i<=N;i++)
        scanf("%d",&array[i].val);
    dfs(list,1);
    constructSTUtil(value, 0, time, 0);
    //for(i=0;i<=2*N-1;i++)
    //        printf("%d ",segment[i]);
    //printf("\n");
    for(i=0;i<Q;i++)
    {
        int type,x,y;
        scanf("%d",&type);
        if(type==0)
        {
            scanf("%d %d",&y,&x);
            array[y].val=minVal(x,array[y].val);
            update(array[y].val,0,time,array[y].start,array[y].start,0);
            update(array[y].val,0,time,array[y].end,array[y].end,0);
        }
        if(type==1)
        {
            scanf("%d",&x);
            printf("%d\n",search(0,time,array[x].start,array[x].end,0));
        }
    }
  /* for(i=0;i<2*N;i++)
        printf("%d ",value[i]);
    printf("\n");

   int qs = 0;  // Starting index of query range
   int qe = 5;  // Ending index of query range
   printf("Minimum of values in range [%d, %d] is = %d\n",
                          qs, qe, search(0,2*N-1, qs, qe,0));
    update(-1,0,2*N-1,qs,qe,0);
    printf("Minimum of values in range [%d, %d] is = %d\n",
                           qs, qe, search(0,2*N-1, 1, qe,0));*/
   return 0;
}
