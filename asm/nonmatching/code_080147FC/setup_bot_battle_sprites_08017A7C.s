	.syntax unified

	thumb_func_start setup_bot_battle_sprites_08017A7C
setup_bot_battle_sprites_08017A7C: @ 0x08017A7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r7, r1, #0
	mov r8, r2
	cmp r5, #2
	bhi _08017A98
	adds r1, r5, #0
	movs r0, #0
	mov sb, r0
	b _08017A9E
_08017A98:
	subs r1, r5, #3
	movs r4, #1
	mov sb, r4
_08017A9E:
	ldr r0, _08017AB0 @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x3d
	ldrb r2, [r2]
	cmp r1, r2
	bne _08017AB4
	movs r6, #0
	b _08017ABE
	.align 2, 0
_08017AB0: .4byte 0x03000440
_08017AB4:
	adds r0, #0x46
	ldrb r0, [r0]
	cmp r1, r0
	bne _08017B08
	movs r6, #1
_08017ABE:
	ldr r4, _08017B18 @ =0x03001864
	adds r0, r5, #0
	adds r1, r4, #0
	bl get_bot_part_effective_values
	ldrb r0, [r4]
	ldrb r1, [r4, #1]
	ldrb r2, [r4, #2]
	ldrb r3, [r4, #3]
	str r5, [sp]
	lsls r5, r6, #2
	str r5, [sp, #4]
	str r7, [sp, #8]
	mov r4, r8
	str r4, [sp, #0xc]
	mov r4, sb
	str r4, [sp, #0x10]
	movs r4, #2
	str r4, [sp, #0x14]
	str r5, [sp, #0x18]
	bl setup_battle_sprite_group
	ldr r4, _08017B1C @ =0x03002C30
	adds r1, r5, #1
	lsls r1, r1, #6
	adds r1, r1, r4
	ldrh r3, [r1]
	ldr r2, _08017B20 @ =0x0000FDFF
	adds r0, r2, #0
	ands r0, r3
	strh r0, [r1]
	adds r5, #2
	lsls r5, r5, #6
	adds r5, r5, r4
	ldrh r0, [r5]
	ands r2, r0
	strh r2, [r5]
_08017B08:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08017B18: .4byte 0x03001864
_08017B1C: .4byte 0x03002C30
_08017B20: .4byte 0x0000FDFF
	.syntax divided
