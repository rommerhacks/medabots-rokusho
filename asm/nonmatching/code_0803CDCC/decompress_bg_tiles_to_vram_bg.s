	.syntax unified

	thumb_func_start decompress_bg_tiles_to_vram_bg
	.global decompress_bg_tiles_to_vram_bg
decompress_bg_tiles_to_vram_bg: @ 0x0803F3A8
	push {lr}
	ldr r0, _0803F3C8 @ =0x084873D0
	ldr r1, _0803F3CC @ =0x06000020
	bl lz_decompress_dispatch
	ldr r0, _0803F3D0 @ =0x084C31BC
	ldr r1, _0803F3D4 @ =0x06001780
	bl lz_decompress_dispatch
	ldr r0, _0803F3D8 @ =0x08488A84
	ldr r1, _0803F3DC @ =0x050001E0
	movs r2, #8
	bl CpuFastSet
	pop {r0}
	bx r0
	.align 2, 0
_0803F3C8: .4byte 0x084873D0
_0803F3CC: .4byte 0x06000020
_0803F3D0: .4byte 0x084C31BC
_0803F3D4: .4byte 0x06001780
_0803F3D8: .4byte 0x08488A84
_0803F3DC: .4byte 0x050001E0
	.syntax divided
