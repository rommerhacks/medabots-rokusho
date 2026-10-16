	.syntax unified

	thumb_func_start decompress_to_bg_scroll_buffer
decompress_to_bg_scroll_buffer: @ 0x08000E70
	push {r4, r5, lr}
	adds r5, r1, #0
	ldr r4, _08000E90 @ =0x02030000
	adds r1, r4, #0
	bl lz_decompress_dispatch
	adds r2, r0, #0
	lsls r2, r2, #0xa
	lsrs r2, r2, #0xb
	adds r0, r4, #0
	adds r1, r5, #0
	bl CpuSet
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08000E90: .4byte 0x02030000
	.syntax divided
