	.syntax unified

	thumb_func_start sub_080027DC
sub_080027DC: @ 0x080027DC
	push {r4, r5, lr}
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xfb
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #8
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0800285C @ =0x084C1608
	ldr r1, _08002860 @ =0x06001800
	bl lz_decompress_dispatch
	ldr r0, _08002864 @ =0x084C17F0
	ldr r1, _08002868 @ =0x06001B00
	bl lz_decompress_dispatch
	ldr r0, _0800286C @ =0x084C1934
	ldr r1, _08002870 @ =0x06001E00
	bl lz_decompress_dispatch
	ldr r0, _08002874 @ =0x084C1ACC
	ldr r1, _08002878 @ =0x06002100
	bl lz_decompress_dispatch
	ldr r0, _0800287C @ =0x08487708
	ldr r1, _08002880 @ =0x06002400
	bl lz_decompress_dispatch
	ldr r4, _08002884 @ =0x040000D4
	ldr r0, _08002888 @ =0x08488A84
	str r0, [r4]
	ldr r0, _0800288C @ =0x050001E0
	str r0, [r4, #4]
	ldr r5, _08002890 @ =0x80000010
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08002894 @ =0x084C6A98
	ldr r1, _08002898 @ =0x06017400
	bl lz_decompress_dispatch
	ldr r0, _0800289C @ =0x084E2E38
	str r0, [r4]
	ldr r0, _080028A0 @ =0x050003E0
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	movs r0, #6
	bl play_song
	ldr r0, _080028A4 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _080028A8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800285C: .4byte 0x084C1608
_08002860: .4byte 0x06001800
_08002864: .4byte 0x084C17F0
_08002868: .4byte 0x06001B00
_0800286C: .4byte 0x084C1934
_08002870: .4byte 0x06001E00
_08002874: .4byte 0x084C1ACC
_08002878: .4byte 0x06002100
_0800287C: .4byte 0x08487708
_08002880: .4byte 0x06002400
_08002884: .4byte 0x040000D4
_08002888: .4byte 0x08488A84
_0800288C: .4byte 0x050001E0
_08002890: .4byte 0x80000010
_08002894: .4byte 0x084C6A98
_08002898: .4byte 0x06017400
_0800289C: .4byte 0x084E2E38
_080028A0: .4byte 0x050003E0
_080028A4: .4byte 0x03000440
_080028A8: .4byte 0x0300137C
	.syntax divided
