#include <stdio.h>
int d[100],C[100][100],sol[100];
int MAKE_A_CHANGE(int N,int n){
int i,j;
for(i=1; i<=n; i++)
C[i][0]=0;
for(j=0; j<=N; j++)
C[0][j]=999;
for(i=1; i<=n; i++){
for(j=1;j<=N;j++){
if (j < d [i])
C[i][j] = C[i-1][j];
else
C[i][j] = (C[i-1][j]>1+C[i][j-d[i]]) ? 1+C[i][j-d[i]] : C[i-1][j];
}
}
return C[n][N];
}
int TRACE_MAKE_A_CHANGE(int N, int n){
int c=0,i=n,j=N;
while (j > 0){
if (C[i][j] == C[i-1][j])
i--;
else{
j-=d[i];
sol[c++] = d[i];
}
}
return c;
}
int main() {
int n,N,i,j,c,minn;
printf("Enter number of denominations: ");
scanf("%d",&n);
d[0]=0;
for(i=1;i<=n;i++){
printf("Enter denomination: ");
scanf("%d",&d[i]);
}
printf("Enter total amount: ");
scanf("%d",&N);
minn=MAKE_A_CHANGE(N,n);
printf("Table:\n");
for(i=-0; i<=n; i++){
for(j=-0;j<=N;j++){
printf("%d\t",C[i][j]);
}
printf("\n");
}
c=TRACE_MAKE_A_CHANGE(N,n);
printf("Minimum number of coins: %d\n",minn);
printf("Change: ");
for(i=0;i<c;i++)
printf("%d\t",sol[i]);
return 0;
}
