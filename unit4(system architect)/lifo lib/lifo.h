#define set_type unsigned char 
typedef struct 
{
unsigned int lenght;
unsigned int count;
set_type * base ;
set_type * head;
	
}lifo_buf;

typedef enum{
lifo_no_error,
lifo_empty,
lifo_full,
lifo_null
}lifo_status;

lifo_status push (lifo_buf * lifo_buf,set_type val);
lifo_status init(lifo_buf * lifo_buf,set_type * arr,int c);
lifo_status pop(lifo_buf * buf);