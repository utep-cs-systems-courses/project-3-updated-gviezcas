
	.arch msp430g2553
	.align 2
	.extern i

	.text
JT:
	.word case0
	.word case1
	.word case2
	.word case3

	.global F

F:
	mov &i, r12
	cmp #4, r12
	jnc end
	add r12, r12
	mov JT(r12), r0

eight:
	.word 08
four:
	.word 04
two:
	.word 02
one:
	.word 01


case0:
	mov &eight, r12
	jmp end
case1:
	mov &four, r12
	jmp end
case2:
	mov &two, r12
	jmp end
case3:
	mov &one, r12
	jmp end
end:	
	pop r0
