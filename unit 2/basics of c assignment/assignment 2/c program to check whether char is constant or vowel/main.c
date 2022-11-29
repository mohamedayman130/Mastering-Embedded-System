#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    printf("enter char ::>> ");fflush(stdin);fflush(stdout);
    scanf("%c",&c);
    switch(c)
    {
    case 'a':
    case 'A':
    case 'I':
    case 'i':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
    case 'e':
    case 'E':
        {
            printf("char is vowel");break;
        }
    default:
        {
            printf("char is constant");break;
        }

    }
}
