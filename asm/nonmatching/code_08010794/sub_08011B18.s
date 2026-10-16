	.syntax unified

	thumb_func_start sub_08011B18
sub_08011B18: @ 0x08011B18
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl game_state_execute_handler_b
	cmp r0, #0
	beq _08011B52
	ldr r0, _08011B40 @ =0x030057E0
	ldr r1, _08011B44 @ =0x00000C2F
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08011B4C
	ldr r1, _08011B48 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08011B50
	.align 2, 0
_08011B40: .4byte 0x030057E0
_08011B44: .4byte 0x00000C2F
_08011B48: .4byte 0x0300137C
_08011B4C:
	ldr r1, _08011B58 @ =0x0300137C
	movs r0, #0x77
_08011B50:
	str r0, [r1]
_08011B52:
	pop {r0}
	bx r0
	.align 2, 0
_08011B58: .4byte 0x0300137C
	.syntax divided
