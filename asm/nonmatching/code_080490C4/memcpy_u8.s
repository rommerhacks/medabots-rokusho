	.syntax unified

	thumb_func_start memcpy_u8
	.global memcpy_u8
memcpy_u8: @ 0x08049774
	push {r4, lr}
	adds r4, r0, #0
	movs r3, #0
	cmp r3, r2
	bhs _0804978C
_0804977E:
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, #1
	adds r1, #1
	adds r3, #1
	cmp r3, r2
	blo _0804977E
_0804978C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
