#include<stdio.h>

int main()
{
	int vals[15],n;void *ptr=&vals;
	printf("Input the number of elements to store in the array (max 15)::>> ");scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d::>> ",i+1 );
		scanf("%d",(int*)ptr+i);
	}

	printf("The elements of array in reverse order are::>> ");
	for (int i = n-1; i >=0; --i)
	{
		printf("\n%d::>>%d",i+1,*(i+(int*)ptr) );
	}
	scanf("%d");

	return 0;
}
