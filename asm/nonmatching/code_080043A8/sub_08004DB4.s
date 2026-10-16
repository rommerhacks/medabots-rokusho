	.syntax unified

	thumb_func_start sub_08004DB4
sub_08004DB4: @ 0x08004DB4
	push {r4, lr}
	ldr r1, _08004DE4 @ =0x03005010
	movs r4, #0
	movs r0, #0
	strh r0, [r1, #6]
	bl sub_08004E74
	bl setup_overworld_scene_from_position
	bl sub_08007540
	bl copy_obj_palette_to_buffer
	ldr r0, _08004DE8 @ =0x03000440
	adds r0, #0x84
	strb r4, [r0]
	ldr r1, _08004DEC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08004DE4: .4byte 0x03005010
_08004DE8: .4byte 0x03000440
_08004DEC: .4byte 0x0300137C
	.syntax divided
