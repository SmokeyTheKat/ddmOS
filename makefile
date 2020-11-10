all:
	nasm -f elf32 ./boot/boot.s -o ./compiled/boot.o
	i686-elf-gcc -c ./kernel/system.c -o ./compiled/system.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/serial.c -o ./compiled/serial.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/ddsh.c -o ./compiled/ddsh.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/kernel.c -o ./compiled/kernel.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/tty.c -o ./compiled/tty.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/fonts.c -o ./compiled/fonts.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/keyboard.c -o ./compiled/keyboard.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/vga.c -o ./compiled/vga.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/interrupt.c -o ./compiled/interrupt.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	nasm -f elf32 ./kernel/interrupt.s -o ./compiled/sinterrupt.o
	i686-elf-gcc -c ./lib/ddcLib/make.c -o ./compiled/make.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./lib/ddcLib/ddcString.c -o ./compiled/ddcString.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./lib/ddcLib/ddcMath.c -o ./compiled/ddcMath.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./lib/ddcLib/ddcMem.c -o ./compiled/ddcMem.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./lib/ddcLib/ddcVec.c -o ./compiled/ddcVec.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -T ./link/linker.ld -o ./compiled/ddmOS.bin -ffreestanding -O2 -nostdlib ./usr/include/bf.h ./include/kernel/fonts.h ./include/kernel/vga.h ./include/ddcLib/ddcMem.h ./include/ddcLib/ddcMath.h ./include/ddcLib/ddcVec.h ./include/ddcLib/ddcString.h ./include/kernel/serial.h ./include/kernel/ddsh.h ./include/kernel/interrupt.h ./include/ddcLib/make.h ./include/kernel/system.h ./include/kernel/kernel.h ./include/kernel/tty.h ./include/kernel/keyboard.h ./compiled/vga.o ./compiled/ddcVec.o ./compiled/ddcMem.o ./compiled/ddcMath.o ./compiled/ddcString.o ./compiled/fonts.o ./compiled/serial.o ./compiled/ddsh.o ./compiled/interrupt.o ./compiled/sinterrupt.o ./compiled/boot.o ./compiled/make.o ./compiled/system.o ./compiled/keyboard.o ./compiled/tty.o ./compiled/kernel.o -lgcc
run: all
	qemu-system-x86_64 -fda ./compiled/ddmOS.bin
