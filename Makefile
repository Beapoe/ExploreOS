kernel.bin: build boot16.bin boot32.bin
	./build

boot16.bin: boot32.S
	gcc -c boot16.S -o boot16.o
	ld -Ttext=0x0 boot16.o -o boot16.elf
	objcopy -O binary boot16.elf boot16.bin

boot32.bin: boot32.S
	gcc -c boot32.S -o boot32.o
	ld -Ttext=0x2000 boot32.o -o boot32.elf
	objcopy -O binary boot32.elf boot32.bin

head64.bin: head64.S
	gcc -c head64.S -o head64.o
	ld -Ttext=0xffffffff80100000 head64.o -o head64.elf
	objcopy -O binary head64.elf head64.bin

build: build.c
	gcc build.c -o build

clean:
	rm -f *.bin *.o *.elf build

run: kernel.bin
	sudo ../kvmtool/lkvm run -c 1 -k ./kernel.bin