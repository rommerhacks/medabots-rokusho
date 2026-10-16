	.syntax unified

	thumb_func_start sub_08031390
sub_08031390: @ 0x08031390
	push {r4, r5, lr}
	ldr r0, _08031410 @ =0x084D796C
	ldr r1, _08031414 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r2, _08031418 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r4, #0
	ldr r0, _0803141C @ =0x0000C404
	strh r0, [r1]
	ldr r1, _08031420 @ =0x0000085C
	adds r0, r2, r1
	strb r4, [r0]
	ldr r1, _08031424 @ =0x03001800
	adds r1, #0x87
	ldrb r0, [r1]
	lsls r0, r0, #8
	movs r3, #0xba
	lsls r3, r3, #5
	adds r0, r0, r3
	adds r0, r0, r2
	ldrh r3, [r0, #2]
	ldr r5, _08031428 @ =0x00000842
	adds r0, r2, r5
	strh r3, [r0]
	ldrb r0, [r1]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r3, _0803142C @ =0x00000844
	adds r1, r2, r3
	strh r0, [r1]
	adds r5, #8
	adds r1, r2, r5
	movs r0, #0xc
	strb r0, [r1]
	ldr r0, _08031430 @ =0x0000084B
	adds r1, r2, r0
	movs r0, #0x80
	strb r0, [r1]
	adds r3, #2
	adds r1, r2, r3
	movs r0, #0xb0
	lsls r0, r0, #7
	strh r0, [r1]
	adds r5, #0x19
	adds r2, r2, r5
	strb r4, [r2]
	movs r0, #0x2a
	bl play_sound_effect
	ldr r1, _08031434 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08031410: .4byte 0x084D796C
_08031414: .4byte 0x06014800
_08031418: .4byte 0x03002C30
_0803141C: .4byte 0x0000C404
_08031420: .4byte 0x0000085C
_08031424: .4byte 0x03001800
_08031428: .4byte 0x00000842
_0803142C: .4byte 0x00000844
_08031430: .4byte 0x0000084B
_08031434: .4byte 0x0300137C
	.syntax divided
