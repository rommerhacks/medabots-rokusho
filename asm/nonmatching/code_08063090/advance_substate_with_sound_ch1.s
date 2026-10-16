	.syntax unified

	thumb_func_start advance_substate_with_sound_ch1
advance_substate_with_sound_ch1: @ 0x08066534
	push {lr}
	ldr r0, _08066558 @ =0x08485BD8
	ldr r0, [r0, #0x48]
	bl run_message
	cmp r0, #0
	beq _08066554
	movs r0, #1
	movs r1, #0x16
	movs r2, #7
	bl open_choice_menu
	ldr r1, _0806655C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08066554:
	pop {r0}
	bx r0
	.align 2, 0
_08066558: .4byte 0x08485BD8
_0806655C: .4byte 0x0300137C
	.syntax divided
