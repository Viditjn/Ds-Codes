#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,M,i,j,time=0,temp=-1,count=0,test=0,ans=0;
		scanf("%d %d",&M,&N);
		int arry[M][N];
		for(i=0;i<M;i++)
		{
			char temp[N];
			scanf("%s",temp);
			for(j=0;j<N;j++)
				arry[i][j]=temp[j];
		}
		while(1)
		{
			for(i=0;i<M;i++)
			{
				for(j=0;j<N;j++)
				{
					if(arry[i][j]=='f')
					{
						if(arry[i][j-1]=='r'&&j!=0)
							arry[i][j]='t';
						if(arry[i][j+1]=='r'&&j!=N-1)
							arry[i][j]='t';
						if(arry[i-1][j]=='r'&&i!=0)
							arry[i][j]='t';
						if(arry[i+1][j]=='r'&&i!=M-1)
							arry[i][j]='t';
					}
				}
			}
			for(i=0;i<M;i++)
			{
				for(j=0;j<N;j++)
				{
					if(arry[i][j]=='t')
					{
						count++;
						arry[i][j]='r';
					}
				}
			}
			if(count==0)
				break;
			count=0;
			time++;
		}
		for(i=0;i<M;i++)
			for(j=0;j<N;j++)
				if(arry[i][j]=='f')
					ans=-1;
		if(ans==-1)
			printf("-1\n");
		else	
			printf("%d\n",time);
	}
	return 0;
}

