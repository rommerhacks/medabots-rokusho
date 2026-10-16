	.syntax unified

	thumb_func_start sub_0802C24C
sub_0802C24C: @ 0x0802C24C
	push {r4, r5, r6, lr}
	ldr r6, _0802C290 @ =0x03001800
	adds r0, r6, #0
	adds r0, #0x89
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r5, r6, #0
	adds r5, #0x28
	adds r0, r0, r5
	adds r4, r6, #0
	adds r4, #0xec
	movs r2, #0
	ldrsh r1, [r4, r2]
	movs r2, #0xa0
	bl sub_08035740
	adds r0, r6, #0
	adds r0, #0x8a
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r4, r2]
	bl sub_0803572C
	adds r1, r6, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802C290: .4byte 0x03001800
_0802C294:
	.byte 0x04, 0x49, 0x0A, 0x1C, 0xA6, 0x32, 0x5B, 0x20, 0x10, 0x70, 0xAA, 0x31
	.byte 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47, 0x00, 0x18, 0x00, 0x03
	.syntax divided
