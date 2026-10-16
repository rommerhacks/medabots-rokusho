	.syntax unified

	thumb_func_start check_medaforce_availability
check_medaforce_availability: @ 0x080155A8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	bl sub_08015648
	adds r1, r0, #0
	cmp r1, #0
	bne _080155F8
	ldr r1, _080155D8 @ =0x03001800
	adds r1, #0x58
	ldrb r1, [r1]
	cmp r1, #0
	bne _080155F8
	ldr r1, _080155DC @ =0x03000590
	lsls r2, r7, #8
	adds r6, r2, r1
	adds r1, r6, #0
	adds r1, #0xc1
	ldrb r1, [r1]
	cmp r1, #0x50
	beq _080155FC
	b _080155F8
	.align 2, 0
_080155D8: .4byte 0x03001800
_080155DC: .4byte 0x03000590
_080155E0:
	adds r0, r7, #0
	movs r1, #0
	b _080155F0
_080155E6:
	adds r0, r7, #0
	movs r1, #1
	b _080155F0
_080155EC:
	adds r0, r7, #0
	movs r1, #2
_080155F0:
	bl load_bot_palette_data
	movs r0, #0
	b _08015640
_080155F8:
	movs r0, #1
	b _08015640
_080155FC:
	cmp r5, #0
	beq _08015606
	bl rng_lookup_table_value
	adds r4, r0, #0
_08015606:
	movs r3, #0
	adds r2, r6, #0
_0801560A:
	cmp r4, #0
	bne _08015618
	ldrb r1, [r2, #5]
	cmp r1, #9
	bhi _080155E0
	cmp r5, #0
	beq _080155F8
_08015618:
	cmp r4, #1
	bne _08015626
	ldrb r1, [r2, #5]
	cmp r1, #0x1d
	bhi _080155E6
	cmp r5, #0
	beq _080155F8
_08015626:
	cmp r4, #2
	bne _08015634
	ldrb r1, [r2, #5]
	cmp r1, #0x3b
	bhi _080155EC
	cmp r5, #0
	beq _080155F8
_08015634:
	cmp r4, #0
	beq _080155F8
	subs r4, #1
	adds r3, #1
	cmp r3, #2
	bls _0801560A
_08015640:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
