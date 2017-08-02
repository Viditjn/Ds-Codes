#include<stdio.h>
#include<string.h>
void prefix(char* s,int* arr,int l)
{
	int i,j;
	arr[0]=0;
	for(i=1,j=0;i<l && j<l;i++)
	{
		if(s[i]==s[j])
			j++;
		else
			j=0;
		arr[i]=j;
	}
	return;
}
int attach(int* st1,int* st2,char* s1,char* s2,int l1,int l2)
{
	int i,j,k;
	for(i=0,j=0;i<l1 && j<l2;)
	{
		while(s1[i]!=s2[j] && j!=0)
			j=st2[j-1];
		if(s1[i]==s2[j])
			j++;
		i++;
		if(j==l2)
			return -1;
	}
	return j;
}
int main()
{
	char s1[100005],s2[100005],s3[100005];
	scanf("%s %s %s",s1,s2,s3);
	int l1,l2,l3,count[3][3],arr1[100005],arr2[100005],arr3[100005],i,j,x,y,t1,t2,t,ans=0,co=0,temp=0,l[3];
	l1=strlen(s1);
	l2=strlen(s2);
	l3=strlen(s3);
	int* p1=arr1;
	int* p2=arr2;
	int* p3=arr3;
	prefix(s1,p1,l1);
	prefix(s2,p2,l2);
	prefix(s3,p3,l3);
	l[0]=l1;l[1]=l2;l[2]=l3;
	count[0][1]=attach(arr1,arr2,s1,s2,l1,l2);
	count[1][0]=attach(arr2,arr1,s2,s1,l2,l1);
	count[1][2]=attach(arr2,arr3,s2,s3,l2,l3);
	count[2][1]=attach(arr3,arr2,s3,s2,l3,l2);
	count[0][2]=attach(arr1,arr3,s1,s3,l1,l3);
	count[2][0]=attach(arr3,arr1,s3,s1,l3,l1);
	count[0][0]=count[1][1]=count[2][2]=-1;
	if(count[0][1]==-1 || count[1][0]==-1)
		co++;
	if(count[1][2]==-1 || count[2][1]==-1)
		co++;
	if(count[0][2]==-1 || count[2][0]==-1)
		co++;
	if(co==0)
	{
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				if(temp<=count[i][j] && i!=j)
				{
					temp=count[i][j];
					x=i;
					y=j;
				}
		t1=count[3-x-y][x];
		t2=count[y][3-x-y];
		t=t1>t2?t1:t2;
		ans=l1+l2+l3-temp-t;
	}
	else if(co==1)
	{
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				if(i!=j && count[i][j]==-1)
				{
					t1=count[3-i-j][i];
					t2=count[i][3-i-j];
					t=t1>t2?t1:t2;
					ans=l[i]+l[3-i-j]-t;
				}
	}
	else if(co>1)
	{
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				if(i!=j && count[i][j]==-1 && count[3-i-j][j]==-1)
				{
					if(count[3-i-j][i]==-1)
						ans=l[3-i-j];
					else if(count[i][3-i-j]==-1)
						ans=l[i];
					else 
					{
						t1=count[3-i-j][i];
						t2=count[i][3-i-j];
						t=t1>t2?t1:t2;
						ans=l[i]+l[3-i-j]-t;
					}
				}
		if(ans==0)
			for(i=0;i<3;i++)
				if(l[i]>=ans)
					ans=l[i];
	}
	printf("%d\n",ans);
	return 0;
}
