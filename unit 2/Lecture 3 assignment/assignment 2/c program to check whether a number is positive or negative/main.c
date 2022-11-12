#include <stdio.h>
#include <stdlib.h>

int main()
{
        float n1;
    printf("enter first number ::>> ");fflush(stdin);fflush(stdout);
    scanf("%f",&n1);
    if(n1>0){printf("number is positive");}
    else if(n1<0){printf("number is negative");}
    else{printf("number is zerroo");}

}
