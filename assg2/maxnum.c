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
		int arry[N],i,j,array[N],temp=0;
		for(i=0;i<N;i++)
			scanf("%d",&arry[i]);
		qsort(arry,N,sizeof(int),cmpfunc);
		for(i=0,j=N-1;i<N;i++,j--)
			array[j]=arry[i];
		for(i=0;i<N;i++)
			if(array[i]>=i+1)
				temp=i+1;
		printf("%d\n",temp);
	}
	return 0;
}

