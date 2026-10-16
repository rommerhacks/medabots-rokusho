	.syntax unified

	thumb_func_start sub_08028504
sub_08028504: @ 0x08028504
	push {r4, r5, r6, r7, lr}
	ldr r1, _08028528 @ =0x03000590
	ldr r0, _0802852C @ =0x03001800
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xa8
	ldrb r0, [r0]
	subs r0, #0xc
	cmp r0, #0x1c
	bls _0802851E
	b _080286B4
_0802851E:
	lsls r0, r0, #2
	ldr r1, _08028530 @ =_08028534
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08028528: .4byte 0x03000590
_0802852C: .4byte 0x03001800
_08028530: .4byte _08028534
_08028534: @ jump table
	.4byte _080285A8 @ case 0
	.4byte _080286B4 @ case 1
	.4byte _080285E8 @ case 2
	.4byte _080286B4 @ case 3
	.4byte _0802861C @ case 4
	.4byte _080286B4 @ case 5
	.4byte _08028650 @ case 6
	.4byte _080286B4 @ case 7
	.4byte _080286B4 @ case 8
	.4byte _080286B4 @ case 9
	.4byte _080286B4 @ case 10
	.4byte _080286B4 @ case 11
	.4byte _080286B4 @ case 12
	.4byte _080286B4 @ case 13
	.4byte _080286B4 @ case 14
	.4byte _080286B4 @ case 15
	.4byte _080286B4 @ case 16
	.4byte _080286B4 @ case 17
	.4byte _080286B4 @ case 18
	.4byte _080286B4 @ case 19
	.4byte _080286B4 @ case 20
	.4byte _080286B4 @ case 21
	.4byte _080286B4 @ case 22
	.4byte _080286B4 @ case 23
	.4byte _080286B4 @ case 24
	.4byte _080286B4 @ case 25
	.4byte _080286B4 @ case 26
	.4byte _080286B4 @ case 27
	.4byte _08028690 @ case 28
_080285A8:
	ldr r0, _080285CC @ =0x084DBEE4
	ldr r1, _080285D0 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _080285D4 @ =0x0850EBD8
	ldr r1, _080285D8 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _080285DC @ =0x03002C30
	ldr r0, _080285E0 @ =0x00000868
	adds r2, r1, r0
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080285E4 @ =0x0000086E
	adds r1, r1, r2
	b _080286B0
	.align 2, 0
_080285CC: .4byte 0x084DBEE4
_080285D0: .4byte 0x06014800
_080285D4: .4byte 0x0850EBD8
_080285D8: .4byte 0x050002E0
_080285DC: .4byte 0x03002C30
_080285E0: .4byte 0x00000868
_080285E4: .4byte 0x0000086E
_080285E8:
	ldr r0, _08028604 @ =0x084DC100
	ldr r1, _08028608 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802860C @ =0x0850EBF8
	ldr r1, _08028610 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08028614 @ =0x03002C30
	ldr r3, _08028618 @ =0x00000868
	adds r2, r1, r3
	movs r0, #1
	b _080286AA
	.align 2, 0
_08028604: .4byte 0x084DC100
_08028608: .4byte 0x06014800
_0802860C: .4byte 0x0850EBF8
_08028610: .4byte 0x050002E0
_08028614: .4byte 0x03002C30
_08028618: .4byte 0x00000868
_0802861C:
	ldr r0, _08028638 @ =0x084DC544
	ldr r1, _0802863C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08028640 @ =0x0850EC18
	ldr r1, _08028644 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08028648 @ =0x03002C30
	ldr r3, _0802864C @ =0x00000868
	adds r2, r1, r3
	movs r0, #2
	b _080286AA
	.align 2, 0
_08028638: .4byte 0x084DC544
_0802863C: .4byte 0x06014800
_08028640: .4byte 0x0850EC18
_08028644: .4byte 0x050002E0
_08028648: .4byte 0x03002C30
_0802864C: .4byte 0x00000868
_08028650:
	ldr r0, _08028674 @ =0x084DC7D0
	ldr r1, _08028678 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802867C @ =0x0850EC38
	ldr r1, _08028680 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08028684 @ =0x03002C30
	ldr r3, _08028688 @ =0x00000868
	adds r2, r1, r3
	movs r0, #3
	strb r0, [r2]
	ldr r0, _0802868C @ =0x0000086E
	adds r1, r1, r0
	movs r0, #0x5c
	b _080286B2
	.align 2, 0
