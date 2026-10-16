	.syntax unified

	thumb_func_start dma_obj_palette_to_hardware
	.global dma_obj_palette_to_hardware
dma_obj_palette_to_hardware: @ 0x08001454
	push {lr}
	ldr r0, _08001470 @ =0x0202FC00
	ldr r1, _08001474 @ =0x05000200
	movs r2, #0x80
	bl CpuFastSet
	ldr r0, _08001478 @ =0x0202FE00
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x80
	bl CpuFastSet
	pop {r0}
	bx r0
	.align 2, 0
_08001470: .4byte 0x0202FC00
_08001474: .4byte 0x05000200
_08001478: .4byte 0x0202FE00
	.syntax divided
