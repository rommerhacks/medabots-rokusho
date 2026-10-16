	.syntax unified

	thumb_func_start sub_08020768
sub_08020768: @ 0x08020768
	push {r4, lr}
	ldr r1, _08020798 @ =0x083C6DE8
	ldr r4, _0802079C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _080207A0 @ =0x030004DE
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x18
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020798: .4byte 0x083C6DE8
_0802079C: .4byte 0x03001800
_080207A0: .4byte 0x030004DE
	.syntax divided
