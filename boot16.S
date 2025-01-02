.text
.code16
start16:
	cli
	lgdt gdtr
	mov %cr0, %eax ;read the cr0 into eax
	or $0x1, %eax ;set the last bit into 1 to enable Protect Mode
	mov %eax, %cr0 ;load the edited cr0 back to cr0
	ljmpl $0x8, $0x20000 ;jump to Protect Mode

gdt:
	.quad 0x0000000000000000 ;reserved
	.quad 0x00c09a00000007ff ;kernel code segment
	.quad 0x00c09200000007ff ;kernel data segment
gdtEnd:

gdtr:
	.word gdtEnd - gdt ;calculate the GDT address through labels subtraction
	.word gdt, 0x1 ; offset in segment
