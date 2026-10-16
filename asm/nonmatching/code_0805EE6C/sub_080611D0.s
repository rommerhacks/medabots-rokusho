	.syntax unified

	thumb_func_start sub_080611D0
sub_080611D0: @ 0x080611D0
	push {r4, r5, r6, lr}
	ldr r0, _08061200 @ =0x03001780
	ldrb r1, [r0]
	movs r0, #8
	movs r2, #8
	bl sub_08041C14
	ldr r0, _08061204 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08061210
	movs r0, #2
	bl play_sound_effect
	ldr r0, _08061208 @ =0x03006F74
	ldr r1, [r0]
	ldrb r0, [r1, #5]
	cmp r0, #0
	beq _0806120C
	subs r0, #1
	b _0806120E
	.align 2, 0
_08061200: .4byte 0x03001780
_08061204: .4byte 0x03001798
_08061208: .4byte 0x03006F74
_0806120C:
	movs r0, #2
_0806120E:
	strb r0, [r1, #5]
_08061210:
	ldr r0, _08061230 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0806123C
	movs r0, #2
	bl play_sound_effect
	ldr r0, _08061234 @ =0x03006F74
	ldr r1, [r0]
	ldrb r0, [r1, #5]
	cmp r0, #1
	bhi _08061238
	adds r0, #1
	b _0806123A
	.align 2, 0
_08061230: .4byte 0x03001798
_08061234: .4byte 0x03006F74
_08061238:
	movs r0, #0
_0806123A:
	strb r0, [r1, #5]
_0806123C:
	ldr r2, _0806127C @ =0x03002C30
	ldr r5, _08061280 @ =0x03006F74
	ldr r0, [r5]
	ldrb r1, [r0, #5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	movs r1, #0x81
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r6, #0
	movs r4, #0
	strh r0, [r2]
	ldr r0, _08061284 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080612C0
	movs r0, #4
	bl play_sound_effect
	ldr r2, [r5]
	ldrb r0, [r2, #5]
	cmp r0, #1
	beq _0806128E
	cmp r0, #1
	bgt _08061288
	cmp r0, #0
	beq _0806128E
	b _080612D0
	.align 2, 0
_0806127C: .4byte 0x03002C30
_08061280: .4byte 0x03006F74
_08061284: .4byte 0x0300058C
_08061288:
	cmp r0, #2
	beq _080612A8
	b _080612D0
_0806128E:
	strh r4, [r2, #2]
	ldr r1, _080612A4 @ =0x0300137C
	movs r0, #8
	str r0, [r1]
	strb r6, [r2, #6]
	movs r0, #0
	movs r1, #0
	bl battle_menu_highlight_icons
	b _080612D0
	.align 2, 0
_080612A4: .4byte 0x0300137C
_080612A8:
	ldr r0, _080612B8 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _080612BC @ =0x0300137C
	movs r0, #6
	str r0, [r1]
	b _080612D0
	.align 2, 0
_080612B8: .4byte 0x03000440
_080612BC: .4byte 0x0300137C
_080612C0:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080612D0
	movs r0, #5
	bl play_sound_effect
	b _080612A8
_080612D0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
