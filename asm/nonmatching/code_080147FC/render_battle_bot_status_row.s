	.syntax unified

	thumb_func_start render_battle_bot_status_row
	.global render_battle_bot_status_row
render_battle_bot_status_row: @ 0x08017F9C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r0, #0
	mov sb, r0
	ldr r1, _08018064 @ =0x0300047D
	mov sl, r1
	movs r6, #4
	movs r7, #0
	ldr r2, _08018068 @ =0x0400000A
	mov r8, r2
_08017FB8:
	ldr r1, _0801806C @ =0x0300047C
	ldrb r0, [r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	mov r2, sl
	ldrb r2, [r2]
	adds r1, r1, r2
	lsls r1, r1, #8
	adds r1, r7, r1
	ldr r0, _08018070 @ =0x03000590
	adds r1, r1, r0
	adds r1, #0x59
	ldrb r0, [r1]
	movs r5, #0xb0
	lsls r5, r5, #8
	cmp r0, #0
	beq _08017FDE
	movs r5, #0xa0
	lsls r5, r5, #8
_08017FDE:
	ldrb r0, [r1]
	mov r2, r8
	ldrh r1, [r2]
	str r1, [sp]
	movs r2, #0xe4
	lsls r2, r2, #2
	adds r1, r2, #0
	adds r4, r5, #0
	orrs r4, r1
	str r4, [sp, #4]
	movs r1, #0x17
	adds r2, r6, #0
	movs r3, #3
	bl sub_08042950
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp]
	movs r2, #0xe9
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r5, r0
	str r5, [sp, #4]
	movs r0, #1
	movs r1, #2
	movs r2, #0x1a
	adds r3, r6, #0
	bl fill_tilemap_rect_08042698
	ldr r0, _0801806C @ =0x0300047C
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	mov r1, sl
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r0, r7, r0
	ldr r2, _08018070 @ =0x03000590
	adds r0, r0, r2
	adds r0, #0x4c
	ldrb r0, [r0]
	mov r2, r8
	ldrh r1, [r2]
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0x1b
	adds r2, r6, #0
	movs r3, #3
	bl sub_08042950
	adds r6, #2
	adds r7, #0x18
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #3
	bls _08017FB8
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08018064: .4byte 0x0300047D
_08018068: .4byte 0x0400000A
_0801806C: .4byte 0x0300047C
_08018070: .4byte 0x03000590
	.syntax divided
