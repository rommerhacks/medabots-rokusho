	.syntax unified

	thumb_func_start sub_0805E5B0
sub_0805E5B0: @ 0x0805E5B0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0
	ldr r4, _0805E624 @ =0x03006F74
	movs r3, #0xfe
_0805E5EE:
	ldr r1, [r4]
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	adds r1, #0x58
	adds r1, r1, r0
	strb r3, [r1]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xf
	ble _0805E5EE
	movs r0, #5
	movs r1, #0xa
	bl clear_sprite_table_mask
	ldr r0, _0805E628 @ =0x03000584
	ldrb r0, [r0]
	cmp r0, #1
	beq _0805E678
	cmp r0, #1
	bgt _0805E62C
	cmp r0, #0
	beq _0805E638
	ldr r7, _0805E624 @ =0x03006F74
	b _0805E754
	.align 2, 0
_0805E624: .4byte 0x03006F74
_0805E628: .4byte 0x03000584
_0805E62C:
	cmp r0, #2
	beq _0805E718
	ldr r7, _0805E634 @ =0x03006F74
	b _0805E754
	.align 2, 0
_0805E634: .4byte 0x03006F74
_0805E638:
	movs r2, #0
	ldr r7, _0805E670 @ =0x03006F74
	adds r4, r7, #0
	ldr r5, _0805E674 @ =0x08483C68
_0805E640:
	ldr r1, [r4]
	lsls r0, r2, #0x18
	asrs r3, r0, #0x18
	adds r1, #0x58
	adds r1, r1, r3
	ldr r0, [r5]
	adds r0, r0, r3
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x58
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0xfe
	beq _0805E752
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xf
	ble _0805E640
	b _0805E752
	.align 2, 0
_0805E670: .4byte 0x03006F74
_0805E674: .4byte 0x08483C68
_0805E678:
	ldr r1, _0805E6C4 @ =0x03000BE0
	ldr r0, _0805E6C8 @ =0x030017EC
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	cmp r0, #1
	bhi _0805E6D4
	movs r2, #0
	ldr r7, _0805E6CC @ =0x03006F74
	adds r0, #0x20
	adds r4, r7, #0
	ldr r1, _0805E6D0 @ =0x083B6410
	lsls r0, r0, #2
	adds r5, r0, r1
_0805E696:
	ldr r1, [r4]
	lsls r0, r2, #0x18
	asrs r3, r0, #0x18
	adds r1, #0x58
	adds r1, r1, r3
	ldr r0, [r5]
	adds r0, r0, r3
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, #0x58
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0xfe
	beq _0805E70A
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xf
	ble _0805E696
	b _0805E70A
	.align 2, 0
_0805E6C4: .4byte 0x03000BE0
_0805E6C8: .4byte 0x030017EC
_0805E6CC: .4byte 0x03006F74
_0805E6D0: .4byte 0x083B6410
_0805E6D4:
	movs r2, #0
	ldr r7, _0805E710 @ =0x03006F74
	lsls r1, r0, #2
	adds r4, r7, #0
	ldr r0, _0805E714 @ =0x083B6410
	adds r5, r1, r0
_0805E6E0:
	ldr r1, [r4]
	lsls r0, r2, #0x18
	asrs r3, r0, #0x18
	adds r1, #0x58
	adds r1, r1, r3
	ldr r0, [r5]
	adds r0, r0, r3
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, #0x58
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0xfe
	beq _0805E70A
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xf
	ble _0805E6E0
