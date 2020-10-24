all:
	nasm -f elf32 ./boot/boot.s -o ./compiled/boot.o
	i686-elf-gcc -c ./kernel/kernel.c -o ./compiled/kernel.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -T ./link/linker.ld -o ./compiled/ddmOS.bin -ffreestanding -O2 -nostdlib ./compiled/boot.o ./compiled/kernel.o -lgcc
run:
	qemu-system-x86_64 -fda ./compiled/ddmOS.bin -curses
