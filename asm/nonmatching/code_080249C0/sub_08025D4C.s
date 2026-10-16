	.syntax unified

	thumb_func_start sub_08025D4C
sub_08025D4C: @ 0x08025D4C
	push {lr}
	movs r0, #0
	bl dispatch_battle_action_substate
	movs r0, #0x51
	bl play_sound_effect
	ldr r1, _08025D68 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08025D68: .4byte 0x03001800
	.syntax divided
