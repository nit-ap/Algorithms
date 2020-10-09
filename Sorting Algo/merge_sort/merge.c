
#include<stdio.h>
void merge(int a[],int ,int ,int);
void merge_sort(int a[], int p, int r)
{
	if (p<r)
	{
	int q=(p+r)/2;
	merge_sort(a,p,q);
	merge_sort(a,q+1,r);
	merge(a,p,q,r);
	}
}

int main()
{
	int n,i,a[20];
	printf("Enter the no of elements:");
	scanf("%d", &n);
	printf("Elements of array are:");
	for(i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
		}
	merge_sort(a,0,n-1);
	printf("the sorted array is:");
	for(i=0;i<n;i++)
		{
			printf("%d", a[i]);
		}
}
void merge(int a[], int p, int q, int r)
{
	int n1,n2,i,j,k,l[10],rh[10];
	n1=q-p+1;
	n2=r-q;
	for(i=0;i<n1;i++)
		{
			l[i]=a[p+i];
		}
	for(j=0;j<n2;j++)
		{
			rh[j]=a[q+j+1];
		}
	l[n1]=100;
	rh[n2]=100;
	i=0;
	j=0;
	for(k=p;k<=r;k++)
	{
		if(l[i]<=rh[j])
		{
			a[k]=l[i];
			i=i+1;
		}
		else
		{
			a[k]=rh[j];
			j=j+1;
		}
	}
}

