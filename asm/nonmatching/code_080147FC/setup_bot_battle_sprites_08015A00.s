	.syntax unified

	thumb_func_start setup_bot_battle_sprites_08015A00
	.global setup_bot_battle_sprites_08015A00
setup_bot_battle_sprites_08015A00: @ 0x08015A00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	mov sb, r1
	mov sl, r2
	ldr r4, _08015A84 @ =0x03001864
	adds r1, r4, #0
	bl get_bot_part_effective_values
	adds r0, r5, #0
	bl sub_08015924
	ldrb r1, [r4]
	mov r8, r1
	ldrb r1, [r4, #1]
	ldrb r2, [r4, #2]
	ldrb r3, [r4, #3]
	str r5, [sp]
	lsls r5, r5, #2
	adds r6, r5, #0
	adds r6, #0x5a
	str r6, [sp, #4]
	mov r7, sb
	str r7, [sp, #8]
	mov r7, sl
	str r7, [sp, #0xc]
	str r0, [sp, #0x10]
	subs r4, #0x28
	ldrb r0, [r4]
	adds r0, #2
	str r0, [sp, #0x14]
	str r6, [sp, #0x18]
	mov r0, r8
	bl setup_battle_sprite_group
	ldr r4, _08015A88 @ =0x03002C30
	adds r1, r5, #0
	adds r1, #0x5b
	lsls r1, r1, #6
	adds r1, r1, r4
	ldrh r3, [r1]
	ldr r2, _08015A8C @ =0x0000FDFF
	adds r0, r2, #0
	ands r0, r3
	movs r3, #0
	strh r0, [r1]
	adds r5, #0x5c
	lsls r5, r5, #6
	adds r5, r5, r4
	ldrh r0, [r5]
	ands r2, r0
	strh r2, [r5]
	strh r3, [r1, #0x18]
	strh r3, [r5, #0x18]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015A84: .4byte 0x03001864
_08015A88: .4byte 0x03002C30
_08015A8C: .4byte 0x0000FDFF
	.syntax divided
