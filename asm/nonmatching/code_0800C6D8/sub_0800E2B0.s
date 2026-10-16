	.syntax unified

	thumb_func_start sub_0800E2B0
sub_0800E2B0: @ 0x0800E2B0
	push {r4, r5, lr}
	bl sub_0800EBFC
	bl load_medapart_sprite_by_slot
	bl toggle_sprite_hflip_by_frame
	ldr r1, _0800E300 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800E2CE
	cmp r0, #4
	bne _0800E30C
_0800E2CE:
	adds r5, r1, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _0800E314
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r4, #0x20
	subs r1, r4, r1
	ldr r2, _0800E304 @ =0x0000FFFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r5]
	lsls r0, r0, #2
	subs r4, r4, r0
	ldr r2, _0800E308 @ =0x0000F0FF
	movs r0, #0
	adds r1, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0800E31C
	.align 2, 0
_0800E300: .4byte 0x03000440
_0800E304: .4byte 0x0000FFFF
_0800E308: .4byte 0x0000F0FF
_0800E30C:
	bl update_blend_effect
	cmp r0, #0
	beq _0800E31C
_0800E314:
	ldr r1, _0800E324 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0800E31C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800E324: .4byte 0x0300137C
	.syntax divided
