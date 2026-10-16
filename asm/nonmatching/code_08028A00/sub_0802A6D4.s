	.syntax unified

	thumb_func_start sub_0802A6D4
sub_0802A6D4: @ 0x0802A6D4
	push {r4, r5, r6, r7, lr}
	ldr r0, _0802A76C @ =0x084DED1C
	ldr r1, _0802A770 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802A774 @ =0x0850ED58
	ldr r1, _0802A778 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0802A77C @ =0x084E30B8
	ldr r1, _0802A780 @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	ldr r5, _0802A784 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r6, r5, r0
	movs r7, #0
	movs r2, #0
	ldr r0, _0802A788 @ =0x0000C604
	strh r0, [r6]
	ldr r1, _0802A78C @ =0x0000085C
	adds r0, r5, r1
	strb r7, [r0]
	ldr r4, _0802A790 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	movs r3, #0xba
	lsls r3, r3, #5
	adds r0, r0, r3
	adds r0, r0, r5
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r3, _0802A794 @ =0x00000844
	adds r1, r5, r3
	strh r0, [r1]
	ldr r0, _0802A798 @ =0x0000084A
	adds r1, r5, r0
	movs r0, #7
	strb r0, [r1]
	adds r3, #7
	adds r1, r5, r3
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, _0802A79C @ =0x00000848
	adds r0, r5, r1
	movs r1, #4
	strb r1, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _0802A7A0 @ =0x00000858
	adds r0, r5, r1
	strh r2, [r0]
	ldr r0, _0802A7A4 @ =0x083B5F80
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	adds r4, #0xf8
	ldrb r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0802A7AC
	ldr r3, _0802A7A8 @ =0x00000842
	adds r1, r5, r3
	movs r0, #0x70
	b _0802A7BE
	.align 2, 0
_0802A76C: .4byte 0x084DED1C
_0802A770: .4byte 0x06014800
_0802A774: .4byte 0x0850ED58
_0802A778: .4byte 0x050002E0
_0802A77C: .4byte 0x084E30B8
_0802A780: .4byte 0x050002C0
_0802A784: .4byte 0x03002C30
_0802A788: .4byte 0x0000C604
_0802A78C: .4byte 0x0000085C
_0802A790: .4byte 0x03001800
_0802A794: .4byte 0x00000844
_0802A798: .4byte 0x0000084A
_0802A79C: .4byte 0x00000848
_0802A7A0: .4byte 0x00000858
_0802A7A4: .4byte 0x083B5F80
_0802A7A8: .4byte 0x00000842
_0802A7AC:
	ldrh r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r6]
	ldr r3, _0802A7D8 @ =0x00000842
	adds r1, r5, r3
	movs r0, #0x80
_0802A7BE:
	strh r0, [r1]
	movs r0, #0x6a
	bl play_sound_effect
	ldr r1, _0802A7DC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802A7D8: .4byte 0x00000842
_0802A7DC: .4byte 0x03001800
_0802A7E0:
	.byte 0x07, 0x49, 0x08, 0x48, 0x0A, 0x18, 0x10, 0x78, 0x40, 0x28, 0x11, 0xD1, 0x06, 0x48, 0x86, 0x30
	.byte 0x3C, 0x21, 0x01, 0x80, 0x05, 0x49, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30, 0x0E, 0xE0, 0x00, 0x00
	.byte 0x30, 0x2C, 0x00, 0x03, 0x48, 0x08, 0x00, 0x00, 0x40, 0x04, 0x00, 0x03, 0x00, 0x18, 0x00, 0x03
	.byte 0x04, 0x30, 0x10, 0x70, 0x02, 0x48, 0x09, 0x18, 0x08, 0x78, 0x04, 0x30, 0x08, 0x70, 0x70, 0x47
	.byte 0x49, 0x08, 0x00, 0x00
	.syntax divided
