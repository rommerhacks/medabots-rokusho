	.syntax unified

	thumb_func_start sub_080230A4
sub_080230A4: @ 0x080230A4
	push {lr}
	bl copy_obj_palette_to_buffer
	ldr r0, _080230C0 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _080230C4 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080230C0: .4byte 0x03000440
_080230C4: .4byte 0x03001800
	.syntax divided
