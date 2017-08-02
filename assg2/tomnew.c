#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int n,k;
		scanf("%lld %lld",&n,&k);
		long long int i,j,temp,t,sum,zero=0,ans=0;
		long long int arry[n],count[k];
		for(i=0;i<k;i++)
			count[i]=0;
		t=1000000007;
		count[0]++;
		for(i=0,sum=0;i<n;i++)
		{
			scanf("%lld",&arry[i]);
			sum=sum+arry[i];
			temp=sum%k;
			count[temp]=count[temp]+1;
//			if(arry[i]==0)
//				zero++;
		}
		for(i=0;i<k;i++)
		{
			j=count[i];
			if(count[i]!=0)
			{
				ans=((ans%t)+((j*(j-1)/2)%t))%t;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
