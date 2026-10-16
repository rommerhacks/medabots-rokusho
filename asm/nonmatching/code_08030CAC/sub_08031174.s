	.syntax unified

	thumb_func_start sub_08031174
sub_08031174: @ 0x08031174
	push {lr}
	ldr r0, _080311E0 @ =0x084C84E4
	ldr r1, _080311E4 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _080311E8 @ =0x084E2FD8
	ldr r1, _080311EC @ =0x050003E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _080311F0 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r2, r1, r0
	movs r3, #0
	ldr r0, _080311F4 @ =0x0000C624
	strh r0, [r2]
	ldr r2, _080311F8 @ =0x0000085C
	adds r0, r1, r2
	strb r3, [r0]
	ldr r0, _080311FC @ =0x00000842
	adds r2, r1, r0
	movs r0, #0x78
	strh r0, [r2]
	ldr r0, _08031200 @ =0x00000844
	adds r2, r1, r0
	movs r3, #0x40
	movs r0, #0x40
	strh r0, [r2]
	ldr r0, _08031204 @ =0x0000084A
	adds r2, r1, r0
	movs r0, #0xf
	strb r0, [r2]
	ldr r0, _08031208 @ =0x0000084B
	adds r2, r1, r0
	movs r0, #0xc0
	strb r0, [r2]
	ldr r0, _0803120C @ =0x00000846
	adds r2, r1, r0
	adds r0, #0xbd
	strh r0, [r2]
	subs r0, #0xba
	adds r2, r1, r0
	movs r0, #0x80
	strb r0, [r2]
	ldr r2, _08031210 @ =0x00000848
	adds r1, r1, r2
	strb r3, [r1]
	ldr r1, _08031214 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080311E0: .4byte 0x084C84E4
_080311E4: .4byte 0x06014800
_080311E8: .4byte 0x084E2FD8
_080311EC: .4byte 0x050003E0
_080311F0: .4byte 0x03002C30
_080311F4: .4byte 0x0000C624
_080311F8: .4byte 0x0000085C
_080311FC: .4byte 0x00000842
_08031200: .4byte 0x00000844
_08031204: .4byte 0x0000084A
_08031208: .4byte 0x0000084B
_0803120C: .4byte 0x00000846
_08031210: .4byte 0x00000848
_08031214: .4byte 0x0300137C
	.syntax divided
