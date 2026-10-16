	.syntax unified

	thumb_func_start battle_select_random_target
	.global battle_select_random_target
battle_select_random_target: @ 0x08037830
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r4, r1, #0
	bl rng_lookup_table_value
	adds r5, r0, #0
	bl rng_next_080424B8
	adds r3, r0, #0
	movs r0, #1
	ands r3, r0
	movs r6, #0
	ldr r7, _08037878 @ =0x03000590
	lsls r4, r4, #8
	adds r4, r4, r7
	adds r4, #0x91
_08037854:
	mov r0, r8
	adds r2, r0, r5
	lsls r0, r2, #8
	adds r1, r0, r7
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803787C
	adds r0, r1, #0
	adds r0, #0x91
	ldrb r0, [r0]
	ldrb r1, [r4]
	cmp r0, r1
	bne _0803787C
	adds r0, r2, #0
	b _0803789C
	.align 2, 0
_08037878: .4byte 0x03000590
_0803787C:
	cmp r3, #0
	beq _0803788A
	adds r5, #1
	cmp r5, #2
	bls _08037894
	movs r5, #0
	b _08037894
_0803788A:
	cmp r5, #0
	bne _08037892
	movs r5, #2
	b _08037894
_08037892:
	subs r5, #1
_08037894:
	adds r6, #1
	cmp r6, #2
	bls _08037854
	movs r0, #0xff
_0803789C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
