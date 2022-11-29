#include <stdio.h>
#include <stdlib.h>

int main()
{
    float arr1[2][2],arr2[2][2],arr3[2][2];
    printf("Enter the elements of 1st matrix ::>> \n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("enter [%d][%d]::>> ",i+1,j+1);
            fflush(stdin);fflush(stdout);
            scanf("%f",&arr1[i][j]);
        }

    }
        printf("\nEnter the elements of 2nd matrix ::>> \n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("enter [%d][%d]::>> ",i+1,j+1);
            fflush(stdin);fflush(stdout);
            scanf("%f",&arr2[i][j]);
        }

    }
    printf("\nSum Of Matrix::>> \n");
        for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            arr3[i][j]=arr1[i][j]+arr2[i][j];
            printf(" %4.2f ",arr3[i][j]);
        }
        printf("\n");

    }



}
