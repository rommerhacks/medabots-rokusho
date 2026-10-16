	.syntax unified

	thumb_func_start position_battle_team_cursors
	.global position_battle_team_cursors
position_battle_team_cursors: @ 0x08017A14
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r1, #0
	movs r1, #0
	mov r8, r1
	ldr r2, _08017A48 @ =0x03000590
	ldr r3, _08017A4C @ =0x083AD3A4
	lsls r1, r0, #1
	adds r5, r1, r3
	lsls r1, r0, #8
	adds r2, #0x40
	adds r6, r1, r2
	adds r4, r0, #0
_08017A30:
	ldrb r0, [r6]
	cmp r0, #0
	beq _08017A5C
	ldrb r1, [r5]
	ldrb r2, [r5, #1]
	cmp r4, #2
	bhi _08017A50
	cmp r7, #0
	beq _08017A56
	subs r1, #0x68
	b _08017A56
	.align 2, 0
_08017A48: .4byte 0x03000590
_08017A4C: .4byte 0x083AD3A4
_08017A50:
	cmp r7, #0
	beq _08017A56
	adds r1, #0x68
_08017A56:
	adds r0, r4, #0
	bl setup_battle_bot_sprites_08017994
_08017A5C:
	adds r5, #2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r4, #1
	movs r1, #1
	add r8, r1
	mov r0, r8
	cmp r0, #2
	bls _08017A30
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
