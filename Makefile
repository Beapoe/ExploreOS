kernel.bin: build boot16.bin boot32.bin
	./build

boot16.bin:
	gcc -c boot16.S -o boot6.o -lstdc++
	ld -Ttext=0x0 boot16.o -o boot16.elf

clean:
	rm -f *.bin *.o *.elf build
