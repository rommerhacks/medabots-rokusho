	.syntax unified

	thumb_func_start load_bg3_tilemap_08488764
	.global load_bg3_tilemap_08488764
load_bg3_tilemap_08488764: @ 0x08015738
	push {lr}
	sub sp, #4
	ldr r2, _08015758 @ =0x08488764
	ldr r0, _0801575C @ =0x0400000E
	ldrh r3, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0xe
	movs r1, #3
	bl set_tilemap_and_decompress_bg
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08015758: .4byte 0x08488764
_0801575C: .4byte 0x0400000E
	.syntax divided
