	.syntax unified

	thumb_func_start battle_phase_dispatch_0801387C
battle_phase_dispatch_0801387C: @ 0x0801387C
	push {r4, r5, lr}
	sub sp, #4
	ldr r1, _0801389C @ =0x03000440
	ldr r2, _080138A0 @ =0x00000139
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r4, r1, #0
	cmp r0, #5
	bls _08013890
	b _08013A50
_08013890:
	lsls r0, r0, #2
	ldr r1, _080138A4 @ =_080138A8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801389C: .4byte 0x03000440
_080138A0: .4byte 0x00000139
_080138A4: .4byte _080138A8
_080138A8: @ jump table
	.4byte _080138C0 @ case 0
	.4byte _0801393C @ case 1
	.4byte _08013968 @ case 2
	.4byte _080139B4 @ case 3
	.4byte _080139F0 @ case 4
	.4byte _08013A2C @ case 5
_080138C0:
	adds r0, r4, #0
	adds r0, #0x96
	movs r5, #0
	strb r5, [r0]
	ldr r0, _08013920 @ =0x03000430
	str r5, [r0]
	bl sub_08043CA8
	bl load_battle_script_entry_b
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _08013924 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08013928 @ =0x04000008
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _0801392C @ =0x00001901
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _08013930 @ =0x00001A0A
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _08013934 @ =0x00001B0B
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #0
	bl battle_phase_dispatch_0801A788
	cmp r0, #0
	bne _0801390E
	b _08013A50
_0801390E:
	adds r0, r4, #0
	adds r0, #0x84
	strb r5, [r0]
	ldr r3, _08013938 @ =0x00000139
	adds r1, r4, r3
	ldrb r0, [r1]
	adds r0, #1
	b _08013A4E
	.align 2, 0
_08013920: .4byte 0x03000430
_08013924: .4byte 0x0000F0FF
_08013928: .4byte 0x04000008
_0801392C: .4byte 0x00001901
_08013930: .4byte 0x00001A0A
_08013934: .4byte 0x00001B0B
_08013938: .4byte 0x00000139
_0801393C:
	movs r0, #0
	str r0, [sp]
	ldr r1, _08013958 @ =0x03002C30
	ldr r2, _0801395C @ =0x01000800
	mov r0, sp
	bl CpuFastSet
	ldr r0, _08013960 @ =0x03000440
	ldr r2, _08013964 @ =0x00000139
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #1
	b _08013A4E
	.align 2, 0
_08013958: .4byte 0x03002C30
_0801395C: .4byte 0x01000800
_08013960: .4byte 0x03000440
_08013964: .4byte 0x00000139
_08013968:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0xfa
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	bl load_all_bot_part_sprites
	bl apply_battle_blend_effect_b
	ldr r2, _080139A4 @ =0x083B24A8
	ldr r0, _080139A8 @ =0x03001800
	adds r0, #0x38
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl decompress_to_ewram_27000
	ldr r0, _080139AC @ =0x03000440
	ldr r2, _080139B0 @ =0x00000139
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #1
	b _08013A4E
	.align 2, 0
_080139A4: .4byte 0x083B24A8
_080139A8: .4byte 0x03001800
_080139AC: .4byte 0x03000440
_080139B0: .4byte 0x00000139
_080139B4:
	ldr r0, _080139D8 @ =0x02020800
	ldr r1, _080139DC @ =0x06002800
	movs r4, #0x80
	lsls r4, r4, #2
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _080139E0 @ =0x02021000
	ldr r1, _080139E4 @ =0x0600C800
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _080139E8 @ =0x03000440
	ldr r3, _080139EC @ =0x00000139
	adds r1, r0, r3
	ldrb r0, [r1]
	adds r0, #1
	b _08013A4E
	.align 2, 0
_080139D8: .4byte 0x02020800
_080139DC: .4byte 0x06002800
_080139E0: .4byte 0x02021000
_080139E4: .4byte 0x0600C800
_080139E8: .4byte 0x03000440
_080139EC: .4byte 0x00000139
_080139F0:
	ldr r0, _08013A14 @ =0x02021800
	ldr r1, _08013A18 @ =0x0600D000
	movs r4, #0x80
	lsls r4, r4, #2
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _08013A1C @ =0x02022000
	ldr r1, _08013A20 @ =0x0600D800
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _08013A24 @ =0x03000440
	ldr r2, _08013A28 @ =0x00000139
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #1
	b _08013A4E
	.align 2, 0
_08013A14: .4byte 0x02021800
_08013A18: .4byte 0x0600D000
_08013A1C: .4byte 0x02022000
_08013A20: .4byte 0x0600D800
_08013A24: .4byte 0x03000440
_08013A28: .4byte 0x00000139
_08013A2C:
	ldr r0, _08013A58 @ =0x02028000
	ldr r1, _08013A5C @ =0x03002C30
	movs r2, #0x80
	lsls r2, r2, #4
	bl CpuFastSet
	ldr r1, _08013A60 @ =0x030017F0
	ldr r0, _08013A64 @ =sub_08044100
	str r0, [r1]
	ldr r1, _08013A68 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, _08013A6C @ =0x03000440
	ldr r3, _08013A70 @ =0x00000139
	adds r1, r0, r3
	movs r0, #0
_08013A4E:
	strb r0, [r1]
_08013A50:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08013A58: .4byte 0x02028000
_08013A5C: .4byte 0x03002C30
_08013A60: .4byte 0x030017F0
_08013A64: .4byte sub_08044100
_08013A68: .4byte 0x0300137C
_08013A6C: .4byte 0x03000440
_08013A70: .4byte 0x00000139
	.syntax divided
