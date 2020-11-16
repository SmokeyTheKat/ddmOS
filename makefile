CSRCS =  $(shell find ./kernel/ -type f -name '*.c') \
	 $(shell find ./lib/ddcLib/ -type f -name '*.c')
ASMSRCS =  $(shell find ./kernel/ -type f -name '*.s') \
	   $(shell find ./boot/ -type f -name '*.s')
CHEADERS = $(shell find ./include/ -type f -name '.h') \
	   $(shell find ./usr/include/ -type f -name '.h')
OBJS =  $(CSRCS:.c=.o) $(ASMSRCS:.s=.o)
CC = i686-elf-gcc
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra

all: compile clean
compile: $(OBJS)
	i686-elf-gcc -T ./link/linker.ld -o ./compiled/ddmOS.bin -ffreestanding -O2 -nostdlib $(CHEADERS) $(OBJS) -lgcc
run: all clean
	qemu-system-x86_64 -fda ./compiled/ddmOS.bin -soundhw pcspk
	clean
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)
%.o: %.s
	nasm -f elf32 $< -o $@
clean:
	rm -rf ${OBJS}
