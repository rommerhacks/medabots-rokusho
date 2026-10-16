	.syntax unified

	thumb_func_start sub_08018A18
	.global sub_08018A18
sub_08018A18: @ 0x08018A18
	ldr r0, _08018A44 @ =0x030057E0
	ldr r1, _08018A48 @ =0x00000C2E
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _08018A40
	movs r1, #0
	ldr r0, _08018A4C @ =0x03000590
	movs r3, #0x50
	ldr r2, _08018A50 @ =0x000003C1
	adds r0, r0, r2
	movs r2, #0x80
	lsls r2, r2, #1
_08018A36:
	strb r3, [r0]
	adds r0, r0, r2
	adds r1, #1
	cmp r1, #2
	bls _08018A36
_08018A40:
	bx lr
	.align 2, 0
_08018A44: .4byte 0x030057E0
_08018A48: .4byte 0x00000C2E
_08018A4C: .4byte 0x03000590
_08018A50: .4byte 0x000003C1
	.syntax divided
