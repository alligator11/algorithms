#include <stdio.h>
int matrix[100][100];
int flag[100];
int c=0;
struct edges{
int start;
int end;
int cost;
}sedges[100],sol_edges[100];
void findmin(int n1){
int p,q,start_min,end_min;
int min=3672;
for (p=0;p<n1;p++)
{
for(q=0;q<n1;q++)
{
if(matrix[p][q]<min)
{
min = matrix[p][q];
start_min=p;
end_min=q;
}
}
}
matrix[start_min][end_min]=3672;
sedges[c].start=start_min;
sedges[c].end=end_min;
sedges[c].cost=min;
c++;
return 0;
}
int main() {
int n1,n2,s,e,i,j,p,q,r,min_cost=0,l=0;
printf("Enter number of nodes: ");
scanf("%d",&n1);
printf("Enter number of edges: ");
scanf("%d",&n2);
for(i=0;i<n2;i++)
{
for(j=0;j<n2;j++)
{
matrix[i][j]=3672;
}
}
for(i=0;i<n2;i++)
{
printf("Enter the start node: ");
scanf("%d",&s);
printf("Enter the end node: ");
scanf("%d",&e);
printf("Enter the cost of edge: ");
scanf("%d",&matrix[s][e]);
}
for(i=0;i<n2;i++)
findmin(n1);
for(i=0;i<c;i++){
if(flag[sedges[i].start]!=1 || flag[sedges[i].end]!=1)
{
sol_edges[i].start=sedges[i].start;
sol_edges[i].end=sedges[i].end;
sol_edges[i].cost=sedges[i].cost;
l++;
flag[sedges[i].start]=1;
flag[sedges[i].end]=1;
}
}
printf("Solution set of edges: \n");
for(i=0;i<l;i++)
{
min_cost+=sol_edges[i].cost;
printf("(%d,%d)",sol_edges[i].start,sol_edges[i].end);
}
printf("\nMinimum cost= %d",min_cost);
return 0;
}
