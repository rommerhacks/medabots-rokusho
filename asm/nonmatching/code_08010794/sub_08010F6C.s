	.syntax unified

	thumb_func_start sub_08010F6C
sub_08010F6C: @ 0x08010F6C
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r0, _08010F8C @ =0x03001800
	ldrb r0, [r0, #1]
	cmp r0, #0
	beq _08010F94
	bl sub_0803FB0C
	ldr r1, _08010F90 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08010F98
	.align 2, 0
_08010F8C: .4byte 0x03001800
_08010F90: .4byte 0x0300137C
_08010F94:
	ldr r1, _08010FA0 @ =0x0300137C
	movs r0, #0x40
_08010F98:
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08010FA0: .4byte 0x0300137C
	.syntax divided
