	.syntax unified

	thumb_func_start export_medals_to_buffer
	.global export_medals_to_buffer
export_medals_to_buffer: @ 0x08042028
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r3, #0
	movs r6, #0x80
	ldr r1, _08042058 @ =0x03000BE0
	adds r5, r1, #0
_08042034:
	ldrb r2, [r5]
	adds r0, r6, #0
	ands r0, r2
	cmp r0, #0
	bne _0804205C
	movs r4, #0x1f
	ands r4, r2
	adds r0, r7, #0
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	orrs r0, r4
	strb r0, [r5]
	b _08042066
	.align 2, 0
_08042058: .4byte 0x03000BE0
_0804205C:
	adds r5, #0x40
	adds r1, #0x40
	adds r3, #1
	cmp r3, #0x1d
	bls _08042034
_08042066:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
