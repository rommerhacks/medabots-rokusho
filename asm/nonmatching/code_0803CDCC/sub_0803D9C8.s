	.syntax unified

	thumb_func_start sub_0803D9C8
sub_0803D9C8: @ 0x0803D9C8
	push {lr}
	bl update_scroll_movement_a
	bl copy_obj_palette_to_buffer
	ldr r0, _0803D9E8 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _0803D9EC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803D9E8: .4byte 0x03000440
_0803D9EC: .4byte 0x0300137C
	.syntax divided
