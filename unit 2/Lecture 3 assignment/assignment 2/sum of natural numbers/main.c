#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,sum=0;
    printf("enter number ::>> ");fflush(stdin);fflush(stdout);
    scanf("%d",&x);
    for(int i=0;i<=x;i++)
    {
        sum+=i;
    }
    printf("sum ::>> %d",sum);
}
