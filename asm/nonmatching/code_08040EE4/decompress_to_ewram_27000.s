	.syntax unified

	thumb_func_start decompress_to_ewram_27000
	.global decompress_to_ewram_27000
decompress_to_ewram_27000: @ 0x080441A8
	push {lr}
	ldr r1, _080441B4 @ =0x02027000
	bl lz_decompress_dispatch
	pop {r0}
	bx r0
	.align 2, 0
_080441B4: .4byte 0x02027000
	.syntax divided
