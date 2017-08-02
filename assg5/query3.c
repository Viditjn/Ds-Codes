#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int parent;
	int child;
	struct node* link;
}node;

node* list[1000000];
int value[1000000],ans[1000000],par[1000000];

void push(node** head,int p,int c)
{
	node* temp =(node*)malloc(sizeof(node));
	temp->parent=p;
    temp->child=c;
	temp->link=*head;
	*head=temp;
	return;
}

void dfs(node** b,int i)
{
    node* temp;
	temp=b[i];
	while(temp!=NULL)
	{
		int t;
		t=temp->child;
	    dfs(b,t);
        ans[i]=ans[i]>ans[t]?ans[t]:ans[i];
		temp=temp->link;
	}
	return;
}

int main()
{
    int n,q,i;
    scanf("%d %d",&n,&q);
    for(i=0;i<=n;i++)
    {
            list[i]=NULL;
            value[i]=0;
            ans[i]=0;
            par[i]=0;
    }
    for(i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        push(&list[a],a,b);
        par[b]=a;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&value[i]);
        ans[i]=value[i];
    }
    dfs(list,1);
    for(i=0;i<q;i++)
    {
        int type,x,y;
        scanf("%d",&type);
        if(type==0)
        {
            scanf("%d %d",&x,&y);
            value[x]=value[x]>y?y:value[x];
            if(value[x]<ans[x])
            {
                ans[x]=value[x];
                int var=par[x];
                while(var!=0)
                {
                    ans[var]=ans[x]>ans[var]?ans[var]:ans[x];
                    x=var;
                    var=par[x];
                }
            }
        }
        if(type==1)
        {
            scanf("%d",&x);
            printf("%d\n",ans[x]);
        }
    }
    return 0;
}
