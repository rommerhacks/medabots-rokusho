	.syntax unified

	thumb_func_start sub_0801120C
sub_0801120C: @ 0x0801120C
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r0, _08011234 @ =0x083C65C4
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _08011230
	ldr r1, _08011238 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08011230:
	pop {r0}
	bx r0
	.align 2, 0
_08011234: .4byte 0x083C65C4
_08011238: .4byte 0x0300137C
	.syntax divided
