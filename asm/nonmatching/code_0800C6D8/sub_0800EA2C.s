	.syntax unified

	thumb_func_start sub_0800EA2C
sub_0800EA2C: @ 0x0800EA2C
	push {r4, r5, lr}
	sub sp, #4
	bl medaparts_scroll_bg
	bl load_medapart_sprite_by_slot
	ldr r2, _0800EA80 @ =0x03002C30
	adds r4, r2, #0
	adds r4, #0x40
	ldrh r3, [r4]
	ldr r1, _0800EA84 @ =0x0000BFFF
	adds r0, r1, #0
	ands r0, r3
	movs r5, #0
	strh r0, [r4]
	adds r2, #0x80
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	ldr r2, _0800EA88 @ =0x084889F8
	ldr r0, _0800EA8C @ =0x04000008
	ldrh r3, [r0]
	movs r0, #0xe0
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0x12
	movs r1, #5
	bl set_tilemap_and_decompress_bg
	ldr r0, _0800EA90 @ =0x03000440
	adds r0, #0x4a
	strb r5, [r0]
	bl sub_08010040
	ldr r1, _0800EA94 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800EA80: .4byte 0x03002C30
_0800EA84: .4byte 0x0000BFFF
_0800EA88: .4byte 0x084889F8
_0800EA8C: .4byte 0x04000008
_0800EA90: .4byte 0x03000440
_0800EA94: .4byte 0x0300137C
	.syntax divided
