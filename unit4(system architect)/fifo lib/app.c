#include"fifo.h"
#include<stdio.h>
void main()
{
	data_type arr1[5];
	fifo_buf buf;
	fifo_init(&buf,arr1,5);
	for(int i=0;i<=7;i++)
	{
		//if(enqueue(&buf,i+10)==fifo_no_error)
			//printf("element %x is added to fifo \n",*(buf.head-1 ));
		//else printf("fifo enqueue is faild\n");
		enqueue(&buf,10+i);
	}

	print_fifo(&buf);printf("\n==================================\n");

	dequeue(&buf);	dequeue(&buf);dequeue(&buf);dequeue(&buf);
	dequeue(&buf);dequeue(&buf);dequeue(&buf);
	enqueue(&buf,5);	enqueue(&buf,5);
	enqueue(&buf,5);	enqueue(&buf,6);	enqueue(&buf,10);
	enqueue(&buf,5);	dequeue(&buf);enqueue(&buf,50);


	print_fifo(&buf);


scanf("%d");
}