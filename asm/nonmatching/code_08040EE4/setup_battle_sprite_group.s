	.syntax unified

	thumb_func_start setup_battle_sprite_group
	.global setup_battle_sprite_group
setup_battle_sprite_group: @ 0x0804305C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	str r1, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	ldr r0, [sp, #0x34]
	mov r8, r0
	ldr r1, [sp, #0x48]
	mov sb, r1
	ldr r2, _080430A0 @ =0x03002C30
	lsls r0, r0, #6
	adds r3, r0, r2
	ldrh r1, [r3]
	ldr r4, _080430A4 @ =0x0000C004
	adds r0, r4, #0
	orrs r1, r0
	ldr r6, [sp, #0x44]
	lsls r0, r6, #0xa
	orrs r1, r0
	strh r1, [r3]
	adds r7, r2, #0
	ldr r0, [sp, #0x40]
	cmp r0, #0
	beq _080430A8
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r2, #0
	orrs r1, r0
	b _080430AC
	.align 2, 0
_080430A0: .4byte 0x03002C30
_080430A4: .4byte 0x0000C004
_080430A8:
	ldr r0, _0804311C @ =0x0000EFFF
	ands r1, r0
_080430AC:
	strh r1, [r3]
	mov r3, r8
	lsls r1, r3, #6
	adds r1, r1, r7
	movs r4, #0
	mov ip, r4
	mov r6, sp
	ldrh r6, [r6, #0x38]
	strh r6, [r1, #2]
	ldr r0, [sp, #0x3c]
	subs r0, #4
	strh r0, [r1, #4]
	ldr r2, [sp, #0x30]
	lsls r2, r2, #3
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r0, r2, r3
	strh r0, [r1, #6]
	ldr r4, _08043120 @ =0x083BEA14
	adds r0, r5, r4
	ldrb r0, [r0]
	strb r0, [r1, #0xa]
	mov r5, ip
	strb r5, [r1, #0x1c]
	mov r0, sb
	adds r0, #2
	strb r0, [r1, #0xb]
	mov r3, r8
	adds r3, #1
	lsls r0, r3, #6
	adds r5, r0, r7
	ldrh r1, [r5]
	ldr r6, _08043124 @ =0x0000C004
	adds r0, r6, #0
	orrs r1, r0
	ldr r6, [sp, #0x44]
	lsls r0, r6, #0xa
	orrs r1, r0
	strh r1, [r5]
	str r0, [sp, #0xc]
	adds r6, r2, #0
	mov sl, r4
	ldr r0, [sp, #0x40]
	cmp r0, #0
	beq _0804312C
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r2, #0
	orrs r1, r0
	strh r1, [r5]
	ldr r4, _08043128 @ =0x00000502
	adds r0, r6, r4
	strh r0, [r5, #6]
	mov r0, sb
	b _0804313C
	.align 2, 0
_0804311C: .4byte 0x0000EFFF
_08043120: .4byte 0x083BEA14
_08043124: .4byte 0x0000C004
_08043128: .4byte 0x00000502
_0804312C:
	ldr r0, _08043190 @ =0x0000EFFF
	ands r1, r0
	strh r1, [r5]
	ldr r1, _08043194 @ =0x00000501
	adds r0, r6, r1
	strh r0, [r5, #6]
	mov r0, sb
	adds r0, #3
_0804313C:
	strb r0, [r5, #0xb]
	lsls r1, r3, #6
	adds r1, r1, r7
	ldr r0, [sp, #0x38]
	subs r0, #8
	strh r0, [r1, #2]
	ldr r3, [sp, #0x3c]
	adds r3, #4
	strh r3, [r1, #4]
	ldr r0, [sp]
	add r0, sl
	ldrb r0, [r0]
	strb r0, [r1, #0xa]
	movs r2, #0
	strb r2, [r1, #0x1c]
	mov r2, r8
	adds r2, #2
	lsls r0, r2, #6
	adds r4, r0, r7
	ldrh r1, [r4]
	ldr r5, _08043198 @ =0x0000C004
	adds r0, r5, #0
	orrs r1, r0
	ldr r0, [sp, #0xc]
	orrs r1, r0
	strh r1, [r4]
	mov ip, r3
	ldr r3, [sp, #0x40]
	cmp r3, #0
	beq _080431A0
	movs r5, #0x80
	lsls r5, r5, #5
	adds r0, r5, #0
	orrs r1, r0
	strh r1, [r4]
	ldr r1, _0804319C @ =0x00000503
	adds r0, r6, r1
	strh r0, [r4, #6]
	mov r0, sb
	adds r0, #3
	strb r0, [r4, #0xb]
	b _080431B0
	.align 2, 0
_08043190: .4byte 0x0000EFFF
_08043194: .4byte 0x00000501
_08043198: .4byte 0x0000C004
_0804319C: .4byte 0x00000503
_080431A0:
	ldr r0, _080431F0 @ =0x0000EFFF
	ands r1, r0
	strh r1, [r4]
	ldr r3, _080431F4 @ =0x00000504
	adds r0, r6, r3
	strh r0, [r4, #6]
	mov r5, sb
	strb r5, [r4, #0xb]
_080431B0:
	lsls r1, r2, #6
	adds r1, r1, r7
	ldr r0, [sp, #0x38]
	adds r0, #8
	movs r3, #0
	strh r0, [r1, #2]
	mov r0, ip
	strh r0, [r1, #4]
	ldr r0, [sp, #4]
	add r0, sl
	ldrb r0, [r0]
	strb r0, [r1, #0xa]
	strb r3, [r1, #0x1c]
	mov r2, r8
	adds r2, #3
	lsls r0, r2, #6
	adds r5, r0, r7
	ldrh r1, [r5]
	ldr r4, _080431F8 @ =0x0000C004
	adds r0, r4, #0
	orrs r1, r0
	ldr r0, [sp, #0xc]
	orrs r1, r0
	strh r1, [r5]
	ldr r4, [sp, #0x40]
	cmp r4, #0
	beq _080431FC
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r3, #0
	orrs r1, r0
	b _08043200
	.align 2, 0
_080431F0: .4byte 0x0000EFFF
_080431F4: .4byte 0x00000504
_080431F8: .4byte 0x0000C004
_080431FC:
	ldr r0, _08043238 @ =0x0000EFFF
	ands r1, r0
_08043200:
	strh r1, [r5]
	lsls r0, r2, #6
	adds r0, r0, r7
	movs r2, #0
	mov r4, sp
	ldrh r4, [r4, #0x38]
	strh r4, [r0, #2]
	mov r5, ip
	strh r5, [r0, #4]
	ldr r3, _0804323C @ =0x00000505
	adds r1, r6, r3
	strh r1, [r0, #6]
	ldr r1, [sp, #8]
	add r1, sl
	ldrb r1, [r1]
	strb r1, [r0, #0xa]
	strb r2, [r0, #0x1c]
	mov r1, sb
	adds r1, #1
	strb r1, [r0, #0xb]
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08043238: .4byte 0x0000EFFF
_0804323C: .4byte 0x00000505
	.syntax divided
