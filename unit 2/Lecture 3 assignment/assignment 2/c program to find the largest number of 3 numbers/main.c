#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1,n2,n3;
    printf("enter first number ::>> ");fflush(stdin);fflush(stdout);
    scanf("%f",&n1);
    printf("enter second number ::>> ");fflush(stdin);fflush(stdout);
    scanf("%f",&n2);
    printf("enter third number ::>> ");fflush(stdin);fflush(stdout);
    scanf("%f",&n3);
    printf("maximum number ::>> ");
    (n1>n2)?(n1>n3)?printf("%f",n1):printf("%f",n3):(n2>n3)?printf("%f",n2):printf("%f",n3);

}
