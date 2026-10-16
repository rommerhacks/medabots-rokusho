	.syntax unified

	thumb_func_start sub_0801E864
sub_0801E864: @ 0x0801E864
	push {r4, lr}
	ldr r0, _0801E890 @ =0x084CC9A8
	ldr r1, _0801E894 @ =0x06010800
	bl lz_decompress_dispatch
	ldr r0, _0801E898 @ =0x0850E338
	ldr r1, _0801E89C @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r3, _0801E8A0 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0801E8A4
	movs r1, #0xac
	lsls r1, r1, #1
	b _0801E8A8
	.align 2, 0
_0801E890: .4byte 0x084CC9A8
_0801E894: .4byte 0x06010800
_0801E898: .4byte 0x0850E338
_0801E89C: .4byte 0x050003C0
_0801E8A0: .4byte 0x03001800
_0801E8A4:
	movs r1, #0xaa
	lsls r1, r1, #1
_0801E8A8:
	adds r0, r3, r1
	ldrh r2, [r0]
	adds r1, #2
	adds r0, r3, r1
	ldrh r0, [r0]
	ldr r4, _0801E8D8 @ =0x03001800
	adds r1, r4, #0
	adds r1, #0x8b
	ldrb r1, [r1]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	lsls r3, r0, #0x10
	asrs r3, r3, #0x10
	movs r0, #0xa
	bl sub_08036784
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801E8D8: .4byte 0x03001800
	.syntax divided
