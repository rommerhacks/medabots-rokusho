	.syntax unified

	thumb_func_start set_battle_state_byte_c83
	.global set_battle_state_byte_c83
set_battle_state_byte_c83: @ 0x08052DE8
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _08052E04 @ =0x030057E0
	ldr r2, _08052E08 @ =0x00000C83
	adds r0, r0, r2
	strb r1, [r0]
	movs r0, #0x30
	bl set_sprite_animation_state
	pop {r0}
	bx r0
	.align 2, 0
_08052E04: .4byte 0x030057E0
_08052E08: .4byte 0x00000C83
	.syntax divided
