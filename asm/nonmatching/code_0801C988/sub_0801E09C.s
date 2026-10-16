	.syntax unified

	thumb_func_start sub_0801E09C
sub_0801E09C: @ 0x0801E09C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r0, _0801E0B4 @ =0x03000440
	ldr r1, _0801E0B8 @ =0x00000139
	adds r6, r0, r1
	ldrb r5, [r6]
	cmp r5, #0
	beq _0801E0BC
	cmp r5, #1
	beq _0801E154
	b _0801E1E4
	.align 2, 0
_0801E0B4: .4byte 0x03000440
_0801E0B8: .4byte 0x00000139
_0801E0BC:
	bl sub_08043CA8
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0801E128 @ =0x0000E0FF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0801E12C @ =0x04000008
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r2, #0
	strh r0, [r1]
	ldr r4, _0801E130 @ =0x0400000A
	ldr r3, _0801E134 @ =0x00001801
	adds r0, r3, #0
	strh r0, [r4]
	adds r1, #4
	ldr r2, _0801E138 @ =0x0000590A
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _0801E13C @ =0x00005B0B
	adds r0, r3, #0
	strh r0, [r1]
	ldr r0, _0801E140 @ =0x084C6A98
	ldr r1, _0801E144 @ =0x06017400
	bl lz_decompress_dispatch
	ldrh r0, [r4]
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r0, _0801E148 @ =0x03001800
	adds r0, #0x38
	ldrb r0, [r0]
	movs r1, #0
	bl decompress_tileset_to_vram
	str r5, [sp, #8]
	ldr r1, _0801E14C @ =0x03002C30
	ldr r2, _0801E150 @ =0x01000800
	add r0, sp, #8
	bl CpuFastSet
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b _0801E1E4
	.align 2, 0
_0801E128: .4byte 0x0000E0FF
_0801E12C: .4byte 0x04000008
_0801E130: .4byte 0x0400000A
_0801E134: .4byte 0x00001801
_0801E138: .4byte 0x0000590A
_0801E13C: .4byte 0x00005B0B
_0801E140: .4byte 0x084C6A98
_0801E144: .4byte 0x06017400
_0801E148: .4byte 0x03001800
_0801E14C: .4byte 0x03002C30
_0801E150: .4byte 0x01000800
_0801E154:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0xfa
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r1, [r2]
	ldr r0, _0801E1A4 @ =0x0000FFDF
	ands r0, r1
	strh r0, [r2]
	bl apply_battle_blend_effect_a
	ldr r4, _0801E1A8 @ =0x03000590
	ldr r3, _0801E1AC @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r2, r0, #8
	adds r1, r2, r4
	adds r0, r1, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0801E1B0
	adds r0, r3, #0
	adds r0, #0xa7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, r0, r4
	adds r0, #0x49
	ldrb r0, [r0]
	bl decompress_indexed_graphics_to_ewram
	b _0801E1BC
	.align 2, 0
_0801E1A4: .4byte 0x0000FFDF
_0801E1A8: .4byte 0x03000590
_0801E1AC: .4byte 0x03001800
_0801E1B0:
	adds r0, r1, #0
	adds r0, #0xa8
	ldrb r0, [r0]
	adds r0, #0x50
	bl decompress_indexed_graphics_to_ewram
_0801E1BC:
	bl decompress_fixed_graphics_to_ewram
	bl sub_08035C3C
	ldr r1, _0801E1EC @ =0x030017F0
	ldr r0, _0801E1F0 @ =sub_08043E48
	str r0, [r1]
	ldr r2, _0801E1F4 @ =0x03000440
	adds r0, r2, #0
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0801E1F8 @ =0x00000139
	adds r0, r2, r3
	strb r1, [r0]
	ldr r1, _0801E1FC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801E1E4:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801E1EC: .4byte 0x030017F0
_0801E1F0: .4byte sub_08043E48
_0801E1F4: .4byte 0x03000440
_0801E1F8: .4byte 0x00000139
_0801E1FC: .4byte 0x03001800
	.syntax divided
