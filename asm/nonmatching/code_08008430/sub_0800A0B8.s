	.syntax unified

	thumb_func_start sub_0800A0B8
	.global sub_0800A0B8
sub_0800A0B8: @ 0x0800A0B8
	push {lr}
	sub sp, #8
	ldr r0, _0800A0EC @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r1, _0800A0F0 @ =0x03000BE0
	ldr r0, _0800A0F4 @ =0x03000440
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #7]
	lsls r0, r0, #0x12
	ldr r1, _0800A0F8 @ =0xD3400000
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x1b
	movs r3, #7
	bl fill_tilemap_rect_08042698
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0800A0EC: .4byte 0x0400000A
_0800A0F0: .4byte 0x03000BE0
_0800A0F4: .4byte 0x03000440
_0800A0F8: .4byte 0xD3400000
	.syntax divided
