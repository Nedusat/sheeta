csrc = $(wildcard kernel/*.c drivers/*.c)
headers = $(wildcard kernel/*.h drivers/*.h)

obj = ${csrc:.c=.o}

cc = gcc
cflags = -g

sheeta.bin: boot/bootsect.bin kernel.bin
	echo $(shell pwd)
	cat $^ > sheeta.bin

kernel.bin: boot/kernel_entry.o ${obj}
	ld -o $@ -Ttext 0x1000 $^ --oformat binary

run: sheeta.bin
	qemu-system-x86_64 -fda sheeta.bin

%.o: %.c ${headers}
	${cc} ${cflags} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf64 -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -rf *.bin *.dis *.o sheeta.bin *.elf *.swp
