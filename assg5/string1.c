#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int m=1000000007;
long long int value[10000000]={0},fact[10000]={0},inverse[10000]={0};
int fre[10000000]={0};

long long int power(long long int x,long long int y)
{
	long long int r,f;
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

long long int modulo(long long int a,long long int b)
{
    return ((a%m)*(power(b,m-2)))%m;
}

int cmpfunc (const void * a, const void * b)
{
		return ( *(long long int*)a - *(long long int*)b );
}

int main()
{
    int l,Q,i,temp=1,t,a,y,j,var,ans;
	fact[0]=1;
	for(i=1;i<10000;i++)
		fact[i]=((i%m)*(fact[i-1]%m))%m;
	for(i=0;i<10000;i++)
		inverse[i]=modulo(1,fact[i]);
    scanf("%d %d",&l,&Q);
    char str[l+1];
    scanf("%s",str);
    value[0]=(str[0]-'a'+1);
    for(i=1;i<l;i++)
    {
        int x = str[i]-'a'+1;
        y = (x*(temp*29)%m)%m;
        temp=(temp*29)%m;
        value[i]=(value[i-1]+y)%m;
    }
    for(i=0,temp=1,t=l;i<l-1;i++)
    {
        for(j=i+1;j<l;j++)
        {
            a = value[j];
            a = ((a%m-value[i]%m)+m)%m;
            value[t]=modulo(a,temp*29);
            t++;
        }
        temp=(temp*29)%m;
    }
    qsort(value,t,sizeof(long long int),cmpfunc);
    int count=1,max=0;
    for(i=1,var=value[0];i<=t;i++)
    {
        if(value[i]==var)
            count++;
        else
        {
            fre[count]+=1;
            max=max>count?max:count;
            var=value[i];
            count=1;
        }
    }
    for(i=0;i<Q;i++)
	{
		int q,j;
		scanf("%d",&q);
		ans=0;
		for(j=q;j<=max;j++)
			ans=(ans+((((((fre[j]%m)*(fact[j]%m))%m)%m*(inverse[j-q]%m)%m)*(inverse[q]%m)%m)))%m;
		printf("%d\n",ans);
	}
    return 0;
}
