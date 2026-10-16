	.syntax unified

	thumb_func_start setup_battle_bg_layers
setup_battle_bg_layers: @ 0x080605A0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	movs r5, #1
	ldr r1, _080605E0 @ =0x0400000A
	ldr r0, _080605E4 @ =0x00001E05
	strh r0, [r1]
	ldr r4, _080605E8 @ =0x0400000C
	subs r0, #0xff
	strh r0, [r4]
	ldr r6, _080605EC @ =0x0400000E
	subs r0, #0xff
	strh r0, [r6]
	ldr r0, _080605F0 @ =0x0878A844
	ldrh r1, [r1]
	bl decompress_and_write_tilemap
	ldr r0, _080605F4 @ =0x0878A918
	ldrh r1, [r4]
	bl decompress_and_write_tilemap
	ldr r0, _080605F8 @ =0x0878AA0C
	ldrh r1, [r6]
	bl decompress_and_write_tilemap
	ldr r0, _080605FC @ =0x03002B8C
	ldr r0, [r0]
	cmp r0, #0x17
	bne _08060604
	ldr r0, _08060600 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #1
	b _08060628
	.align 2, 0
_080605E0: .4byte 0x0400000A
_080605E4: .4byte 0x00001E05
_080605E8: .4byte 0x0400000C
_080605EC: .4byte 0x0400000E
_080605F0: .4byte 0x0878A844
_080605F4: .4byte 0x0878A918
_080605F8: .4byte 0x0878AA0C
_080605FC: .4byte 0x03002B8C
_08060600: .4byte 0x03006F74
_08060604:
	ldrh r1, [r6]
	lsrs r1, r1, #8
	movs r2, #0x1f
	ands r1, r2
	lsls r1, r1, #0xb
	ldr r0, _08060640 @ =0x06000248
	adds r1, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #8
	ands r0, r2
	lsls r0, r0, #0xb
	ldr r2, _08060644 @ =0x0600021E
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, _08060648 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0
_08060628:
	strb r0, [r1, #0x18]
	ldr r0, _0806064C @ =0x030057E0
	ldr r1, _08060650 @ =0x00000C32
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08060654
	lsls r7, r5, #0xe
	cmp r0, #1
	beq _08060688
	b _080606B8
	.align 2, 0
_08060640: .4byte 0x06000248
_08060644: .4byte 0x0600021E
_08060648: .4byte 0x03006F74
_0806064C: .4byte 0x030057E0
_08060650: .4byte 0x00000C32
_08060654:
	movs r4, #0
	lsls r7, r5, #0xe
	mov r5, sp
_0806065A:
	movs r0, #0
	strh r0, [r5]
	ldr r0, _080607AC @ =0x0400000C
	ldrh r1, [r0]
	lsrs r1, r1, #8
	movs r0, #0x1f
	ands r1, r0
	lsls r1, r1, #0xb
	adds r0, r4, #0
	adds r0, #0xa
	lsls r0, r0, #6
	ldr r2, _080607B0 @ =0x0600001A
	adds r0, r0, r2
	adds r1, r1, r0
	mov r0, sp
	ldr r2, _080607B4 @ =0x01000005
	bl CpuSet
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #2
	bls _0806065A
_08060688:
	movs r4, #0
	mov r5, sp
_0806068C:
	movs r0, #0
	strh r0, [r5]
	ldr r0, _080607AC @ =0x0400000C
	ldrh r1, [r0]
	lsrs r1, r1, #8
	movs r0, #0x1f
	ands r1, r0
	lsls r1, r1, #0xb
	adds r0, r4, #4
	lsls r0, r0, #6
	ldr r3, _080607B8 @ =0x06000010
	adds r0, r0, r3
	adds r1, r1, r0
	mov r0, sp
	ldr r2, _080607B4 @ =0x01000005
	bl CpuSet
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #2
	bls _0806068C
_080606B8:
	ldr r0, _080607BC @ =0x087877C4
	ldr r6, _080607C0 @ =0x02030000
	adds r1, r6, #0
	bl dma3_copy_or_decompress
	adds r4, r0, #0
	movs r5, #0xc0
	lsls r5, r5, #0x13
	adds r1, r7, r5
	lsls r2, r4, #9
	lsrs r2, r2, #0xb
	adds r0, r6, #0
	bl CpuFastSet
	ldr r0, _080607C4 @ =0x08784CB0
	adds r5, r4, r5
	adds r5, r7, r5
	adds r1, r5, #0
	bl lz_decompress_dispatch
	ldr r5, _080607C8 @ =0x03006F74
	ldr r0, [r5]
	lsrs r4, r4, #5
	subs r4, #1
	movs r6, #0
	strh r4, [r0, #0x36]
	ldr r0, _080607CC @ =0x087871E4
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x70
	bl CpuFastSet
	ldr r0, _080607D0 @ =0x08785F34
	ldr r1, _080607D4 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _080607D8 @ =0x080AF9A8
	ldr r1, _080607DC @ =0x05000200
	movs r2, #0x18
	bl CpuFastSet
	ldr r2, [r5]
	ldr r1, _080607E0 @ =0x08483CE0
	ldr r0, _080607E4 @ =0x030057E0
	ldr r3, _080607E8 @ =0x000007FE
	adds r0, r0, r3
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2, #0x17]
	ldr r0, _080607EC @ =0x03002C30
	mov ip, r0
	movs r1, #0xc0
	lsls r1, r1, #8
	strh r1, [r0]
	movs r4, #2
	strb r4, [r0, #0x1c]
	movs r0, #0x3c
	mov r2, ip
	strh r0, [r2, #4]
	ldr r3, [r5]
	ldrb r0, [r3, #0x18]
	strb r0, [r2, #0xa]
	ldr r0, _080607F0 @ =0x0000010D
	strh r0, [r2, #6]
	strh r6, [r2, #0x1a]
	mov r0, ip
	adds r0, #0x40
	strh r1, [r0]
	adds r0, #0x1c
	strb r4, [r0]
	ldr r2, _080607F4 @ =0x08483DC0
	ldrb r0, [r3, #0x17]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	mov r1, ip
	adds r1, #0x42
	strh r0, [r1]
	ldrb r0, [r3, #0x17]
	lsls r0, r0, #1
	adds r0, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r1, #2
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x4a
	strb r4, [r0]
	adds r1, #2
	movs r0, #0x87
	lsls r0, r0, #1
	strh r0, [r1]
	ldrb r0, [r3, #0x17]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	mov r1, ip
	strh r0, [r1, #2]
	ldrb r0, [r3, #0x17]
	lsls r0, r0, #1
	adds r0, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	strh r0, [r1, #4]
	ldr r0, _080607F8 @ =0x087873A4
	ldr r1, _080607FC @ =0x020301E0
	bl dma3_copy_or_decompress
	ldr r1, _08060800 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080607AC: .4byte 0x0400000C
_080607B0: .4byte 0x0600001A
_080607B4: .4byte 0x01000005
_080607B8: .4byte 0x06000010
_080607BC: .4byte 0x087877C4
_080607C0: .4byte 0x02030000
_080607C4: .4byte 0x08784CB0
_080607C8: .4byte 0x03006F74
_080607CC: .4byte 0x087871E4
_080607D0: .4byte 0x08785F34
_080607D4: .4byte 0x06010000
_080607D8: .4byte 0x080AF9A8
_080607DC: .4byte 0x05000200
_080607E0: .4byte 0x08483CE0
_080607E4: .4byte 0x030057E0
_080607E8: .4byte 0x000007FE
_080607EC: .4byte 0x03002C30
_080607F0: .4byte 0x0000010D
_080607F4: .4byte 0x08483DC0
_080607F8: .4byte 0x087873A4
_080607FC: .4byte 0x020301E0
_08060800: .4byte 0x0300137C
	.syntax divided
