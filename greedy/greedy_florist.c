#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMinimumCost(int k, int n, int* c) {
    int total_cost=0;
    qsort(c, n, sizeof(int), cmpfunc);
    int r=0;
    int coun=k;
    for (int i=0; i<n; i++){
        if(coun==0){
            r+=1;
            coun=k;
        }
        total_cost+=(r+1)*c[i];
        coun-=1;
    }
    return total_cost;
}

int main()
{
    int n,k,c[100];
    int minimumCost;
    printf("Enter no. of flowers: ");
    scanf("%d",&n);
    printf("Enter no. of friends: ");
    scanf("%d",&k);
    printf("Enter original prices: ");
    for (int i = 0; i < n; i++) {
      scanf("%d",&c[i]);
    }
    minimumCost = getMinimumCost(k, n, c);
    printf("%d", minimumCost);
    return 0;
}
