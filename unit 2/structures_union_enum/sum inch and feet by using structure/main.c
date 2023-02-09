#include <stdio.h>
#include <stdlib.h>

struct Distance{
int feet;
float inch;
}n1,n2,sum;

int main(){
printf("Enter information for 1st distance\n");
printf("Enter feet::>> ");scanf("%d",&n1.feet);
printf("Enter inch::>> ");scanf("%f",&n1.inch);
printf("\nEnter information for 2nd distance\n");
printf("Enter feet::>> ");scanf("%d",&n2.feet);
printf("Enter inch::>> ");scanf("%f",&n2.inch);
sum.feet=n1.feet+n2.feet;sum.inch=n1.inch+n2.inch;

if(sum.inch>12.0){
sum.inch-=12.0;
++sum.feet;}

printf("\nSum of distances=%d-%.2f",sum.feet,sum.inch);
}
