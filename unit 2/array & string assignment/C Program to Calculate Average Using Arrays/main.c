#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;float arr[100],avr=0;
    printf("Enter the numbers of data::>> ");fflush(stdin);fflush(stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("[%d] element::>> ",i+1);fflush(stdin);fflush(stdout);
        scanf("%f",&arr[i]);
        avr+=arr[i];
    }

    printf("%f",avr/n);

}
