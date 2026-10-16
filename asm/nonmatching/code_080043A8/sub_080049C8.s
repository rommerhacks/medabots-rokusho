	.syntax unified

	thumb_func_start sub_080049C8
sub_080049C8: @ 0x080049C8
	push {lr}
	bl sub_08004E74
	bl setup_overworld_scene_from_position
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	ldr r1, _080049E8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080049E8: .4byte 0x0300137C
	.syntax divided
