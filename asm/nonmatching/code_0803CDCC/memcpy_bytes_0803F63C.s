	.syntax unified

	thumb_func_start memcpy_bytes_0803F63C
	.global memcpy_bytes_0803F63C
memcpy_bytes_0803F63C: @ 0x0803F63C
	push {r4, lr}
	adds r4, r0, #0
	movs r3, #0
	cmp r3, r2
	bhs _0803F654
_0803F646:
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, #1
	adds r1, #1
	adds r3, #1
	cmp r3, r2
	blo _0803F646
_0803F654:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
