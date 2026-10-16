	.syntax unified

	thumb_func_start sub_08004A18
sub_08004A18: @ 0x08004A18
	push {lr}
	bl sub_08004E74
	bl setup_overworld_scene_from_position
	bl clear_battle_bot_array
	bl count_active_battle_bots
	bl battle_setup_bot_entry
	ldr r1, _08004A3C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08004A3C: .4byte 0x0300137C
	.syntax divided
