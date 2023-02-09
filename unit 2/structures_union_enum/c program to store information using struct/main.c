#include <stdio.h>
#include <stdlib.h>

struct student{
int mark;
char name[100];
int roll;
}std;
int main()
{
    printf("enter name::>> ");gets(std.name);
    printf("enter roll::>> ");scanf("%d",&std.roll);
    printf("enter mark::>> ");scanf("%d",&std.mark);
    printf("\nname : %s",std.name);
    printf("\nroll : %d",std.roll);
    printf("\nmark : %d",std.mark);

}
