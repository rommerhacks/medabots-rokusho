	.syntax unified

	thumb_func_start sub_080109A0
sub_080109A0: @ 0x080109A0
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl copy_obj_palette_to_buffer
	ldr r0, _080109C4 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _080109C8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080109C4: .4byte 0x03000440
_080109C8: .4byte 0x0300137C
	.syntax divided
