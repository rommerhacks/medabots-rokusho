	.syntax unified

	thumb_func_start load_battle_background_graphics
load_battle_background_graphics: @ 0x0805F034
	push {r4, r5, r6, r7, lr}
	ldr r1, _0805F198 @ =0x0400000A
	ldr r0, _0805F19C @ =0x00001E05
	strh r0, [r1]
	ldr r4, _0805F1A0 @ =0x0400000C
	subs r0, #0xff
	strh r0, [r4]
	ldr r5, _0805F1A4 @ =0x0400000E
	ldr r0, _0805F1A8 @ =0x00003C07
	strh r0, [r5]
	ldr r0, _0805F1AC @ =0x08791694
	ldrh r1, [r1]
	bl decompress_and_write_tilemap
	ldr r0, _0805F1B0 @ =0x087917F4
	ldrh r1, [r4]
	bl decompress_and_write_tilemap
	ldr r0, _0805F1B4 @ =0x087919C4
	ldrh r1, [r5]
	bl decompress_and_write_tilemap
	ldr r0, _0805F1B8 @ =0x08790600
	ldr r5, _0805F1BC @ =0x02030000
	adds r1, r5, #0
	bl dma3_copy_or_decompress
	adds r4, r0, #0
	ldr r1, _0805F1C0 @ =0x06004000
	lsls r2, r4, #0xa
	lsrs r2, r2, #0xb
	adds r0, r5, #0
	bl CpuSet
	ldr r0, _0805F1C4 @ =0x08784CB0
	ldr r2, _0805F1C0 @ =0x06004000
	adds r1, r4, r2
	bl lz_decompress_dispatch
	ldr r5, _0805F1C8 @ =0x03006F74
	ldr r0, [r5]
	lsrs r4, r4, #5
	subs r4, #1
	movs r6, #0
	strh r4, [r0, #0x36]
	ldr r0, _0805F1CC @ =0x08790400
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x80
	bl CpuFastSet
	ldr r0, _0805F1D0 @ =0x08483AA0
	ldr r1, _0805F1D4 @ =0x050001C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0805F1D8 @ =0x08784DA4
	ldr r1, _0805F1DC @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0805F1E0 @ =0x084E2E58
	ldr r1, _0805F1E4 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _0805F1E8 @ =0x03002C30
	movs r2, #0x80
	lsls r2, r2, #8
	strh r2, [r1]
	movs r0, #2
	strb r0, [r1, #0x1c]
	movs r0, #0xe
	strb r0, [r1, #0xa]
	movs r0, #6
	strh r0, [r1, #6]
	ldr r0, [r5]
	strb r6, [r0, #5]
	movs r0, #0x14
	strh r0, [r1, #2]
	ldr r0, [r5]
	ldrb r0, [r0, #5]
	lsls r0, r0, #4
	adds r0, #0x20
	strh r0, [r1, #4]
	movs r3, #0
	adds r5, r1, #0
	mov ip, r2
	movs r7, #2
	movs r2, #0xe
	adds r4, r5, #0
	movs r6, #5
_0805F0EA:
	adds r1, r3, #1
	lsls r0, r1, #6
	adds r0, r0, r5
	mov r3, ip
	strh r3, [r0]
	strb r7, [r0, #0x1c]
	strb r2, [r0, #0xa]
	strh r6, [r0, #6]
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	cmp r3, #1
	bls _0805F0EA
	adds r2, r4, #0
	adds r2, #0x40
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	adds r1, r4, #0
	adds r1, #0x42
	movs r0, #0x78
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x44
	movs r1, #0x20
	strh r1, [r0]
	adds r2, #0x42
	movs r0, #0x90
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0x84
	strh r1, [r0]
	movs r3, #0
	ldr r0, _0805F1EC @ =0x0300137C
	mov ip, r0
	adds r1, r4, #0
	movs r7, #0x80
	lsls r7, r7, #8
	movs r6, #2
	movs r5, #0xe
	movs r2, #5
_0805F140:
	adds r0, r3, #3
	lsls r0, r0, #6
	adds r0, r0, r1
	strh r7, [r0]
	strb r6, [r0, #0x1c]
	strb r5, [r0, #0xa]
	strh r2, [r0, #6]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bls _0805F140
	adds r2, r4, #0
	adds r2, #0xc0
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	adds r1, r4, #0
	adds r1, #0xc2
	movs r0, #0x78
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc4
	movs r1, #0x30
	strh r1, [r0]
	movs r0, #0x81
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r0, #0x90
	strh r0, [r2]
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	mov r3, ip
	ldr r0, [r3]
	adds r0, #1
	str r0, [r3]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805F198: .4byte 0x0400000A
_0805F19C: .4byte 0x00001E05
_0805F1A0: .4byte 0x0400000C
_0805F1A4: .4byte 0x0400000E
_0805F1A8: .4byte 0x00003C07
_0805F1AC: .4byte 0x08791694
_0805F1B0: .4byte 0x087917F4
_0805F1B4: .4byte 0x087919C4
_0805F1B8: .4byte 0x08790600
_0805F1BC: .4byte 0x02030000
_0805F1C0: .4byte 0x06004000
_0805F1C4: .4byte 0x08784CB0
_0805F1C8: .4byte 0x03006F74
_0805F1CC: .4byte 0x08790400
_0805F1D0: .4byte 0x08483AA0
_0805F1D4: .4byte 0x050001C0
_0805F1D8: .4byte 0x08784DA4
_0805F1DC: .4byte 0x06010000
_0805F1E0: .4byte 0x084E2E58
_0805F1E4: .4byte 0x050003C0
_0805F1E8: .4byte 0x03002C30
_0805F1EC: .4byte 0x0300137C
	.syntax divided
