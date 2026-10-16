	.syntax unified

	thumb_func_start sub_08033D10
sub_08033D10: @ 0x08033D10
	push {lr}
	ldr r1, _08033D2C @ =0x03001800
	adds r0, r1, #0
	adds r0, #0xe8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x12
	adds r1, #0xea
	strh r0, [r1]
	bl sub_08034F08
	pop {r0}
	bx r0
	.align 2, 0
_08033D2C: .4byte 0x03001800
	.syntax divided
