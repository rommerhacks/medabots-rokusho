	.syntax unified

	thumb_func_start sub_08020004
sub_08020004: @ 0x08020004
	push {r4, lr}
	ldr r4, _08020034 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #8
	ldr r1, _08020038 @ =0x0300059A
	adds r0, r0, r1
	ldr r1, _0802003C @ =0x030004DE
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x14
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020034: .4byte 0x03001800
_08020038: .4byte 0x0300059A
_0802003C: .4byte 0x030004DE
_08020040:
	.byte 0x02, 0x48, 0xAA, 0x30, 0x00, 0x21, 0x01, 0x70, 0x70, 0x47, 0x00, 0x00, 0x00, 0x18, 0x00, 0x03
	.syntax divided
