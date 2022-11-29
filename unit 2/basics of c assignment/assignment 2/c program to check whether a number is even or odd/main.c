#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
       printf("enter number ::>> ");fflush(stdin);fflush(stdout);
    scanf("%d",&number);
    (number%2==0)?printf("number is even"):printf("number is odd");

}
