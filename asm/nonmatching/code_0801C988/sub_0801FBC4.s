	.syntax unified

	thumb_func_start sub_0801FBC4
sub_0801FBC4: @ 0x0801FBC4
	push {r4, r5, lr}
	ldr r1, _0801FBE0 @ =0x03000440
	ldr r2, _0801FBE4 @ =0x00000139
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r4, r1, #0
	cmp r0, #4
	bls _0801FBD6
	b _0801FD6C
_0801FBD6:
	lsls r0, r0, #2
	ldr r1, _0801FBE8 @ =_0801FBEC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801FBE0: .4byte 0x03000440
_0801FBE4: .4byte 0x00000139
_0801FBE8: .4byte _0801FBEC
_0801FBEC: @ jump table
	.4byte _0801FC00 @ case 0
	.4byte _0801FC78 @ case 1
	.4byte _0801FCC4 @ case 2
	.4byte _0801FD10 @ case 3
	.4byte _0801FD3C @ case 4
_0801FC00:
	adds r0, r4, #0
	adds r0, #0x96
	movs r5, #0
	strb r5, [r0]
	ldr r0, _0801FC5C @ =0x03000430
	str r5, [r0]
	bl sub_08043CA8
	bl load_battle_script_entry_b
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0801FC60 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0801FC64 @ =0x04000008
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _0801FC68 @ =0x00001901
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _0801FC6C @ =0x00001A0A
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _0801FC70 @ =0x00001B0B
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #1
	bl battle_phase_dispatch_0801A788
	cmp r0, #0
	bne _0801FC4E
	b _0801FD6C
_0801FC4E:
	adds r0, r4, #0
	adds r0, #0x84
	strb r5, [r0]
	ldr r3, _0801FC74 @ =0x00000139
	adds r1, r4, r3
	b _0801FD22
	.align 2, 0
_0801FC5C: .4byte 0x03000430
_0801FC60: .4byte 0x0000F0FF
_0801FC64: .4byte 0x04000008
_0801FC68: .4byte 0x00001901
_0801FC6C: .4byte 0x00001A0A
_0801FC70: .4byte 0x00001B0B
_0801FC74: .4byte 0x00000139
_0801FC78:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r4, #0xfa
	lsls r4, r4, #5
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	bl load_all_bot_part_sprites
	bl iterate_bots_setup_battle_sprites
	bl apply_battle_blend_effect_b
	ldr r2, _0801FCB4 @ =0x083B24A8
	ldr r0, _0801FCB8 @ =0x03001800
	adds r0, #0x38
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl decompress_to_ewram_27000
	ldr r0, _0801FCBC @ =0x03000440
	ldr r2, _0801FCC0 @ =0x00000139
	adds r1, r0, r2
	b _0801FD22
	.align 2, 0
_0801FCB4: .4byte 0x083B24A8
_0801FCB8: .4byte 0x03001800
_0801FCBC: .4byte 0x03000440
_0801FCC0: .4byte 0x00000139
_0801FCC4:
	ldr r0, _0801FCF0 @ =0x02021000
	ldr r1, _0801FCF4 @ =0x0600C800
	movs r4, #0x80
	lsls r4, r4, #2
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _0801FCF8 @ =0x02021800
	ldr r1, _0801FCFC @ =0x0600D000
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _0801FD00 @ =0x02022000
	ldr r1, _0801FD04 @ =0x0600D800
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _0801FD08 @ =0x03000440
	ldr r3, _0801FD0C @ =0x00000139
	adds r1, r0, r3
	b _0801FD22
	.align 2, 0
_0801FCF0: .4byte 0x02021000
_0801FCF4: .4byte 0x0600C800
_0801FCF8: .4byte 0x02021800
_0801FCFC: .4byte 0x0600D000
_0801FD00: .4byte 0x02022000
_0801FD04: .4byte 0x0600D800
_0801FD08: .4byte 0x03000440
_0801FD0C: .4byte 0x00000139
_0801FD10:
	ldr r0, _0801FD2C @ =0x02028000
	ldr r1, _0801FD30 @ =0x03002C30
	movs r2, #0x80
	lsls r2, r2, #4
	bl CpuFastSet
	ldr r0, _0801FD34 @ =0x03000440
	ldr r4, _0801FD38 @ =0x00000139
	adds r1, r0, r4
_0801FD22:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0801FD6C
	.align 2, 0
_0801FD2C: .4byte 0x02028000
_0801FD30: .4byte 0x03002C30
_0801FD34: .4byte 0x03000440
_0801FD38: .4byte 0x00000139
_0801FD3C:
	bl load_all_bot_part_sprites
	bl iterate_bots_setup_battle_sprites
	ldr r1, _0801FD74 @ =0x030017F0
	ldr r0, _0801FD78 @ =sub_08044100
	str r0, [r1]
	ldr r3, _0801FD7C @ =0x03000440
	adds r0, r3, #0
	adds r0, #0x84
	movs r2, #0
	strb r2, [r0]
	ldr r1, _0801FD80 @ =0x03001800
	movs r4, #0xd7
	lsls r4, r4, #1
	adds r0, r1, r4
	strb r2, [r0]
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, _0801FD84 @ =0x00000139
	adds r0, r3, r1
	strb r2, [r0]
_0801FD6C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801FD74: .4byte 0x030017F0
_0801FD78: .4byte sub_08044100
_0801FD7C: .4byte 0x03000440
_0801FD80: .4byte 0x03001800
_0801FD84: .4byte 0x00000139
	.syntax divided
