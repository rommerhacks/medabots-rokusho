	.syntax unified

	thumb_func_start sub_080236E0
sub_080236E0: @ 0x080236E0
	push {r4, lr}
	ldr r4, _08023710 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	ldr r1, _08023714 @ =0x03000648
	adds r0, r0, r1
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0xec
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0x78
	bl sub_08035740
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08023710: .4byte 0x03001800
_08023714: .4byte 0x03000648
_08023718:
	.byte 0x04, 0x49, 0x0A, 0x1C, 0xA6, 0x32, 0x1D, 0x20
	.byte 0x10, 0x70, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47, 0x00, 0x18, 0x00, 0x03
	.syntax divided
