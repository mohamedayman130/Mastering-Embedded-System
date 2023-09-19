

#ifndef UART_H_
#define UART_H_

////////////////////generic macros/////////////////////
#define  UBRRL *(volatile char *)(0x29)
#define  UCSRA *(volatile char *)(0x2b)
#define  UCSRB *(volatile char *)(0x2a)
#define  UDR   *(volatile char *)(0x2c)

////////////////////generic variables
char string [150] ;

/////////////////////////APIS///////////////////

//////////////////////
//name:uart_init
//des:to init uart 
//param:none
///////////////////////
void uart_init();

//////////////////////
//name:uart_rec
//des:receive char from another mcu (or virtual terminal)
//param:none
///////////////////////
char uart_rec();

//////////////////////
//name:uart_send
//des:to send char to another mcu (or virtual terminal)
//param [in]::>> char you want to send
///////////////////////
void uart_Send(char x);

//////////////////////
//name:uart_rec_string
//des:receive string from another mcu (or virtual terminal) and display it on lcd  by typing string and pressing enter key
//param:none
///////////////////////
void uart_rec_string();

//////////////////////
//name: uart_send_string
//des:to send string to another mcu (or virtual terminal) 
//param [in]::>> string you want to  send
///////////////////////
void uart_send_string(char * text);

#endif /* UART_H_ */