CSRCS = $(shell find ./kernel/ -type f -name '*.c') \
	$(shell find ./ddcLib/ -type f -name '*.c') \
	$(shell find ./stdlib/ -type f -name '*.c')
ASMSRCS = $(shell find ./boot/ -type f -name '*.s') \
	  $(shell find ./kernel/ -type f -name '*.s')
OBJS =  $(CSRCS:.c=.o) $(ASMSRCS:.s=.o)
DFILES =  $(CSRCS:.c=.d)

CC = gcc
CFLAGS = -nostdlib -nostdinc -fno-builtin -ffreestanding -O2 -g -Wall -Wextra -m64 -MMD -mno-red-zone -mcmodel=kernel -fno-pie -I ./include/

all: compile

compile: $(OBJS)
	mkdir -p ./build
	ld -n -o ./build/ddmOS.bin -T ./boot/linker.ld $(OBJS)
	cp ./boot/grub/grub.cfg ./isodir/boot/grub/
	cp ./build/ddmOS.bin ./isodir/boot/
	grub-mkrescue /usr/lib/grub/i386-pc -o ./build/ddmOS.iso isodir
	rm $(OBJS)
	rm $(DFILES)
fs:
	dd if=./misc/magic of=./isodir/root/disk bs=8
	dd if=/dev/zero of=./isodir/root/disk bs=1M count=500 skip=8 seek=8
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
%.o: %.s
	nasm -f elf64 -o $@ $<
clean:
	rm $(OBJS)
	rm $(DFILES)

tc:
	qemu-system-x86_64 -hda ./build/ddmOS.iso -boot a -m 4G -soundhw pcspk
