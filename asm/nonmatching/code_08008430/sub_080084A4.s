	.syntax unified

	thumb_func_start sub_080084A4
sub_080084A4: @ 0x080084A4
	push {r4, lr}
	bl sub_080093F8
	bl sub_0800A180
	bl sub_0800A1E4
	bl sub_0800ABF0
	ldr r1, _080084E8 @ =0x0300058C
	ldrb r2, [r1]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _080084F4
	movs r0, #4
	bl play_sound_effect
	movs r0, #1
	movs r1, #2
	bl clear_sprite_table_mask
	ldr r0, _080084EC @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x46
	movs r1, #0
	strb r1, [r2]
	adds r0, #0x3f
	strb r1, [r0]
	ldr r1, _080084F0 @ =0x0300137C
	movs r0, #0x30
	b _08008580
	.align 2, 0
_080084E8: .4byte 0x0300058C
_080084EC: .4byte 0x03000440
_080084F0: .4byte 0x0300137C
_080084F4:
	movs r4, #2
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _08008510
	movs r0, #5
	bl play_sound_effect
	ldr r1, _0800850C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08008580
	.align 2, 0
_0800850C: .4byte 0x0300137C
_08008510:
	ldrb r1, [r1, #1]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0800853C
	movs r0, #2
	bl play_sound_effect
	ldr r2, _08008534 @ =0x03000440
	adds r2, #0x42
	ldrb r0, [r2]
	subs r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	ldr r1, _08008538 @ =0x0300137C
	movs r0, #0x34
	b _08008580
	.align 2, 0
_08008534: .4byte 0x03000440
_08008538: .4byte 0x0300137C
_0800853C:
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08008568
	movs r0, #2
	bl play_sound_effect
	ldr r2, _08008560 @ =0x03000440
	adds r2, #0x42
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	ldr r1, _08008564 @ =0x0300137C
	movs r0, #0x34
	b _08008580
	.align 2, 0
_08008560: .4byte 0x03000440
_08008564: .4byte 0x0300137C
_08008568:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08008582
	movs r0, #4
	bl play_sound_effect
	ldr r0, _08008588 @ =0x03000440
	adds r0, #0x43
	strb r4, [r0]
	ldr r1, _0800858C @ =0x0300137C
	movs r0, #0x48
_08008580:
	str r0, [r1]
_08008582:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08008588: .4byte 0x03000440
_0800858C: .4byte 0x0300137C
	.syntax divided
