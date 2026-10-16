	.syntax unified

	thumb_func_start sub_0800E488
sub_0800E488: @ 0x0800E488
	push {r4, lr}
	bl sub_0800EBFC
	bl load_medapart_sprite_by_slot
	bl toggle_sprite_hflip_by_frame
	ldr r1, _0800E4D0 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800E4A6
	cmp r0, #4
	bne _0800E4DC
_0800E4A6:
	adds r4, r1, #0
	adds r4, #0x84
	ldrb r0, [r4]
	cmp r0, #8
	bhi _0800E4E4
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r2, _0800E4D4 @ =0x0000FFFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r4]
	lsls r1, r1, #2
	ldr r2, _0800E4D8 @ =0x0000F0FF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0800E4EC
	.align 2, 0
_0800E4D0: .4byte 0x03000440
_0800E4D4: .4byte 0x0000FFFF
_0800E4D8: .4byte 0x0000F0FF
_0800E4DC:
	bl update_blend_effect
	cmp r0, #0
	beq _0800E4EC
_0800E4E4:
	ldr r1, _0800E4F4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0800E4EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800E4F4: .4byte 0x0300137C
	.syntax divided
