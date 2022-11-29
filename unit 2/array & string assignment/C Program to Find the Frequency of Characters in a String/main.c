#include <stdio.h>
#include <stdlib.h>

int main()
{
   char string [300],c;int i=0,counter=0;
  printf("enter your string ::>> ");fflush(stdin);fflush(stdout);
  gets(string);
   printf("Enter a character to find frequency::>> ");fflush(stdin);fflush(stdout);
   scanf("%c",&c);
   for(int i=0;i<strlen(string);i++)
   {
       if(string[i]==c){counter++;}
   }
printf("Frequency of [%c] ::>> %d",c,counter);

}
