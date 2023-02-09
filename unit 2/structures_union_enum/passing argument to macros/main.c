#include <stdio.h>
#include <stdlib.h>
# define area(r) 3.14*r*r
int main()
{
    int r;float area;
    printf("enter raduis::>> ");scanf("%d",&r);
    area=area(r);
    printf("%.3f",area);
    return 0;
}
