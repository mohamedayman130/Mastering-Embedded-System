
#include<stdio.h>
int stlen(char string[300])
{
    int counter=0;
	while(string[counter]!=0)
	{
		counter++;
	}
return counter;
}
int main()
{
    char string[300]="";int n;
    printf("Enter a string::>> ");
    gets(string);
    n=stlen(string);
    printf("Length of string::>> %d",n);
}




