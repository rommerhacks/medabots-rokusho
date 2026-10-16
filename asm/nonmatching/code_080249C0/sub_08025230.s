	.syntax unified

	thumb_func_start sub_08025230
sub_08025230: @ 0x08025230
	push {r4, r5, r6, lr}
	ldr r0, _080252D8 @ =0x084D6AAC
	ldr r1, _080252DC @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _080252E0 @ =0x0850E8B8
	ldr r1, _080252E4 @ =0x050002C0
	movs r2, #0x10
	bl CpuFastSet
	ldr r2, _080252E8 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r2, r0
	ldrh r3, [r1]
	movs r4, #0x88
	lsls r4, r4, #2
	adds r0, r4, #0
	movs r5, #0
	movs r4, #0
	orrs r0, r3
	strh r0, [r1]
	ldr r6, _080252EC @ =0x00000848
	adds r0, r2, r6
	movs r1, #0x40
	strb r1, [r0]
	ldr r3, _080252F0 @ =0x00000849
	adds r0, r2, r3
	strb r1, [r0]
	adds r6, #0x10
	adds r0, r2, r6
	strh r4, [r0]
	ldr r0, _080252F4 @ =0x0000084A
	adds r1, r2, r0
	movs r0, #6
	strb r0, [r1]
	subs r3, #3
	adds r1, r2, r3
	movs r0, #0xa0
	lsls r0, r0, #7
	strh r0, [r1]
	ldr r3, _080252F8 @ =0x03001800
	adds r4, r3, #0
	adds r4, #0x88
	ldrb r0, [r4]
	lsls r0, r0, #8
	movs r6, #0xba
	lsls r6, r6, #5
	adds r0, r0, r6
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	movs r6, #0x87
	lsls r6, r6, #4
	adds r0, r2, r6
	strh r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r4, _080252FC @ =0x00000872
	adds r1, r2, r4
	strh r0, [r1]
	subs r6, #0xc
	adds r1, r2, r6
	movs r0, #3
	strb r0, [r1]
	ldr r0, _08025300 @ =0x00000863
	adds r2, r2, r0
	strb r5, [r2]
	ldr r0, _08025304 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	adds r3, #0xaa
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080252D8: .4byte 0x084D6AAC
_080252DC: .4byte 0x06014800
_080252E0: .4byte 0x0850E8B8
_080252E4: .4byte 0x050002C0
_080252E8: .4byte 0x03002C30
_080252EC: .4byte 0x00000848
_080252F0: .4byte 0x00000849
_080252F4: .4byte 0x0000084A
_080252F8: .4byte 0x03001800
_080252FC: .4byte 0x00000872
_08025300: .4byte 0x00000863
_08025304: .4byte 0x03000440
	.syntax divided
