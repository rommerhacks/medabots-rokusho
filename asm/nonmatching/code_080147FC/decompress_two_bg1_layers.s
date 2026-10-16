	.syntax unified

	thumb_func_start decompress_two_bg1_layers
	.global decompress_two_bg1_layers
decompress_two_bg1_layers: @ 0x08015AFC
	push {r4, lr}
	sub sp, #4
	ldr r2, _08015B30 @ =0x084887A4
	ldr r4, _08015B34 @ =0x0400000A
	ldrh r3, [r4]
	movs r0, #0x8c
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0xc
	movs r1, #0x15
	bl set_tilemap_and_decompress_bg
	ldr r2, _08015B38 @ =0x084887F4
	ldrh r3, [r4]
	movs r0, #0x90
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0x14
	movs r1, #0x15
	bl set_tilemap_and_decompress_bg
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08015B30: .4byte 0x084887A4
_08015B34: .4byte 0x0400000A
_08015B38: .4byte 0x084887F4
	.syntax divided