_0805E70A:
	ldr r0, [r7]
	strb r2, [r0, #0xf]
	b _0805E754
	.align 2, 0
_0805E710: .4byte 0x03006F74
_0805E714: .4byte 0x083B6410
_0805E718:
	movs r2, #0
	ldr r7, _0805E834 @ =0x03006F74
	ldr r6, _0805E838 @ =0x030017EC
	adds r4, r7, #0
	ldr r5, _0805E83C @ =0x03000BEA
_0805E722:
	ldr r1, [r4]
	lsls r0, r2, #0x18
	asrs r3, r0, #0x18
	adds r1, #0x58
	adds r1, r1, r3
	ldrb r0, [r6]
	lsls r0, r0, #6
	adds r0, r3, r0
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x58
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0xfe
	beq _0805E752
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xf
	ble _0805E722
_0805E752:
	strb r2, [r1, #0xf]
_0805E754:
	ldr r1, [r7]
	adds r0, r1, #0
	adds r0, #0x58
	adds r1, #0x68
	movs r2, #8
	bl CpuSet
	ldr r0, [r7]
	adds r0, #0x58
	bl calc_text_pixel_width
	ldr r4, _0805E840 @ =0x03002C30
	adds r0, #0x28
	movs r1, #0x81
	lsls r1, r1, #1
	adds r5, r4, r1
	movs r2, #0
	strh r0, [r5]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r0, #0x1b
	strh r0, [r1]
	ldr r0, [r7]
	adds r0, #0x58
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xd
	str r1, [sp, #4]
	movs r1, #1
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	movs r1, #5
	movs r2, #5
	movs r3, #3
	bl render_text_sprites_08040DB8
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r3, r0, #2
	ldr r0, [r7]
	ldrb r2, [r0, #0xf]
	lsls r1, r2, #0x18
	asrs r0, r1, #0x18
	cmp r0, #9
	bgt _0805E7EA
	adds r6, r4, #0
	movs r5, #0
	ldr r4, _0805E844 @ =0x083B4C88
_0805E7B6:
	asrs r2, r1, #0x18
	adds r1, r2, #5
	lsls r1, r1, #6
	adds r1, r1, r6
	movs r0, #0xc0
	lsls r0, r0, #8
	strh r0, [r1]
	strb r5, [r1, #0x1c]
	movs r0, #0xd
	strb r0, [r1, #0xa]
	movs r0, #0x42
	strh r0, [r1, #6]
	strh r3, [r1, #2]
	movs r0, #0x1c
	strh r0, [r1, #4]
	movs r0, #0xff
	strb r0, [r1, #0xb]
	adds r0, r4, #0
	adds r0, #0x86
	ldrb r0, [r0]
	adds r3, r3, r0
	adds r2, #1
	lsls r1, r2, #0x18
	asrs r0, r1, #0x18
	cmp r0, #9
	ble _0805E7B6
_0805E7EA:
	ldr r0, _0805E848 @ =0x08483AA0
	ldr r1, _0805E84C @ =0x0202FA20
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0805E850 @ =0x084E2E58
	ldr r1, _0805E854 @ =0x0202F9C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0805E858 @ =0x084E2E38
	ldr r1, _0805E85C @ =0x0202F9A0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0805E860 @ =0x080AF810
	ldr r1, _0805E864 @ =0x0202F800
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0805E868 @ =0x08793428
	ldr r1, _0805E86C @ =0x0202FA00
	movs r2, #0x80
	bl CpuFastSet
	ldr r0, _0805E870 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _0805E874 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805E834: .4byte 0x03006F74
_0805E838: .4byte 0x030017EC
_0805E83C: .4byte 0x03000BEA
_0805E840: .4byte 0x03002C30
_0805E844: .4byte 0x083B4C88
_0805E848: .4byte 0x08483AA0
_0805E84C: .4byte 0x0202FA20
_0805E850: .4byte 0x084E2E58
_0805E854: .4byte 0x0202F9C0
_0805E858: .4byte 0x084E2E38
_0805E85C: .4byte 0x0202F9A0
_0805E860: .4byte 0x080AF810
_0805E864: .4byte 0x0202F800
_0805E868: .4byte 0x08793428
_0805E86C: .4byte 0x0202FA00
_0805E870: .4byte 0x03000440
_0805E874: .4byte 0x0300137C
	.syntax divided
