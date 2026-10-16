	.syntax unified

	thumb_func_start battle_intro_countdown_tick
battle_intro_countdown_tick: @ 0x0806DA6C
	push {r4, r5, lr}
	ldr r0, _0806DA9C @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _0806DAA8
	movs r0, #6
	movs r1, #2
	bl sub_0806DF80
	movs r0, #3
	bl play_sound_effect
	ldr r1, _0806DAA0 @ =0x03001800
	movs r0, #0
	str r0, [r1, #8]
	ldr r1, _0806DAA4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _0806DAE4
	.align 2, 0
_0806DA9C: .4byte 0x0300058C
_0806DAA0: .4byte 0x03001800
_0806DAA4: .4byte 0x0300137C
_0806DAA8:
	ldr r5, _0806DAD4 @ =0x03001800
	ldr r1, [r5, #8]
	ldr r0, _0806DAD8 @ =0x00000547
	cmp r1, r0
	ble _0806DAE0
	str r4, [r5, #8]
	movs r0, #2
	bl sub_0806B584
	movs r0, #4
	movs r1, #1
	movs r2, #0
	bl setup_screen_transition_effect_080684F0
	movs r0, #3
	strh r0, [r5]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	ldr r1, _0806DADC @ =0x0300137C
	movs r0, #2
	str r0, [r1]
	b _0806DAE4
	.align 2, 0
_0806DAD4: .4byte 0x03001800
_0806DAD8: .4byte 0x00000547
_0806DADC: .4byte 0x0300137C
_0806DAE0:
	adds r0, r1, #1
	str r0, [r5, #8]
_0806DAE4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
