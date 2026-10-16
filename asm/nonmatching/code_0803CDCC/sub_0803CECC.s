	.syntax unified

	thumb_func_start sub_0803CECC
sub_0803CECC: @ 0x0803CECC
	push {r4, r5, lr}
	ldr r5, _0803CEEC @ =0x03002C30
	ldr r0, _0803CEF0 @ =0x03000440
	ldr r1, _0803CEF4 @ =0x0000012F
	adds r4, r0, r1
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r2, r0, r5
	adds r1, r2, #0
	adds r1, #0x2b
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803CEF8
	subs r0, #1
	strb r0, [r1]
	b _0803CF74
	.align 2, 0
_0803CEEC: .4byte 0x03002C30
_0803CEF0: .4byte 0x03000440
_0803CEF4: .4byte 0x0000012F
_0803CEF8:
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
	ldr r2, _0803CF68 @ =0x0000FDFF
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
	ldr r2, _0803CF6C @ =0x0000B00F
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r2, r0, r5
	adds r3, r2, #0
	adds r3, #0x2f
	ldrb r0, [r3]
	adds r1, r0, #0
	cmp r1, #0
	bne _0803CF70
	adds r0, r2, #0
	adds r0, #0x29
	strb r1, [r0]
	b _0803CF74
	.align 2, 0
_0803CF68: .4byte 0x0000FDFF
_0803CF6C: .4byte 0x0000B00F
_0803CF70:
	subs r0, #1
	strb r0, [r3]
_0803CF74:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
