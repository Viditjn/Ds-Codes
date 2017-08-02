#include <stdio.h>
#include<stdlib.h>
long double a[100005],b[100005],c[100005];//,left[100005],right[100005];
long long int count=0;
long long int mergenew(long double arr[],long double arry[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;
	long double L[n1], R[n2],L1[n1],R1[n2];
	long long int co=0;
	for(i = 0; i < n1; i++)
	{
		L1[i] = arry[l+i];
		L[i] = arr[l + i];
	}
	for(j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1+ j];
		R1[j]=arry[m+1+j];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arry[k]=L1[i];
			arr[k] = L[i];
			i++;
		}
		else
		{
			arry[k] = R1[j];
			arr[k] = R[j];
			co=((co%1000000007)+((n1-i)%1000000007))%1000000007;
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arry[k]=L1[i];
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		arry[k]=R[j];
		j++;
		k++;
	}
	return co;
}
long long int mergeSortnew(long double arr[],long double arry[], int l, int r)
{
	long long int m,co=0;
	if (l < r)
	{
		m = l+(r-l)/2;
		co = mergeSortnew(arr,arry, l, m)%1000000007;
		co += mergeSortnew(arr,arry, m+1, r)%1000000007;
		co += mergenew(arr,arry, l, m+1, r)%1000000007;
	}
	return co;
}
/*int  _mergeSort(long double arr[],long double temp[], int left, int right);
int merge(long double arr[], long double temp[], int left, int mid, int right);
long long int mergeSort(long double arr[], int array_size)
{
	long double *temp = (long double *)malloc(sizeof(long double)*array_size);
	return _mergeSort(arr, temp, 0, array_size - 1);
}
int _mergeSort(long double arr[],long double temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left)
	{
		mid = (right + left)/2;
		inv_count  = (_mergeSort(arr, temp, left, mid))%1000000007;
		inv_count += (_mergeSort(arr, temp, mid+1, right))%1000000007;
		inv_count += (merge(arr, temp, left, mid+1, right))%1000000007;
	}
	return inv_count;
}
int merge(long double arr[], long double temp[], int left, int mid, int right)
{
	int i, j, k;
	int inv_count = 0;
	i = left; 
	j = mid; 
	k = left; 
	while ((i <= mid - 1) && (j <= right))
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
			inv_count = (inv_count + (mid - i))%1000000007;
		}
	}
	while (i <= mid - 1)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	for (i=left; i <= right; i++)
		arr[i] = temp[i];
	return inv_count;
}*/
int main()
{
	int N;
	double L,R;
	scanf("%d %lf %lf",&N,&L,&R);
	long long int i,j,count1=0,p=0,f=0,total=0,t=0;
//	double a[100005],b[100005],c[100005];
	long double left[N],right[N],d;
	for(i=0;i<N;i++)
	{
		scanf("%Lf %Lf %Lf",&a[i],&b[i],&c[i]);
		if(b[i]==0)
			p++;
		left[i]=0;
		right[i]=0;
	}
	for(i=0;i<N;i++)
	{
		if(b[i]==0)
		{
			double d=-1.00*c[i]/a[i];
			if(d>L && d<R)
				count1=(count1+N-p)%1000000007;
			f++;
		}
		else if(b[i]!=0)
		{
			left[i-f]=(-1.00*c[i]-a[i]*L)/b[i];
			right[i-f]=(-1.00*c[i]-a[i]*R)/b[i];
		}
	}
	t=mergeSortnew(left,right,0,N-f-1);
	for(i=0;i<N-f;i++)
	printf("%Lf %Lf\n",left[i],right[i]);
	printf("%lld\n",t);
	t=0;
	t=mergeSortnew(right,left,0,N-f-1);
	printf("%lld\n",t);
	total=((t%1000000007)+(count1%1000000007))%1000000007;
	printf("%lld\n",total);
	return 0;
}
