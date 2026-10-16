	.syntax unified

	thumb_func_start sub_0801FEE8
sub_0801FEE8: @ 0x0801FEE8
	push {r4, r5, lr}
	ldr r0, _0801FF6C @ =0x084CC9A8
	ldr r1, _0801FF70 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0801FF74 @ =0x0850E338
	ldr r1, _0801FF78 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _0801FF7C @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r3, #0
	ldr r0, _0801FF80 @ =0x0000C004
	strh r0, [r1]
	ldr r1, _0801FF84 @ =0x0000085C
	adds r0, r2, r1
	strb r3, [r0]
	ldr r4, _0801FF88 @ =0x03001800
	adds r3, r4, #0
	adds r3, #0x51
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r5, #0xba
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	ldr r5, _0801FF8C @ =0x00000842
	adds r0, r2, r5
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r3, _0801FF90 @ =0x00000844
	adds r1, r2, r3
	strh r0, [r1]
	adds r5, #8
	adds r1, r2, r5
	movs r0, #7
	strb r0, [r1]
	ldr r0, _0801FF94 @ =0x0000084B
	adds r2, r2, r0
	movs r0, #0xf0
	strb r0, [r2]
	ldr r0, _0801FF98 @ =0x083B5F80
	adds r0, #0x88
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801FF6C: .4byte 0x084CC9A8
_0801FF70: .4byte 0x06014800
_0801FF74: .4byte 0x0850E338
_0801FF78: .4byte 0x050002E0
_0801FF7C: .4byte 0x03002C30
_0801FF80: .4byte 0x0000C004
_0801FF84: .4byte 0x0000085C
_0801FF88: .4byte 0x03001800
_0801FF8C: .4byte 0x00000842
_0801FF90: .4byte 0x00000844
_0801FF94: .4byte 0x0000084B
_0801FF98: .4byte 0x083B5F80
	.syntax divided
