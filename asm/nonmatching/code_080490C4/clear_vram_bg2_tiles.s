	.syntax unified

	thumb_func_start clear_vram_bg2_tiles
clear_vram_bg2_tiles: @ 0x0804B24C
	push {lr}
	ldr r0, _0804B260 @ =0x06003000
	movs r1, #0xc0
	lsls r1, r1, #7
	movs r2, #0x80
	bl sub_080496DC
	pop {r0}
	bx r0
	.align 2, 0
_0804B260: .4byte 0x06003000
	.syntax divided
