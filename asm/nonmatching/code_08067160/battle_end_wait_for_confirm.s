	.syntax unified

	thumb_func_start battle_end_wait_for_confirm
battle_end_wait_for_confirm: @ 0x080681E0
	push {lr}
	sub sp, #4
	bl update_battle_sprite_explosions
	ldr r0, _08068224 @ =0x08485788
	ldr r0, [r0, #0x48]
	bl run_message
	cmp r0, #0
	beq _0806821C
	ldr r0, _08068228 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0806821C
	ldr r0, _0806822C @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x50
	movs r1, #0xc0
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl init_blend_effect
	ldr r1, _08068230 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0806821C:
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08068224: .4byte 0x08485788
_08068228: .4byte 0x0300058C
_0806822C: .4byte 0x03006F74
_08068230: .4byte 0x0300137C
	.syntax divided
