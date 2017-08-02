#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int overlap(long long int arry1[],long long int arry2[],int len1,int len2);
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
long long int modulo(long long int a,long long int b)
{
	int m=1000000007;
	return ((a%m)*(power(b,m-2)))%m;
}
int maxlen(long long int arr1[],long long int arr2[],int l1,int l2)
{
	int temp,i,j,hess,len,a=0,b=0;
	len=l1+l2;
	if(l1>=l2)
	{
		a=overlap(arr1,arr2,l1,l2);
		if(a==1)
		{
		//	for(j=0;j<l1;j++)
		//		tem[i]=arr1[i];
			len=len-l2;
		}
	}
	if(l1<l2)
	{
		a=overlap(arr2,arr1,l2,l1);
		if(a==1)
		{
			//for(j=0;j<l2;j++)
			//	tem[i]=arr2[i];
			len=len-l1;
		}
	}
	if(a==0)
	{
		for(i=l1-1,j=0;i>=0&&j<l2;i--,j++)
		{
			if((arr2[j]*power(29,i))%1000000007==modulo((arr1[l1-1]-arr1[i-1]),power(29,i)))
				ans=i+1;
		}
		/*for(k=0;k<l1;k++)
			tem[i]=arr1[i];
		for(k=l1
		len=len-j-1;*/
	
	/*for(i=l2-1,j=0;i>=0&&j<l3;i--)
	{
		if(arr3[j]!=modulo((arr2[n-1]-arr2[i-1]),power(29,i)))
			break;
		j++;
	}*/
		len=len-j;
	}
	return len;
}
int overlap(long long int arry1[],long long int arry2[],int l1,int l2)
{
	int i,j,fl=0;
	for(i=0;i<=l1-l2;i++)
	{
		if(i==0)
		{
			if(arry2[l2-1]==modulo(arry1[i+l2-1],power(29,i)))
			{
				fl=1;
				break;
			}
		}
		else if(arry2[l2-1]==(modulo(arry1[i+l2-1],power(29,i))-modulo(arry1[i-1],power(29,i))));
		{
			fl=1;
			break;
		}
	}
	return fl;
}
int main()
{
	char st1[100005],st2[100005],st3[100005];
	int i,j,k,l1,l2,l3;
	scanf("%s %s %s",st1,st2,st3);
	l1=strlen(st1);
	l2=strlen(st2);
//	l3=strlen(st3);
	long long int h1[l1],h2[l2],h3[l3],cum1[l1],cum2[l2],cum3[l3];
	for(i=0;i<l1;i++)
	{
		cum1[i]=0;
		h1[i]=((st1[i]-'a'+1)+power(29,i+1))%1000000007;
		if(i==0)
			cum1[i]=h1[i];
		else
			cum1[i]=cum1[i-1]+h1[i];
	}
	for(i=0;i<l2;i++)
	{
		cum2[i]=0;
		h2[i]=((st2[i]-'a'+1)+power(29,i+1))%1000000007;
		if(i==0)
			cum2[i]=h2[i];
		else
			cum2[i]=cum2[i-1]+h2[i];
	}
	/*for(i=0;i<l3;i++)
	{
		cum3[i]=0;
		h2[i]=((st3[i]-'a'+1)+power(29,i+1))%1000000007;
		if(i==0)
			cum3[i]=h3[i];
		else
			cum3[i]=cum3[i-1]+h3[i];
	}*/
	printf("%d\n",overlap(cum1,cum2,l1,l2));
	return 0;
}
