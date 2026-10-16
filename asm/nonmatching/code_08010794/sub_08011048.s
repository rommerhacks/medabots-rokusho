	.syntax unified

	thumb_func_start sub_08011048
sub_08011048: @ 0x08011048
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl battle_check_medal_level_up
	ldr r0, _08011070 @ =0x03001800
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08011074 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08011070: .4byte 0x03001800
_08011074: .4byte 0x0300137C
	.syntax divided
