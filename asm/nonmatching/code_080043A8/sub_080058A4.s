	.syntax unified

	thumb_func_start sub_080058A4
	.global sub_080058A4
sub_080058A4: @ 0x080058A4
	push {r4, r5, r6, lr}
	ldr r4, _0800591C @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x50
	ldrb r6, [r0]
	cmp r6, #0
	bne _0800593E
	ldr r0, _08005920 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800593E
	movs r0, #2
	bl play_sound_effect
	adds r5, r4, #0
	adds r5, #0x52
	ldrb r1, [r5]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08005928
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r5]
	adds r1, r4, #0
	adds r1, #0x51
	ldrb r2, [r1]
	cmp r0, r2
	beq _08005916
	ldrb r0, [r5]
	lsls r0, r0, #3
	ldr r2, _08005924 @ =0x030017A0
	adds r0, r0, r2
	ldrb r1, [r1]
	lsls r1, r1, #3
	adds r1, r1, r2
	movs r2, #8
	bl memswap
	bl sub_08004FD0
	bl sub_08005000
	bl sub_0800508C
	bl sub_08005118
	bl sub_0800519C
	bl sub_0800522C
	bl sub_080053C8
	bl sub_08005948
_08005916:
	strb r6, [r5]
	b _08005936
	.align 2, 0
_0800591C: .4byte 0x03000440
_08005920: .4byte 0x0300058C
_08005924: .4byte 0x030017A0
_08005928:
	adds r0, r4, #0
	adds r0, #0x51
	ldrb r0, [r0]
	adds r0, #0x80
	strb r0, [r5]
	bl sub_08005628
_08005936:
	bl update_battle_icon_blink_and_orbit
	movs r0, #1
	b _08005940
_0800593E:
	movs r0, #0
_08005940:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
