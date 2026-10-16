	.syntax unified

	thumb_func_start can_bot_perform_action
can_bot_perform_action: @ 0x080156F8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_080154E0
	cmp r0, #0
	bne _0801572E
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_08015508
	cmp r0, #0
	bne _0801572E
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_08015528
	cmp r0, #0
	bne _0801572E
	adds r0, r4, #0
	adds r1, r5, #0
	bl begin_battle_action_lookup
	cmp r0, #0
	bne _0801572E
	movs r0, #0
	b _08015730
_0801572E:
	movs r0, #1
_08015730:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
