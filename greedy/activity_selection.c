#include <stdio.h>
struct activities{
int act;
int start;
int finish;
}act_info[100];
void sort(int n)
{
int i, j;
struct activities temp;
for (i = 0; i < n-1; i++)
{
for (j = 0; j < n-i-1; j++)
{
if (act_info[j].finish > act_info[j+1].finish)
{
temp=act_info[j];
act_info[j]=act_info[j+1];
act_info[j+1]=temp;
}
}
}
}
int main()
{
int n,i,k=0,j=1;
int soln[100];
printf("Enter number of activities: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter activity number: ");
scanf("%d",&act_info[i].act);
printf("Enter start time for A%d: ",act_info[i].act);
scanf("%d",&act_info[i].start);
printf("Enter finish time for A%d: ",act_info[i].act);
scanf("%d",&act_info[i].finish);
}
sort(n);
soln[0]=act_info[0].act;
k=act_info[0].finish;
for(i=0;i<n-1;i++)
{
if(act_info[i+1].start>=k)
{
soln[j]=act_info[i+1].act;
j++;
k=act_info[i+1].finish;
}
}
printf("\nThe final solution array that gives an optimal solution:\n");
for (i=0;i<j;i++)
{
printf("A%d\t",soln[i]);
}
return 0;
}
