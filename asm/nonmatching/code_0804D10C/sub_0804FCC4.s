	.syntax unified

	thumb_func_start sub_0804FCC4
sub_0804FCC4: @ 0x0804FCC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r6, #0
	mov sb, r6
	ldr r3, _0804FD1C @ =0x030064A0
	adds r0, r3, #0
	adds r0, #0x52
	adds r1, r3, #0
	ldrb r0, [r0]
	cmp r6, r0
	blt _0804FCE4
	b _0804FDEE
_0804FCE4:
	adds r5, r1, #0
	adds r5, #0xa
	movs r0, #0x54
	adds r0, r0, r1
	mov r8, r0
	movs r7, #0
	movs r0, #0x12
	adds r0, r0, r1
	mov sl, r0
_0804FCF6:
	ldrb r0, [r5]
	cmp r0, #1
	bhi _0804FDD6
	ldrb r0, [r5]
	lsls r2, r0, #2
	adds r0, r2, r7
	adds r3, #0x12
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #4
	bgt _0804FDCC
	cmp r0, #3
	bge _0804FD4A
	cmp r0, #1
	beq _0804FD20
	cmp r0, #2
	beq _0804FD36
	b _0804FDCC
	.align 2, 0
_0804FD1C: .4byte 0x030064A0
_0804FD20:
	adds r0, r7, #1
	adds r0, r2, r0
	adds r0, r0, r3
	ldrb r0, [r0]
	adds r1, r7, #2
	adds r1, r2, r1
	adds r1, r1, r3
	ldrb r1, [r1]
	bl set_battle_sprite_animation
	b _0804FDC4
_0804FD36:
	adds r0, r7, #1
	adds r0, r2, r0
	adds r0, r0, r3
	ldrb r0, [r0]
	mov r1, r8
	strb r0, [r1]
	ldrb r0, [r1]
	bl sub_08050508
	b _0804FDC4
_0804FD4A:
	cmp r0, #3
	beq _0804FD52
	cmp r0, #4
	beq _0804FD56
_0804FD52:
	movs r3, #0
	b _0804FD58
_0804FD56:
	movs r3, #1
_0804FD58:
	ldr r0, _0804FD70 @ =0x030064A0
	adds r0, #0x5c
	mov r1, sb
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #1
	beq _0804FDAA
	cmp r0, #1
	bgt _0804FD74
	cmp r0, #0
	beq _0804FD7A
	b _0804FDCE
	.align 2, 0
_0804FD70: .4byte 0x030064A0
_0804FD74:
	cmp r0, #2
	beq _0804FDC0
	b _0804FDCE
_0804FD7A:
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r1, r7, #1
	adds r0, r0, r1
	add r0, sl
	ldrb r0, [r0]
	str r3, [sp]
	bl sub_0804DBA4
	adds r0, #0x4f
	mov r1, r8
	strb r0, [r1]
	ldrb r0, [r1]
	ldrb r1, [r5]
	lsls r1, r1, #2
	adds r2, r7, #2
	adds r1, r1, r2
	add r1, sl
	ldrb r1, [r1]
	ldr r3, [sp]
	adds r2, r3, #0
	bl setup_battle_sprite_terrain
	b _0804FDB8
_0804FDAA:
	mov r1, r8
	ldrb r0, [r1]
	movs r1, #1
	bl update_battle_sprite_movement
	cmp r0, #0
	beq _0804FDCE
_0804FDB8:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0804FDCE
_0804FDC0:
	movs r0, #0
	strb r0, [r4]
_0804FDC4:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0804FDCE
_0804FDCC:
	adds r6, #1
_0804FDCE:
	ldrb r0, [r5]
	ldr r1, _0804FE1C @ =0x030064A0
	cmp r0, #1
	bls _0804FDD8
_0804FDD6:
	adds r6, #1
_0804FDD8:
	adds r5, #1
	movs r0, #1
	add r8, r0
	adds r7, #8
	add sb, r0
	adds r3, r1, #0
	adds r0, r1, #0
	adds r0, #0x52
	ldrb r0, [r0]
	cmp sb, r0
	blt _0804FCF6
_0804FDEE:
	adds r2, r1, #0
	adds r2, #0x52
	ldrb r0, [r2]
	cmp r6, r0
	bne _0804FE0A
	movs r0, #0
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x12
	movs r1, #0x40
	bl sub_080496C8
	bl map_script_command_done
_0804FE0A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804FE1C: .4byte 0x030064A0
	.syntax divided
