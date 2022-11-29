#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[30],n,num,pos;
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
    printf("\nEnter the element to be inserted ::>>  ");fflush(stdout);fflush(stdin);
    scanf("%d",&num);
    printf("Enter the location ::>> ");fflush(stdout);fflush(stdin);
    scanf("%d",&pos);pos--;
    for(int i=n;i>pos;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos]=num;
    printf("new array::>> \n ");
        for(int i=0;i<=n;i++)
    {
        printf("%d  ",arr[i]);

    }

}