_08028674: .4byte 0x084DC7D0
_08028678: .4byte 0x06014800
_0802867C: .4byte 0x0850EC38
_08028680: .4byte 0x050002E0
_08028684: .4byte 0x03002C30
_08028688: .4byte 0x00000868
_0802868C: .4byte 0x0000086E
_08028690:
	ldr r0, _08028748 @ =0x084DD188
	ldr r1, _0802874C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08028750 @ =0x0850EC78
	ldr r1, _08028754 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08028758 @ =0x03002C30
	ldr r3, _0802875C @ =0x00000868
	adds r2, r1, r3
	movs r0, #4
_080286AA:
	strb r0, [r2]
	ldr r0, _08028760 @ =0x0000086E
	adds r1, r1, r0
_080286B0:
	movs r0, #0x5b
_080286B2:
	strb r0, [r1]
_080286B4:
	ldr r0, _08028764 @ =0x084E30B8
	ldr r1, _08028768 @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	ldr r5, _08028758 @ =0x03002C30
	movs r1, #0x84
	lsls r1, r1, #4
	adds r7, r5, r1
	movs r6, #0
	movs r2, #0
	ldr r0, _0802876C @ =0x0000C604
	strh r0, [r7]
	ldr r3, _08028770 @ =0x0000085C
	adds r0, r5, r3
	strb r6, [r0]
	ldr r0, _08028774 @ =0x00000844
	adds r1, r5, r0
	movs r0, #0xe0
	strh r0, [r1]
	subs r3, #0x12
	adds r1, r5, r3
	movs r0, #7
	strb r0, [r1]
	ldr r1, _08028778 @ =0x00000848
	adds r0, r5, r1
	movs r1, #0x40
	strb r1, [r0]
	subs r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _0802877C @ =0x00000858
	adds r0, r5, r1
	strh r2, [r0]
	ldr r2, _08028780 @ =0x0000084B
	adds r1, r5, r2
	movs r0, #0xf0
	strb r0, [r1]
	adds r3, #0x20
	adds r0, r5, r3
	movs r4, #1
	strb r4, [r0]
	ldr r0, _08028784 @ =0x0000086B
	adds r1, r5, r0
	movs r0, #0x20
	strb r0, [r1]
	adds r2, #0x21
	adds r1, r5, r2
	movs r0, #0xc0
	strb r0, [r1]
	adds r3, #4
	adds r0, r5, r3
	strb r6, [r0]
	ldr r1, _08028788 @ =0x083B5F80
	adds r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r0, _0802878C @ =0x03001800
	adds r0, #0xf8
	ldrb r0, [r0]
	ands r4, r0
	cmp r4, #0
	bne _08028794
	ldr r3, _08028790 @ =0x00000842
	adds r1, r5, r3
	movs r0, #0xb8
	b _080287A6
	.align 2, 0
_08028748: .4byte 0x084DD188
_0802874C: .4byte 0x06014800
_08028750: .4byte 0x0850EC78
_08028754: .4byte 0x050002E0
_08028758: .4byte 0x03002C30
_0802875C: .4byte 0x00000868
_08028760: .4byte 0x0000086E
_08028764: .4byte 0x084E30B8
_08028768: .4byte 0x050002C0
_0802876C: .4byte 0x0000C604
_08028770: .4byte 0x0000085C
_08028774: .4byte 0x00000844
_08028778: .4byte 0x00000848
_0802877C: .4byte 0x00000858
_08028780: .4byte 0x0000084B
_08028784: .4byte 0x0000086B
_08028788: .4byte 0x083B5F80
_0802878C: .4byte 0x03001800
_08028790: .4byte 0x00000842
_08028794:
	ldrh r0, [r7]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r7]
	ldr r3, _080287B8 @ =0x00000842
	adds r1, r5, r3
	movs r0, #0x38
_080287A6:
	strh r0, [r1]
	ldr r1, _080287BC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080287B8: .4byte 0x00000842
_080287BC: .4byte 0x03001800
	.syntax divided
