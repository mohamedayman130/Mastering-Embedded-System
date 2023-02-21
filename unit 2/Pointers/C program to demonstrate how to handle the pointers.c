#include<stdio.h>
void main(void)
{
	int val,*ptr=&val;
	val=150;
	printf("value of val is ::>>%d and its location is ::>>%p\n",val,&val);*ptr=300;
	printf("value of val is ::>>%d and its location is ::>>%p (by using poiters)\n",*ptr,ptr);

}
