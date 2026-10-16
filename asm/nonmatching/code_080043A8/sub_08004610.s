	.syntax unified

	thumb_func_start sub_08004610
sub_08004610: @ 0x08004610
	push {lr}
	bl sub_08004E74
	bl sub_08006764
	bl toggle_sprite_pair_visibility
	bl dispatch_game_substate_handler_08006824
	bl battle_update_medabot_display
	bl sub_08006F14
	bl update_blend_effect
	cmp r0, #0
	beq _0800463A
	ldr r1, _08004640 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0800463A:
	pop {r0}
	bx r0
	.align 2, 0
_08004640: .4byte 0x0300137C
	.syntax divided
