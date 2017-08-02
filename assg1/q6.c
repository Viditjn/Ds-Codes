#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n1,n2,n3,i,j,k,l,count=0,temp=0;
		scanf("%d",&n1);
		int a1[n1];
		for(i=0;i<n1;i++)
			scanf("%d",&a1[i]);
		scanf("%d",&n2);
		int a2[n2];
		for(i=0;i<n2;i++)
			scanf("%d",&a2[i]);
		scanf("%d",&n3);
		int a3[n3];
		for(i=0;i<n3;i++)
			scanf("%d",&a3[i]);
		for(i=0,j=0,k=0;i<n1&&j<n2&&k<n3;)
		{
			if(a1[i]==a2[j]&&a2[j]==a3[k])
			{
				count++;
				i++;j++;k++;
			}
			else if(a1[i]<a2[j])
			{
				if(a1[i]<a3[k])
					i++;
				else
					k++;
			}
			else if(a1[i]>=a2[j])
			{
				if(a2[j]<a3[k])
					j++;
				else
					k++;
			}
//temp++;
		}
//printf("%d\n",temp);
		printf("%d\n",count);
	}
	return 0;
}
