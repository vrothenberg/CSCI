ocd:
	openocd -f st_nucleo_f4.cfg
elf:
	arm-none-eabi-as -mcpu=cortex-m4 -g main.S -o main.o
	arm-none-eabi-gcc -T stm32_flash.ld -nostdlib main.o -o main.elf
	arm-none-eabi-gdb
