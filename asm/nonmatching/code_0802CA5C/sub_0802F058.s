	.syntax unified

	thumb_func_start sub_0802F058
sub_0802F058: @ 0x0802F058
	push {r4, r5, r6, lr}
	ldr r0, _0802F104 @ =0x084D50DC
	ldr r1, _0802F108 @ =0x06015800
	bl lz_decompress_dispatch
	ldr r0, _0802F10C @ =0x0850E658
	ldr r1, _0802F110 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _0802F114 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r3, #0
	movs r5, #0
	ldr r0, _0802F118 @ =0x0000C624
	strh r0, [r1]
	ldr r1, _0802F11C @ =0x0000085C
	adds r0, r2, r1
	strb r3, [r0]
	ldr r4, _0802F120 @ =0x03001800
	movs r6, #0x87
	adds r6, r6, r4
	mov ip, r6
	ldrb r0, [r6]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	ldr r6, _0802F124 @ =0x00000842
	adds r0, r2, r6
	strh r1, [r0]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #8
	movs r6, #0xba
	lsls r6, r6, #5
	adds r0, r0, r6
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r6, _0802F128 @ =0x00000844
	adds r1, r2, r6
	strh r0, [r1]
	ldr r0, _0802F12C @ =0x0000084A
	adds r1, r2, r0
	movs r0, #7
	strb r0, [r1]
	adds r6, #7
	adds r1, r2, r6
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, _0802F130 @ =0x00000848
	adds r0, r2, r1
	movs r1, #0x40
	strb r1, [r0]
	subs r6, #2
	adds r0, r2, r6
	strb r1, [r0]
	ldr r1, _0802F134 @ =0x00000858
	adds r0, r2, r1
	strh r5, [r0]
	subs r6, #3
	adds r1, r2, r6
	movs r0, #0x82
	lsls r0, r0, #7
	strh r0, [r1]
	ldr r1, _0802F138 @ =0x00000863
	adds r0, r2, r1
	strb r3, [r0]
	adds r6, #0x21
	adds r2, r2, r6
	strb r3, [r2]
	movs r0, #0x29
	bl play_sound_effect
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802F104: .4byte 0x084D50DC
_0802F108: .4byte 0x06015800
_0802F10C: .4byte 0x0850E658
_0802F110: .4byte 0x050002E0
_0802F114: .4byte 0x03002C30
_0802F118: .4byte 0x0000C624
_0802F11C: .4byte 0x0000085C
_0802F120: .4byte 0x03001800
_0802F124: .4byte 0x00000842
_0802F128: .4byte 0x00000844
_0802F12C: .4byte 0x0000084A
_0802F130: .4byte 0x00000848
_0802F134: .4byte 0x00000858
_0802F138: .4byte 0x00000863
	.syntax divided
