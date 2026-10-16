	.syntax unified

	thumb_func_start sub_0804D5A4
sub_0804D5A4: @ 0x0804D5A4
	push {r4, r5, lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r3, _0804D5D8 @ =0x030057E0
	ldr r1, _0804D5DC @ =0x00000C94
	adds r0, r3, r1
	ldrb r2, [r0]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0804D680
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _0804D5EE
	ldr r2, _0804D5E0 @ =0x00000C95
	adds r1, r3, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _0804D5E4
	movs r0, #0x2f
	bl sub_0804877C
	b _0804D702
	.align 2, 0
_0804D5D8: .4byte 0x030057E0
_0804D5DC: .4byte 0x00000C94
_0804D5E0: .4byte 0x00000C95
_0804D5E4:
	ldrb r1, [r1]
	movs r0, #0x2f
	bl sub_08050770
	b _0804D702
_0804D5EE:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0804D652
	ldr r5, _0804D63C @ =0x00000CB4
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r4, r0, r3
	ldr r1, _0804D640 @ =0x000005DE
	adds r0, r4, r1
	ldrh r2, [r0]
	ldr r0, _0804D644 @ =0x00000FFF
	subs r5, #0x26
	adds r1, r3, r5
	ands r0, r2
	ldrh r1, [r1]
	cmp r0, r1
	bne _0804D702
	movs r1, #0xbc
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #3
	movs r2, #0xc4
	lsls r2, r2, #0x16
	adds r0, r0, r2
	lsrs r2, r0, #0x18
	adds r5, #7
	adds r1, r3, r5
	ldrb r0, [r1]
	cmp r0, #0
	bne _0804D648
	adds r0, r2, #0
	bl sub_0804877C
	b _0804D702
	.align 2, 0
_0804D63C: .4byte 0x00000CB4
_0804D640: .4byte 0x000005DE
_0804D644: .4byte 0x00000FFF
_0804D648:
	ldrb r1, [r1]
	adds r0, r2, #0
	bl sub_08050770
	b _0804D702
_0804D652:
	ldr r0, _0804D670 @ =0x00000C95
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _0804D674
	movs r0, #0xf
	ands r0, r2
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_0804877C
	b _0804D702
	.align 2, 0
_0804D670: .4byte 0x00000C95
_0804D674:
	movs r0, #0xf
	ands r0, r2
	ldrb r1, [r1]
	bl sub_08050780
	b _0804D702
_0804D680:
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _0804D69C
	ldr r1, _0804D698 @ =0x00000C95
	adds r0, r3, r1
	ldrb r1, [r0]
	movs r0, #0x2f
	bl sub_080507A0
	b _0804D702
	.align 2, 0
_0804D698: .4byte 0x00000C95
_0804D69C:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0804D6F4
	ldr r2, _0804D6E4 @ =0x00000CB4
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r4, r0, r3
	ldr r5, _0804D6E8 @ =0x000005DE
	adds r0, r4, r5
	ldrh r2, [r0]
	ldr r0, _0804D6EC @ =0x00000FFF
	ldr r5, _0804D6F0 @ =0x00000C8E
	adds r1, r3, r5
	ands r0, r2
	ldrh r1, [r1]
	cmp r0, r1
	bne _0804D702
	movs r1, #0xbc
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #3
	movs r2, #0xc4
	lsls r2, r2, #0x16
	adds r0, r0, r2
	lsrs r2, r0, #0x18
	adds r5, #7
	adds r0, r3, r5
	ldrb r1, [r0]
	adds r0, r2, #0
	bl sub_080507A0
	b _0804D702
	.align 2, 0
_0804D6E4: .4byte 0x00000CB4
_0804D6E8: .4byte 0x000005DE
_0804D6EC: .4byte 0x00000FFF
_0804D6F0: .4byte 0x00000C8E
_0804D6F4:
	movs r0, #0xf
	ands r0, r2
	ldr r2, _0804D708 @ =0x00000C95
	adds r1, r3, r2
	ldrb r1, [r1]
	bl sub_080507C0
_0804D702:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804D708: .4byte 0x00000C95
	.syntax divided
