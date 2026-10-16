	.syntax unified

	thumb_func_start sub_0806174C
sub_0806174C: @ 0x0806174C
	push {r4, r5, r6, r7, lr}
	ldr r0, _0806177C @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x84
	ldrb r0, [r4]
	cmp r0, #8
	bhi _08061788
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r2, _08061780 @ =0x0000FFFE
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r4]
	lsls r1, r1, #2
	ldr r2, _08061784 @ =0x00007FFD
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _080617D2
	.align 2, 0
_0806177C: .4byte 0x03000440
_08061780: .4byte 0x0000FFFE
_08061784: .4byte 0x00007FFD
_08061788:
	ldr r5, _080617D8 @ =0x03006F74
	ldr r6, _080617DC @ =0x03002B8C
	ldr r7, _080617E0 @ =0x0300137C
	ldr r0, _080617E4 @ =0x03002C30
	ldr r4, _080617E8 @ =0x0000BFFF
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r3, #3
_0806179A:
	ldrh r1, [r2]
	adds r0, r4, #0
	ands r0, r1
	strh r0, [r2]
	adds r2, #0x40
	subs r3, #1
	cmp r3, #0
	bge _0806179A
	ldr r1, [r5]
	movs r2, #0
	movs r0, #1
	strb r0, [r1, #6]
	ldr r0, [r5]
	strb r2, [r0, #0x1a]
	ldr r0, _080617EC @ =0x02023078
	strb r2, [r0]
	movs r1, #0
	movs r3, #0x77
	subs r0, #1
_080617C0:
	strb r1, [r0]
	subs r0, #1
	subs r3, #1
	cmp r3, #0
	bge _080617C0
	movs r0, #0xc
	str r0, [r6]
	movs r0, #0
	str r0, [r7]
_080617D2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080617D8: .4byte 0x03006F74
_080617DC: .4byte 0x03002B8C
_080617E0: .4byte 0x0300137C
_080617E4: .4byte 0x03002C30
_080617E8: .4byte 0x0000BFFF
_080617EC: .4byte 0x02023078
	.syntax divided
