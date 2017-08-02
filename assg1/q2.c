#include<string.h>
#include<stdio.h>
long long int power(long long int x,long long int y)
{
	long long int m,r,f;
	m=1000000007;
	x=x%m;
	for(r=1;y>0;)
	{
		if(y%2==1)
			r=(r*x)%m;
		x=(x*x)%m;
		y=y>>1;
	}
	f=r%m;
	return f;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,j,k;
		char postfix[200000];
		scanf("%s",postfix);
		long long int num[100005]={0};
		for(i=0,j=0,k=0;k<strlen(postfix);k++)
		{
			if(postfix[k]!='+'&&postfix[k]!='-'&&postfix[k]!='*'&&postfix[k]!='/')
			{
				num[i]=postfix[k]-48;
				i++;
			}
			else
			{
				if(postfix[k]=='*')
					num[i-2]=((num[i-1]%1000000007)*(num[i-2]%1000000007))%1000000007;
				else if(postfix[k]=='/')
					num[i-2]=((num[i-2]%1000000007)*(power(num[i-1],1000000005)%1000000007))%1000000007;
				else if(postfix[k]=='+')
					num[i-2]=((num[i-1]%1000000007)+(num[i-2]%1000000007))%1000000007;
				else if(postfix[k]=='-')
					num[i-2]=((num[i-2]%1000000007)-(num[i-1]%1000000007)+1000000007)%1000000007;
				num[i-1]=0;
				i--;
				//printf("%d\n",num[i-1]);
			}
		}
		printf("%lld\n",num[0]);
	}
}
