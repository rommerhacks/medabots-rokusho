	.syntax unified

	thumb_func_start advance_substate_with_sound
advance_substate_with_sound: @ 0x08002730
	push {lr}
	ldr r0, _08002754 @ =0x083B53F8
	ldr r0, [r0, #4]
	bl run_message
	cmp r0, #0
	beq _08002750
	movs r0, #0
	movs r1, #0x16
	movs r2, #7
	bl open_choice_menu
	ldr r1, _08002758 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08002750:
	pop {r0}
	bx r0
	.align 2, 0
_08002754: .4byte 0x083B53F8
_08002758: .4byte 0x0300137C
	.syntax divided
