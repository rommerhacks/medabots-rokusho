	.syntax unified

	thumb_func_start sub_08009F90
	.global sub_08009F90
sub_08009F90: @ 0x08009F90
	push {lr}
	sub sp, #4
	ldr r1, _08009FB8 @ =0x03000BE0
	ldr r0, _08009FBC @ =0x03000440
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #5]
	ldr r1, _08009FC0 @ =0x0400000A
	ldrh r3, [r1]
	ldr r1, _08009FC4 @ =0x0000C314
	str r1, [sp]
	movs r1, #0xc
	movs r2, #3
	bl fill_tilemap_pair_or_divide
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08009FB8: .4byte 0x03000BE0
_08009FBC: .4byte 0x03000440
_08009FC0: .4byte 0x0400000A
_08009FC4: .4byte 0x0000C314
	.syntax divided
