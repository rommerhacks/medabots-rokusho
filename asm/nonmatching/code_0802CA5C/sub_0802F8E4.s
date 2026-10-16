	.syntax unified

	thumb_func_start sub_0802F8E4
sub_0802F8E4: @ 0x0802F8E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r6, #0
	ldr r7, _0802F988 @ =0x03001800
	movs r0, #0x60
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0xc8
	adds r1, r1, r7
	mov sl, r1
	ldr r3, _0802F98C @ =0x03000590
	mov sb, r3
_0802F902:
	adds r0, r7, #0
	adds r0, #0xd2
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0802F96A
	lsls r0, r6, #1
	adds r1, r7, #0
	adds r1, #0xd6
	adds r5, r0, r1
	ldrh r0, [r5]
	cmp r0, #0
	beq _0802F96A
	movs r0, #3
	strb r0, [r4]
	mov r1, r8
	ldrb r0, [r1]
	adds r0, r0, r6
	ldrh r2, [r5]
	movs r1, #3
	bl battle_set_damage_vs_armor
	adds r0, r7, #0
	adds r0, #0xd1
	ldrb r0, [r0]
	lsls r0, r0, #7
	ldrb r1, [r4]
	orrs r0, r1
	strb r0, [r4]
	mov r3, sl
	ldrh r2, [r3]
	strh r2, [r5]
	ldrb r1, [r4]
	movs r0, #0x7f
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	mov r3, r8
	ldrb r0, [r3]
	adds r0, r0, r6
	lsls r0, r0, #8
	adds r1, r1, r0
	add r1, sb
	adds r1, #0x59
	ldrb r0, [r1]
	subs r0, r0, r2
	strb r0, [r1]
	ldrb r0, [r3]
	adds r0, r0, r6
	bl sub_08035194
_0802F96A:
	adds r6, #1
	cmp r6, #2
	bls _0802F902
	ldr r1, _0802F988 @ =0x03001800
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
_0802F988: .4byte 0x03001800
_0802F98C: .4byte 0x03000590
	.syntax divided
