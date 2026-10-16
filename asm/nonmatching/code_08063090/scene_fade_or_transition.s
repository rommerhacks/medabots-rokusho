	.syntax unified

	thumb_func_start scene_fade_or_transition
scene_fade_or_transition: @ 0x08063770
	push {r4, lr}
	ldr r4, _08063798 @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x50
	bl blend_fade_step_08065598
	cmp r0, #0
	beq _080637A4
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r1, _0806379C @ =0x03002B8C
	movs r0, #0x14
	str r0, [r1]
	ldr r1, _080637A0 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
	b _080637C8
	.align 2, 0
_08063798: .4byte 0x03006F74
_0806379C: .4byte 0x03002B8C
_080637A0: .4byte 0x0300137C
_080637A4:
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
_080637C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
