	.syntax unified

	thumb_func_start update_battle_sprite_direction
update_battle_sprite_direction: @ 0x0806CBD4
	push {r4, r5, r6, r7, lr}
	ldr r0, _0806CBF4 @ =0x03001800
	adds r0, #0x41
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #3
	ble _0806CC00
	movs r2, #3
	ldr r7, _0806CBF8 @ =0x03002C30
	cmp r1, #8
	bne _0806CBEC
	movs r2, #4
_0806CBEC:
	ldr r1, _0806CBFC @ =0x00000786
	adds r0, r7, r1
	strh r2, [r0]
	b _0806CC30
	.align 2, 0
_0806CBF4: .4byte 0x03001800
_0806CBF8: .4byte 0x03002C30
_0806CBFC: .4byte 0x00000786
_0806CC00:
	movs r0, #3
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0806CC24
	subs r0, #5
	movs r2, #1
	ldr r7, _0806CC1C @ =0x03002C30
	cmp r1, r0
	bne _0806CC14
	movs r2, #2
_0806CC14:
	ldr r3, _0806CC20 @ =0x00000786
	adds r0, r7, r3
	strh r2, [r0]
	b _0806CC30
	.align 2, 0
_0806CC1C: .4byte 0x03002C30
_0806CC20: .4byte 0x00000786
_0806CC24:
	ldr r2, _0806CC6C @ =0x03002C30
	ldr r0, _0806CC70 @ =0x00000786
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	adds r7, r2, #0
_0806CC30:
	ldr r1, _0806CC74 @ =0x000007A1
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806CC3C
	b _0806CD3E
_0806CC3C:
	ldr r2, _0806CC78 @ =0x0000079A
	adds r0, r7, r2
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	movs r1, #6
	cmp r0, #0
	beq _0806CC4E
	movs r1, #5
_0806CC4E:
	ldr r3, _0806CC70 @ =0x00000786
	adds r0, r7, r3
	strh r1, [r0]
	ldr r1, _0806CC7C @ =0x000007A2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806CC80
	movs r2, #0xf3
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #0x20
	b _0806CC8A
	.align 2, 0
_0806CC6C: .4byte 0x03002C30
_0806CC70: .4byte 0x00000786
_0806CC74: .4byte 0x000007A1
_0806CC78: .4byte 0x0000079A
_0806CC7C: .4byte 0x000007A2
_0806CC80:
	movs r3, #0xf3
	lsls r3, r3, #3
	adds r1, r7, r3
	ldrh r0, [r1]
	subs r0, #0x20
_0806CC8A:
	strh r0, [r1]
	adds r5, r7, #0
	ldr r1, _0806CCE8 @ =0x00000782
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _0806CCEC @ =0x00000842
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _0806CCF0 @ =0x00000784
	adds r4, r5, r3
	ldr r0, _0806CCF4 @ =0x0000079A
	adds r6, r5, r0
	ldrh r0, [r6]
	movs r1, #0xa
	bl sub_0807CD58
	adds r0, #0xc
	ldrh r4, [r4]
	adds r0, r0, r4
	ldr r2, _0806CCF8 @ =0x00000844
	adds r1, r5, r2
	strh r0, [r1]
	ldrh r1, [r6]
	cmp r1, #0x1f
	bhi _0806CD04
	ldr r2, _0806CCFC @ =0x08485E84
	ldrh r0, [r6]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x19
	adds r0, #0x40
	movs r3, #0xf1
	lsls r3, r3, #3
	adds r1, r5, r3
	strb r0, [r1]
	ldrh r0, [r6]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x19
	adds r0, #0x40
	ldr r2, _0806CD00 @ =0x00000789
	adds r1, r5, r2
	strb r0, [r1]
	b _0806CD3E
	.align 2, 0
_0806CCE8: .4byte 0x00000782
_0806CCEC: .4byte 0x00000842
_0806CCF0: .4byte 0x00000784
_0806CCF4: .4byte 0x0000079A
_0806CCF8: .4byte 0x00000844
_0806CCFC: .4byte 0x08485E84
_0806CD00: .4byte 0x00000789
_0806CD04:
	movs r3, #0xf4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #3
	bne _0806CD28
	movs r0, #4
	ands r0, r1
	movs r1, #0x2c
	cmp r0, #0
	beq _0806CD1C
	movs r1, #0x2b
_0806CD1C:
	ldr r2, _0806CD24 @ =0x00000E46
	adds r0, r5, r2
	b _0806CD3C
	.align 2, 0
_0806CD24: .4byte 0x00000E46
_0806CD28:
	cmp r0, #2
	bne _0806CD3E
	movs r0, #4
	ands r0, r1
	movs r1, #0x2d
	cmp r0, #0
	beq _0806CD38
	movs r1, #0x2c
_0806CD38:
	ldr r3, _0806CD44 @ =0x00000E46
	adds r0, r7, r3
_0806CD3C:
	strh r1, [r0]
_0806CD3E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806CD44: .4byte 0x00000E46
	.syntax divided
