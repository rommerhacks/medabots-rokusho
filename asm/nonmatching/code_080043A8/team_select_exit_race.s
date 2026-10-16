	.syntax unified

	thumb_func_start team_select_exit_race
team_select_exit_race: @ 0x080048D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r2, _080049AC @ =0x03000440
	adds r0, r2, #0
	adds r0, #0x96
	movs r1, #0
	strb r1, [r0]
	ldr r0, _080049B0 @ =0x03000430
	str r1, [r0]
	movs r6, #0
	ldr r7, _080049B4 @ =0x030017A0
	ldr r5, _080049B8 @ =0x03001800
	movs r0, #0xf
	mov r8, r0
	movs r1, #0x92
	adds r1, r1, r5
	mov sb, r1
	adds r2, #0xee
	mov sl, r2
_0800490C:
	adds r4, r5, #0
	adds r4, #0x41
	adds r4, r6, r4
	ldrb r1, [r4]
	mov r0, r8
	ands r0, r1
	lsls r0, r0, #3
	adds r0, r0, r7
	ldrb r0, [r0, #6]
	movs r1, #3
	mov r2, sl
	bl load_part_data
	adds r1, r5, #0
	adds r1, #0x8c
	adds r1, r6, r1
	mov r2, sl
	ldrb r0, [r2, #1]
	subs r0, #0x64
	strb r0, [r1]
	lsls r3, r6, #2
	adds r2, r5, #0
	adds r2, #0x8f
	adds r2, r3, r2
	ldrb r1, [r4]
	mov r0, r8
	ands r0, r1
	lsls r0, r0, #3
	adds r0, r0, r7
	ldrb r0, [r0, #3]
	strb r0, [r2]
	adds r2, r5, #0
	adds r2, #0x90
	adds r2, r3, r2
	ldrb r1, [r4]
	mov r0, r8
	ands r0, r1
	lsls r0, r0, #3
	adds r0, r0, r7
	ldrb r0, [r0, #4]
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x91
	adds r3, r3, r0
	ldrb r1, [r4]
	mov r0, r8
	ands r0, r1
	lsls r0, r0, #3
	adds r0, r0, r7
	ldrb r0, [r0, #5]
	strb r0, [r3]
	ldrb r1, [r4]
	mov r0, r8
	ands r0, r1
	lsls r0, r0, #3
	adds r0, r0, r7
	ldrb r0, [r0, #6]
	mov r1, sb
	strb r0, [r1]
	movs r2, #4
	add sb, r2
	adds r6, #1
	cmp r6, #2
	ble _0800490C
	ldr r1, _080049BC @ =0x0300178C
	movs r0, #3
	str r0, [r1]
	ldr r1, _080049C0 @ =0x03002B8C
	movs r0, #4
	str r0, [r1]
	ldr r1, _080049C4 @ =0x0300137C
	movs r0, #5
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080049AC: .4byte 0x03000440
_080049B0: .4byte 0x03000430
_080049B4: .4byte 0x030017A0
_080049B8: .4byte 0x03001800
_080049BC: .4byte 0x0300178C
_080049C0: .4byte 0x03002B8C
_080049C4: .4byte 0x0300137C
	.syntax divided
