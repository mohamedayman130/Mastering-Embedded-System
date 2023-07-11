CFLAGS=-g -mcpu=arm926ej-s
cc=arm-none-eabi-
src=$(wildcard *.c)
obj=$(src:.c=.o)
ass=$(wildcard *.s)
assobj=$(ass:.s=.o)	
project_name=final

all:$(project_name).bin
	@echo "============compiling done============"


%.o : %.c
	$(cc)gcc.exe -c $(CFLAGS) $< -o $@

startup.o:startup.s
	$(cc)gcc.exe -c $(CFLAGS) $< -o $@
$(project_name).elf:$(obj) $(assobj)
	$(cc)ld.exe -T linker.ld $(obj) $(assobj)-o $@


$(project_name).bin:$(project_name).elf
	$(cc)objcopy.exe -O binary $< $@
clean_all:
	rm *.o *.elf *.bin
clean:
	rm *.elf *.bin		