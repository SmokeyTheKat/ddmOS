CSRCS = $(shell find ./kernel/ -type f -name '*.c') \
	$(shell find ./ddcLib/ -type f -name '*.c')
ASMSRCS = $(shell find ./boot/ -type f -name '*.s') \
	  $(shell find ./kernel/ -type f -name '*.s')
OBJS =  $(CSRCS:.c=.o) $(ASMSRCS:.s=.o)
DFILES =  $(CSRCS:.c=.d)

CC = gcc
CFLAGS = -nostdlib -nostdinc -fno-builtin -ffreestanding -O2 -g -Wall -Wextra -m64 -MMD -mno-red-zone -mcmodel=kernel -fno-pie -I ./include/ 

all: compile

compile: $(OBJS)
	ld -n -o ./build/ddmOS.bin -T ./boot/linker.ld $(OBJS)
	cp ./boot/grub/grub.cfg ./isodir/boot/grub/
	cp ./build/ddmOS.bin ./isodir/boot/
	grub-mkrescue /usr/lib/grub/i386-pc -o ./ddmOS.iso isodir
	rm $(OBJS)
	rm $(DFILES)
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
%.o: %.s
	nasm -f elf64 -o $@ $<
clean:
	rm $(OBJS)
	rm $(DFILES)

tc: all
	$(TERM) -e qemu-system-x86_64 -cdrom ./ddmOS.iso -boot a -m 4G -curses
