	.syntax unified

	thumb_func_start sub_080115B4
sub_080115B4: @ 0x080115B4
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl setup_battle_result_sprite
	bl sub_08012468
	bl copy_obj_palette_to_buffer
	ldr r0, _080115E0 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _080115E4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080115E0: .4byte 0x03000440
_080115E4: .4byte 0x0300137C
	.syntax divided
