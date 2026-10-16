	.syntax unified

	thumb_func_start sub_08010930
sub_08010930: @ 0x08010930
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl poll_choice_menu
	cmp r0, #0
	beq _0801095E
	lsrs r0, r0, #4
	cmp r0, #0
	bne _08010958
	bl sub_0803FB0C
	ldr r1, _08010954 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _0801095C
	.align 2, 0
_08010954: .4byte 0x0300137C
_08010958:
	ldr r1, _08010964 @ =0x0300137C
	movs r0, #0x20
_0801095C:
	str r0, [r1]
_0801095E:
	pop {r0}
	bx r0
	.align 2, 0
_08010964: .4byte 0x0300137C
	.syntax divided
