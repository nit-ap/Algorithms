#include<stdio.h>
void radixsort(int a[], int n);
void countsort(int a[] ,int ,int);
int max(int a[],int n);
int main()
{
int n,i;
printf("Enter the size of the array:");
scanf("%d",&n);
int a[n];
printf("Enter the array:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
radixsort(a,n);
printf("array after radix sort is:\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
return 0;
}
void radixsort(int a[],int n)
{
int pow;
int large=max(a,n);
for(pow=1;large/pow>0;pow*=10)
countsort(a,n,pow);
}
//function to get maximum value from the array
int max(int a[],int n)
{
int m=a[0],i;
for(i=1;i<n;i++)
{
if(m<a[i])
m=a[i];
}
return m;
}
//count sort as a subroutine
void countsort(int a[],int n,int pow)
{
int res[n];
int i,count[10]={0};
for(i=0;i<n;i++)
count[(a[i]/pow)%10]++;
for(i=1;i<10;i++)
count[i]+=count[i-1];
for(i=n-1;i>=0;i--)
{
res[count[(a[i]/pow)%10]-1]=a[i];
count[(a[i]/pow)%10]--;
}
for(i=0;i<n;i++)
a[i]=res[i];
}





