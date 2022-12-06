#include <stdio.h>
#include <stdlib.h>
int pow (int base,int power)
{
    if(power==0) return 1;
    else return base*pow(base,power-1);
}
int main()
{
    int base,power;
    printf("enter base::>> ");fflush(stdin);fflush(stdout);scanf("%d",&base);
    printf("enter power::>> ");fflush(stdin);fflush(stdout);scanf("%d",&power);
    printf("%d^%d=%d",base,power,pow(base,power));

    return 0;
}
