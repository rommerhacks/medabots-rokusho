	.syntax unified

	thumb_func_start sub_080233E0
sub_080233E0: @ 0x080233E0
	push {r4, lr}
	ldr r4, _08023410 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x89
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r1, r4, #0
	adds r1, #0x28
	adds r0, r0, r1
	adds r1, #0xc4
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0xa0
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
_08023410: .4byte 0x03001800
_08023414:
	.byte 0x04, 0x49, 0x0A, 0x1C, 0xA6, 0x32, 0x1C, 0x20, 0x10, 0x70, 0xAA, 0x31
	.byte 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47, 0x00, 0x18, 0x00, 0x03
	.syntax divided
