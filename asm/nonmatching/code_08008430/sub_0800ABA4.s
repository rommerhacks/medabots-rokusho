	.syntax unified

	thumb_func_start sub_0800ABA4
	.global sub_0800ABA4
sub_0800ABA4: @ 0x0800ABA4
	push {lr}
	sub sp, #0xc
	ldr r2, _0800ABE0 @ =0x083B4AE0
	ldr r1, _0800ABE4 @ =0x03000BE0
	ldr r0, _0800ABE8 @ =0x03000440
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #9]
	adds r0, #0x51
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _0800ABEC @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	movs r0, #0x10
	movs r1, #2
	movs r2, #6
	movs r3, #0xa
	bl write_tilemap_rect
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_0800ABE0: .4byte 0x083B4AE0
_0800ABE4: .4byte 0x03000BE0
_0800ABE8: .4byte 0x03000440
_0800ABEC: .4byte 0x0400000A
	.syntax divided
