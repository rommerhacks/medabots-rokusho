	.syntax unified

	thumb_func_start sub_08027494
sub_08027494: @ 0x08027494
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r5, #0
	ldr r0, _0802753C @ =0x03000590
	mov r8, r0
	ldr r6, _08027540 @ =0x03001800
	adds r7, r6, #0
	adds r7, #0x60
	movs r0, #0x7f
	mov sb, r0
	movs r0, #0xd6
	adds r0, r0, r6
	mov sl, r0
_080274B4:
	ldrb r0, [r7]
	adds r0, r0, r5
	lsls r2, r0, #8
	mov r0, r8
	adds r1, r2, r0
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802751E
	adds r0, r1, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802751E
	adds r4, r6, #0
	adds r4, #0xd2
	adds r4, r5, r4
	ldrb r1, [r4]
	mov r0, sb
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	add r1, r8
	adds r1, #0x59
	lsls r0, r5, #1
	add r0, sl
	ldrb r2, [r0]
	ldrb r0, [r1]
	subs r0, r0, r2
	strb r0, [r1]
	ldrb r0, [r7]
	adds r0, r0, r5
	bl sub_08035194
	ldrb r1, [r4]
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	bne _0802751E
	ldrb r0, [r7]
	adds r1, r0, r5
	lsls r0, r1, #8
	add r0, r8
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802751E
	adds r0, r1, #0
	bl add_bot_to_defeated_list
_0802751E:
	adds r5, #1
	cmp r5, #2
	bls _080274B4
	ldr r1, _08027540 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802753C: .4byte 0x03000590
_08027540: .4byte 0x03001800
	.syntax divided
