#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b;
    printf("enter first number ::>> ");fflush(stdin);fflush(stdout);
    scanf("%f",&a);
    printf("enter second number ::>> ");fflush(stdin);fflush(stdout);
    scanf("%f",&b);
    float temp=a;
    a=b;
    b=temp;
    printf("========after swapping=========\n");
    printf("first number ::>> %.3f\n",a);
    printf("second number ::>> %.3f",b);

}
