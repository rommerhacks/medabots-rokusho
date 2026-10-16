	.syntax unified

	thumb_func_start set_tilemap_and_decompress_bg
	.global set_tilemap_and_decompress_bg
set_tilemap_and_decompress_bg: @ 0x08000E04
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r0, r2, #0
	mov r8, r3
	ldr r2, [sp, #0x14]
	ldr r1, _08000E38 @ =0x03000580
	strh r2, [r1]
	ldr r4, _08000E3C @ =0x02030000
	adds r1, r4, #0
	bl lz_decompress_dispatch
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	mov r3, r8
	bl write_tilemap_to_vram_08000E94
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08000E38: .4byte 0x03000580
_08000E3C: .4byte 0x02030000
	.syntax divided
