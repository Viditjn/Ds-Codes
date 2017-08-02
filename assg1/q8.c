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
	int N,L,R;
	scanf("%d %d %d",&N,&L,&R);
	int arry[N][3],i,j,count,a,b,c,no;
	float x,t;
	double left[N],right[N];
	for(i=0;i<N;i++)
	{
		scanf("%d %d %d",&arry[i][0],&arry[i][1],&arry[i][2]);
		left[i]=0;
		right[i]=0;
	}
	for(i=0,j=0;i<N;i++)
	{
		a=arry[i][0];
		b=arry[i][1];
		c=arry[i][2];
		if(arry[i][1]!=0)
		{
			left[j]=(double)(-(c/b)-((a/b)*L));
			right[j]=(double)(-(c/b)-((a/b)*R));
			j++;
		}
		else
		{
			if(arry[i][0]!=0)
			{
				t=-arry[i][2]/arry[i][0];
				if(t>L && t<R)
					count++;
			}
			if(arry[i][0]==0)
				if(arry[i][2]>L && arry[i][2]<R)
					count++;
		}
	}
	no=j;
	for(i=0;i<no;i++)
		printf("%lf %lf\n",left[i],right[i]);
	mergeSort(left,right,0,no);
	for(i=0;i<no;i++)
		printf("%lf %lf\n",left[i],right[i]);
	printf("%d\n",count);
	return 0;
}

