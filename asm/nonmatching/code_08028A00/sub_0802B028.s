	.syntax unified

	thumb_func_start sub_0802B028
sub_0802B028: @ 0x0802B028
	push {r4, r5, lr}
	ldr r0, _0802B10C @ =0x084DFA88
	ldr r1, _0802B110 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802B114 @ =0x0850EDB8
	ldr r1, _0802B118 @ =0x050002C0
	movs r2, #0x10
	bl CpuFastSet
	ldr r3, _0802B11C @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r3, r0
	movs r4, #0
	ldr r0, _0802B120 @ =0x0000C604
	strh r0, [r1]
	ldr r1, _0802B124 @ =0x0000085C
	adds r0, r3, r1
	strb r4, [r0]
	ldr r2, _0802B128 @ =0x03001800
	adds r2, #0x87
	ldrb r0, [r2]
	lsls r0, r0, #8
	movs r5, #0xba
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r3
	ldrh r1, [r0, #2]
	ldr r5, _0802B12C @ =0x00000842
	adds r0, r3, r5
	strh r1, [r0]
	ldrb r0, [r2]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	subs r0, #4
	adds r5, #2
	adds r1, r3, r5
	strh r0, [r1]
	ldr r0, _0802B130 @ =0x0000084A
	adds r1, r3, r0
	movs r0, #6
	strb r0, [r1]
	adds r5, #7
	adds r1, r3, r5
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, _0802B134 @ =0x00000848
	adds r0, r3, r1
	movs r1, #0x40
	strb r1, [r0]
	subs r5, #2
	adds r0, r3, r5
	strb r1, [r0]
	ldr r0, _0802B138 @ =0x00000846
	adds r1, r3, r0
	movs r0, #0xf4
	lsls r0, r0, #7
	strh r0, [r1]
	adds r5, #0x37
	adds r1, r3, r5
	ldr r0, _0802B13C @ =0x0000C404
	strh r0, [r1]
	ldr r1, _0802B140 @ =0x0000089C
	adds r0, r3, r1
	strb r4, [r0]
	ldrb r0, [r2]
	lsls r0, r0, #8
	movs r5, #0xba
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r3
	ldrh r1, [r0, #2]
	ldr r5, _0802B144 @ =0x00000882
	adds r0, r3, r5
	strh r1, [r0]
	ldrb r0, [r2]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	subs r0, #4
	adds r5, #2
	adds r1, r3, r5
	strh r0, [r1]
	ldr r0, _0802B148 @ =0x0000088A
	adds r1, r3, r0
	movs r0, #7
	strb r0, [r1]
	adds r5, #7
	adds r1, r3, r5
	movs r0, #0xe0
	strb r0, [r1]
	ldr r1, _0802B14C @ =0x000008AD
	adds r0, r3, r1
	strb r4, [r0]
	ldr r1, _0802B150 @ =0x03000590
	ldrb r0, [r2]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xa8
	ldrb r0, [r0]
	cmp r0, #0x1e
	bne _0802B158
	subs r5, #5
	adds r1, r3, r5
	ldr r0, _0802B154 @ =0x00007A01
	b _0802B15E
	.align 2, 0
_0802B10C: .4byte 0x084DFA88
_0802B110: .4byte 0x06014800
_0802B114: .4byte 0x0850EDB8
_0802B118: .4byte 0x050002C0
_0802B11C: .4byte 0x03002C30
_0802B120: .4byte 0x0000C604
_0802B124: .4byte 0x0000085C
_0802B128: .4byte 0x03001800
_0802B12C: .4byte 0x00000842
_0802B130: .4byte 0x0000084A
_0802B134: .4byte 0x00000848
_0802B138: .4byte 0x00000846
_0802B13C: .4byte 0x0000C404
_0802B140: .4byte 0x0000089C
_0802B144: .4byte 0x00000882
_0802B148: .4byte 0x0000088A
_0802B14C: .4byte 0x000008AD
_0802B150: .4byte 0x03000590
_0802B154: .4byte 0x00007A01
_0802B158:
	ldr r0, _0802B178 @ =0x00000886
	adds r1, r3, r0
	ldr r0, _0802B17C @ =0x00007A02
_0802B15E:
	strh r0, [r1]
	movs r0, #0x4c
	bl play_sound_effect
	ldr r1, _0802B180 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802B178: .4byte 0x00000886
_0802B17C: .4byte 0x00007A02
_0802B180: .4byte 0x03001800
	.syntax divided
