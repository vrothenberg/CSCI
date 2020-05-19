flash:
	arm-none-eabi-as -mcpu=cortex-m4 -g main2.S -o main.o
	arm-none-eabi-gcc -T stm32_flash.ld -nostdlib main.o -o main.elf
	arm-none-eabi-objcopy -O binary main.elf main.bin
	st-flash write main.bin 0x8000000
