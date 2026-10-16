	.syntax unified

	thumb_func_start sub_08020628
sub_08020628: @ 0x08020628
	push {r4, r5, lr}
	ldr r0, _080206B8 @ =0x084CC9A8
	ldr r1, _080206BC @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _080206C0 @ =0x0850E338
	ldr r1, _080206C4 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _080206C8 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r3, #0
	ldr r0, _080206CC @ =0x0000C004
	strh r0, [r1]
	ldr r1, _080206D0 @ =0x0000085C
	adds r0, r2, r1
	strb r3, [r0]
	ldr r4, _080206D4 @ =0x03001800
	movs r3, #0x87
	adds r3, r3, r4
	mov ip, r3
	ldrb r1, [r3]
	lsls r1, r1, #2
	adds r3, r4, #0
	adds r3, #0xa7
	ldrb r0, [r3]
	adds r0, #0x5a
	adds r1, r1, r0
	lsls r1, r1, #6
	adds r1, r1, r2
	ldrh r1, [r1, #2]
	ldr r5, _080206D8 @ =0x00000842
	adds r0, r2, r5
	strh r1, [r0]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #2
	ldrb r1, [r3]
	adds r1, #0x5a
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r0, r0, r2
	ldrh r1, [r0, #4]
	ldr r3, _080206DC @ =0x00000844
	adds r0, r2, r3
	strh r1, [r0]
	adds r5, #8
	adds r1, r2, r5
	movs r0, #7
	strb r0, [r1]
	ldr r0, _080206E0 @ =0x0000084B
	adds r2, r2, r0
	movs r0, #0xf0
	strb r0, [r2]
	ldr r0, _080206E4 @ =0x083B5F80
	adds r0, #0x88
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080206B8: .4byte 0x084CC9A8
_080206BC: .4byte 0x06014800
_080206C0: .4byte 0x0850E338
_080206C4: .4byte 0x050002E0
_080206C8: .4byte 0x03002C30
_080206CC: .4byte 0x0000C004
_080206D0: .4byte 0x0000085C
_080206D4: .4byte 0x03001800
_080206D8: .4byte 0x00000842
_080206DC: .4byte 0x00000844
_080206E0: .4byte 0x0000084B
_080206E4: .4byte 0x083B5F80
	.syntax divided
