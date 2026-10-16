	.syntax unified

	thumb_func_start update_battle_bot_death_animations
update_battle_bot_death_animations: @ 0x0806AC1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	movs r0, #0
	str r0, [sp, #0x1c]
	ldr r1, _0806AD50 @ =0x03006FA0
	mov sl, r1
	movs r2, #1
	str r2, [sp, #0x20]
	movs r7, #1
	mov sb, r0
_0806AC38:
	ldr r0, _0806AD54 @ =0x03006F8C
	ldr r3, [sp, #0x1c]
	adds r5, r3, r0
	ldrb r0, [r5]
	cmp r0, #1
	bls _0806AC46
	b _0806AE56
_0806AC46:
	ldr r0, _0806AD58 @ =0x03002C30
	mov r8, r0
	ldr r6, _0806AD5C @ =0x08485CC4
	ldrb r1, [r5]
	adds r0, r1, r7
	adds r0, r0, r6
	ldrb r2, [r0]
	lsls r0, r2, #6
	add r0, r8
	adds r0, #0x2a
	ldrb r4, [r0]
	cmp r4, #1
	beq _0806AC62
	b _0806AD68
_0806AC62:
	subs r0, r2, #3
	subs r1, #1
	mov r2, sb
	subs r1, r2, r1
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	ldrb r0, [r5]
	mov r3, sb
	adds r1, r0, r3
	adds r1, #0x15
	lsls r1, r1, #6
	add r1, r8
	adds r0, r0, r7
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #6
	add r0, r8
	ldrh r0, [r0, #2]
	movs r2, #0
	movs r3, #0
	mov ip, r3
	strh r0, [r1, #2]
	ldr r0, _0806AD60 @ =0x03001780
	ldr r0, [r0]
	ands r0, r4
	cmp r0, #0
	bne _0806AC9C
	b _0806AE56
_0806AC9C:
	ldrb r0, [r5]
	adds r0, r0, r7
	adds r0, r0, r6
	ldrb r1, [r0]
	lsls r1, r1, #6
	add r1, r8
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x18
	beq _0806ACB8
	b _0806AE56
_0806ACB8:
	ldrb r0, [r5]
	adds r0, r0, r7
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x2a
	strb r2, [r0]
	ldrb r4, [r5]
	ldr r0, [sp, #0x20]
	adds r3, r4, r0
	mov r1, sl
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r1, #3
	adds r1, r3, r1
	ldrb r1, [r1]
	mov r2, sl
	adds r2, #6
	adds r2, r3, r2
	ldrb r2, [r2]
	str r2, [sp, #0x24]
	ldr r2, _0806AD64 @ =0x03006FA9
	adds r3, r3, r2
	ldrb r3, [r3]
	str r3, [sp, #0x28]
	subs r4, #1
	mov r3, sb
	subs r4, r3, r4
	str r4, [sp]
	ldrb r4, [r5]
	adds r4, r4, r7
	adds r4, r4, r6
	ldrb r4, [r4]
	subs r4, #3
	str r4, [sp, #4]
	ldrb r4, [r5]
	adds r4, r4, r7
	adds r4, r4, r6
	ldrb r4, [r4]
	subs r4, #3
	lsls r4, r4, #6
	add r4, r8
	movs r2, #2
	ldrsh r4, [r4, r2]
	str r4, [sp, #8]
	ldrb r4, [r5]
	adds r4, r4, r7
	adds r4, r4, r6
	ldrb r4, [r4]
	subs r4, #3
	lsls r4, r4, #6
	add r4, r8
	movs r3, #4
	ldrsh r4, [r4, r3]
	adds r4, #3
	str r4, [sp, #0xc]
	mov r2, ip
	str r2, [sp, #0x10]
	movs r4, #3
	str r4, [sp, #0x14]
	movs r4, #5
	str r4, [sp, #0x18]
	ldr r2, [sp, #0x24]
	ldr r3, [sp, #0x28]
	bl init_battle_medabot_sprites
	ldrb r0, [r5]
	adds r0, r0, r7
	adds r0, r0, r6
	ldrb r0, [r0]
	subs r0, #3
	movs r1, #8
	bl battle_sprite_set_palette_index
	b _0806AE56
	.align 2, 0
_0806AD50: .4byte 0x03006FA0
_0806AD54: .4byte 0x03006F8C
_0806AD58: .4byte 0x03002C30
_0806AD5C: .4byte 0x08485CC4
_0806AD60: .4byte 0x03001780
_0806AD64: .4byte 0x03006FA9
_0806AD68:
	cmp r4, #2
	bne _0806AE56
	subs r0, r2, #3
	subs r1, #1
	mov r3, sb
	subs r1, r3, r1
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	ldrb r0, [r5]
	mov r2, sb
	adds r1, r0, r2
	adds r1, #0x15
	lsls r1, r1, #6
	add r1, r8
	adds r0, r0, r7
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #6
	add r0, r8
	ldrh r0, [r0, #2]
	movs r2, #0
	movs r3, #0
	mov ip, r3
	strh r0, [r1, #2]
	ldr r0, _0806AE80 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0806AE56
	ldrb r0, [r5]
	adds r0, r0, r7
	adds r0, r0, r6
	ldrb r1, [r0]
	lsls r1, r1, #6
	add r1, r8
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x2c
	bne _0806AE56
	ldrb r0, [r5]
	adds r0, r0, r7
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x2a
	strb r2, [r0]
	ldrb r4, [r5]
	ldr r0, [sp, #0x20]
	adds r3, r4, r0
	mov r1, sl
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r1, #3
	adds r1, r3, r1
	ldrb r1, [r1]
	mov r2, sl
	adds r2, #6
	adds r2, r3, r2
	ldrb r2, [r2]
	str r2, [sp, #0x24]
	ldr r2, _0806AE84 @ =0x03006FA9
	adds r3, r3, r2
	ldrb r3, [r3]
	str r3, [sp, #0x28]
	subs r4, #1
	mov r3, sb
	subs r4, r3, r4
	str r4, [sp]
	ldrb r4, [r5]
	adds r4, r4, r7
	adds r4, r4, r6
	ldrb r4, [r4]
	subs r4, #3
	str r4, [sp, #4]
	ldrb r4, [r5]
	adds r4, r4, r7
	adds r4, r4, r6
	ldrb r4, [r4]
	subs r4, #3
	lsls r4, r4, #6
	add r4, r8
	movs r2, #2
	ldrsh r4, [r4, r2]
	str r4, [sp, #8]
	ldrb r4, [r5]
	adds r4, r4, r7
	adds r4, r4, r6
	ldrb r4, [r4]
	subs r4, #3
	lsls r4, r4, #6
	add r4, r8
	movs r3, #4
	ldrsh r4, [r4, r3]
	adds r4, #3
	str r4, [sp, #0xc]
	mov r2, ip
	str r2, [sp, #0x10]
	movs r4, #3
	str r4, [sp, #0x14]
	movs r4, #5
	str r4, [sp, #0x18]
	ldr r2, [sp, #0x24]
	ldr r3, [sp, #0x28]
	bl init_battle_medabot_sprites
	ldrb r0, [r5]
	adds r0, r0, r7
	adds r0, r0, r6
	ldrb r0, [r0]
	subs r0, #3
	movs r1, #0xc
	bl battle_sprite_set_palette_index
_0806AE56:
	ldr r3, [sp, #0x20]
	adds r3, #0xc
	str r3, [sp, #0x20]
	adds r7, #3
	movs r0, #3
	add sb, r0
	ldr r1, [sp, #0x1c]
	adds r1, #1
	str r1, [sp, #0x1c]
	cmp r1, #2
	bgt _0806AE6E
	b _0806AC38
_0806AE6E:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806AE80: .4byte 0x03001780
_0806AE84: .4byte 0x03006FA9
	.syntax divided
