#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,k,q;
		scanf("%d %d %d",&N,&k,&q);
		long long int i,j,temp,sum1=0,sum2=0,weight[N],stack[N],head=0,tail=0,sum=0,price[N],cost=0,cost1=0,cost2=0;
		for(i=0;i<N;i++)
		{
			scanf("%lld",&weight[i]);
			sum=sum+weight[i];
			stack[i]=0;
		}
		for(i=0;i<N;i++)
		{
			scanf("%lld",&price[i]);
			cost=cost+price[i];
		}
		for(i=N-1;i>=N-k;i--)
		{
			cost1=cost1+price[i];
			sum1=sum1+weight[i];
		}
		j=i;
		while(sum1>(q*sum2) && head<=N)
		{
			stack[head]=j;
			head++;
			sum2=sum2+weight[j];
			cost2=cost2+price[j];
			j--;
		}
		temp=cost1+cost2;
		for(i=N-k-1;i>=k;i--)
		{
			sum1=sum1-weight[i+k]+weight[i];
			cost1=cost1-price[i+k]+price[i];
			sum2=sum2-weight[i];
			cost2=cost2-price[i];
			stack[tail]=0;
			tail++;
			if(sum1>(q*sum2))
			{
				while(sum1>(q*sum2) && head<=N)
				{
					stack[head]=j;
					head++;
					sum2=sum2+weight[j];
					cost2=cost2+price[j];
					j--;
				}
			}
			else if(sum1<(q*sum2) && tail<head)
			{
				while(sum1<=(q*sum2))
				{
					sum2=sum2-weight[stack[head-1]];
					cost2=cost2-price[stack[head-1]];
					stack[head-1]=0;
					head--;
					j++;
				}
				sum2=sum2+weight[j];
				cost2=cost2+price[j];
				stack[head]=j;
				head++;
				j--;
			}
			if(temp>=cost2+cost1 && (q*sum2)>=sum1)
				temp=cost2+cost1;
//printf("%d %d %d\n",cost1,cost2,temp);
		}
		printf("%lld\n",cost-temp);
	}
	return 0;
}





