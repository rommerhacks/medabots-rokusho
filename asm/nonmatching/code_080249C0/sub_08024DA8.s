	.syntax unified

	thumb_func_start sub_08024DA8
sub_08024DA8: @ 0x08024DA8
	push {lr}
	ldr r0, _08024DC0 @ =0x03001800
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #1
	beq _08024DC8
	cmp r0, #2
	beq _08024DD4
	ldr r0, _08024DC4 @ =0x083C6DE8
	ldr r0, [r0]
	b _08024DD8
	.align 2, 0
_08024DC0: .4byte 0x03001800
_08024DC4: .4byte 0x083C6DE8
_08024DC8:
	ldr r0, _08024DD0 @ =0x083C6DE8
	ldr r0, [r0, #4]
	b _08024DD8
	.align 2, 0
_08024DD0: .4byte 0x083C6DE8
_08024DD4:
	ldr r0, _08024DF8 @ =0x083C6DE8
	ldr r0, [r0, #8]
_08024DD8:
	ldr r1, _08024DFC @ =0x030004DE
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	ldr r1, _08024E00 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xa6
	movs r0, #0x30
	strb r0, [r2]
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08024DF8: .4byte 0x083C6DE8
_08024DFC: .4byte 0x030004DE
_08024E00: .4byte 0x03001800
	.syntax divided
