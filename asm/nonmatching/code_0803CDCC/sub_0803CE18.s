	.syntax unified

	thumb_func_start sub_0803CE18
sub_0803CE18: @ 0x0803CE18
	push {r4, r5, r6, lr}
	ldr r5, _0803CE3C @ =0x03002C30
	ldr r0, _0803CE40 @ =0x03000440
	ldr r1, _0803CE44 @ =0x0000012F
	adds r4, r0, r1
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r2, r0, r5
	adds r1, r2, #0
	adds r1, #0x2b
	ldrb r0, [r1]
	adds r6, r0, #0
	cmp r6, #0
	beq _0803CE48
	subs r0, #1
	strb r0, [r1]
	b _0803CEC4
	.align 2, 0
_0803CE3C: .4byte 0x03002C30
_0803CE40: .4byte 0x03000440
_0803CE44: .4byte 0x0000012F
_0803CE48:
	adds r0, r2, #0
	adds r0, #0x2e
	ldrb r1, [r0]
	lsls r1, r1, #0xa
	subs r0, #1
	ldrb r0, [r0]
	lsls r0, r0, #5
	orrs r1, r0
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r2, #0
	adds r1, #0x2f
	ldrb r1, [r1]
	ldr r2, _0803CEB8 @ =0x0000FDFF
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r2, r0, r5
	adds r0, r2, #0
	adds r0, #0x2e
	ldrb r1, [r0]
	lsls r1, r1, #0xa
	subs r0, #1
	ldrb r0, [r0]
	lsls r0, r0, #5
	orrs r1, r0
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r2, #0
	adds r1, #0x2f
	ldrb r1, [r1]
	ldr r2, _0803CEBC @ =0x0000B00F
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r1, r0, r5
	adds r2, r1, #0
	adds r2, #0x2f
	ldrb r0, [r2]
	cmp r0, #0x10
	bne _0803CEC0
	adds r0, r1, #0
	adds r0, #0x29
	strb r6, [r0]
	b _0803CEC4
	.align 2, 0
_0803CEB8: .4byte 0x0000FDFF
_0803CEBC: .4byte 0x0000B00F
_0803CEC0:
	adds r0, #1
	strb r0, [r2]
_0803CEC4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
