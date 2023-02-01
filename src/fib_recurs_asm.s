.globl   fib_recurs_asm
    .p2align 2
	.type    fib_recurs_asm,%function

fib_recurs_asm:

		cmp x0, xzr
		beq end_label

		cmp x0, #1
		beq end_label

		sub sp, sp, #32
		str x30, [sp, #0]
		str x0, [sp, #8]

		sub x0, x0, #1
		bl fib_recurs_asm
		mov x11, x0
		str x11, [sp, #16]

		ldr x0, [sp, #8]

		sub x0, x0, #2
		bl fib_recurs_asm
		mov x12, x0

		ldr x11, [sp, #16]

		add x0, x12, x11

		ldr x30, [sp, #0]
		add sp, sp, #32

		b end_label


end_label:
	br x30
