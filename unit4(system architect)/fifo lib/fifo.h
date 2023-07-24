#define data_type unsigned int

typedef struct
{
	int count;
	int lenght;
	data_type *head;
	data_type *tail;
	data_type *base;
	
}fifo_buf;

typedef enum{
	fifo_no_error,
	fifo_null,
	fifo_full,
	fifo_empty
}fifo_Status;

fifo_Status fifo_init(fifo_buf *buf,data_type *arr,unsigned int lenght);
fifo_Status enqueue(fifo_buf * buf,data_type val);
fifo_Status dequeue(fifo_buf *buf);
fifo_Status print_fifo (fifo_buf * buf);
