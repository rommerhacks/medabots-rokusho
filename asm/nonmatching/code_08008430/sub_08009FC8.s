	.syntax unified

	thumb_func_start sub_08009FC8
sub_08009FC8: @ 0x08009FC8
	push {lr}
	sub sp, #4
	ldr r1, _08009FF0 @ =0x03000BE0
	ldr r0, _08009FF4 @ =0x03000440
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #5]
	ldr r1, _08009FF8 @ =0x0400000A
	ldrh r3, [r1]
	ldr r1, _08009FFC @ =0x0000C3A4
	str r1, [sp]
	movs r1, #0xc
	movs r2, #3
	bl fill_tilemap_pair_or_divide
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08009FF0: .4byte 0x03000BE0
_08009FF4: .4byte 0x03000440
_08009FF8: .4byte 0x0400000A
_08009FFC: .4byte 0x0000C3A4
	.syntax divided
