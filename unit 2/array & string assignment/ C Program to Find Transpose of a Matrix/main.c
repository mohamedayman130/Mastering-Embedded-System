#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row,col;
    printf("enter number of rows::>> ");fflush(stdout);fflush(stdin);scanf("%d",&row);
    printf("enter number of cols::>> ");fflush(stdout);fflush(stdin);scanf("%d",&col);
    float arr[10][10];
    printf("Enter elements of matrix::>> \n");
   for(int i=0;i<row;i++)
   {
       for(int j=0;j<col;j++)
       {
           printf("[%d][%d] ::>>  ",i+1,j+1);
           fflush(stdout);fflush(stdin);scanf("%f",&arr[i][j]);
       }
   }
      for(int i=0;i<row;i++)
   {
       for(int j=0;j<col;j++)
       {
           printf("%10.2f",arr[i][j]);
       }
       printf("\n ");
   }
   printf("Transpose of Matrix:\n");

         for(int i=0;i<col;i++)
   {
       for(int j=0;j<row;j++)
       {
           printf("%10.2f",arr[j][i]);
       }
       printf("\n");
   }



}
