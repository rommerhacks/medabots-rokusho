	.syntax unified

	thumb_func_start sub_080045DC
sub_080045DC: @ 0x080045DC
	push {lr}
	bl sub_08004E74
	bl sub_08006764
	bl toggle_sprite_pair_visibility
	bl dispatch_game_substate_handler_08006824
	bl battle_update_medabot_display
	bl sub_08006F14
	movs r0, #6
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	ldr r1, _0800460C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800460C: .4byte 0x0300137C
	.syntax divided
