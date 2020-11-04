all:
	nasm -f elf32 ./boot/boot.s -o ./compiled/boot.o
	i686-elf-gcc -c ./kernel/system.c -o ./compiled/system.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/serial.c -o ./compiled/serial.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/ddsh.c -o ./compiled/ddsh.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/kernel.c -o ./compiled/kernel.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/tty.c -o ./compiled/tty.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/keyboard.c -o ./compiled/keyboard.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	#i686-elf-gcc -c ./kernel/serial.c -o ./compiled/serial.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -c ./kernel/interrupt.c -o ./compiled/interrupt.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	nasm -f elf32 ./kernel/interrupt.s -o ./compiled/sinterrupt.o
	i686-elf-gcc -c ./lib/ddcLib/make.c -o ./compiled/make.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	#i686-elf-gcc -c ./lib/ddcLib/ddcString.c -o ./compiled/ddcString.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -T ./link/linker.ld -o ./compiled/ddmOS.bin -ffreestanding -O2 -nostdlib ./include/kernel/serial.h ./include/kernel/ddsh.h ./include/kernel/interrupt.h ./include/ddcLib/make.h ./include/kernel/system.h ./include/kernel/kernel.h ./include/kernel/tty.h ./include/kernel/keyboard.h ./compiled/serial.o ./compiled/ddsh.o ./compiled/interrupt.o ./compiled/sinterrupt.o ./compiled/boot.o ./compiled/make.o ./compiled/system.o ./compiled/keyboard.o ./compiled/tty.o ./compiled/kernel.o -lgcc
	#i686-elf-gcc -T ./link/linker.ld -o ./compiled/ddmOS.bin -ffreestanding -O2 -nostdlib ./include/kernel/serial.h ./include/kernel/interrupt.h ./include/ddcLib/make.h ./include/kernel/system.h ./include/kernel/kernel.h ./include/kernel/tty.h ./include/kernel/keyboard.h ./compiled/serial.o ./compiled/interrupt.o ./compiled/sinterrupt.o ./compiled/boot.o ./compiled/sgdt.o ./compiled/make.o ./compiled/system.o ./compiled/keyboard.o ./compiled/tty.o ./compiled/kernel.o -lgcc
	#i686-elf-gcc -T ./link/linker.ld -o ./compiled/ddmOS.bin -ffreestanding -O2 -nostdlib ./include/kernel/gdt.h ./include/kernel/interrupt.h ./include/ddcLib/make.h ./include/kernel/system.h ./include/kernel/kernel.h ./include/kernel/tty.h ./include/kernel/keyboard.h ./compiled/boot.o ./compiled/gdt.o ./compiled/sgdt.o ./compiled/sinterrupt.o ./compiled/interrupt.o ./compiled/make.o ./compiled/system.o ./compiled/keyboard.o ./compiled/tty.o ./compiled/kernel.o -lgcc
run:
	qemu-system-x86_64 -fda ./compiled/ddmOS.bin -curses
