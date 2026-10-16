	.syntax unified

	thumb_func_start menu_confirm_selection_with_fade
menu_confirm_selection_with_fade: @ 0x080636C8
	push {r4, lr}
	sub sp, #4
	ldr r4, _08063758 @ =0x03006F74
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x31
	ldrb r0, [r0]
	adds r1, #0x33
	ldrb r1, [r1]
	movs r2, #0
	bl load_medapart_sprite_animation
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r0, [r0]
	adds r1, #0x34
	ldrb r1, [r1]
	movs r2, #1
	bl load_medapart_sprite_animation
	ldr r1, _0806375C @ =0x08485BD8
	ldr r0, [r4]
	adds r0, #0x33
	ldrb r0, [r0]
	adds r0, #0x14
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _08063722
	ldr r0, _08063760 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08063722
	ldr r1, _08063764 @ =0x03005010
	ldr r0, _08063768 @ =0x0000FF07
	strh r0, [r1, #6]
	movs r0, #0xd
	bl play_sound_effect
_08063722:
	ldr r2, _08063764 @ =0x03005010
	ldrh r0, [r2, #0xa]
	ldr r1, _08063768 @ =0x0000FF07
	cmp r0, r1
	beq _08063732
	ldrh r0, [r2, #0xe]
	cmp r0, r1
	bne _0806374E
_08063732:
	ldr r0, _08063758 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x50
	movs r1, #0xc0
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl init_blend_effect
	ldr r1, _0806376C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0806374E:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08063758: .4byte 0x03006F74
_0806375C: .4byte 0x08485BD8
_08063760: .4byte 0x0300058C
_08063764: .4byte 0x03005010
_08063768: .4byte 0x0000FF07
_0806376C: .4byte 0x0300137C
	.syntax divided
