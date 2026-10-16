	.syntax unified

	thumb_func_start load_battle_bg_layers
	.global load_battle_bg_layers
load_battle_bg_layers: @ 0x08015A90
	push {r4, lr}
	sub sp, #4
	ldr r2, _08015AE8 @ =0x08488830
	ldr r4, _08015AEC @ =0x0400000A
	ldrh r3, [r4]
	movs r0, #0x96
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0
	movs r1, #0xd
	bl set_tilemap_and_decompress_bg
	ldr r2, _08015AF0 @ =0x08488744
	ldrh r3, [r4]
	movs r0, #0x84
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0
	movs r1, #0x11
	bl set_tilemap_and_decompress_bg
	ldr r2, _08015AF4 @ =0x084887A4
	ldrh r3, [r4]
	movs r0, #0x8c
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0xc
	movs r1, #0xf
	bl set_tilemap_and_decompress_bg
	ldr r2, _08015AF8 @ =0x084887F4
	ldrh r3, [r4]
	movs r0, #0x90
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0x14
	movs r1, #0x10
	bl set_tilemap_and_decompress_bg
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08015AE8: .4byte 0x08488830
_08015AEC: .4byte 0x0400000A
_08015AF0: .4byte 0x08488744
_08015AF4: .4byte 0x084887A4
_08015AF8: .4byte 0x084887F4
	.syntax divided
