	.syntax unified

	thumb_func_start decompress_to_ewram_buffer
decompress_to_ewram_buffer: @ 0x08000E40
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r0, r2, #0
	mov r8, r3
	ldr r4, _08000E6C @ =0x02030000
	adds r1, r4, #0
	bl lz_decompress_dispatch
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	mov r3, r8
	bl load_tilemap_rows_to_vram
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08000E6C: .4byte 0x02030000
	.syntax divided
