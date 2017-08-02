#include<stdio.h>
int greatest(int arry[],int start,int size)
{
	int i,temp;
	for(i=start,temp=arry[start];i<start+size;i++)
		if(temp<arry[i])
			temp=arry[i];
	return temp;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,W,i,j;
		scanf("%d %d",&N,&W);
		int arry[N];
		for(i=0;i<N;i++)
			scanf("%d",&arry[i]);
		for(i=0;i<=N-W;i++)
			printf("%d ",greatest(arry,i,W));
		printf("\n");
	}
	return 0;
}
