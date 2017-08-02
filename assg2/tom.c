#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,k;
		scanf("%d %d",&N,&k);
		int arry[N],i,count=0,data[N];
		for(i=0;i<N;i++)
		{
			scanf("%d",&arry[i]);
			if(arry[i]==0)
				count++;
			data[i]=0;
		}
		int temp,j=0,sum=arry[0],tempsum=0;
		for(i=0,j=1;i<N;i++)
		{
			if(i!=0)
				sum=sum-arry[i-1];
			if(arry[i]!=0)
			{
				printf("%d\n",sum);
				if(arry[i]%k==0)
				{
					data[i]=1;
				}
				else if(sum<=k)
				{
					while(sum%k!=0)
					{
						if(j==N)
						{
							data[i]=0;
							break;
						}
						sum=sum+arry[j];
						j++;
					}
					if(sum%k==0)
						data[i]=1;
				}
				else if(sum>k)
				{
					tempsum=sum;
					temp=j;
					while(sum%k!=0)
					{
						if(sum==0)
						{
							sum=tempsum;
							j=temp;
							break;
						}
						sum=sum-arry[j-1];
						j--;
					}
					if(sum%k!=0)
					{
						while(sum%k!=0)
						{
							if(j==N)
								break;
							sum=sum+arry[j];
							j++;
						}
						if(sum%k==0)
							data[i]=1;
					}
					else if(sum%k==0)
					{
						data[i]=1;
						if(sum>k)
						{
							while(sum==k || j>i)
							{
								sum=sum-arry[j-1];
								j--;
								if(sum%k==0)
									temp=j+1;
							}
						}
						j=temp;
					}
				}
			}
			for(i=0;i<N;i++)
				printf("%d ",data[i]);
			printf("\n%d\n",count); 
		}
	}
	return 0;
}





