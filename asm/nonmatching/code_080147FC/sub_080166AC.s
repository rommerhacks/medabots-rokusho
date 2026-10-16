	.syntax unified

	thumb_func_start sub_080166AC
	.global sub_080166AC
sub_080166AC: @ 0x080166AC
	push {lr}
	sub sp, #4
	ldr r2, _080166E0 @ =0x084888A8
	ldr r0, _080166E4 @ =0x04000008
	ldrh r3, [r0]
	movs r0, #0xa2
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #9
	movs r1, #0x15
	bl set_tilemap_and_decompress_bg
	ldr r2, _080166E8 @ =0x0848895C
	ldr r0, _080166EC @ =0x0400000A
	ldrh r3, [r0]
	movs r0, #0xb4
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0x12
	movs r1, #0x15
	bl set_tilemap_and_decompress_bg
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_080166E0: .4byte 0x084888A8
_080166E4: .4byte 0x04000008
_080166E8: .4byte 0x0848895C
_080166EC: .4byte 0x0400000A
	.syntax divided
