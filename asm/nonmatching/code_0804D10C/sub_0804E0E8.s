	.syntax unified

	thumb_func_start sub_0804E0E8
sub_0804E0E8: @ 0x0804E0E8
	push {r4, r5, r6, r7, lr}
	ldr r4, _0804E100 @ =0x030057E0
	ldr r0, _0804E104 @ =0x00000C93
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804E108
	cmp r0, #1
	bne _0804E0FC
	b _0804E2FC
_0804E0FC:
	b _0804E31A
	.align 2, 0
_0804E100: .4byte 0x030057E0
_0804E104: .4byte 0x00000C93
_0804E108:
	bl sub_08050B50
	ldr r2, _0804E12C @ =0x03002C30
	ldr r1, _0804E130 @ =0x00000BE6
	adds r0, r2, r1
	ldr r3, _0804E134 @ =0x00000C94
	adds r1, r4, r3
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r1, [r1]
	adds r0, r1, #0
	cmp r0, #0xff
	bne _0804E138
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0804E31A
	.align 2, 0
_0804E12C: .4byte 0x03002C30
_0804E130: .4byte 0x00000BE6
_0804E134: .4byte 0x00000C94
_0804E138:
	ldr r3, _0804E158 @ =0x00000BE8
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804E144
	b _0804E31A
_0804E144:
	movs r0, #0xf0
	ands r0, r1
	lsrs r0, r0, #4
	cmp r0, #1
	beq _0804E174
	cmp r0, #1
	bgt _0804E15C
	cmp r0, #0
	beq _0804E166
	b _0804E196
	.align 2, 0
_0804E158: .4byte 0x00000BE8
_0804E15C:
	cmp r0, #2
	beq _0804E180
	cmp r0, #3
	beq _0804E18C
	b _0804E196
_0804E166:
	ldr r0, _0804E170 @ =0x03002B64
	ldrb r1, [r0]
	movs r2, #0x40
	b _0804E192
	.align 2, 0
_0804E170: .4byte 0x03002B64
_0804E174:
	ldr r0, _0804E17C @ =0x03002B64
	ldrb r1, [r0]
	movs r2, #0x80
	b _0804E192
	.align 2, 0
_0804E17C: .4byte 0x03002B64
_0804E180:
	ldr r0, _0804E188 @ =0x03002B64
	ldrb r1, [r0]
	movs r2, #0x20
	b _0804E192
	.align 2, 0
_0804E188: .4byte 0x03002B64
_0804E18C:
	ldr r0, _0804E234 @ =0x03002B64
	ldrb r1, [r0]
	movs r2, #0x10
_0804E192:
	orrs r1, r2
	strb r1, [r0]
_0804E196:
	ldr r7, _0804E238 @ =0x03002C30
	ldr r0, _0804E23C @ =0x00000BE8
	adds r4, r7, r0
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804E1AA
	b _0804E31A
_0804E1AA:
	movs r0, #0x2f
	bl sub_080518F4
	adds r1, r0, #0
	movs r0, #0x10
	bl sub_0807CBBC
	strb r0, [r4]
	ldr r2, _0804E240 @ =0x00000BE7
	adds r1, r7, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804E1CC
	b _0804E31A
_0804E1CC:
	ldr r4, _0804E244 @ =0x030057E0
	ldr r3, _0804E248 @ =0x00000C52
	adds r0, r4, r3
	ldrh r0, [r0]
	bl sub_080526F0
	ldr r2, _0804E24C @ =0x00000C56
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _0804E250 @ =0x00000C54
	adds r0, r4, r3
	ldrh r0, [r0]
	bl sub_08052714
	ldr r2, _0804E254 @ =0x00000C57
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _0804E258 @ =0x00000C76
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E21A
	ldr r1, _0804E25C @ =0x00000C6E
	adds r0, r4, r1
	ldrh r0, [r0]
	bl sub_080526F0
	ldr r2, _0804E260 @ =0x00000C72
	adds r1, r4, r2
	strb r0, [r1]
	movs r3, #0xc7
	lsls r3, r3, #4
	adds r0, r4, r3
	ldrh r0, [r0]
	bl sub_08052714
	ldr r2, _0804E264 @ =0x00000C73
	adds r1, r4, r2
	strb r0, [r1]
