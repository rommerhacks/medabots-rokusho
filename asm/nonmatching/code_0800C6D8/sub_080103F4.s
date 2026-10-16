	.syntax unified

	thumb_func_start sub_080103F4
sub_080103F4: @ 0x080103F4
	push {r4, r5, lr}
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08010450 @ =0x04000008
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _08010454 @ =0x03005000
	movs r5, #0
	movs r4, #0
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, _08010458 @ =0x084C696C
	ldr r1, _0801045C @ =0x06002600
	bl lz_decompress_dispatch
	ldr r1, _08010460 @ =0x040000D4
	ldr r0, _08010464 @ =0x084C6A78
	str r0, [r1]
	ldr r0, _08010468 @ =0x050001A0
	str r0, [r1, #4]
	ldr r0, _0801046C @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _08010470 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x3f
	strb r5, [r0]
	adds r0, #9
	strh r4, [r0]
	adds r0, #0x3c
	strb r5, [r0]
	ldr r1, _08010474 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010450: .4byte 0x04000008
_08010454: .4byte 0x03005000
_08010458: .4byte 0x084C696C
_0801045C: .4byte 0x06002600
_08010460: .4byte 0x040000D4
_08010464: .4byte 0x084C6A78
_08010468: .4byte 0x050001A0
_0801046C: .4byte 0x84000008
_08010470: .4byte 0x03000440
_08010474: .4byte 0x0300137C
	.syntax divided
