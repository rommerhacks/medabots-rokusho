	.syntax unified

	thumb_func_start sub_0801058C
sub_0801058C: @ 0x0801058C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	bl sub_08043CA8
	movs r6, #0x80
	lsls r6, r6, #0x13
	ldrh r1, [r6]
	ldr r0, _080106EC @ =0x0000E0FF
	ands r0, r1
	strh r0, [r6]
	ldr r5, _080106F0 @ =0x04000008
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r1, #0
	strh r0, [r5]
	ldr r4, _080106F4 @ =0x0400000A
	ldr r2, _080106F8 @ =0x00001801
	adds r0, r2, #0
	strh r0, [r4]
	ldr r1, _080106FC @ =0x0400000C
	ldr r2, _08010700 @ =0x0000590A
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _08010704 @ =0x00005B0B
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _08010708 @ =0x084E6C9C
	ldr r1, _0801070C @ =0x06004000
	bl lz_decompress_dispatch
	ldr r0, _08010710 @ =0x084C48B4
	ldr r1, _08010714 @ =0x06006000
	bl lz_decompress_dispatch
	ldr r0, _08010718 @ =0x084C4A34
	ldr r1, _0801071C @ =0x06006200
	bl lz_decompress_dispatch
	ldr r0, _08010720 @ =0x084C7D10
	ldr r1, _08010724 @ =0x06012800
	bl lz_decompress_dispatch
	ldr r0, _08010728 @ =0x084C6A98
	ldr r1, _0801072C @ =0x06017400
	bl lz_decompress_dispatch
	ldrh r0, [r5]
	str r0, [sp]
	movs r5, #0
	str r5, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldrh r0, [r4]
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r2, _08010730 @ =0x084EFA34
	ldrh r3, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	adds r4, #0xca
	ldr r0, _08010734 @ =0x084F29E0
	str r0, [r4]
	ldr r0, _08010738 @ =0x0202FA00
	str r0, [r4, #4]
	ldr r0, _0801073C @ =0x84000070
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08010740 @ =0x084C69D8
	str r0, [r4]
	ldr r0, _08010744 @ =0x0202FB00
	str r0, [r4, #4]
	ldr r2, _08010748 @ =0x84000008
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0801074C @ =0x084C69F8
	str r0, [r4]
	ldr r0, _08010750 @ =0x0202FB20
	str r0, [r4, #4]
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08010754 @ =0x0850DEF8
	str r0, [r4]
	ldr r0, _08010758 @ =0x0202F800
	str r0, [r4, #4]
	ldr r0, _0801075C @ =0x84000040
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _08010760 @ =0x0850DE58
	str r1, [r4]
	ldr r0, _08010764 @ =0x0202F980
	str r0, [r4, #4]
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08010768 @ =0xFFFFFEA0
	adds r1, r1, r0
	str r1, [r4]
	ldr r0, _0801076C @ =0x0202F9A0
	str r0, [r4, #4]
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08010770 @ =0x084E2FB8
	str r0, [r4]
	ldr r0, _08010774 @ =0x0202F940
	str r0, [r4, #4]
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08010778 @ =0x084E2F98
	str r0, [r4]
	ldr r0, _0801077C @ =0x0202F960
	str r0, [r4, #4]
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08010780 @ =0x03001800
	adds r0, #0x38
	ldrb r0, [r0]
	movs r1, #1
	bl decompress_tileset_to_vram
	str r5, [sp, #8]
	add r1, sp, #8
	str r1, [r4]
	ldr r0, _08010784 @ =0x03002C30
	str r0, [r4, #4]
	ldr r0, _08010788 @ =0x85000800
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldrh r0, [r6]
	movs r2, #0xfb
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r6]
	bl sub_08011F50
	bl sub_08011FA0
	bl sub_08011FEC
	bl sub_08012024
	bl sub_080120C8
	bl sub_0801214C
	bl sub_080121A8
	bl apply_battle_blend_effect_a
	ldr r0, _0801078C @ =0x03000440
	adds r0, #0x84
	strb r5, [r0]
	ldr r1, _08010790 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080106EC: .4byte 0x0000E0FF
_080106F0: .4byte 0x04000008
_080106F4: .4byte 0x0400000A
_080106F8: .4byte 0x00001801
_080106FC: .4byte 0x0400000C
_08010700: .4byte 0x0000590A
_08010704: .4byte 0x00005B0B
_08010708: .4byte 0x084E6C9C
_0801070C: .4byte 0x06004000
_08010710: .4byte 0x084C48B4
_08010714: .4byte 0x06006000
_08010718: .4byte 0x084C4A34
_0801071C: .4byte 0x06006200
_08010720: .4byte 0x084C7D10
_08010724: .4byte 0x06012800
_08010728: .4byte 0x084C6A98
_0801072C: .4byte 0x06017400
_08010730: .4byte 0x084EFA34
_08010734: .4byte 0x084F29E0
_08010738: .4byte 0x0202FA00
_0801073C: .4byte 0x84000070
_08010740: .4byte 0x084C69D8
_08010744: .4byte 0x0202FB00
_08010748: .4byte 0x84000008
_0801074C: .4byte 0x084C69F8
_08010750: .4byte 0x0202FB20
_08010754: .4byte 0x0850DEF8
_08010758: .4byte 0x0202F800
_0801075C: .4byte 0x84000040
_08010760: .4byte 0x0850DE58
_08010764: .4byte 0x0202F980
_08010768: .4byte 0xFFFFFEA0
_0801076C: .4byte 0x0202F9A0
_08010770: .4byte 0x084E2FB8
_08010774: .4byte 0x0202F940
_08010778: .4byte 0x084E2F98
_0801077C: .4byte 0x0202F960
_08010780: .4byte 0x03001800
_08010784: .4byte 0x03002C30
_08010788: .4byte 0x85000800
_0801078C: .4byte 0x03000440
_08010790: .4byte 0x0300137C
	.syntax divided
