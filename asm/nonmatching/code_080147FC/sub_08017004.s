	.syntax unified

	thumb_func_start sub_08017004
	.global sub_08017004
sub_08017004: @ 0x08017004
	push {lr}
	sub sp, #4
	ldr r2, _08017038 @ =0x084888E4
	ldr r0, _0801703C @ =0x04000008
	ldrh r3, [r0]
	movs r0, #0xa8
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #9
	movs r1, #0x15
	bl set_tilemap_and_decompress_bg
	ldr r2, _08017040 @ =0x08488920
	ldr r0, _08017044 @ =0x0400000A
	ldrh r3, [r0]
	movs r0, #0xae
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0x12
	movs r1, #0x15
	bl set_tilemap_and_decompress_bg
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08017038: .4byte 0x084888E4
_0801703C: .4byte 0x04000008
_08017040: .4byte 0x08488920
_08017044: .4byte 0x0400000A
	.syntax divided
