#include <stdio.h>
#include <string.h>
int main() {
char str1[100],str2[100],str[100],p=0;
int LCS[100][100],flag[100][100];
int i,j;
printf("Enter String 1: ");
scanf("%s",&str1);
printf("Enter String 2: ");
scanf("%s",&str2);
for(int j=1;j<=strlen(str2);j++){
for(int i=1;i<=strlen(str1);i++){
if(str1[i-1]==str2[j-1]){
LCS[i][j]=LCS[i-1][j-1]+1;
flag[i][j]=1;
}
else if(LCS[i-1][j]>LCS[i][j-1]){
LCS[i][j]=LCS[i-1][j];
flag[i][j]=2;
}
else
LCS[i][j]=LCS[i][j-1];
}
}
printf("LCS Table:\n");
for(int i=0;i<=strlen(str1);i++){
for(int j=0;j<=strlen(str2);j++){
printf("%d\t",LCS[i][j]);
}
printf("\n");
}
i=strlen(str1);
j=strlen(str2);
while(i!=0 && j!=0){
if(flag[i][j]==1){
str[p]=str1[i-1];
i=i-1;
j=j-1;
p++;
}
else if(flag[i][j]==2)
i=i-1;
else
j=j-1;
}
printf("LCS: ");
for(int k=strlen(str)-1;k>=0;k--)
printf("%c",str[k]);
return 0;
}
