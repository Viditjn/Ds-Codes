#include<stdio.h>
#include<stdlib.h>
int fre[1000001];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int i,n,ans=0;
        scanf("%d",&n);
        for(i=0;i<1000001;i++)
            fre[i]=0;
        for(i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            fre[a]+=1;
        }
        for(i=0;i<1000001;i++)
            if(fre[i] > ((n+1)/2))
                ans=fre[i];
        if(ans==0)
            ans=(n+1)/2;
        printf("%d\n",ans);
    }
}
