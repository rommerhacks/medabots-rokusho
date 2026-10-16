	.syntax unified

	thumb_func_start sub_08029E34
sub_08029E34: @ 0x08029E34
	push {r4, r5, lr}
	ldr r0, _08029EE4 @ =0x084DDEA4
	ldr r1, _08029EE8 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08029EEC @ =0x0850ECF8
	ldr r1, _08029EF0 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08029EF4 @ =0x084E30B8
	ldr r1, _08029EF8 @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	ldr r4, _08029EFC @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r3, #0
	movs r2, #0
	ldr r0, _08029F00 @ =0x0000C604
	strh r0, [r1]
	ldr r1, _08029F04 @ =0x0000085C
	adds r0, r4, r1
	strb r3, [r0]
	ldr r5, _08029F08 @ =0x00000844
	adds r1, r4, r5
	movs r0, #0xe0
	strh r0, [r1]
	ldr r0, _08029F0C @ =0x0000084A
	adds r1, r4, r0
	movs r0, #7
	strb r0, [r1]
	adds r5, #7
	adds r1, r4, r5
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, _08029F10 @ =0x00000848
	adds r0, r4, r1
	movs r1, #0x40
	strb r1, [r0]
	subs r5, #2
	adds r0, r4, r5
	strb r1, [r0]
	ldr r1, _08029F14 @ =0x00000858
	adds r0, r4, r1
	strh r2, [r0]
	adds r5, #0x1f
	adds r0, r4, r5
	strb r3, [r0]
	adds r1, #0x16
	adds r0, r4, r1
	movs r2, #0x5c
	strb r2, [r0]
	adds r5, #1
	adds r1, r4, r5
	movs r0, #6
	strb r0, [r1]
	ldr r0, _08029F18 @ =0x0000086B
	adds r1, r4, r0
	movs r0, #0x20
	strb r0, [r1]
	adds r5, #3
	adds r1, r4, r5
	movs r0, #0xc0
	strb r0, [r1]
	ldr r1, _08029F1C @ =0x0000086D
	adds r0, r4, r1
	strb r3, [r0]
	ldr r0, _08029F20 @ =0x083B5F80
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r0, _08029F24 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08029F28
	subs r5, #0x2a
	adds r1, r4, r5
	movs r0, #0xb8
	b _08029F2E
	.align 2, 0
_08029EE4: .4byte 0x084DDEA4
_08029EE8: .4byte 0x06014800
_08029EEC: .4byte 0x0850ECF8
_08029EF0: .4byte 0x050002E0
_08029EF4: .4byte 0x084E30B8
_08029EF8: .4byte 0x050002C0
_08029EFC: .4byte 0x03002C30
_08029F00: .4byte 0x0000C604
_08029F04: .4byte 0x0000085C
_08029F08: .4byte 0x00000844
_08029F0C: .4byte 0x0000084A
_08029F10: .4byte 0x00000848
_08029F14: .4byte 0x00000858
_08029F18: .4byte 0x0000086B
_08029F1C: .4byte 0x0000086D
_08029F20: .4byte 0x083B5F80
_08029F24: .4byte 0x03001800
_08029F28:
	ldr r0, _08029F48 @ =0x00000842
	adds r1, r4, r0
	movs r0, #0x38
_08029F2E:
	strh r0, [r1]
	ldr r1, _08029F4C @ =0x03001800
	adds r2, r1, #0
	adds r2, #0x51
	movs r0, #2
	strb r0, [r2]
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08029F48: .4byte 0x00000842
_08029F4C: .4byte 0x03001800
	.syntax divided
