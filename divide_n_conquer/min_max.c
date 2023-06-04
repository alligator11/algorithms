#include <stdio.h>
int a[100],min,max,c=0;
int MaxMin(int i,int j)
{
int max1,min1,mid;
if(i==j)
{
max=a[i];
min=max;
}
else if(i==j-1)
{
if(a[i]<a[j] | ++c<0)
{
max=a[j];
min=a[i];
}
else
{
max=a[i];
min=a[j];
}
}
else
{
mid=(i+j)/2;
MaxMin(i,mid);
max1=max;
min1=min;
MaxMin(mid+1,j);
if(max<max1)
max=max1;
if(min>min1)
min=min1;
}
}
int main()
{
int i,n;
printf("Enter number of elements: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter a number: ");
scanf("%d",&a[i]);
}
min=a[0];
max=min;
MaxMin(0,n-1);
printf("Minimum is %d.\n",min);
printf("Maximum is %d.\n",max);
printf("Number of comparision = %d",c);
return 0;
}
