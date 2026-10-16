	.syntax unified

	thumb_func_start sub_08061080
sub_08061080: @ 0x08061080
	push {r4, r5, r6, r7, lr}
	ldr r7, _080610C8 @ =0x03006F74
	ldr r1, [r7]
	ldrb r0, [r1, #6]
	cmp r0, #1
	bne _08061100
	ldrb r0, [r1, #0x19]
	movs r1, #8
	bl battle_menu_highlight_icons
	ldr r0, _080610CC @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _080610D8
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r4, #0x20
	subs r1, r4, r1
	ldr r2, _080610D0 @ =0x00007FFE
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r5]
	lsls r0, r0, #2
	subs r4, r4, r0
	ldr r2, _080610D4 @ =0x00007FFD
	movs r0, #0
	adds r1, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08061172
	.align 2, 0
_080610C8: .4byte 0x03006F74
_080610CC: .4byte 0x03000440
_080610D0: .4byte 0x00007FFE
_080610D4: .4byte 0x00007FFD
_080610D8:
	ldr r0, [r7]
	movs r5, #0
	movs r4, #0
	strh r4, [r0, #2]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	ldr r0, [r7]
	strh r4, [r0, #2]
	strb r5, [r0]
	ldr r0, [r7]
	strb r5, [r0, #6]
	ldr r1, _080610FC @ =0x0300137C
	movs r0, #9
	b _08061170
	.align 2, 0
_080610FC: .4byte 0x0300137C
_08061100:
	ldr r0, _08061138 @ =0x03000440
	adds r6, r0, #0
	adds r6, #0x84
	ldrb r0, [r6]
	cmp r0, #8
	bhi _08061140
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r4, #0x20
	subs r1, r4, r1
	ldr r5, _0806113C @ =0x0000FFFF
	movs r0, #0
	adds r2, r5, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r6]
	lsls r0, r0, #2
	subs r4, r4, r0
	movs r0, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b _08061172
	.align 2, 0
_08061138: .4byte 0x03000440
_0806113C: .4byte 0x0000FFFF
_08061140:
	movs r5, #0
	movs r4, #0
	strh r4, [r1, #2]
	ldr r1, _08061178 @ =0x03002C30
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r2, r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	ldr r0, [r7]
	strh r4, [r0, #2]
	strb r5, [r0]
	ldr r1, _0806117C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
_08061170:
	str r0, [r1]
_08061172:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061178: .4byte 0x03002C30
_0806117C: .4byte 0x0300137C
	.syntax divided
