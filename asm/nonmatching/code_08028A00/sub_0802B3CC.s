	.syntax unified

	thumb_func_start sub_0802B3CC
sub_0802B3CC: @ 0x0802B3CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _0802B43C @ =0x084DCF54
	ldr r1, _0802B440 @ =0x06016000
	bl lz_decompress_dispatch
	ldr r0, _0802B444 @ =0x0850EC58
	ldr r1, _0802B448 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	movs r5, #0
	ldr r0, _0802B44C @ =0x030018D2
	mov r8, r0
	ldr r7, _0802B450 @ =0x083B6118
	ldr r0, _0802B454 @ =0x03002C30
	movs r6, #0x84
	lsls r6, r6, #0x16
	movs r1, #0x84
	lsls r1, r1, #4
	adds r4, r0, r1
_0802B3F8:
	mov r2, r8
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802B418
	movs r0, #7
	strb r0, [r4, #0xa]
	ldrh r0, [r4]
	ldr r2, _0802B458 @ =0x0000EFFF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r4]
	ldr r0, [r7]
	lsrs r1, r6, #0x18
	bl init_battle_sprite_entry_08040B90
_0802B418:
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r6, r6, r0
	adds r4, #0x40
	adds r5, #1
	cmp r5, #2
	bls _0802B3F8
	ldr r1, _0802B45C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802B43C: .4byte 0x084DCF54
_0802B440: .4byte 0x06016000
_0802B444: .4byte 0x0850EC58
_0802B448: .4byte 0x050002E0
_0802B44C: .4byte 0x030018D2
_0802B450: .4byte 0x083B6118
_0802B454: .4byte 0x03002C30
_0802B458: .4byte 0x0000EFFF
_0802B45C: .4byte 0x03001800
	.syntax divided