_0804E21A:
	ldr r3, _0804E268 @ =0x00000BE6
	adds r5, r7, r3
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _0804E270
	ldr r0, _0804E26C @ =0x00000C93
	adds r1, r4, r0
	b _0804E282
	.align 2, 0
_0804E234: .4byte 0x03002B64
_0804E238: .4byte 0x03002C30
_0804E23C: .4byte 0x00000BE8
_0804E240: .4byte 0x00000BE7
_0804E244: .4byte 0x030057E0
_0804E248: .4byte 0x00000C52
_0804E24C: .4byte 0x00000C56
_0804E250: .4byte 0x00000C54
_0804E254: .4byte 0x00000C57
_0804E258: .4byte 0x00000C76
_0804E25C: .4byte 0x00000C6E
_0804E260: .4byte 0x00000C72
_0804E264: .4byte 0x00000C73
_0804E268: .4byte 0x00000BE6
_0804E26C: .4byte 0x00000C93
_0804E270:
	ldrb r0, [r5]
	ldr r1, _0804E28C @ =0x00000C94
	adds r6, r4, r1
	adds r1, r0, r6
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _0804E294
	ldr r2, _0804E290 @ =0x00000C93
	adds r1, r4, r2
_0804E282:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0804E31A
	.align 2, 0
_0804E28C: .4byte 0x00000C94
_0804E290: .4byte 0x00000C93
_0804E294:
	ldrb r1, [r1]
	ldr r3, _0804E2B8 @ =0x00000BEA
	adds r0, r7, r3
	ldrb r2, [r0]
	movs r0, #0x2f
	bl setup_battle_sprite_terrain
	ldrb r0, [r5]
	adds r0, r0, r6
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	beq _0804E2D4
	cmp r0, #1
	bgt _0804E2BC
	cmp r0, #0
	beq _0804E2C6
	b _0804E31A
	.align 2, 0
_0804E2B8: .4byte 0x00000BEA
_0804E2BC:
	cmp r0, #2
	beq _0804E2E0
	cmp r0, #3
	beq _0804E2EC
	b _0804E31A
_0804E2C6:
	ldr r0, _0804E2D0 @ =0x03002B64
	ldrb r1, [r0]
	movs r2, #0x40
	b _0804E2F2
	.align 2, 0
_0804E2D0: .4byte 0x03002B64
_0804E2D4:
	ldr r0, _0804E2DC @ =0x03002B64
	ldrb r1, [r0]
	movs r2, #0x80
	b _0804E2F2
	.align 2, 0
_0804E2DC: .4byte 0x03002B64
_0804E2E0:
	ldr r0, _0804E2E8 @ =0x03002B64
	ldrb r1, [r0]
	movs r2, #0x20
	b _0804E2F2
	.align 2, 0
_0804E2E8: .4byte 0x03002B64
_0804E2EC:
	ldr r0, _0804E2F8 @ =0x03002B64
	ldrb r1, [r0]
	movs r2, #0x10
_0804E2F2:
	orrs r1, r2
	strb r1, [r0]
	b _0804E31A
	.align 2, 0
_0804E2F8: .4byte 0x03002B64
_0804E2FC:
	movs r1, #0xc2
	lsls r1, r1, #4
	adds r0, r4, r1
	movs r2, #0xc1
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r2, #8
	bl memcpy_u8
	ldr r3, _0804E320 @ =0x00000C5F
	adds r1, r4, r3
	movs r0, #0
	strb r0, [r1]
	bl sub_08050244
_0804E31A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804E320: .4byte 0x00000C5F
	.syntax divided
