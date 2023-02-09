#include <stdio.h>
#include <stdlib.h>

struct complix{
int real,img;
}n1,n2,res;

struct complix add(struct complix n1,struct complix n2)
{
    struct complix res;
 res.real=n1.real+n2.real;
 res.img=n1.img+n2.img;
 return res;
}
int main()
{
    printf("enter first number::>> ");scanf("%d %d",&n1.real,&n1.img);
    printf("enter second number::>> ");scanf("%d%d",&n2.real,&n2.img);
    res=add(n1,n2);
    printf("res::>> %d+%dj",res.real,res.img);


    return 0;
}
