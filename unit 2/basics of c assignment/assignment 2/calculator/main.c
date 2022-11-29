#include <stdio.h>
#include <stdlib.h>

int main()
{
   float n1,n2;char c;
    printf("enter first number ::>> ");fflush(stdin);fflush(stdout);
    scanf("%f",&n1);
    printf("enter second number ::>> ");fflush(stdin);fflush(stdout);
    scanf("%f",&n2);
    printf("enter operator '+' ,'-' ,'*' ,'/' ::>> ");fflush(stdin);fflush(stdout);
    scanf("%c",&c);
    switch(c)
    {
        case '+':printf("%f + %f = %f",n1,n2,n1+n2);break;
        case '-':printf("%f - %f = %f",n1,n2,n1-n2);break;
        case '*':printf("%f * %f = %f",n1,n2,n1*n2);break;
        case '/':printf("%f / %f = %f",n1,n2,n1/n2);break;
        default : printf("operator is not valid !!!!! ");



    }


}
