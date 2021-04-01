CSRCS =  $(shell find ./kernel/ -type f -name '*.c')
ASMSRCS =  $(shell find ./kernel/ -type f -name '*.s') \
	   $(shell find ./boot/ -type f -name '*.S')
CHEADERS = $(shell find ./include/ -type f -name '.h')
OBJS =  $(CSRCS:.c=.o) $(ASMSRCS:.S=.o)
DFILES =  $(CSRCS:.c=.d) $(ASMSRCS:.S=.d)
CC = gcc
CFLAGS = -nostdlib -nostdinc -fno-builtin -ffreestanding -O2 -g -Wall -Wextra -Werror -MMD -mno-red-zone -mcmodel=kernel -fno-pie -I ./include/ 

all: clean compile clean

compile: $(OBJS)
	$(CC) -z max-page-size=0x1000 $(CFLAGS) -no-pie -Wl,--build-id=none -T ./boot/linker.ld -o ./ddmOS.bin $(OBJS)

	mkdir -p ./build/boot/grub
	mv ./ddmOS.bin ./build/boot/ddmOS.bin
	cp ./boot/grub/grub.cfg ./build/boot/grub/grub.cfg
	grub-mkrescue -o ./ddmOS.iso ./build/
	rm -f $(OBJS)
	rm -f $(DFILES)
nc: all
	alacritty -e qemu-system-x86_64 ./ddmOS.iso
tc: all
	alacritty -e qemu-system-x86_64 ./ddmOS.iso -curses &

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
%.o: %.S
	$(CC) $(CFLAGS) -Wa,--divide -c -o $@ $<
clean:
	rm -f $(OBJS)
	rm -f $(DFILES)
