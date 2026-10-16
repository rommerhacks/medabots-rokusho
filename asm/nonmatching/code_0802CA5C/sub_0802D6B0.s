	.syntax unified

	thumb_func_start sub_0802D6B0
sub_0802D6B0: @ 0x0802D6B0
	push {lr}
	ldr r0, _0802D724 @ =0x084E0360
	ldr r1, _0802D728 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802D72C @ =0x0850EE98
	ldr r1, _0802D730 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _0802D734 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r2, r1, r0
	movs r3, #0
	ldr r0, _0802D738 @ =0x0000C604
	strh r0, [r2]
	ldr r2, _0802D73C @ =0x0000085C
	adds r0, r1, r2
	strb r3, [r0]
	ldr r3, _0802D740 @ =0x00000842
	adds r2, r1, r3
	movs r0, #0x78
	strh r0, [r2]
	ldr r0, _0802D744 @ =0x00000844
	adds r2, r1, r0
	movs r0, #0x40
	strh r0, [r2]
	ldr r2, _0802D748 @ =0x00000848
	adds r0, r1, r2
	movs r2, #4
	strb r2, [r0]
	adds r3, #7
	adds r0, r1, r3
	strb r2, [r0]
	ldr r0, _0802D74C @ =0x0000084A
	adds r2, r1, r0
	movs r0, #7
	strb r0, [r2]
	adds r3, #2
	adds r2, r1, r3
	movs r0, #0xf0
	strb r0, [r2]
	ldr r0, _0802D750 @ =0x00000846
	adds r1, r1, r0
	movs r0, #0xfc
	lsls r0, r0, #7
	strh r0, [r1]
	movs r0, #0x6e
	bl play_sound_effect
	ldr r1, _0802D754 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0802D724: .4byte 0x084E0360
_0802D728: .4byte 0x06014800
_0802D72C: .4byte 0x0850EE98
_0802D730: .4byte 0x050002E0
_0802D734: .4byte 0x03002C30
_0802D738: .4byte 0x0000C604
_0802D73C: .4byte 0x0000085C
_0802D740: .4byte 0x00000842
_0802D744: .4byte 0x00000844
_0802D748: .4byte 0x00000848
_0802D74C: .4byte 0x0000084A
_0802D750: .4byte 0x00000846
_0802D754: .4byte 0x03001800
	.syntax divided
