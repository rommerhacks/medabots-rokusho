	.syntax unified

	thumb_func_start sub_0805D628
sub_0805D628: @ 0x0805D628
	push {r4, r5, lr}
	ldr r1, _0805D6B4 @ =0x0400000A
	ldr r0, _0805D6B8 @ =0x00001E05
	strh r0, [r1]
	ldr r4, _0805D6BC @ =0x0400000C
	subs r0, #0xff
	strh r0, [r4]
	ldr r5, _0805D6C0 @ =0x0400000E
	ldr r0, _0805D6C4 @ =0x00003C07
	strh r0, [r5]
	ldr r0, _0805D6C8 @ =0x0878DE10
	ldrh r1, [r1]
	bl decompress_and_write_tilemap
	ldr r0, _0805D6CC @ =0x0878DFE0
	ldrh r1, [r4]
	bl decompress_and_write_tilemap
	ldr r0, _0805D6D0 @ =0x0878E104
	ldrh r1, [r5]
	bl decompress_and_write_tilemap
	ldr r0, _0805D6D4 @ =0x0878CC64
	ldr r5, _0805D6D8 @ =0x02030000
	adds r1, r5, #0
	bl dma3_copy_or_decompress
	adds r4, r0, #0
	ldr r1, _0805D6DC @ =0x06004000
	lsls r2, r4, #0xa
	lsrs r2, r2, #0xb
	adds r0, r5, #0
	bl CpuSet
	ldr r0, _0805D6E0 @ =0x08784CB0
	ldr r2, _0805D6DC @ =0x06004000
	adds r1, r4, r2
	bl lz_decompress_dispatch
	ldr r0, _0805D6E4 @ =0x03006F74
	ldr r0, [r0]
	lsrs r4, r4, #5
	subs r4, #1
	movs r5, #0
	strh r4, [r0, #0x36]
	ldr r0, _0805D6E8 @ =0x08784DA4
	ldr r1, _0805D6EC @ =0x06010000
	bl lz_decompress_dispatch
	ldr r1, _0805D6F0 @ =0x03002C30
	movs r0, #0xc0
	lsls r0, r0, #8
	strh r0, [r1]
	movs r0, #2
	strb r0, [r1, #0x1c]
	strb r5, [r1, #0xa]
	movs r0, #0x23
	strh r0, [r1, #6]
	movs r0, #0xd0
	strh r0, [r1, #2]
	movs r0, #0x18
	strh r0, [r1, #4]
	ldr r1, _0805D6F4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805D6B4: .4byte 0x0400000A
_0805D6B8: .4byte 0x00001E05
_0805D6BC: .4byte 0x0400000C
_0805D6C0: .4byte 0x0400000E
_0805D6C4: .4byte 0x00003C07
_0805D6C8: .4byte 0x0878DE10
_0805D6CC: .4byte 0x0878DFE0
_0805D6D0: .4byte 0x0878E104
_0805D6D4: .4byte 0x0878CC64
_0805D6D8: .4byte 0x02030000
_0805D6DC: .4byte 0x06004000
_0805D6E0: .4byte 0x08784CB0
_0805D6E4: .4byte 0x03006F74
_0805D6E8: .4byte 0x08784DA4
_0805D6EC: .4byte 0x06010000
_0805D6F0: .4byte 0x03002C30
_0805D6F4: .4byte 0x0300137C
	.syntax divided
