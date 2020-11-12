CSRCS =  $(wildcard ./kernel/*.c) \
	$(wildcard ./lib/ddcLib/*.c)
ASMSRCS =  $(wildcard ./kernel/*.s) \
	   $(wildcard ./boot/*.s)
OBJS =  $(CSRCS:.c=.o) $(ASMSRCS:.s=.o)
CC = i686-elf-gcc
CFLAGS = -std=gnu99 -ffreestanding -Os -Wall -Wextra

all: $(OBJS)
	i686-elf-gcc -T ./link/linker.ld -o ./compiled/ddmOS.bin -ffreestanding -O2 -nostdlib ./usr/include/bf.h ./include/kernel/* ./include/ddcLib/* ./include/ddcDef.h $(OBJS) -lgcc
run: all
	qemu-system-x86_64 -fda ./compiled/ddmOS.bin
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)
%.o: %.s
	nasm -f elf32 $< -o $@
clean:
	rm -rf ${OBJS}
