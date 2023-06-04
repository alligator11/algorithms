#include <stdio.h>
struct items{
int item;
int weight;
int value;
float ratio;
}item_list[100],temp;
sortInDesc(int n){
int i,j;
for(i=0;i<n;i++){
for(j=0;j<n-i-1;j++){
if(item_list[i].ratio>item_list[j].ratio){
temp=item_list[i];
item_list[i]=item_list[j];
item_list[j]=temp;
}
Design and Analysis of Algorithms | Farin Khan - 60009210140
April 2, 2023 3
}
}
}
int main() {
int s[100];
int n,i,m,count=0,flag=0;
float frac,w=0.0,p=0.0;
printf("Name: Farin Khan\n");
printf("SAP Id: 60009210140\n");
printf("Enter number of items: ");
scanf("%d",&n);
for(i=0;i<n;i++){
item_list[i].item=i+1;
printf("Enter weight of item %d: ",i+1);
scanf("%d",&item_list[i].weight);
printf("Enter value of item %d: ",i+1);
scanf("%d",&item_list[i].value);
item_list[i].ratio=(float)item_list[i].value/(float)item_list[i].weight;
}
sortInDesc(n);
printf("Sorted Items:\n");
printf("Item\tWeight\tValue\tRatio");
for(i=0;i<n;i++){
printf("\n%d\t\t%d\t\t%d\t\t%.2f",item_list[i].item,item_list[i].weight,item_list[i].value,item_list[i].ratio);
}
printf("\nEnter maximum capacity: ");
scanf("%d",&m);
for(i=0;i<n;i++){
if(item_list[i].weight<=(m-w)){
w+=item_list[i].weight;
Design and Analysis of Algorithms | Farin Khan - 60009210140
April 2, 2023 4
p+=item_list[i].value;
s[count]=item_list[i].item;
count++;
}
else{
frac=(m-w)/item_list[i].weight;
w+=frac*item_list[i].weight;
p+=frac*item_list[i].value;
s[count]=item_list[i].item;
flag=1;
break;
}
}
printf("Profit: %.2f\n",p);
printf("Selected Items:");
for(i=0;i<=count;i++){
printf("\tI%d",s[i]);
}
printf("*%.2f",frac);
return 0;
}
