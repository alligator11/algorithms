#include <stdio.h>
int seq[100],cost[100][100],kvalue[100][100];
int name=1;
int printParenthesis(int i,int j)
{
if (i == j)
{
printf("%d",name++);
return;
}
printf("(");
printParenthesis(i,kvalue[i][j]);
printParenthesis(kvalue[i][j]+1,j);
printf(")");
}
void matrix(int i, int j){
int min_cost=0,min_k=0,cos;
for (int k=i;k<j;k++){
cos=cost[i][k]+cost[k+1][j]+seq[i]*seq[k+1]*seq[j+1];
if(min_cost==0||min_cost>cos){
min_cost=cos;
min_k=k;
}
}
cost[i][j]=min_cost;
kvalue[i][j]=min_k;
}
void print_matrix(int mat[][100],int n){
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
printf("%d\t\t",mat[i][j]);
}
printf("\n");
}
}
int main() {
int n;
printf("Enter number of matrices: ");
scanf("%d",&n);
printf("Enter number of rows of each matrix:\n");
for (int i=0;i<n;i++){
scanf("%d",&seq[i]);
}
printf("Enter number of columns of the last matrix: ");
scanf("%d",&seq[n]);
for (int k=1;k<n;k++){
for(int j=k,i=0;j<n;j++,i++){
matrix(i,j);
}
}
printf("\nCost Matrix:\n");
print_matrix(cost,n);
printf("\nk value Matrix:\n");
print_matrix(kvalue,n);
printf("\nOptimal parenthesis: ");
printParenthesis(0, n-1);
return 0;
}
