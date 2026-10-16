	.syntax unified

	thumb_func_start sub_0805EE94
sub_0805EE94: @ 0x0805EE94
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, _0805EEC8 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _0805EED0
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r4, _0805EECC @ =0x0000FFFF
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r5]
	lsls r1, r1, #2
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0805EF7E
	.align 2, 0
_0805EEC8: .4byte 0x03000440
_0805EECC: .4byte 0x0000FFFF
_0805EED0:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0805EF00 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r2]
	movs r0, #0
	str r0, [sp]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	ldr r2, _0805EF04 @ =0x01006000
	mov r0, sp
	bl CpuFastSet
	ldr r0, _0805EF08 @ =0x03000584
	ldrb r0, [r0]
	cmp r0, #1
	beq _0805EF30
	cmp r0, #1
	bgt _0805EF0C
	cmp r0, #0
	beq _0805EF12
	b _0805EF7E
	.align 2, 0
_0805EF00: .4byte 0x0000FDFF
_0805EF04: .4byte 0x01006000
_0805EF08: .4byte 0x03000584
_0805EF0C:
	cmp r0, #2
	beq _0805EF5C
	b _0805EF7E
_0805EF12:
	ldr r0, _0805EF28 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x58
	ldr r1, _0805EF2C @ =0x03002B74
	movs r2, #8
	bl CpuSet
	movs r0, #0
	bl dispatch_by_index_0476e8
	b _0805EF7E
	.align 2, 0
_0805EF28: .4byte 0x03006F74
_0805EF2C: .4byte 0x03002B74
_0805EF30:
	ldr r0, _0805EF50 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x58
	ldr r1, _0805EF54 @ =0x030017EC
	ldrb r1, [r1]
	lsls r1, r1, #6
	ldr r2, _0805EF58 @ =0x03000BEA
	adds r1, r1, r2
	movs r2, #7
	bl CpuSet
	movs r0, #1
	bl dispatch_by_index_0476e8
	b _0805EF7E
	.align 2, 0
_0805EF50: .4byte 0x03006F74
_0805EF54: .4byte 0x030017EC
_0805EF58: .4byte 0x03000BEA
_0805EF5C:
	ldr r0, _0805EF88 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x58
	ldr r1, _0805EF8C @ =0x030017EC
	ldrb r1, [r1]
	lsls r1, r1, #6
	ldr r2, _0805EF90 @ =0x03000BEA
	adds r1, r1, r2
	movs r2, #7
	bl CpuSet
	ldr r1, _0805EF94 @ =0x03002B8C
	movs r0, #0x12
	str r0, [r1]
	ldr r1, _0805EF98 @ =0x0300137C
	movs r0, #0xa
	str r0, [r1]
_0805EF7E:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805EF88: .4byte 0x03006F74
_0805EF8C: .4byte 0x030017EC
_0805EF90: .4byte 0x03000BEA
_0805EF94: .4byte 0x03002B8C
_0805EF98: .4byte 0x0300137C
	.syntax divided
