	.syntax unified

	thumb_func_start sub_08029B84
sub_08029B84: @ 0x08029B84
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r5, #0
_08029B92:
	ldr r1, _08029C50 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0xd2
	adds r0, r5, r0
	ldrb r0, [r0]
	adds r2, r5, #1
	mov sl, r2
	cmp r0, #0
	beq _08029C2E
	movs r6, #0
	mov sb, r6
	adds r4, r1, #0
	movs r7, #0x60
	adds r7, r7, r4
	mov r8, r7
	adds r3, r4, #0
	adds r3, #0xd0
	lsls r1, r5, #1
	adds r0, r4, #0
	adds r0, #0xd6
	adds r1, r1, r0
	str r1, [sp, #4]
_08029BBE:
	mov r1, r8
	ldrb r0, [r1]
	adds r0, r0, r5
	str r3, [sp]
	bl clear_ewram_buffer_02023000_b
	ldr r3, [sp]
	cmp r0, #0
	beq _08029C2E
	subs r0, #1
	strb r0, [r3]
	mov r2, r8
	ldrb r0, [r2]
	adds r0, r0, r5
	ldrb r1, [r3]
	ldr r6, _08029C54 @ =0x030018EC
	movs r7, #0
	ldrsh r2, [r6, r7]
	str r3, [sp]
	bl battle_calc_damage_split
	ldr r3, [sp]
	ldrb r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	mov r2, r8
	ldrb r0, [r2]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r1, r1, r0
	ldr r6, _08029C58 @ =0x03000590
	adds r1, r1, r6
	adds r1, #0x59
	ldr r7, _08029C5C @ =0x030018C8
	ldrb r0, [r7]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r0, [r7]
	ldr r6, [sp, #4]
	ldrh r6, [r6]
	adds r0, r0, r6
	ldr r7, [sp, #4]
	strh r0, [r7]
	ldr r1, _08029C60 @ =0x030018CA
	ldrh r0, [r1]
	cmp r0, #0
	beq _08029C2E
	ldr r2, _08029C54 @ =0x030018EC
	strh r0, [r2]
	movs r6, #1
	add sb, r6
	mov r7, sb
	cmp r7, #3
	bls _08029BBE
_08029C2E:
	mov r5, sl
	cmp r5, #2
	bls _08029B92
	ldr r1, _08029C50 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029C50: .4byte 0x03001800
_08029C54: .4byte 0x030018EC
_08029C58: .4byte 0x03000590
_08029C5C: .4byte 0x030018C8
_08029C60: .4byte 0x030018CA
	.syntax divided
