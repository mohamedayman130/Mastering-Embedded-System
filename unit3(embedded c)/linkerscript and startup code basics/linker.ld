ENTRY(reset)

MEMORY{
	
	flash (rwx) : ORIGIN = 0x00000000,LENGTH = 64M

}

SECTIONS{
	. = 0x10000;
	.reset . : {
	startup.o(.text)

	}>flash

	.text : {
	*(.text)
	}>flash
	.data : {*(.data)}


	.bss : {*(.bss)}>flash
	. = . +0x1000;
	stack_top = . ;

}