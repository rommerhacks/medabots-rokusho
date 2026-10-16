	.syntax unified

	thumb_func_start memcpy_bytes_08041D04
	.global memcpy_bytes_08041D04
memcpy_bytes_08041D04: @ 0x08041D04
	push {r4, lr}
	adds r4, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r3, #0
	cmp r3, r2
	bhs _08041D20
_08041D12:
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, #1
	adds r1, #1
	adds r3, #1
	cmp r3, r2
	blo _08041D12
_08041D20:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
