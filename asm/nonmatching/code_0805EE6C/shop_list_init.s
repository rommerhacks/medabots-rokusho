	.syntax unified

	thumb_func_start shop_list_init
shop_list_init: @ 0x08061848
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080619E8 @ =0x0400000A
	ldr r4, _080619EC @ =0x00001B05
	adds r0, r4, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _080619F0 @ =0x00001A06
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _080619F4 @ =0x08784DA4
	ldr r1, _080619F8 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r2, _080619FC @ =0x03002C30
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r2, r3
	movs r0, #0x84
	lsls r0, r0, #8
	strh r0, [r1]
	movs r4, #0x87
	lsls r4, r4, #2
	adds r0, r2, r4
	movs r1, #2
	strb r1, [r0]
	adds r3, #0xa
	adds r0, r2, r3
	strb r1, [r0]
	subs r4, #0x16
	adds r1, r2, r4
	movs r0, #6
	strh r0, [r1]
	movs r4, #0
	adds r5, r2, #0
	movs r3, #2
	adds r6, r5, #0
_080618AA:
	lsls r2, r4, #0x18
	asrs r2, r2, #0x18
	adds r1, r2, #0
	adds r1, #0xb
	lsls r1, r1, #6
	adds r1, r1, r5
	movs r0, #0x80
	lsls r0, r0, #8
	strh r0, [r1]
	strb r3, [r1, #0x1c]
	strb r3, [r1, #0xa]
	movs r0, #5
	strh r0, [r1, #6]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, #0xd0
	strh r0, [r1, #2]
	ldr r0, _08061A00 @ =0x03006F74
	ldr r0, [r0]
	ldrb r0, [r0, #0x1a]
	lsls r0, r0, #4
	adds r0, #0x54
	strh r0, [r1, #4]
	adds r2, #1
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	asrs r2, r2, #0x18
	cmp r2, #1
	ble _080618AA
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r4, #0
	ldr r0, _08061A04 @ =0x084C6A98
	mov r8, r0
	adds r7, r6, #0
	movs r2, #2
	movs r5, #0x84
	lsls r5, r5, #8
_08061906:
	lsls r0, r4, #0x18
	asrs r1, r0, #0x18
	adds r0, r1, #0
	adds r0, #0x68
	lsls r0, r0, #6
	adds r3, r0, r7
	strh r5, [r3]
	strb r2, [r3, #0x1c]
	strb r2, [r3, #0xa]
	movs r0, #8
	strh r0, [r3, #6]
	movs r0, #0x1c
	strh r0, [r3, #2]
	movs r0, #0x44
	cmp r1, #0
	beq _08061928
	movs r0, #0x95
_08061928:
	strh r0, [r3, #4]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	ble _08061906
	movs r1, #0xd2
	lsls r1, r1, #5
	adds r2, r6, r1
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #6
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r4, #0
	movs r5, #0x84
	lsls r5, r5, #8
	movs r3, #2
_08061950:
	lsls r2, r4, #0x18
	asrs r2, r2, #0x18
	adds r1, r2, #0
	adds r1, #0x6a
	lsls r1, r1, #6
	adds r1, r1, r6
	strh r5, [r1]
	strb r3, [r1, #0x1c]
	movs r0, #3
	strb r0, [r1, #0xa]
	movs r0, #0x78
	strh r0, [r1, #2]
	lsls r0, r2, #4
	adds r0, #0x50
	strh r0, [r1, #4]
	adds r2, #1
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	asrs r2, r2, #0x18
	cmp r2, #3
	ble _08061950
	movs r4, #0
	ldr r5, _080619FC @ =0x03002C30
	movs r3, #0x84
	lsls r3, r3, #8
_08061982:
	lsls r2, r4, #0x18
	asrs r2, r2, #0x18
	adds r1, r2, #0
	adds r1, #0x6e
	lsls r1, r1, #6
	adds r1, r1, r5
	strh r3, [r1]
	movs r0, #2
	strb r0, [r1, #0x1c]
	movs r0, #3
	strb r0, [r1, #0xa]
	adds r0, r2, #0
	adds r0, #0x1d
	strh r0, [r1, #6]
	movs r0, #0x90
	strh r0, [r1, #2]
	lsls r0, r2, #4
	adds r0, #0x50
	strh r0, [r1, #4]
	adds r2, #1
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	asrs r2, r2, #0x18
	cmp r2, #3
	ble _08061982
	ldr r1, _08061A08 @ =0x04000052
	movs r0, #0x10
	strh r0, [r1]
	ldr r1, _08061A0C @ =0x06017400
	mov r0, r8
	bl lz_decompress_dispatch
	ldr r1, _080619FC @ =0x03002C30
	ldr r4, _08061A10 @ =0x00000202
	adds r2, r1, r4
	movs r0, #8
	strh r0, [r2]
	ldr r3, _08061A00 @ =0x03006F74
	ldr r2, [r3]
	ldrb r0, [r2, #0x1a]
	lsls r0, r0, #4
	adds r0, #0x54
	adds r4, #2
	adds r1, r1, r4
	strh r0, [r1]
	ldrb r0, [r2, #5]
	cmp r0, #1
	bne _08061A14
	bl shop_build_sell_list
	b _08061AA8
	.align 2, 0
_080619E8: .4byte 0x0400000A
_080619EC: .4byte 0x00001B05
_080619F0: .4byte 0x00001A06
_080619F4: .4byte gUnk_08784DA4
_080619F8: .4byte 0x06010000
_080619FC: .4byte 0x03002C30
_08061A00: .4byte 0x03006F74
_08061A04: .4byte gUnk_084C6A98
_08061A08: .4byte 0x04000052
_08061A0C: .4byte 0x06017400
_08061A10: .4byte 0x00000202
_08061A14:
	movs r4, #0
	movs r0, #0x81
	lsls r0, r0, #0x12
	mov sl, r0
	ldr r1, _08061B54 @ =0x02040004
	mov sb, r1
	ldr r2, _08061B58 @ =0x03004C40
	mov r8, r2
	ldr r7, _08061B5C @ =0x0300052E
_08061A26:
	ldr r0, _08061B60 @ =0x03002420
	ldrb r1, [r0]
	lsls r1, r1, #2
	lsls r0, r4, #0x18
	asrs r6, r0, #0x18
	adds r1, r1, r6
	ldr r0, _08061B64 @ =0x08483E50
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _08061A92
	cmp r0, #0x20
	bne _08061A48
	ldr r0, [r3]
	ldrb r0, [r0, #0x19]
	cmp r0, #3
	bne _08061A92
_08061A48:
	lsls r5, r6, #3
	mov r2, sl
	adds r4, r5, r2
	ldrb r0, [r1]
	strh r0, [r4]
	ldrh r1, [r4]
	lsls r1, r1, #1
	ldr r0, [r3]
	ldrb r2, [r0, #0x19]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r1, r1, r0
	add r1, r8
	ldrb r0, [r1]
	strb r0, [r4, #2]
	ldrh r0, [r4]
	ldr r1, [r3]
	ldrb r1, [r1, #0x19]
	adds r2, r7, #0
	str r3, [sp]
	bl load_part_data
	ldrb r0, [r7, #3]
	strb r0, [r4, #3]
	add r5, sb
	ldrb r1, [r7, #0xb]
	movs r0, #0x64
	muls r0, r1, r0
	str r0, [r5]
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	asrs r0, r0, #0x18
	ldr r3, [sp]
	cmp r0, #3
	ble _08061A26
_08061A92:
	lsls r0, r4, #0x18
	asrs r0, r0, #0x15
	movs r3, #0x81
	lsls r3, r3, #0x12
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0, #2]
	ldr r0, _08061B68 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x20
	strb r4, [r0]
_08061AA8:
	movs r4, #0
	ldr r5, _08061B68 @ =0x03006F74
_08061AAC:
	ldr r2, [r5]
	adds r0, r2, #0
	adds r0, #0x20
	ldrb r1, [r0]
	lsls r0, r4, #0x18
	asrs r4, r0, #0x18
	cmp r1, r4
	ble _08061ADA
	lsls r0, r4, #3
	movs r1, #0x81
	lsls r1, r1, #0x12
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrb r1, [r2, #0x19]
	adds r2, r4, #0
	bl load_battle_sprite_tiles
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	ble _08061AAC
_08061ADA:
	ldr r1, [r5]
	movs r0, #0
	str r0, [r1, #0x1c]
	movs r4, #0
	adds r1, #0x20
	ldr r5, _08061B68 @ =0x03006F74
	ldr r2, _08061B6C @ =0x0300137C
	mov r8, r2
	ldrb r1, [r1]
	cmp r4, r1
	bge _08061B20
	mov ip, r5
	ldr r7, _08061B70 @ =0x02023000
	ldr r6, _08061B54 @ =0x02040004
_08061AF6:
	mov r0, ip
	ldr r3, [r0]
	lsls r1, r4, #0x18
	asrs r1, r1, #0x18
	adds r0, r1, r7
	ldrb r2, [r0]
	lsls r0, r1, #3
	adds r0, r0, r6
	ldr r0, [r0]
	muls r2, r0, r2
	ldr r0, [r3, #0x1c]
	adds r0, r0, r2
	str r0, [r3, #0x1c]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	asrs r1, r1, #0x18
	adds r3, #0x20
	ldrb r3, [r3]
	cmp r1, r3
	blt _08061AF6
_08061B20:
	ldr r1, [r5]
	ldrb r0, [r1, #5]
	cmp r0, #0
	beq _08061B2E
	ldr r0, [r1, #0x1c]
	lsrs r0, r0, #1
	str r0, [r1, #0x1c]
_08061B2E:
	ldr r1, [r5]
	ldr r0, [r1, #0x1c]
	ldr r2, _08061B74 @ =0x0001869F
	cmp r0, r2
	bls _08061B3A
	str r2, [r1, #0x1c]
_08061B3A:
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061B54: .4byte 0x02040004
_08061B58: .4byte 0x03004C40
_08061B5C: .4byte 0x0300052E
_08061B60: .4byte 0x03002420
_08061B64: .4byte gUnk_08483E50
_08061B68: .4byte 0x03006F74
_08061B6C: .4byte 0x0300137C
_08061B70: .4byte 0x02023000
_08061B74: .4byte 0x0001869F
	.syntax divided
