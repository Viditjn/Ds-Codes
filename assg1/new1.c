#include<stdio.h>
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		int arry[N],i,j,count,temp,ans;
		for(i=0;i<N;i++)
			scanf("%d",&arry[i]);
		qsort(arry,N,sizeof(int),cmpfunc);
		for(i=0,temp=arry[0],count=0;i<N;i++)
		{
			if(temp==arry[i])
			{
				count++;
				if(count>=N/2)
				{
					ans=arry[i];
					break;
				}
			}
			else
			{
				count=1;
				temp=arry[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
