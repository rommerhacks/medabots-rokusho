	.syntax unified

	thumb_func_start sub_08061300
sub_08061300: @ 0x08061300
	push {r4, r5, lr}
	ldr r0, _08061330 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _08061338
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r4, _08061334 @ =0x0000FFFF
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r5]
	lsls r1, r1, #2
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08061362
	.align 2, 0
_08061330: .4byte 0x03000440
_08061334: .4byte 0x0000FFFF
_08061338:
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldrh r2, [r1]
	ldr r0, _08061368 @ =0x0000FDFF
	ands r0, r2
	strh r0, [r1]
	ldrh r2, [r1]
	ldr r0, _0806136C @ =0x0000FBFF
	ands r0, r2
	strh r0, [r1]
	ldrh r2, [r1]
	ldr r0, _08061370 @ =0x0000F7FF
	ands r0, r2
	strh r0, [r1]
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	movs r0, #3
	bl dispatch_by_index_0476e8
_08061362:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08061368: .4byte 0x0000FDFF
_0806136C: .4byte 0x0000FBFF
_08061370: .4byte 0x0000F7FF
	.syntax divided
