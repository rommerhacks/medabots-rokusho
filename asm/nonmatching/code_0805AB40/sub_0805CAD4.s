	.syntax unified

	thumb_func_start sub_0805CAD4
sub_0805CAD4: @ 0x0805CAD4
	push {r4, r5, r6, r7, lr}
	ldr r1, _0805CBF4 @ =0x0400000A
	ldr r0, _0805CBF8 @ =0x00001E05
	strh r0, [r1]
	ldr r4, _0805CBFC @ =0x0400000C
	ldr r0, _0805CC00 @ =0x00001C06
	strh r0, [r4]
	ldr r5, _0805CC04 @ =0x0400000E
	ldr r0, _0805CC08 @ =0x00003D07
	strh r0, [r5]
	ldr r0, _0805CC0C @ =0x0878C484
	ldrh r1, [r1]
	bl decompress_and_write_tilemap
	ldr r0, _0805CC10 @ =0x0878C5B4
	ldrh r1, [r4]
	bl decompress_and_write_tilemap
	ldr r0, _0805CC14 @ =0x0878C750
	ldrh r1, [r5]
	bl decompress_and_write_tilemap
	ldr r0, _0805CC18 @ =0x0878B078
	ldr r5, _0805CC1C @ =0x02030000
	adds r1, r5, #0
	bl dma3_copy_or_decompress
	adds r4, r0, #0
	ldr r1, _0805CC20 @ =0x06004000
	lsls r2, r4, #0xa
	lsrs r2, r2, #0xb
	adds r0, r5, #0
	bl CpuSet
	ldr r0, _0805CC24 @ =0x08784CB0
	ldr r2, _0805CC20 @ =0x06004000
	adds r1, r4, r2
	bl lz_decompress_dispatch
	ldr r0, _0805CC28 @ =0x03006F74
	ldr r0, [r0]
	lsrs r4, r4, #5
	subs r4, #1
	strh r4, [r0, #0x36]
	ldr r0, _0805CC2C @ =0x08784DA4
	ldr r1, _0805CC30 @ =0x06010000
	bl lz_decompress_dispatch
	movs r3, #0
	ldr r2, _0805CC34 @ =0x03002C30
	movs r6, #0
	adds r7, r2, #0
	movs r5, #0x80
	lsls r5, r5, #8
	movs r4, #2
_0805CB42:
	adds r1, r3, #0
	adds r1, #0x51
	lsls r1, r1, #6
	adds r1, r1, r2
	strh r5, [r1]
	strb r4, [r1, #0x1c]
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, #0x18
	strh r0, [r1, #2]
	movs r0, #0x18
	strh r0, [r1, #4]
	strb r6, [r1, #0xa]
	movs r0, #5
	strh r0, [r1, #6]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bls _0805CB42
	movs r3, #0xa2
	lsls r3, r3, #5
	adds r2, r7, r3
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r3, #0
	ldr r0, _0805CC38 @ =0x084C6A98
	mov ip, r0
	adds r6, r7, #0
	movs r2, #0
	movs r5, #0x80
	lsls r5, r5, #8
	movs r4, #2
	movs r1, #6
_0805CB90:
	adds r0, r3, #0
	adds r0, #0x53
	lsls r0, r0, #6
	adds r0, r0, r6
	strh r5, [r0]
	strb r4, [r0, #0x1c]
	strb r2, [r0, #0xa]
	strh r1, [r0, #6]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bls _0805CB90
	movs r3, #0
	ldr r7, _0805CC34 @ =0x03002C30
	movs r6, #0x80
	lsls r6, r6, #8
	movs r5, #2
	movs r4, #0xe
	movs r2, #7
_0805CBB8:
	adds r1, r3, #0
	adds r1, #0x55
	lsls r1, r1, #6
	adds r1, r1, r7
	strh r6, [r1]
	strb r5, [r1, #0x1c]
	strb r4, [r1, #0xa]
	strh r2, [r1, #6]
	movs r0, #0xe0
	strh r0, [r1, #2]
	lsls r0, r3, #4
	adds r0, #0x20
	strh r0, [r1, #4]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #4
	bls _0805CBB8
	ldr r1, _0805CC3C @ =0x06017400
	mov r0, ip
	bl lz_decompress_dispatch
	ldr r1, _0805CC40 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805CBF4: .4byte 0x0400000A
_0805CBF8: .4byte 0x00001E05
_0805CBFC: .4byte 0x0400000C
_0805CC00: .4byte 0x00001C06
_0805CC04: .4byte 0x0400000E
_0805CC08: .4byte 0x00003D07
_0805CC0C: .4byte 0x0878C484
_0805CC10: .4byte 0x0878C5B4
_0805CC14: .4byte 0x0878C750
_0805CC18: .4byte 0x0878B078
_0805CC1C: .4byte 0x02030000
_0805CC20: .4byte 0x06004000
_0805CC24: .4byte 0x08784CB0
_0805CC28: .4byte 0x03006F74
_0805CC2C: .4byte 0x08784DA4
_0805CC30: .4byte 0x06010000
_0805CC34: .4byte 0x03002C30
_0805CC38: .4byte 0x084C6A98
_0805CC3C: .4byte 0x06017400
_0805CC40: .4byte 0x0300137C
	.syntax divided
