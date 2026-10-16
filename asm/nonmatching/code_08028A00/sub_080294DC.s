	.syntax unified

	thumb_func_start sub_080294DC
sub_080294DC: @ 0x080294DC
	push {r4, r5, lr}
	ldr r0, _0802958C @ =0x084DD648
	ldr r1, _08029590 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08029594 @ =0x0850ECB8
	ldr r1, _08029598 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0802959C @ =0x084E30B8
	ldr r1, _080295A0 @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	ldr r4, _080295A4 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r3, #0
	movs r2, #0
	ldr r0, _080295A8 @ =0x0000C604
	strh r0, [r1]
	ldr r1, _080295AC @ =0x0000085C
	adds r0, r4, r1
	strb r3, [r0]
	ldr r5, _080295B0 @ =0x00000844
	adds r1, r4, r5
	movs r0, #0xe0
	strh r0, [r1]
	ldr r0, _080295B4 @ =0x0000084A
	adds r1, r4, r0
	movs r0, #7
	strb r0, [r1]
	ldr r1, _080295B8 @ =0x00000848
	adds r0, r4, r1
	movs r1, #0x40
	strb r1, [r0]
	adds r5, #5
	adds r0, r4, r5
	strb r1, [r0]
	ldr r1, _080295BC @ =0x00000858
	adds r0, r4, r1
	strh r2, [r0]
	adds r5, #2
	adds r1, r4, r5
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, _080295C0 @ =0x00000868
	adds r0, r4, r1
	strb r3, [r0]
	adds r5, #0x23
	adds r0, r4, r5
	movs r2, #0x5b
	strb r2, [r0]
	ldr r0, _080295C4 @ =0x00000869
	adds r1, r4, r0
	movs r0, #6
	strb r0, [r1]
	subs r5, #3
	adds r1, r4, r5
	movs r0, #0x20
	strb r0, [r1]
	ldr r0, _080295C8 @ =0x0000086C
	adds r1, r4, r0
	movs r0, #0xc0
	strb r0, [r1]
	ldr r1, _080295CC @ =0x0000086D
	adds r0, r4, r1
	strb r3, [r0]
	ldr r0, _080295D0 @ =0x083B5F80
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r0, _080295D4 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080295D8
	subs r5, #0x29
	adds r1, r4, r5
	movs r0, #0xb8
	b _080295DE
	.align 2, 0
_0802958C: .4byte 0x084DD648
_08029590: .4byte 0x06014800
_08029594: .4byte 0x0850ECB8
_08029598: .4byte 0x050002E0
_0802959C: .4byte 0x084E30B8
_080295A0: .4byte 0x050002C0
_080295A4: .4byte 0x03002C30
_080295A8: .4byte 0x0000C604
_080295AC: .4byte 0x0000085C
_080295B0: .4byte 0x00000844
_080295B4: .4byte 0x0000084A
_080295B8: .4byte 0x00000848
_080295BC: .4byte 0x00000858
_080295C0: .4byte 0x00000868
_080295C4: .4byte 0x00000869
_080295C8: .4byte 0x0000086C
_080295CC: .4byte 0x0000086D
_080295D0: .4byte 0x083B5F80
_080295D4: .4byte 0x03001800
_080295D8:
	ldr r0, _080295F8 @ =0x00000842
	adds r1, r4, r0
	movs r0, #0x38
_080295DE:
	strh r0, [r1]
	ldr r1, _080295FC @ =0x03001800
	adds r2, r1, #0
	adds r2, #0x51
	movs r0, #0
	strb r0, [r2]
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080295F8: .4byte 0x00000842
_080295FC: .4byte 0x03001800
	.syntax divided
