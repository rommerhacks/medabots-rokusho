	.syntax unified

	thumb_func_start sub_0800E6C8
sub_0800E6C8: @ 0x0800E6C8
	push {lr}
	bl sub_0800EBFC
	bl load_medapart_sprite_by_slot
	ldr r0, _0800E704 @ =0x083B5F80
	ldr r0, [r0, #0xc]
	movs r1, #6
	bl process_sprite_anim_commands
	ldr r0, _0800E708 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _0800E710
	ldr r2, _0800E70C @ =0x03000440
	adds r1, r2, #0
	adds r1, #0x44
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800E6FE
	adds r0, r2, #0
	adds r0, #0x45
	ldrb r0, [r0]
_0800E6FE:
	subs r0, #1
	strb r0, [r1]
	b _0800E738
	.align 2, 0
_0800E704: .4byte 0x083B5F80
_0800E708: .4byte 0x03001798
_0800E70C: .4byte 0x03000440
_0800E710:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800E744
	ldr r0, _0800E730 @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x44
	ldrb r1, [r2]
	adds r0, #0x45
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne _0800E734
	strb r3, [r2]
	b _0800E738
	.align 2, 0
_0800E730: .4byte 0x03000440
_0800E734:
	adds r0, r1, #1
	strb r0, [r2]
_0800E738:
	movs r0, #2
	bl play_sound_effect
	bl sub_0800FFF4
	b _0800E784
_0800E744:
	ldr r0, _0800E768 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800E770
	movs r0, #4
	bl play_sound_effect
	bl setup_battle_cursor_sprite_0800FF50
	bl sub_0803FB0C
	ldr r1, _0800E76C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _0800E782
	.align 2, 0
_0800E768: .4byte 0x0300058C
_0800E76C: .4byte 0x0300137C
_0800E770:
	movs r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _0800E784
	movs r0, #5
	bl play_sound_effect
	ldr r1, _0800E788 @ =0x0300137C
	movs r0, #0x24
_0800E782:
	str r0, [r1]
_0800E784:
	pop {r0}
	bx r0
	.align 2, 0
_0800E788: .4byte 0x0300137C
	.syntax divided
