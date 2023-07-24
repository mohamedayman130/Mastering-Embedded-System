#include"lifo.h"
#include<stdio.h>
//add item to lifo
lifo_status push (lifo_buf * buf,set_type val)
{
	
	if(buf->count>=buf->lenght) return lifo_full;
	else if(buf->head==NULL || buf->base==NULL) return lifo_null;
		else{

			*(buf->head)=val;
			if(sizeof(set_type)==4)
			printf("element %d is pushed\n",val);
		else if(sizeof(set_type)==1)
			printf("element %c is pushed\n",val);
			(buf->head)++;
			(buf->count)++;
	return lifo_no_error;


		}
}
//itialize lifo 
lifo_status init(lifo_buf * buf,set_type * arr,int c)
{
	if(arr==NULL) return lifo_null;
	else{
	buf->count=0;
	buf->lenght=c;
	buf->base=arr;
	buf->head=arr;
	return lifo_no_error;
}

}
//remove item from lifo
lifo_status pop(lifo_buf * buf)
{
	if(buf->count==0) return lifo_empty;
	else if(buf->head==NULL || buf->base==NULL) return lifo_null;	
	else
	{
			buf->head--;
			if(sizeof(set_type)==4)
			printf("element %d is poped\n",*(buf->head));
		else if(sizeof(set_type)==1)
			printf("element %c is poped\n",*(buf->head));
			buf->count--;
	}
}


