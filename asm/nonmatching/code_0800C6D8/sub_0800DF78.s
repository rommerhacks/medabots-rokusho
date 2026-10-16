	.syntax unified

	thumb_func_start sub_0800DF78
sub_0800DF78: @ 0x0800DF78
	push {lr}
	bl sub_0800EBFC
	bl sub_0800EF58
	ldr r0, _0800DFAC @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #0x50
	bl sub_08041C14
	bl load_medapart_sprite_by_slot
	bl copy_obj_palette_to_buffer
	ldr r0, _0800DFB0 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _0800DFB4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800DFAC: .4byte 0x03001780
_0800DFB0: .4byte 0x03000440
_0800DFB4: .4byte 0x0300137C
	.syntax divided
