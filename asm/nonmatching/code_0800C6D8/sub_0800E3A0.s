	.syntax unified

	thumb_func_start sub_0800E3A0
sub_0800E3A0: @ 0x0800E3A0
	push {lr}
	bl sub_0800EBFC
	bl load_medapart_sprite_by_slot
	bl toggle_sprite_hflip_by_frame
	bl handle_medapart_selection_scroll
	cmp r0, #0
	beq _0800E3C8
	bl sub_0803FB0C
	ldr r1, _0800E3C4 @ =0x0300137C
	ldr r0, [r1]
	subs r0, #1
	b _0800E430
	.align 2, 0
_0800E3C4: .4byte 0x0300137C
_0800E3C8:
	ldr r0, _0800E3E4 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800E3EC
	movs r0, #5
	bl play_sound_effect
	ldr r1, _0800E3E8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _0800E430
	.align 2, 0
_0800E3E4: .4byte 0x0300058C
_0800E3E8: .4byte 0x0300137C
_0800E3EC:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0800E432
	movs r0, #4
	bl play_sound_effect
	ldr r1, _0800E410 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	cmp r0, #2
	bgt _0800E414
	cmp r0, #1
	bge _0800E420
	cmp r0, #0
	beq _0800E41A
	b _0800E42C
	.align 2, 0
_0800E410: .4byte 0x03000440
_0800E414:
	cmp r0, #3
	beq _0800E426
	b _0800E42C
_0800E41A:
	adds r1, #0x43
	movs r0, #3
	b _0800E42A
_0800E420:
	adds r1, #0x43
	movs r0, #4
	b _0800E42A
_0800E426:
	adds r1, #0x43
	movs r0, #5
_0800E42A:
	strb r0, [r1]
_0800E42C:
	ldr r1, _0800E438 @ =0x0300137C
	movs r0, #0x20
_0800E430:
	str r0, [r1]
_0800E432:
	pop {r0}
	bx r0
	.align 2, 0
_0800E438: .4byte 0x0300137C
	.syntax divided
