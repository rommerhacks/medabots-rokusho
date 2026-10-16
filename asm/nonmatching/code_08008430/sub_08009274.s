	.syntax unified

	thumb_func_start sub_08009274
sub_08009274: @ 0x08009274
	push {lr}
	bl sub_080093F8
	bl update_battle_sprite_visibility
	ldr r0, _08009294 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x4a
	ldrb r1, [r1]
	cmp r1, #1
	beq _080092B8
	cmp r1, #1
	bgt _08009298
	cmp r1, #0
	beq _0800929E
	b _080092CC
	.align 2, 0
_08009294: .4byte 0x03000440
_08009298:
	cmp r1, #2
	beq _080092C8
	b _080092CC
_0800929E:
	adds r0, #0x42
	strb r1, [r0]
	movs r0, #6
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	ldr r1, _080092B4 @ =0x0300137C
	movs r0, #7
	str r0, [r1]
	b _080092CC
	.align 2, 0
_080092B4: .4byte 0x0300137C
_080092B8:
	ldr r1, _080092C4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _080092CC
	.align 2, 0
_080092C4: .4byte 0x0300137C
_080092C8:
	ldr r0, _080092D0 @ =0x0300137C
	str r1, [r0]
_080092CC:
	pop {r0}
	bx r0
	.align 2, 0
_080092D0: .4byte 0x0300137C
	.syntax divided
