#include<stdio.h>
void merge(double arr[],double arry[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;
	double L[n1], R[n2],L2[n1],R2[n2];
	for(i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
		L2[i]= arry[l+i];
	}
	for(j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1+ j];
		R2[j]= arry[m+1+j];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			arry[k] = L2[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			arry[k] = R2[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		arry[k] = L2[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		arry[k] = R2[j];
		j++;
		k++;
	}
}
void mergeSort(double arr[],double arry[], int l, int r)
{
	if (l < r)
	{
		int m = l+(r-l)/2; 
		mergeSort(arr,arry, l, m);
		mergeSort(arr,arry, m+1, r);
		merge(arr,arry, l, m, r);
	}
}
int main()
{
	int N;
	double L,R;
	scanf("%d %lf %lf",&N,&L,&R);
	int i,j,count,p,d,f;
	double left[N],right[N],a[N],b[N],c[N];
	for(i=0;i<N;i++)
	{
		scanf("%lf %lf %lf",&a[i],&b[i],&c[i]);
		if(b[i]==0)
			p++;
		left[i]=0;
		right[i]=0;
	}
	for(i=0,j=0;i<N;i++)
	{
		if(b[i]==0)
		{
			double d=-1.00*c[i]/a[i];
			if(d>L && d<R)
				count=(count+N-p)%1000000007;
			f++;
		}
		else if(b[i]!=0)
		{
			left[i-f]=(-1.00*c[i]-a[i]*L)/b[i];
			right[i-f]=(-1.00*c[i]-a[i]*R)/b[i];
		}
	}
	for(i=0;i<N-f;i++)
		printf("%lf %lf\n",left[i],right[i]);
	mergeSort(left,right,0,N-f);
	for(i=0;i<N-f;i++)
		printf("%lf %lf\n",left[i],right[i]);
	printf("%d\n",count);
	return 0;
}

