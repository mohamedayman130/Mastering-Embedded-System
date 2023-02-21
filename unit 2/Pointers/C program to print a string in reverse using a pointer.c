#include<stdio.h>
int strlen(char *str)
{
	int len=0;
	while(*(str++)!='\0'){len++;}
	return len;
}
int main()
{
	char str[100],*ptr=str;
	printf("enter your string::>> ");
	gets(str),printf("string reverse::>> ");
	for (int i = strlen(str)-1; i >= 0; --i)
	{
		printf("%c",*(ptr+i));
	}
}

