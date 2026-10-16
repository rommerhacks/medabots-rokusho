	.syntax unified

	thumb_func_start sub_0805D394
sub_0805D394: @ 0x0805D394
	push {r4, lr}
	ldr r0, _0805D3C4 @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x84
	ldrb r0, [r4]
	cmp r0, #8
	bhi _0805D3D0
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r2, _0805D3C8 @ =0x00003FFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r4]
	lsls r1, r1, #2
	ldr r2, _0805D3CC @ =0x0000FFFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0805D3FE
	.align 2, 0
_0805D3C4: .4byte 0x03000440
_0805D3C8: .4byte 0x00003FFF
_0805D3CC: .4byte 0x0000FFFF
_0805D3D0:
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldrh r2, [r1]
	ldr r0, _0805D404 @ =0x0000FDFF
	ands r0, r2
	strh r0, [r1]
	ldrh r2, [r1]
	ldr r0, _0805D408 @ =0x0000FBFF
	ands r0, r2
	strh r0, [r1]
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r1, _0805D40C @ =0x0300178C
	movs r0, #0
	str r0, [r1]
	ldr r1, _0805D410 @ =0x03002B8C
	movs r0, #1
	str r0, [r1]
	ldr r1, _0805D414 @ =0x0300137C
	movs r0, #0x10
	str r0, [r1]
_0805D3FE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805D404: .4byte 0x0000FDFF
_0805D408: .4byte 0x0000FBFF
_0805D40C: .4byte 0x0300178C
_0805D410: .4byte 0x03002B8C
_0805D414: .4byte 0x0300137C
	.syntax divided
