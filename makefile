iso:
	export PREFIX="$$HOME/opt/cross"
	export TARGET=i686-elf
	export PATH="$$PREFIX/bin:$$PATH"
	nasm -felf32 ./boot/boot.s -o ./boot/boot.o
	i686-elf-gcc -c ./kernel/kernel.c -o ./kernel/kernel.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -T ./buildutils/linked.ld -o ddmOS.bin -ffreestanding -O2 -nostdlib ./boot/boot.o ./kernel/kernel.o -lgcc
	cp ./ddmOS.bin isodir/boot/ddmOS.bin 
	cp ./initgrub/grub.cfg isodir/boot/grub/grub.cfg 
	grub-mkrescue -o ddmOS.iso isodir
iso-run:
	export PREFIX="$$HOME/opt/cross"
	export TARGET=i686-elf
	export PATH="$$PREFIX/bin:$$PATH"
	nasm -felf32 ./boot/boot.s -o ./boot/boot.o
	i686-elf-gcc -c ./kernel/kernel.c -o ./kernel/kernel.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -T ./buildutils/linked.ld -o ddmOS.bin -ffreestanding -O2 -nostdlib ./boot/boot.o ./kernel/kernel.o -lgcc
	cp ./ddmOS.bin isodir/boot/ddmOS.bin 
	cp ./initgrub/grub.cfg isodir/boot/grub/grub.cfg 
	grub-mkrescue -o ddmOS.iso isodir
	qemu-system-i386 -cdrom ddmOS.iso
iso-runc:
	export PREFIX="$$HOME/opt/cross"
	export TARGET=i686-elf
	export PATH="$$PREFIX/bin:$$PATH"
	nasm -felf32 ./boot/boot.s -o ./boot/boot.o
	i686-elf-gcc -c ./kernel/kernel.c -o ./kernel/kernel.o -std=gnu99 -ffreestanding -Os -Wall -Wextra
	i686-elf-gcc -T ./buildutils/linked.ld -o ddmOS.bin -ffreestanding -O2 -nostdlib ./boot/boot.o ./kernel/kernel.o -lgcc
	cp ./ddmOS.bin isodir/boot/ddmOS.bin 
	cp ./initgrub/grub.cfg isodir/boot/grub/grub.cfg 
	grub-mkrescue -o ddmOS.iso isodir
	qemu-system-i386 -cdrom ddmOS.iso -curses
