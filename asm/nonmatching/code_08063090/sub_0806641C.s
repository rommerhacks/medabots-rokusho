	.syntax unified

	thumb_func_start sub_0806641C
sub_0806641C: @ 0x0806641C
	push {r4, lr}
	ldr r4, _08066444 @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x50
	bl blend_fade_step_08065598
	cmp r0, #0
	beq _08066458
	ldr r1, [r4]
	ldrb r0, [r1, #5]
	cmp r0, #2
	bhi _0806644C
	ldr r0, _08066448 @ =0x080AFB45
	ldrb r1, [r1, #5]
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	bl init_game_mode
	b _08066458
	.align 2, 0
_08066444: .4byte 0x03006F74
_08066448: .4byte 0x080AFB45
_0806644C:
	ldr r1, _08066460 @ =0x03002B8C
	movs r0, #0x1b
	str r0, [r1]
	ldr r1, _08066464 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
_08066458:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08066460: .4byte 0x03002B8C
_08066464: .4byte 0x0300137C
	.syntax divided
