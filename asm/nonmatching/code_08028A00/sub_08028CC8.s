	.syntax unified

	thumb_func_start sub_08028CC8
sub_08028CC8: @ 0x08028CC8
	push {r4, r5, r6, lr}
	ldr r0, _08028CE0 @ =0x03001800
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #1
	beq _08028D24
	cmp r0, #1
	bgt _08028CE4
	cmp r0, #0
	beq _08028CEE
	b _08028DA8
	.align 2, 0
_08028CE0: .4byte 0x03001800
_08028CE4:
	cmp r0, #2
	beq _08028D58
	cmp r0, #3
	beq _08028D8C
	b _08028DA8
_08028CEE:
	ldr r0, _08028D0C @ =0x084DBEE4
	ldr r1, _08028D10 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08028D14 @ =0x0850EBD8
	ldr r1, _08028D18 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08028D1C @ =0x03002C30
	ldr r1, _08028D20 @ =0x0000086E
	adds r0, r0, r1
	movs r1, #0x5b
	b _08028DA6
	.align 2, 0
_08028D0C: .4byte 0x084DBEE4
_08028D10: .4byte 0x06014800
_08028D14: .4byte 0x0850EBD8
_08028D18: .4byte 0x050002E0
_08028D1C: .4byte 0x03002C30
_08028D20: .4byte 0x0000086E
_08028D24:
	ldr r0, _08028D40 @ =0x084DC100
	ldr r1, _08028D44 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08028D48 @ =0x0850EBF8
	ldr r1, _08028D4C @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08028D50 @ =0x03002C30
	ldr r2, _08028D54 @ =0x0000086E
	adds r0, r0, r2
	movs r1, #0x5b
	b _08028DA6
	.align 2, 0
_08028D40: .4byte 0x084DC100
_08028D44: .4byte 0x06014800
_08028D48: .4byte 0x0850EBF8
_08028D4C: .4byte 0x050002E0
_08028D50: .4byte 0x03002C30
_08028D54: .4byte 0x0000086E
_08028D58:
	ldr r0, _08028D74 @ =0x084DC544
	ldr r1, _08028D78 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08028D7C @ =0x0850EC18
	ldr r1, _08028D80 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08028D84 @ =0x03002C30
	ldr r3, _08028D88 @ =0x0000086E
	adds r0, r0, r3
	movs r1, #0x5b
	b _08028DA6
	.align 2, 0
_08028D74: .4byte 0x084DC544
_08028D78: .4byte 0x06014800
_08028D7C: .4byte 0x0850EC18
_08028D80: .4byte 0x050002E0
_08028D84: .4byte 0x03002C30
_08028D88: .4byte 0x0000086E
_08028D8C:
	ldr r0, _08028E14 @ =0x084DC7D0
	ldr r1, _08028E18 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08028E1C @ =0x0850EC38
	ldr r1, _08028E20 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08028E24 @ =0x03002C30
	ldr r1, _08028E28 @ =0x0000086E
	adds r0, r0, r1
	movs r1, #0x5c
_08028DA6:
	strb r1, [r0]
_08028DA8:
	ldr r4, _08028E24 @ =0x03002C30
	movs r2, #0x84
	lsls r2, r2, #4
	adds r5, r4, r2
	movs r6, #0
	movs r2, #0
	ldr r0, _08028E2C @ =0x0000C604
	strh r0, [r5]
	ldr r3, _08028E30 @ =0x0000085C
	adds r0, r4, r3
	strb r6, [r0]
	ldr r0, _08028E34 @ =0x00000844
	adds r1, r4, r0
	movs r0, #0xe0
	strh r0, [r1]
	subs r3, #0x12
	adds r1, r4, r3
	movs r0, #7
	strb r0, [r1]
	ldr r1, _08028E38 @ =0x00000848
	adds r0, r4, r1
	movs r1, #0x40
	strb r1, [r0]
	subs r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08028E3C @ =0x00000858
	adds r0, r4, r1
	strh r2, [r0]
	ldr r2, _08028E40 @ =0x0000084B
	adds r1, r4, r2
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, _08028E44 @ =0x083B5F80
	adds r3, #0x25
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r0, _08028E48 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08028E50
	ldr r0, _08028E4C @ =0x00000842
	adds r1, r4, r0
	movs r0, #0xb8
	b _08028E62
	.align 2, 0
_08028E14: .4byte 0x084DC7D0
_08028E18: .4byte 0x06014800
_08028E1C: .4byte 0x0850EC38
_08028E20: .4byte 0x050002E0
_08028E24: .4byte 0x03002C30
_08028E28: .4byte 0x0000086E
_08028E2C: .4byte 0x0000C604
_08028E30: .4byte 0x0000085C
_08028E34: .4byte 0x00000844
_08028E38: .4byte 0x00000848
_08028E3C: .4byte 0x00000858
_08028E40: .4byte 0x0000084B
_08028E44: .4byte 0x083B5F80
_08028E48: .4byte 0x03001800
_08028E4C: .4byte 0x00000842
_08028E50:
	ldrh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
	ldr r3, _08028E7C @ =0x00000842
	adds r1, r4, r3
	movs r0, #0x38
_08028E62:
	strh r0, [r1]
	movs r0, #0x61
	bl play_sound_effect
	ldr r1, _08028E80 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08028E7C: .4byte 0x00000842
_08028E80: .4byte 0x03001800
	.syntax divided
