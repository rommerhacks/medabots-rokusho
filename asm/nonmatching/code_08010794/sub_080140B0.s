	.syntax unified

	thumb_func_start sub_080140B0
sub_080140B0: @ 0x080140B0
	push {r4, lr}
	ldr r0, _080140CC @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x84
	ldrb r2, [r4]
	adds r1, r0, #0
	cmp r2, #1
	beq _08014130
	cmp r2, #1
	bgt _080140D0
	cmp r2, #0
	beq _080140DE
	b _08014220
	.align 2, 0
_080140CC: .4byte 0x03000440
_080140D0:
	cmp r2, #2
	bne _080140D6
	b _080141D0
_080140D6:
	cmp r2, #3
	bne _080140DC
	b _080141F4
_080140DC:
	b _08014220
_080140DE:
	ldr r3, _08014124 @ =0x03002C30
	adds r1, r3, #0
	adds r1, #0xc0
	movs r2, #0
	ldr r0, _08014128 @ =0x0000C005
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xdc
	strb r2, [r0]
	adds r1, #2
	movs r0, #0x78
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #6
	movs r0, #0xf
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xc0
	strb r0, [r1]
	subs r1, #5
	movs r0, #0x90
	lsls r0, r0, #4
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xe0
	movs r1, #8
	strb r1, [r0]
	ldr r2, _0801412C @ =0x0400004C
	lsls r0, r1, #0xc
	lsls r1, r1, #8
	adds r0, r0, r1
	strh r0, [r2]
	b _080141E4
	.align 2, 0
_08014124: .4byte 0x03002C30
_08014128: .4byte 0x0000C005
_0801412C: .4byte 0x0400004C
_08014130:
	ldr r0, _080141B4 @ =0x03001780
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _0801413C
	b _0801424A
_0801413C:
	ldr r0, _080141B8 @ =0x03002C30
	mov ip, r0
	adds r0, #0xe0
	ldrb r2, [r0]
	subs r2, #1
	strb r2, [r0]
	ldr r3, _080141BC @ =0x0400004C
	ldrb r0, [r0]
	lsls r1, r0, #0xc
	lsls r0, r0, #8
	adds r1, r1, r0
	strh r1, [r3]
	lsls r2, r2, #0x18
	cmp r2, #0
	bne _0801424A
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	movs r2, #0
	ldr r0, _080141C0 @ =0x0000C224
	strh r0, [r1]
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, ip
	strb r2, [r0]
	movs r1, #0x81
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0x78
	strh r0, [r1]
	movs r1, #0x82
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0x48
	strh r0, [r1]
	movs r1, #0x85
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0xf
	strb r0, [r1]
	ldr r1, _080141C4 @ =0x0000010B
	add r1, ip
	movs r0, #0xc0
	strb r0, [r1]
	movs r1, #0x83
	lsls r1, r1, #1
	add r1, ip
	ldr r0, _080141C8 @ =0x00000901
	strh r0, [r1]
	ldr r1, _080141CC @ =0x00000109
	add r1, ip
	movs r0, #8
	strb r0, [r1]
	movs r1, #0x84
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0x40
	strb r0, [r1]
	b _080141E4
	.align 2, 0
_080141B4: .4byte 0x03001780
_080141B8: .4byte 0x03002C30
_080141BC: .4byte 0x0400004C
_080141C0: .4byte 0x0000C224
_080141C4: .4byte 0x0000010B
_080141C8: .4byte 0x00000901
_080141CC: .4byte 0x00000109
_080141D0:
	ldr r0, _080141EC @ =0x03002C30
	ldr r2, _080141F0 @ =0x00000109
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x60
	bne _0801424A
_080141E4:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0801424A
	.align 2, 0
_080141EC: .4byte 0x03002C30
_080141F0: .4byte 0x00000109
_080141F4:
	ldr r0, _08014218 @ =0x03002C30
	ldr r3, _0801421C @ =0x00000109
	adds r2, r0, r3
	ldrb r0, [r2]
	subs r0, #8
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bne _0801424A
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r1, #0x86
	movs r0, #0
	strh r0, [r1]
	b _0801424A
	.align 2, 0
_08014218: .4byte 0x03002C30
_0801421C: .4byte 0x00000109
_08014220:
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3c
	bne _0801424A
	movs r0, #3
	movs r1, #2
	bl clear_battle_sprite_slot
	ldr r0, _08014250 @ =0x0850DDF8
	ldr r1, _08014254 @ =0x050003E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08014258 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0801424A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08014250: .4byte 0x0850DDF8
_08014254: .4byte 0x050003E0
_08014258: .4byte 0x0300137C
	.syntax divided
