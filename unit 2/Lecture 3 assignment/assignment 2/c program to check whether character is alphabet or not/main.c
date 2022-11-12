#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    printf("enter a char :::>> ");fflush(stdin);fflush(stdout);
    scanf("%c",&c);
    if(c>='A'&&c<='Z' || c>='a'&&c<='z')
    {
        printf("character is alphabet ");
    }
    else{printf("character is is not alphabet ");}
}
