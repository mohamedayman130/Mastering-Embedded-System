#include"fifo.h"
#include<stdio.h>

fifo_Status fifo_init(fifo_buf * buf,data_type * arr,unsigned int lenght)
{
	if(arr==NULL) return fifo_null;
	buf->count=0;
	buf->lenght=lenght;
	buf->base=arr;
	buf->head=arr;
	buf->tail=arr;
	return fifo_no_error;
}
fifo_Status enqueue(fifo_buf * buf,data_type val)
{
	if(!buf->head || !buf->tail || !buf->base) return fifo_null;
	if(buf->count==buf->lenght) {printf("fifo is full\n");return fifo_full;}
	buf->count++;
	*(buf->head)=val;
	printf("element %x is added to fifo\n",val);
//circular fifo
 	if(buf->head==buf->base + sizeof(data_type)*buf->lenght)
		buf->head=buf->base;
	else buf->head++;
	return fifo_no_error;
}
fifo_Status dequeue(fifo_buf *buf)
{
	if(!buf->head || !buf->tail || !buf->base) return fifo_null;
	if(buf->count==0){printf("fifo is empty\n");return fifo_empty;}
	buf->count--;
 	if(buf->tail==buf->base + sizeof(data_type)*buf->lenght)
		buf->tail=buf->base;
	else buf->tail++;
		printf("element %x is deleted from fifo\n",*(buf->tail-1));
	return fifo_no_error;
}

fifo_Status print_fifo (fifo_buf * buf)
{
	data_type *temp=buf->tail;
	if(buf->count==0) return fifo_empty;
	for(int i=0;i<buf->count;i++){
		printf("print:: %x\n",*(temp) );
		temp++;
	}
	return fifo_no_error;

}
