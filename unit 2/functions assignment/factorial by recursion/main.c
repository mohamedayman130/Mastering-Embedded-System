#include <stdio.h>
#include <stdlib.h>

int fact(int num)
{
    if(num==0) return 1;
    else return num*fact(num-1);
}
int main()
{
    int num;
    printf("enter number ::>> ");fflush(stdin);fflush(stdout);scanf("%d",&num);
    printf("%d",fact(num));

}
