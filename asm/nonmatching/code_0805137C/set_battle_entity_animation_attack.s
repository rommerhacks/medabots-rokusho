	.syntax unified

	thumb_func_start set_battle_entity_animation_attack
	.global set_battle_entity_animation_attack
set_battle_entity_animation_attack: @ 0x08052DC0
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _08052DE0 @ =0x030057E0
	ldr r2, _08052DE4 @ =0x00000C67
	adds r0, r0, r2
	strb r1, [r0]
	movs r0, #0x2f
	bl set_sprite_animation_state
	movs r0, #3
	bl update_battle_direction_indicator
	pop {r0}
	bx r0
	.align 2, 0
_08052DE0: .4byte 0x030057E0
_08052DE4: .4byte 0x00000C67
	.syntax divided
