#include<stdio.h>
#include"uart.h"

char text[100]="MOHAMED AYMAN";

void main(void)
{
	uart0(text);
}