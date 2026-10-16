	.syntax unified

	thumb_func_start sub_08008650
sub_08008650: @ 0x08008650
	push {r4, r5, r6, r7, lr}
	bl sub_080093F8
	ldr r6, _08008680 @ =0x03000440
	adds r7, r6, #0
	adds r7, #0x3f
	ldrb r0, [r7]
	cmp r0, #0
	bne _08008708
	bl sub_0800AD00
	bl sub_0800AD58
	cmp r0, #0
	beq _08008688
	bl sub_0800AB0C
	bl sub_0803FB0C
	ldr r1, _08008684 @ =0x0300137C
	ldr r0, [r1]
	subs r0, #1
	b _080087BC
	.align 2, 0
_08008680: .4byte 0x03000440
_08008684: .4byte 0x0300137C
_08008688:
	bl sub_0800ADE8
	cmp r0, #0
	beq _080086A0
	bl sub_0803FB0C
	ldr r1, _0800869C @ =0x0300137C
	ldr r0, [r1]
	subs r0, #1
	b _080087BC
	.align 2, 0
_0800869C: .4byte 0x0300137C
_080086A0:
	ldr r0, _080086D0 @ =0x0300058C
	ldrb r2, [r0]
	movs r5, #1
	adds r4, r5, #0
	ands r4, r2
	adds r1, r0, #0
	cmp r4, #0
	beq _080086D8
	movs r0, #4
	bl play_sound_effect
	movs r0, #1
	movs r1, #2
	bl clear_sprite_table_mask
	bl sub_0800ACA8
	bl sub_0803FB0C
	strb r5, [r7]
	ldr r1, _080086D4 @ =0x0300137C
	ldr r0, [r1]
	subs r0, #1
	b _080087BC
	.align 2, 0
_080086D0: .4byte 0x0300058C
_080086D4: .4byte 0x0300137C
_080086D8:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08008794
	movs r0, #5
	bl play_sound_effect
	movs r0, #1
	movs r1, #2
	bl clear_sprite_table_mask
	adds r0, r6, #0
	adds r0, #0x46
	strb r4, [r0]
	bl sub_0800A0FC
	bl sub_0803FB0C
	ldr r1, _08008704 @ =0x0300137C
	movs r0, #0x2b
	b _080087BC
	.align 2, 0
_08008704: .4byte 0x0300137C
_08008708:
	ldr r0, _0800872C @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #0x30
	bl sub_08041C5C
	bl sub_0800AE54
	adds r5, r0, #0
	cmp r5, #0
	beq _08008730
	bl sub_0800AB0C
	bl sub_0800ABA4
	bl sub_0800ACA8
	b _080087BE
	.align 2, 0
_0800872C: .4byte 0x03001780
_08008730:
	ldr r0, _08008760 @ =0x0300058C
	ldrb r2, [r0]
	movs r4, #1
	ands r4, r2
	adds r1, r0, #0
	cmp r4, #0
	beq _08008768
	movs r0, #4
	bl play_sound_effect
	movs r0, #3
	movs r1, #1
	bl clear_sprite_table_mask
	adds r0, r6, #0
	adds r0, #0x46
	strb r5, [r0]
	bl sub_0800A0FC
	bl sub_0803FB0C
	ldr r1, _08008764 @ =0x0300137C
	movs r0, #0x2b
	b _080087BC
	.align 2, 0
_08008760: .4byte 0x0300058C
_08008764: .4byte 0x0300137C
_08008768:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08008794
	movs r0, #5
	bl play_sound_effect
	movs r0, #3
	movs r1, #1
	bl clear_sprite_table_mask
	bl sub_0800AC2C
	bl sub_0803FB0C
	strb r4, [r7]
	ldr r1, _08008790 @ =0x0300137C
	ldr r0, [r1]
	subs r0, #1
	b _080087BC
	.align 2, 0
_08008790: .4byte 0x0300137C
_08008794:
	ldrb r1, [r1]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080087BE
	movs r0, #4
	bl play_sound_effect
	ldr r1, _080087C4 @ =0x03000440
	adds r3, r1, #0
	adds r3, #0x46
	ldrb r2, [r3]
	movs r0, #0x80
	orrs r0, r2
	strb r0, [r3]
	adds r1, #0x43
	movs r0, #2
	strb r0, [r1]
	ldr r1, _080087C8 @ =0x0300137C
	movs r0, #0x48
_080087BC:
	str r0, [r1]
_080087BE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080087C4: .4byte 0x03000440
_080087C8: .4byte 0x0300137C
	.syntax divided
