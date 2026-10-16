	.syntax unified

	thumb_func_start check_battle_timer_expired
	.global check_battle_timer_expired
check_battle_timer_expired: @ 0x0806FC1C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	ldr r6, _0806FC40 @ =0x03001800
	adds r7, r6, #0
	adds r7, #0x2e
	ldrb r0, [r7]
	mov r8, r0
	mov r1, r8
	cmp r1, #0x27
	bls _0806FC44
	movs r0, #1
	b _0806FC9C
	.align 2, 0
_0806FC40: .4byte 0x03001800
_0806FC44:
	ldr r0, [r6, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0806FC9A
	ldrb r4, [r7]
	adds r0, r4, #0
	movs r1, #0xa
	bl sub_0807CD58
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x12
	adds r0, r4, #0
	movs r1, #0xa
	bl sub_0807CDD0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r5, r5, r0
	add r4, sb
	lsls r4, r4, #1
	adds r0, r6, #0
	adds r0, #0x30
	adds r4, r4, r0
	ldr r1, _0806FCAC @ =0x00008001
	adds r0, r1, #0
	ldrh r4, [r4]
	adds r0, r0, r4
	mov r1, sp
	strh r0, [r1]
	ldr r1, _0806FCB0 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _0806FCB4 @ =0x0600FB0A
	adds r5, r5, r0
	str r5, [r1, #4]
	ldr r0, _0806FCB8 @ =0x80000001
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r0, r8
	adds r0, #1
	strb r0, [r7]
_0806FC9A:
	movs r0, #0
_0806FC9C:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806FCAC: .4byte 0x00008001
_0806FCB0: .4byte 0x040000D4
_0806FCB4: .4byte 0x0600FB0A
_0806FCB8: .4byte 0x80000001
	.syntax divided
