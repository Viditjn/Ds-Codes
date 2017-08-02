#include<stdlib.h>
#include<stdio.h>
typedef struct all
{
	double X;
	double Y;
}all;
int cmpfunc (const void * a, const void * b)
{
		return ( *(int*)a - *(int*)b );
}
int  MegeeSort(double arr[], double temp[], double left, double right);
int merge(double arr[], double temp[], double left, double mid, double right);
int com_doub(const void * a, const void * b)
{
	struct all *var1 = (struct all *) a;
	struct all *var2 = (struct all *) b;
	return (var1->X > var2->X) - (var1->X < var2->X);
}
int mergeSort(double arr[], double n)
{
	double *temp = (double *)malloc(sizeof(double)*n);
	return MegeeSort(arr, temp, 0, n-1);
}
int MegeeSort(double arr[], double temp[], double left, double right)
{
	int mid, inv_count = 0;
	if (right > left)
	{
		mid = (right + left)/2;

		inv_count  = MegeeSort(arr, temp, left, mid);
		inv_count += MegeeSort(arr, temp, mid+1, right);
		inv_count += merge(arr, temp, left, mid+1, right);
	}
	return inv_count;
}
int merge(double arr[], double temp[], double left,double  mid, double right)
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
			inv_count = inv_count + (mid - i);
		}
	}
	while (i <= mid - 1)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	for (i=left; i <= right; i++)
		arr[i] = temp[i];
	return inv_count;
}
int main()
{
	int n,l,r;
	scanf("%d %d %d",&n,&l,&r);
	int i,j,k,test[n];
	double a[n],b[n],c[n];
	for(i=0;i<n;i++)
		scanf("%lf %lf %lf",&a[i],&b[i],&c[i]);
	double y1,y2,x;
	struct all arry[100003];
	int  count=0;
	for(i=0;i<n;i++)
	{
		if(b[i]!=0)
		{
			y1 = -1.00*((c[i]+(a[i]*l)))/b[i];
			y2 = -1.00*((c[i]+(a[i]*r)))/b[i];
			test[i]=(int)y1;
		}
		else if(b[i]==0)
		{
			x = -1.00 * ((c[i])/a[i]);
				if(x>l && x<r)
					count++;
		}
		if(y1<y2)
		{
			arry[i].X=y1;
			arry[i].Y=y2;
		}
		else
		{
			arry[i].X=y2;
			arry[i].Y=y1;
		}

	}
	qsort(test,n,sizeof(int),cmpfunc);
	qsort(arry,n,sizeof(struct all),com_doub);
	double next[n];
	for(i=0;i<n;i++)
		next[i] = arry[i].Y;
	int m = 1000000007;
	if(count==0)
		printf("%d\n",mergeSort(next,n)%m);
	if(count!=0)
		printf("%d\n",((count)%m * (mergeSort(next,n))%m)%m);
	return 0;
}
