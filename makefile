all:
	nasm -f elf32 ./boot/boot.s -o ./compiled/boot.o
	i686-elf-gcc -c ./kernel/system.c -o ./compiled/system.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/kernel.c -o ./compiled/kernel.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/tty.c -o ./compiled/tty.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/keyboard.c -o ./compiled/keyboard.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./lib/ddcLib/make.c -o ./compiled/make.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -T ./link/linker.ld -o ./compiled/ddmOS.bin -ffreestanding -O2 -nostdlib ./include/ddcLib/make.h ./include/kernel/system.h ./include/kernel/kernel.h ./include/kernel/tty.h ./include/kernel/keyboard.h ./compiled/make.o ./compiled/system.o ./compiled/keyboard.o ./compiled/tty.o ./compiled/kernel.o ./compiled/boot.o -lgcc
run:
	qemu-system-x86_64 -fda ./compiled/ddmOS.bin -curses
