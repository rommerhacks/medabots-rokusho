	.syntax unified

	thumb_func_start memswap
	.global memswap
memswap: @ 0x0803F65C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	movs r2, #0
	cmp r2, r5
	bhs _0803F67C
_0803F66A:
	ldrb r1, [r4]
	ldrb r0, [r3]
	strb r0, [r4]
	adds r4, #1
	strb r1, [r3]
	adds r3, #1
	adds r2, #1
	cmp r2, r5
	blo _0803F66A
_0803F67C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
