	.syntax unified

	thumb_func_start sub_080312CC
sub_080312CC: @ 0x080312CC
	push {lr}
	bl copy_obj_palette_to_buffer
	ldr r0, _080312E8 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _080312EC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080312E8: .4byte 0x03000440
_080312EC: .4byte 0x0300137C
	.syntax divided
