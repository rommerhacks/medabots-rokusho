	.syntax unified

	thumb_func_start sub_080345E8
sub_080345E8: @ 0x080345E8
	push {lr}
	ldr r2, _08034624 @ =0x03001800
	adds r3, r2, #0
	adds r3, #0x8a
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x2a
	movs r1, #0
	strb r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x2b
	strb r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x2c
	strb r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x2d
	strb r1, [r0]
	bl sub_08034F08
	pop {r0}
	bx r0
	.align 2, 0
_08034624: .4byte 0x03001800
	.syntax divided
