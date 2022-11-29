#include <stdio.h>
#include <stdlib.h>

int main()
{
        int arr[30],n,num,f=0;
    printf("enter number of array::>> ");fflush(stdout);fflush(stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("[%d] ::>> ",i+1);fflush(stdout);fflush(stdin);
        scanf("%d",&arr[i]);

    }printf("your array::>> \n");
        for(int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);

    }
    printf("\nEnter the elements to be searched::>>  ");fflush(stdout);fflush(stdin);
    scanf("%d",&num);
    for(int i=0;i<n;i++)
    {
        if(num==arr[i]){printf("yes and its position::>> %d \n",i+1); f=1;}
    }
if(f==0){printf("no");}
}
