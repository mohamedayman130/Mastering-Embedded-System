#include <stdio.h>
#include <stdlib.h>

struct student{
int roll,mark;
char name[100];
};
int main()
{
    struct student std [10];
    for(int i=0;i<3;i++)
    {
        printf("std num ::>> %d\n",i+1);
        printf("enter name::>> ");fflush(stdout);fflush(stdin);gets(std[i].name);
        printf("enter roll::>> ");scanf("%d",&std[i].roll);
        printf("enter mark::>> ");scanf("%d",&std[i].mark);printf("\n");

    }
        for(int i=0;i<3;i++)
    {
        printf("std num ::>> %d\n",i+1);
        printf("name::>> %s\n",std[i].name);
        printf("roll::>> %d\n",std[i].roll);
        printf("mark::>> %d\n\n",std[i].mark);

    }


}
