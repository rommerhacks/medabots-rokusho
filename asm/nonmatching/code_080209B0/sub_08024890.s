	.syntax unified

	thumb_func_start sub_08024890
sub_08024890: @ 0x08024890
	push {r4, r5, r6, lr}
	ldr r0, _0802491C @ =0x084CC9A8
	ldr r1, _08024920 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08024924 @ =0x0850E338
	ldr r1, _08024928 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _0802492C @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r3, #0
	ldr r0, _08024930 @ =0x0000C004
	strh r0, [r1]
	ldr r1, _08024934 @ =0x0000085C
	adds r0, r2, r1
	strb r3, [r0]
	ldr r5, _08024938 @ =0x03001800
	adds r4, r5, #0
	adds r4, #0x88
	ldrb r1, [r4]
	lsls r1, r1, #2
	adds r3, r5, #0
	adds r3, #0xd0
	ldrb r0, [r3]
	adds r0, #0x5a
	adds r1, r1, r0
	lsls r1, r1, #6
	adds r1, r1, r2
	ldrh r1, [r1, #2]
	ldr r6, _0802493C @ =0x00000842
	adds r0, r2, r6
	strh r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #2
	ldrb r1, [r3]
	adds r1, #0x5a
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r0, r0, r2
	ldrh r1, [r0, #4]
	ldr r3, _08024940 @ =0x00000844
	adds r0, r2, r3
	strh r1, [r0]
	adds r6, #8
	adds r1, r2, r6
	movs r0, #7
	strb r0, [r1]
	ldr r0, _08024944 @ =0x0000084B
	adds r2, r2, r0
	movs r0, #0xf0
	strb r0, [r2]
	ldr r0, _08024948 @ =0x083B5F80
	adds r0, #0x88
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	adds r1, r5, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802491C: .4byte 0x084CC9A8
_08024920: .4byte 0x06014800
_08024924: .4byte 0x0850E338
_08024928: .4byte 0x050002E0
_0802492C: .4byte 0x03002C30
_08024930: .4byte 0x0000C004
_08024934: .4byte 0x0000085C
_08024938: .4byte 0x03001800
_0802493C: .4byte 0x00000842
_08024940: .4byte 0x00000844
_08024944: .4byte 0x0000084B
_08024948: .4byte 0x083B5F80
	.syntax divided
