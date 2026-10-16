	.syntax unified

	thumb_func_start sub_0803D74C
sub_0803D74C: @ 0x0803D74C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x14
	bl sub_08043CA8
	movs r5, #0
	str r5, [sp, #8]
	ldr r1, _0803D89C @ =0x05000200
	ldr r4, _0803D8A0 @ =0x01000080
	add r0, sp, #8
	adds r2, r4, #0
	bl CpuFastSet
	str r5, [sp, #0xc]
	add r0, sp, #0xc
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r2, r4, #0
	bl CpuFastSet
	movs r0, #0x80
	lsls r0, r0, #0x13
	mov r8, r0
	ldrh r1, [r0]
	ldr r0, _0803D8A4 @ =0x0000E0FF
	ands r0, r1
	mov r1, r8
	strh r0, [r1]
	ldr r6, _0803D8A8 @ =0x04000008
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r2, #0
	strh r0, [r6]
	ldr r4, _0803D8AC @ =0x0400000A
	ldr r1, _0803D8B0 @ =0x00001801
	adds r0, r1, #0
	strh r0, [r4]
	ldr r1, _0803D8B4 @ =0x0400000C
	ldr r2, _0803D8B8 @ =0x0000590A
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _0803D8BC @ =0x00005B0B
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0803D8C0 @ =0x084E6C9C
	ldr r1, _0803D8C4 @ =0x06004000
	bl lz_decompress_dispatch
	ldr r0, _0803D8C8 @ =0x084C48B4
	ldr r1, _0803D8CC @ =0x06006000
	bl lz_decompress_dispatch
	ldr r0, _0803D8D0 @ =0x084C4A34
	ldr r1, _0803D8D4 @ =0x06006200
	bl lz_decompress_dispatch
	ldr r0, _0803D8D8 @ =0x084C6A98
	ldr r1, _0803D8DC @ =0x06017400
	bl lz_decompress_dispatch
	ldrh r0, [r6]
	str r0, [sp]
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
	ldr r2, _0803D8E0 @ =0x084EFA34
	ldrh r3, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r0, _0803D8E4 @ =0x084F29E0
	ldr r1, _0803D8E8 @ =0x0202FA00
	movs r2, #0x70
	bl CpuFastSet
	ldr r0, _0803D8EC @ =0x084C69D8
	ldr r1, _0803D8F0 @ =0x0202FB00
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0803D8F4 @ =0x084C69F8
	ldr r1, _0803D8F8 @ =0x0202FB20
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0803D8FC @ =0x0850DEF8
	ldr r1, _0803D900 @ =0x0202F800
	movs r2, #0x40
	bl CpuFastSet
	ldr r4, _0803D904 @ =0x0850DE58
	ldr r1, _0803D908 @ =0x0202F980
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0803D90C @ =0xFFFFFEA0
	adds r4, r4, r0
	ldr r1, _0803D910 @ =0x0202F9A0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0803D914 @ =0x03001800
	adds r0, #0x38
	ldrb r0, [r0]
	movs r1, #1
	bl decompress_tileset_to_vram
	str r5, [sp, #0x10]
	add r0, sp, #0x10
	ldr r1, _0803D918 @ =0x03002C30
	ldr r2, _0803D91C @ =0x01000800
	bl CpuFastSet
	mov r1, r8
	ldrh r0, [r1]
	movs r2, #0xfb
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	mov r1, r8
	strh r0, [r1]
	bl render_battle_text_label
	bl load_battle_anim_data_38
	bl draw_battle_ui_tiles_from_rom
	bl load_battle_script_entry_a
	bl apply_battle_blend_effect_a
	movs r0, #8
	bl play_song
	ldr r0, _0803D920 @ =0x03000440
	adds r0, #0x84
	strb r5, [r0]
	ldr r1, _0803D924 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803D89C: .4byte 0x05000200
_0803D8A0: .4byte 0x01000080
_0803D8A4: .4byte 0x0000E0FF
_0803D8A8: .4byte 0x04000008
_0803D8AC: .4byte 0x0400000A
_0803D8B0: .4byte 0x00001801
_0803D8B4: .4byte 0x0400000C
_0803D8B8: .4byte 0x0000590A
_0803D8BC: .4byte 0x00005B0B
_0803D8C0: .4byte 0x084E6C9C
_0803D8C4: .4byte 0x06004000
_0803D8C8: .4byte 0x084C48B4
_0803D8CC: .4byte 0x06006000
_0803D8D0: .4byte 0x084C4A34
_0803D8D4: .4byte 0x06006200
_0803D8D8: .4byte 0x084C6A98
_0803D8DC: .4byte 0x06017400
_0803D8E0: .4byte 0x084EFA34
_0803D8E4: .4byte 0x084F29E0
_0803D8E8: .4byte 0x0202FA00
_0803D8EC: .4byte 0x084C69D8
_0803D8F0: .4byte 0x0202FB00
_0803D8F4: .4byte 0x084C69F8
_0803D8F8: .4byte 0x0202FB20
_0803D8FC: .4byte 0x0850DEF8
_0803D900: .4byte 0x0202F800
_0803D904: .4byte 0x0850DE58
_0803D908: .4byte 0x0202F980
_0803D90C: .4byte 0xFFFFFEA0
_0803D910: .4byte 0x0202F9A0
_0803D914: .4byte 0x03001800
_0803D918: .4byte 0x03002C30
_0803D91C: .4byte 0x01000800
_0803D920: .4byte 0x03000440
_0803D924: .4byte 0x0300137C
	.syntax divided
