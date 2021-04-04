CSRCS = $(shell find ./kernel/ -type f -name '*.c') \
	$(shell find ./ddcLib/ -type f -name '*.c')
ASMSRCS = $(shell find ./kernel/ -type f -name '*.s')
CHEADERS = $(shell find ./include/ -type f -name '.h')
OBJS =  $(CSRCS:.c=.o) $(ASMSRCS:.s=.o)
DFILES =  $(CSRCS:.c=.d) $(ASMSRCS:.s=.d)
CC = gcc
CFLAGS = -nostdlib -nostdinc -fno-builtin -ffreestanding -O2 -g -Wall -Wextra -MMD -mno-red-zone -mcmodel=kernel -fno-pie -I ./include/ 

all: clean compile clean
compile: $(OBJS)
	nasm -f elf64 ./boot/boot.s -o ./build/objs/boot.o
	nasm -f elf64 ./boot/stage.s -o ./build/objs/stage.o
	#gcc -c ./kernel/kernel.c -o ./build/objs/kernel.o -ffreestanding -O2 -nostdlib
	gcc -T ./boot/link.ld -o ./build/ddmOS.bin -ffreestanding -O2 -nostdlib ./build/objs/boot.o ./build/objs/stage.o $(OBJS)
	rm -f $(OBJS)
	rm -f $(DFILES)
tc: all
	alacritty -e qemu-system-x86_64 -fda ./build/ddmOS.bin -boot a -m 4G -curses

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
%.o: %.s
	nasm -f elf64 -o $@ $<
clean:
	rm -f $(OBJS)
