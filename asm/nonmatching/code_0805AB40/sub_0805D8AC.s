	.syntax unified

	thumb_func_start sub_0805D8AC
sub_0805D8AC: @ 0x0805D8AC
	push {r4, r5, lr}
	ldr r0, _0805D920 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _0805D92C
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r4, #0x20
	subs r1, r4, r1
	ldr r2, _0805D924 @ =0x00003FFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r5]
	lsls r0, r0, #2
	subs r4, r4, r0
	ldr r2, _0805D928 @ =0x0000FFFF
	movs r0, #0
	adds r1, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0805D93E
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
	b _0805D93E
	.align 2, 0
_0805D920: .4byte 0x03000440
_0805D924: .4byte 0x00003FFF
_0805D928: .4byte 0x0000FFFF
_0805D92C:
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	ldr r1, _0805D944 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805D93E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805D944: .4byte 0x0300137C
	.syntax divided
