	.syntax unified

	thumb_func_start update_battle_bot_damage_animations
update_battle_bot_damage_animations: @ 0x0806AE88
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	movs r0, #0
	mov r8, r0
	movs r1, #0x10
	rsbs r1, r1, #0
	mov sb, r1
	movs r7, #1
	rsbs r7, r7, #0
	movs r3, #0
_0806AEA2:
	ldr r0, _0806AF34 @ =0x03006F8C
	mov r1, r8
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0806AF16
	ldr r6, _0806AF38 @ =0x03002C30
	ldr r5, _0806AF3C @ =0x08485CC4
	adds r0, r0, r7
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r1, r0, r6
	adds r0, r1, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #1
	bne _0806AF16
	ldrh r0, [r1, #2]
	subs r0, #1
	movs r2, #0
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, sb
	bgt _0806AEE6
	ldrb r0, [r4]
	adds r0, r0, r7
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r6
	adds r0, #0x2a
	strb r2, [r0]
_0806AEE6:
	ldrb r1, [r4]
	adds r0, r1, r7
	adds r0, r0, r5
	ldrb r0, [r0]
	subs r0, #3
	subs r1, #3
	subs r1, r3, r1
	movs r2, #0
	str r3, [sp]
	bl update_battle_sprite_orbiting_positions
	ldrb r0, [r4]
	ldr r3, [sp]
	adds r1, r0, r3
	adds r1, #0x13
	lsls r1, r1, #6
	adds r1, r1, r6
	adds r0, r0, r7
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r6
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
_0806AF16:
	adds r7, #3
	adds r3, #3
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #2
	ble _0806AEA2
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806AF34: .4byte 0x03006F8C
_0806AF38: .4byte 0x03002C30
_0806AF3C: .4byte 0x08485CC4
	.syntax divided
