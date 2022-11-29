#include <stdio.h>
#include <stdlib.h>

int main()
{

    int x,fact=1;
    printf("enter a number ::>> ");fflush(stdin);fflush(stdout);
    scanf("%d",&x);
    for(int i=2;i<=x;i++)
    {
        fact*=i;
    }
    if(x>=0){
    printf("factorial ::>> %d",fact);
    }
    else{printf("ERROR !!!!");}
}
