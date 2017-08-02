#include<stdio.h>
long double arr[100005],arr1[100005];
long long int a[100005][3];
long long int count=0,e=0;
void merge1(long double a[],long long int l,long long int m,long long int r)
{
	long long int i, j, k, n1 = m - l + 1, n2 =  r - m;
	long double L[n1], R[n2];
	for(i = 0; i < n1; i++)
	{
		L[i] = a[l + i];
	}
	for(j = 0; j < n2; j++)
	{
		R[j] = a[m + 1+ j];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
i		{
			a[k] = R[j];
			count=count+n1-i;
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}
void inversion(long double a[],long long int l,long long int r)
{
	if (l < r)
	{
		long long int m = l+(r-l)/2; 
		inversion(a,l, m);
		inversion( a,m+1, r);
		merge1(a, l, m, r);
	}
}
void merge(long double a[],long double b[],long long int l,long long int m,long long int r)
{
	long long int i, j, k, n1 = m - l + 1, n2 =  r - m;
	long double L1[n1], R1[n2];
	long double L2[n1], R2[n2];

	for(i = 0; i < n1; i++)
	{
		L1[i] = a[l + i];
		L2[i] = b[l + i];
	}
	for(j = 0; j < n2; j++)
	{
		R1[j] = a[m + 1+ j];
		R2[j] = b[m + 1+ j];
	}

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L1[i] <= R1[j])
		{
			a[k] = L1[i];
			b[k] = L2[i];
			i++;
		}
		else
		{
			a[k] = R1[j];
			b[k] = R2[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		a[k] = L1[i];
		b[k] = L2[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		a[k] = R1[j];
		b[k] = R2[j];
		j++;
		k++;
	}
}

void mergeSort(long double a[],long double b[],long long int l,long long int r)
{
	if (l < r)
	{
		long long int m = l+(r-l)/2; 
		mergeSort(a,b,l, m);
		mergeSort(a,b,m+1, r);
		merge(a,b,l, m, r);
	}
}
int main()
{
	long long int n,l,r,i,x=0,y=0;
	long double z;
	long long int e;
	scanf("%lld%lld%lld",&n,&l,&r);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i][1]!=0)
		{
			arr[x]=-(a[i][2]+a[i][0]*l)/a[i][1];
			arr1[x]=-(a[i][2]+a[i][0]*r)/a[i][1];
			x++;
		}
		else
		{
			z=-a[i][2]/a[i][0];
			if(z>l && z<r)
			{
				y++;
			}
		}
	}
	e=x*y;
	mergeSort(arr,arr1,0,x-1);
	inversion(arr1,0,x-1);
	count=(count+e)%1000000007;
	printf("%lld\n",count);
	return 0;
}




