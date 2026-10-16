	.syntax unified

	thumb_func_start sub_0801AC98
sub_0801AC98: @ 0x0801AC98
	push {r4, lr}
	sub sp, #4
	cmp r0, #2
	bhi _0801ACD4
	ldr r2, _0801ACC8 @ =0x08488830
	ldr r4, _0801ACCC @ =0x0400000A
	ldrh r3, [r4]
	movs r0, #0x96
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0
	movs r1, #0xd
	bl set_tilemap_and_decompress_bg
	ldr r2, _0801ACD0 @ =0x08488744
	ldrh r3, [r4]
	movs r0, #0x84
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0
	movs r1, #0x11
	bl set_tilemap_and_decompress_bg
	b _0801ACFA
	.align 2, 0
_0801ACC8: .4byte 0x08488830
_0801ACCC: .4byte 0x0400000A
_0801ACD0: .4byte 0x08488744
_0801ACD4:
	ldr r2, _0801AD04 @ =0x0848886C
	ldr r4, _0801AD08 @ =0x0400000A
	ldrh r3, [r4]
	movs r0, #0x9c
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0x12
	movs r1, #0xd
	bl set_tilemap_and_decompress_bg
	ldr r2, _0801AD0C @ =0x08488744
	ldrh r3, [r4]
	movs r0, #0x84
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0x14
	movs r1, #0x11
	bl set_tilemap_and_decompress_bg
_0801ACFA:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801AD04: .4byte 0x0848886C
_0801AD08: .4byte 0x0400000A
_0801AD0C: .4byte 0x08488744
	.syntax divided
