#include"lifo.h"
#include<stdio.h>

set_type arr1[5];

void main()
{
	lifo_buf my_lifo;
	init(&my_lifo,arr1,5);
	for(int i=0;i<=6;i++)
	{
		if(push(&my_lifo,i+75)==lifo_full)
			printf("%s\n","lifo is full,," );
	}

		for(int i=0;i<=3;i++)
	{
		if(pop(&my_lifo)==lifo_empty)
			printf("%s\n","lifo is empty,," );
	}

	for(int i=0;i<=1;i++)
	{
		if(push(&my_lifo,i+75)==lifo_full)
			printf("%s\n","lifo is full,," );
	}
		for(int i=0;i<=5;i++)
	{
		if(pop(&my_lifo)==lifo_empty)
			printf("%s\n","lifo is empty,," );
	}


	scanf("%d");

}