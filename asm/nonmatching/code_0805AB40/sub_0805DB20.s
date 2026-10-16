	.syntax unified

	thumb_func_start sub_0805DB20
sub_0805DB20: @ 0x0805DB20
	push {lr}
	bl sub_0803FB0C
	bl copy_obj_palette_to_buffer
	ldr r0, _0805DB40 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _0805DB44 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0805DB40: .4byte 0x03000440
_0805DB44: .4byte 0x0300137C
	.syntax divided
