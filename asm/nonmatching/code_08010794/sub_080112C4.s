	.syntax unified

	thumb_func_start sub_080112C4
sub_080112C4: @ 0x080112C4
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl copy_obj_palette_to_buffer
	ldr r0, _080112E8 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _080112EC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080112E8: .4byte 0x03000440
_080112EC: .4byte 0x0300137C
	.syntax divided
