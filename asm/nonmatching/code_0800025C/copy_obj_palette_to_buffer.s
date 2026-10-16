	.syntax unified

	thumb_func_start copy_obj_palette_to_buffer
	.global copy_obj_palette_to_buffer
copy_obj_palette_to_buffer: @ 0x08001380
	push {lr}
	ldr r0, _0800139C @ =0x05000200
	ldr r1, _080013A0 @ =0x0202F800
	movs r2, #0x80
	bl CpuFastSet
	movs r0, #0xa0
	lsls r0, r0, #0x13
	ldr r1, _080013A4 @ =0x0202FA00
	movs r2, #0x80
	bl CpuFastSet
	pop {r0}
	bx r0
	.align 2, 0
_0800139C: .4byte 0x05000200
_080013A0: .4byte 0x0202F800
_080013A4: .4byte 0x0202FA00
	.syntax divided
