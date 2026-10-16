	.syntax unified

	thumb_func_start init_battle_medabot_sprites
	.global init_battle_medabot_sprites
init_battle_medabot_sprites: @ 0x08042E58
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	str r1, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	ldr r0, [sp, #0x34]
	mov sl, r0
	ldr r6, [sp, #0x44]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #4
	bl clear_battle_sprite_slot
	ldr r1, _08042EA0 @ =0x03002C30
	mov r2, sl
	lsls r0, r2, #6
	adds r2, r0, r1
	lsls r1, r6, #0xa
	ldr r3, _08042EA4 @ =0x0000C004
	adds r0, r3, #0
	movs r3, #0
	orrs r1, r0
	strh r1, [r2]
	ldr r5, [sp, #0x40]
	cmp r5, #0
	beq _08042EA8
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r3, #0
	orrs r1, r0
	b _08042EAC
	.align 2, 0
_08042EA0: .4byte 0x03002C30
_08042EA4: .4byte 0x0000C004
_08042EA8:
	ldr r0, _08042F20 @ =0x0000EFFF
	ands r1, r0
_08042EAC:
	strh r1, [r2]
	ldr r3, _08042F24 @ =0x03002C30
	mov r5, sl
	lsls r1, r5, #6
	adds r1, r1, r3
	movs r0, #0
	mov ip, r0
	mov r2, sp
	ldrh r2, [r2, #0x38]
	strh r2, [r1, #2]
	ldr r0, [sp, #0x3c]
	subs r0, #4
	strh r0, [r1, #4]
	ldr r2, [sp, #0x30]
	lsls r2, r2, #3
	movs r5, #0xa0
	lsls r5, r5, #3
	adds r0, r2, r5
	strh r0, [r1, #6]
	ldr r5, _08042F28 @ =0x083BEA14
	adds r0, r4, r5
	ldrb r0, [r0]
	strb r0, [r1, #0xa]
	mov r0, ip
	strb r0, [r1, #0x1c]
	ldr r0, [sp, #0x48]
	adds r0, #2
	strb r0, [r1, #0xb]
	mov r4, sl
	adds r4, #1
	lsls r0, r4, #6
	adds r7, r0, r3
	lsls r1, r6, #0xa
	ldr r6, _08042F2C @ =0x0000C004
	adds r0, r6, #0
	adds r6, r1, #0
	orrs r6, r0
	mov r0, ip
	orrs r6, r0
	strh r6, [r7]
	mov sb, r3
	str r1, [sp, #0xc]
	mov r8, r2
	ldr r1, [sp, #0x40]
	cmp r1, #0
	beq _08042F34
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r2, #0
	orrs r6, r0
	strh r6, [r7]
	ldr r0, _08042F30 @ =0x00000502
	add r0, r8
	strh r0, [r7, #6]
	add r3, sp, #0x48
	ldrb r3, [r3]
	strb r3, [r7, #0xb]
	b _08042F46
	.align 2, 0
_08042F20: .4byte 0x0000EFFF
_08042F24: .4byte 0x03002C30
_08042F28: .4byte 0x083BEA14
_08042F2C: .4byte 0x0000C004
_08042F30: .4byte 0x00000502
_08042F34:
	ldr r0, _08042FA0 @ =0x0000EFFF
	ands r6, r0
	strh r6, [r7]
	ldr r0, _08042FA4 @ =0x00000501
	add r0, r8
	strh r0, [r7, #6]
	ldr r0, [sp, #0x48]
	adds r0, #3
	strb r0, [r7, #0xb]
_08042F46:
	lsls r0, r4, #6
	add r0, sb
	ldr r1, [sp, #0x38]
	subs r1, #8
	movs r6, #0
	movs r2, #0
	strh r1, [r0, #2]
	ldr r3, [sp, #0x3c]
	adds r3, #4
	strh r3, [r0, #4]
	ldr r4, [sp]
	adds r1, r4, r5
	ldrb r1, [r1]
	strb r1, [r0, #0xa]
	strb r6, [r0, #0x1c]
	movs r1, #0x40
	strb r1, [r0, #8]
	strb r1, [r0, #9]
	strh r2, [r0, #0x18]
	mov r1, sl
	adds r1, #2
	lsls r0, r1, #6
	mov r2, sb
	adds r4, r0, r2
	ldr r2, _08042FA8 @ =0x0000C004
	adds r0, r2, #0
	ldr r2, [sp, #0xc]
	orrs r2, r0
	orrs r2, r6
	strh r2, [r4]
	ldr r0, [sp, #0x40]
	cmp r0, #0
	beq _08042FB0
	movs r6, #0x80
	lsls r6, r6, #5
	adds r0, r6, #0
	orrs r2, r0
	strh r2, [r4]
	ldr r0, _08042FAC @ =0x00000503
	add r0, r8
	strh r0, [r4, #6]
	ldr r0, [sp, #0x48]
	adds r0, #3
	b _08042FC0
	.align 2, 0
_08042FA0: .4byte 0x0000EFFF
_08042FA4: .4byte 0x00000501
_08042FA8: .4byte 0x0000C004
_08042FAC: .4byte 0x00000503
_08042FB0:
	ldr r0, _0804300C @ =0x0000EFFF
	ands r2, r0
	strh r2, [r4]
	ldr r0, _08043010 @ =0x00000504
	add r0, r8
	strh r0, [r4, #6]
	add r0, sp, #0x48
	ldrb r0, [r0]
_08042FC0:
	strb r0, [r4, #0xb]
	lsls r0, r1, #6
	add r0, sb
	ldr r1, [sp, #0x38]
	adds r1, #8
	movs r7, #0
	movs r2, #0
	strh r1, [r0, #2]
	strh r3, [r0, #4]
	ldr r4, [sp, #4]
	adds r1, r4, r5
	ldrb r1, [r1]
	strb r1, [r0, #0xa]
	strb r7, [r0, #0x1c]
	movs r1, #0x40
	strb r1, [r0, #8]
	strb r1, [r0, #9]
	strh r2, [r0, #0x18]
	mov r1, sl
	adds r1, #3
	lsls r0, r1, #6
	mov r2, sb
	adds r6, r0, r2
	ldr r4, _08043014 @ =0x0000C004
	adds r0, r4, #0
	ldr r2, [sp, #0xc]
	orrs r2, r0
	orrs r2, r7
	strh r2, [r6]
	ldr r0, [sp, #0x40]
	cmp r0, #0
	beq _08043018
	movs r4, #0x80
	lsls r4, r4, #5
	adds r0, r4, #0
	orrs r2, r0
	b _0804301C
	.align 2, 0
_0804300C: .4byte 0x0000EFFF
_08043010: .4byte 0x00000504
_08043014: .4byte 0x0000C004
_08043018:
	ldr r0, _08043054 @ =0x0000EFFF
	ands r2, r0
_0804301C:
	strh r2, [r6]
	lsls r0, r1, #6
	add r0, sb
	movs r2, #0
	mov r6, sp
	ldrh r6, [r6, #0x38]
	strh r6, [r0, #2]
	strh r3, [r0, #4]
	ldr r1, _08043058 @ =0x00000505
	add r1, r8
	strh r1, [r0, #6]
	ldr r3, [sp, #8]
	adds r1, r3, r5
	ldrb r1, [r1]
	strb r1, [r0, #0xa]
	strb r2, [r0, #0x1c]
	ldr r1, [sp, #0x48]
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
_08043054: .4byte 0x0000EFFF
_08043058: .4byte 0x00000505
	.syntax divided
