	.syntax unified

	thumb_func_start sub_08011764
sub_08011764: @ 0x08011764
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	bl sub_08043CA8
	movs r0, #0x80
	lsls r0, r0, #0x13
	mov sl, r0
	ldrh r1, [r0]
	ldr r0, _08011970 @ =0x0000E0FF
	ands r0, r1
	mov r1, sl
	strh r0, [r1]
	ldr r2, _08011974 @ =0x04000008
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r0, r3, #0
	strh r0, [r2]
	ldr r4, _08011978 @ =0x0400000A
	ldr r1, _0801197C @ =0x00001801
	adds r0, r1, #0
	strh r0, [r4]
	ldr r1, _08011980 @ =0x0400000C
	ldr r3, _08011984 @ =0x0000590A
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _08011988 @ =0x00005B0B
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldrh r0, [r4]
	str r0, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r0, _0801198C @ =0x084E6C9C
	ldr r1, _08011990 @ =0x06004000
	bl lz_decompress_dispatch
	ldr r0, _08011994 @ =0x084C48B4
	ldr r1, _08011998 @ =0x06006000
	bl lz_decompress_dispatch
	ldr r0, _0801199C @ =0x084C4A34
	ldr r1, _080119A0 @ =0x06006200
	bl lz_decompress_dispatch
	ldr r0, _080119A4 @ =0x084C7D10
	ldr r1, _080119A8 @ =0x06012800
	bl lz_decompress_dispatch
	ldr r0, _080119AC @ =0x084C6A98
	ldr r1, _080119B0 @ =0x06017400
	bl lz_decompress_dispatch
	ldr r2, _080119B4 @ =0x084EFA34
	ldrh r3, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	adds r4, #0xca
	ldr r0, _080119B8 @ =0x084F29E0
	str r0, [r4]
	ldr r0, _080119BC @ =0x0202FA00
	str r0, [r4, #4]
	ldr r0, _080119C0 @ =0x84000070
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _080119C4 @ =0x084C69D8
	str r0, [r4]
	ldr r0, _080119C8 @ =0x0202FB00
	str r0, [r4, #4]
	ldr r5, _080119CC @ =0x84000008
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _080119D0 @ =0x084C69F8
	str r0, [r4]
	ldr r0, _080119D4 @ =0x0202FB20
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _080119D8 @ =0x0850DEF8
	str r0, [r4]
	ldr r0, _080119DC @ =0x0202F800
	str r0, [r4, #4]
	ldr r0, _080119E0 @ =0x84000040
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _080119E4 @ =0x0850DE58
	str r1, [r4]
	ldr r0, _080119E8 @ =0x0202F980
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r2, _080119EC @ =0xFFFFFEA0
	adds r1, r1, r2
	str r1, [r4]
	ldr r0, _080119F0 @ =0x0202F9A0
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _080119F4 @ =0x084E2FB8
	str r0, [r4]
	ldr r6, _080119F8 @ =0x0202F940
	str r6, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r3, _080119FC @ =0x084E2F98
	mov sb, r3
	str r3, [r4]
	ldr r0, _08011A00 @ =0x0202F960
	mov r8, r0
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r7, _08011A04 @ =0x03001800
	adds r0, r7, #0
	adds r0, #0x38
	ldrb r0, [r0]
	movs r1, #1
	bl decompress_tileset_to_vram
	ldr r0, _08011A08 @ =0x084D7C9C
	ldr r1, _08011A0C @ =0x06012400
	bl lz_decompress_dispatch
	ldr r0, _08011A10 @ =0x0850E9D8
	str r0, [r4]
	str r6, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08011A14 @ =0x084D7DB0
	ldr r1, _08011A18 @ =0x06016C00
	bl lz_decompress_dispatch
	mov r1, sb
	str r1, [r4]
	mov r2, r8
	str r2, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	movs r3, #0
	str r3, [sp, #8]
	add r0, sp, #8
	str r0, [r4]
	ldr r1, _08011A1C @ =0x03002C30
	str r1, [r4, #4]
	ldr r0, _08011A20 @ =0x85000800
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08011A24 @ =0x02020800
	str r0, [r4]
	ldr r0, _08011A28 @ =0x06002800
	str r0, [r4, #4]
	ldr r0, _08011A2C @ =0x84000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08011A30 @ =0x02021000
	str r0, [r4]
	ldr r0, _08011A34 @ =0x06000280
	str r0, [r4, #4]
	ldr r0, _08011A38 @ =0x84000380
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08011A3C @ =0x02028000
	str r0, [r4]
	str r1, [r4, #4]
	ldr r0, _08011A40 @ =0x84000800
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	mov r1, sl
	ldrh r0, [r1]
	movs r2, #0xfb
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	mov r3, sl
	strh r0, [r3]
	bl sub_08011F50
	bl sub_08011FA0
	bl sub_08011FEC
	bl sub_08012024
	bl sub_080120C8
	bl sub_0801214C
	bl sub_080121A8
	bl apply_battle_blend_effect_a
	bl setup_battle_result_sprite_animation
	ldr r1, _08011A44 @ =0x083C6DE8
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r5, r7, r0
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r4, _08011A48 @ =0x030004DE
	adds r1, r4, #0
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	ldr r1, _08011A4C @ =0x083BB9CC
	ldr r2, _08011A50 @ =0x00000169
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	ldrb r5, [r5]
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0x14
	movs r2, #0xf
	bl memcpy_bytes_0803F63C
	subs r4, #0x1a
	movs r3, #0
	strb r3, [r4]
	ldr r1, _08011A54 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011970: .4byte 0x0000E0FF
_08011974: .4byte 0x04000008
_08011978: .4byte 0x0400000A
_0801197C: .4byte 0x00001801
_08011980: .4byte 0x0400000C
_08011984: .4byte 0x0000590A
_08011988: .4byte 0x00005B0B
_0801198C: .4byte 0x084E6C9C
_08011990: .4byte 0x06004000
_08011994: .4byte 0x084C48B4
_08011998: .4byte 0x06006000
_0801199C: .4byte 0x084C4A34
_080119A0: .4byte 0x06006200
_080119A4: .4byte 0x084C7D10
_080119A8: .4byte 0x06012800
_080119AC: .4byte 0x084C6A98
_080119B0: .4byte 0x06017400
_080119B4: .4byte 0x084EFA34
_080119B8: .4byte 0x084F29E0
_080119BC: .4byte 0x0202FA00
_080119C0: .4byte 0x84000070
_080119C4: .4byte 0x084C69D8
_080119C8: .4byte 0x0202FB00
_080119CC: .4byte 0x84000008
_080119D0: .4byte 0x084C69F8
_080119D4: .4byte 0x0202FB20
_080119D8: .4byte 0x0850DEF8
_080119DC: .4byte 0x0202F800
_080119E0: .4byte 0x84000040
_080119E4: .4byte 0x0850DE58
_080119E8: .4byte 0x0202F980
_080119EC: .4byte 0xFFFFFEA0
_080119F0: .4byte 0x0202F9A0
_080119F4: .4byte 0x084E2FB8
_080119F8: .4byte 0x0202F940
_080119FC: .4byte 0x084E2F98
_08011A00: .4byte 0x0202F960
_08011A04: .4byte 0x03001800
_08011A08: .4byte 0x084D7C9C
_08011A0C: .4byte 0x06012400
_08011A10: .4byte 0x0850E9D8
_08011A14: .4byte 0x084D7DB0
_08011A18: .4byte 0x06016C00
_08011A1C: .4byte 0x03002C30
_08011A20: .4byte 0x85000800
_08011A24: .4byte 0x02020800
_08011A28: .4byte 0x06002800
_08011A2C: .4byte 0x84000200
_08011A30: .4byte 0x02021000
_08011A34: .4byte 0x06000280
_08011A38: .4byte 0x84000380
_08011A3C: .4byte 0x02028000
_08011A40: .4byte 0x84000800
_08011A44: .4byte 0x083C6DE8
_08011A48: .4byte 0x030004DE
_08011A4C: .4byte 0x083BB9CC
_08011A50: .4byte 0x00000169
_08011A54: .4byte 0x0300137C
	.syntax divided
