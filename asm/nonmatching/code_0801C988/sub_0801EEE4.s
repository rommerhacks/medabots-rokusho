	.syntax unified

	thumb_func_start sub_0801EEE4
sub_0801EEE4: @ 0x0801EEE4
	push {r4, lr}
	ldr r0, _0801EF54 @ =0x084CA428
	ldr r1, _0801EF58 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0801EF5C @ =0x0850E178
	ldr r1, _0801EF60 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r3, _0801EF64 @ =0x03002C30
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r2, #0
	ldr r0, _0801EF68 @ =0x0000C404
	strh r0, [r1]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r3, r1
	strb r2, [r0]
	ldr r4, _0801EF6C @ =0x0000028A
	adds r1, r3, r4
	movs r0, #0xe
	strb r0, [r1]
	ldr r0, _0801EF70 @ =0x0000028B
	adds r1, r3, r0
	movs r0, #0x80
	strb r0, [r1]
	subs r4, #4
	adds r1, r3, r4
	movs r0, #0xa0
	lsls r0, r0, #5
	strh r0, [r1]
	ldr r1, _0801EF74 @ =0x000002A3
	adds r0, r3, r1
	strb r2, [r0]
	ldr r2, _0801EF78 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0801EF80
	movs r4, #0xac
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r1, [r0]
	ldr r4, _0801EF7C @ =0x00000282
	adds r0, r3, r4
	strh r1, [r0]
	movs r1, #0xad
	lsls r1, r1, #1
	b _0801EF92
	.align 2, 0
_0801EF54: .4byte 0x084CA428
_0801EF58: .4byte 0x06010000
_0801EF5C: .4byte 0x0850E178
_0801EF60: .4byte 0x050003C0
_0801EF64: .4byte 0x03002C30
_0801EF68: .4byte 0x0000C404
_0801EF6C: .4byte 0x0000028A
_0801EF70: .4byte 0x0000028B
_0801EF74: .4byte 0x000002A3
_0801EF78: .4byte 0x03001800
_0801EF7C: .4byte 0x00000282
_0801EF80:
	movs r4, #0xaa
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r1, [r0]
	ldr r4, _0801EFC0 @ =0x00000282
	adds r0, r3, r4
	strh r1, [r0]
	movs r1, #0xab
	lsls r1, r1, #1
_0801EF92:
	adds r0, r2, r1
	ldrh r2, [r0]
	adds r1, r2, #0
	subs r1, #0x10
	adds r4, #2
	adds r0, r3, r4
	strh r1, [r0]
	movs r1, #0xac
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	movs r0, #0x2f
	bl play_sound_effect
	ldr r1, _0801EFC4 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801EFC0: .4byte 0x00000282
_0801EFC4: .4byte 0x03001800
_0801EFC8:
	.byte 0x0F, 0x48, 0x00, 0x68, 0x01, 0x21, 0x08, 0x40
	.byte 0x00, 0x28, 0x17, 0xD0, 0x0D, 0x4A, 0xA1, 0x20, 0x80, 0x00, 0x11, 0x18, 0x08, 0x88, 0x01, 0x30
	.byte 0x08, 0x80, 0x00, 0x23, 0xC9, 0x5E, 0xAC, 0x23, 0x9B, 0x00, 0xD0, 0x18, 0x00, 0x88, 0x81, 0x42
	.byte 0x08, 0xD1, 0x07, 0x48, 0x86, 0x30, 0x3C, 0x21, 0x01, 0x80, 0x06, 0x49, 0xAA, 0x31, 0x08, 0x78
	.byte 0x01, 0x30, 0x08, 0x70, 0x70, 0x47, 0x00, 0x00, 0x80, 0x17, 0x00, 0x03, 0x30, 0x2C, 0x00, 0x03
	.byte 0x40, 0x04, 0x00, 0x03, 0x00, 0x18, 0x00, 0x03
	.syntax divided
