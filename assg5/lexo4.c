#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int data;
	struct node* link;
}node;

node* list[27];
int visited[27],ans=0,flag[27];

void push(node** head,int dat)
{
	node* temp =(node*)malloc(sizeof(node));
	temp->data=dat;
	temp->link=*head;
	*head=temp;
	return;
}

void print(node** b,int x)
{
    node* temp=b[x];
    printf("%d =>",x);
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
    return;
}

void cycle(node** b,int x)
{
    node* temp;
    temp=list[x];
    visited[x]=1;
    while(temp!=NULL)
    {
        int t=temp->data;
        if(flag[t]==1)
            ans=1;
        if(visited[t]==0)
        {
            if(flag[x]==0)
                flag[x]=1;
            else if(flag[t]==1)
                ans=1;
            cycle(b,t);
        }
        temp=temp->link;
    }
    //visited[x]=0;
    flag[x]=2;
    return;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,i,j,a1,b1,l1,l2,t;
        ans=0;
        scanf("%d",&n);
        char string[505][505];
        for(i=0;i<27;i++)
        {
            list[i]=NULL;
            visited[i]=0;
            flag[i]=0;
        }
        for(i=0;i<n;i++)
            scanf("%s",string[i]);
        for(i=0;i<n-1;i++)
        {
            l1=strlen(string[i]);
            l2=strlen(string[i+1]);
            t=l1<l2?l1:l2;
            for(j=0;j<=t;j++)
                if(string[i][j]!=string[i+1][j])
                    break;
            if(j<=t && l1<=l2)
            {
                a1=string[i][j]-'a';
                b1=string[i+1][j]-'a';
                //printf("%d %d\n",a1,b1);
                push(&list[a1],b1);
            }
            else if(l1>l2 && j==t)
                ans=1;
        }
        //for(i=0;i<26;i++)
        //    print(list,i);
        for(i=0;i<26;i++)
        {
            if(visited[i]==0)
                cycle(list,i);
        }
        //printf("ans => %d\n",ans);
        if(ans==1)
            printf("Impossible\n");
        else
            printf("Possible\n");
    }
    return 0;
}
