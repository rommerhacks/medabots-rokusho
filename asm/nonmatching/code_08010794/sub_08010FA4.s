	.syntax unified

	thumb_func_start sub_08010FA4
sub_08010FA4: @ 0x08010FA4
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r0, _08010FD4 @ =0x083C65C4
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _08010FD0
	movs r0, #0x32
	movs r1, #1
	bl sub_080422B8
	ldr r1, _08010FD8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08010FD0:
	pop {r0}
	bx r0
	.align 2, 0
_08010FD4: .4byte 0x083C65C4
_08010FD8: .4byte 0x0300137C
	.syntax divided
