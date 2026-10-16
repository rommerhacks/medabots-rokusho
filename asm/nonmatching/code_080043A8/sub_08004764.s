	.syntax unified

	thumb_func_start sub_08004764
sub_08004764: @ 0x08004764
	push {lr}
	bl sub_08004E74
	bl sub_08005000
	bl setup_overworld_scene_from_position
	movs r0, #0
	movs r1, #4
	bl clear_sprite_table_mask
	ldr r0, _08004790 @ =0x03000440
	adds r0, #0x5c
	movs r1, #0
	strh r1, [r0]
	ldr r1, _08004794 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08004790: .4byte 0x03000440
_08004794: .4byte 0x0300137C
	.syntax divided
