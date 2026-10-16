	.syntax unified

	thumb_func_start sub_0801E474
sub_0801E474: @ 0x0801E474
	push {r4, lr}
	ldr r0, _0801E4E4 @ =0x084CC430
	ldr r1, _0801E4E8 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0801E4EC @ =0x0850E2D8
	ldr r1, _0801E4F0 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r3, _0801E4F4 @ =0x03002C30
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r2, #0
	ldr r0, _0801E4F8 @ =0x0000C404
	strh r0, [r1]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r3, r1
	strb r2, [r0]
	ldr r4, _0801E4FC @ =0x0000028A
	adds r1, r3, r4
	movs r0, #0xe
	strb r0, [r1]
	ldr r0, _0801E500 @ =0x0000028B
	adds r1, r3, r0
	movs r0, #0x80
	strb r0, [r1]
	subs r4, #4
	adds r1, r3, r4
	movs r0, #0xf8
	lsls r0, r0, #5
	strh r0, [r1]
	ldr r1, _0801E504 @ =0x000002A3
	adds r0, r3, r1
	strb r2, [r0]
	ldr r2, _0801E508 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0801E510
	movs r4, #0xac
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r1, [r0]
	ldr r4, _0801E50C @ =0x00000282
	adds r0, r3, r4
	strh r1, [r0]
	movs r1, #0xad
	lsls r1, r1, #1
	b _0801E522
	.align 2, 0
_0801E4E4: .4byte 0x084CC430
_0801E4E8: .4byte 0x06010000
_0801E4EC: .4byte 0x0850E2D8
_0801E4F0: .4byte 0x050003C0
_0801E4F4: .4byte 0x03002C30
_0801E4F8: .4byte 0x0000C404
_0801E4FC: .4byte 0x0000028A
_0801E500: .4byte 0x0000028B
_0801E504: .4byte 0x000002A3
_0801E508: .4byte 0x03001800
_0801E50C: .4byte 0x00000282
_0801E510:
	movs r4, #0xaa
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r1, [r0]
	ldr r4, _0801E544 @ =0x00000282
	adds r0, r3, r4
	strh r1, [r0]
	movs r1, #0xab
	lsls r1, r1, #1
_0801E522:
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r0, r3, r2
	strh r1, [r0]
	movs r0, #0x72
	bl play_sound_effect
	ldr r1, _0801E548 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801E544: .4byte 0x00000282
_0801E548: .4byte 0x03001800
	.syntax divided
