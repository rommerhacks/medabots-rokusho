	.syntax unified

	thumb_func_start sub_08022FB4
sub_08022FB4: @ 0x08022FB4
	push {r4, lr}
	ldr r4, _08022FE4 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r0, r0, #8
	ldr r1, _08022FE8 @ =0x0300059A
	adds r0, r0, r1
	ldr r1, _08022FEC @ =0x030004DE
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x28
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08022FE4: .4byte 0x03001800
_08022FE8: .4byte 0x0300059A
_08022FEC: .4byte 0x030004DE
	.syntax divided
