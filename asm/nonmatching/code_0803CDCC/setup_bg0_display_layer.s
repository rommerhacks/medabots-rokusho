	.syntax unified

	thumb_func_start setup_bg0_display_layer
setup_bg0_display_layer: @ 0x0803F3E0
	push {lr}
	sub sp, #4
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0803F414 @ =0x04000008
	movs r0, #0xa0
	lsls r0, r0, #3
	strh r0, [r1]
	ldr r2, _0803F418 @ =0x08488540
	ldrh r3, [r1]
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	movs r1, #0xd
	bl set_tilemap_and_decompress_bg
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0803F414: .4byte 0x04000008
_0803F418: .4byte 0x08488540
	.syntax divided
