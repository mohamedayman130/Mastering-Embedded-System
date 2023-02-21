#include<stdio.h>
int main()
{
	char alpha[26];
	char *ptr=alpha;
	for(int i='A';i<='Z';i++) *(ptr+i-65)=i;
	for(int i=0;i<26;i++) printf("%c ",*(ptr+i));
}
