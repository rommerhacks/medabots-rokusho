	.syntax unified

	thumb_func_start battle_sprite_blink_update
battle_sprite_blink_update: @ 0x08035410
	push {r4, r5, lr}
	adds r3, r1, #0
	adds r4, r2, #0
	ldr r1, _08035448 @ =0x03002C30
	lsls r0, r0, #6
	adds r2, r0, r1
	ldrh r1, [r2]
	movs r5, #0x80
	lsls r5, r5, #8
	adds r0, r5, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldrb r1, [r4]
	cmp r1, #0
	bne _08035450
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08035470
	ldrh r1, [r2]
	ldr r0, _0803544C @ =0x00007FFF
	ands r0, r1
	strh r0, [r2]
	b _08035470
	.align 2, 0
_08035448: .4byte 0x03002C30
_0803544C: .4byte 0x00007FFF
_08035450:
	ldrb r0, [r3]
	cmp r0, r1
	bne _0803546C
	strb r5, [r3]
	ldrh r0, [r2]
	ldr r1, _08035468 @ =0x00007FFF
	ands r1, r0
	strh r1, [r2]
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _08035470
	.align 2, 0
_08035468: .4byte 0x00007FFF
_0803546C:
	adds r0, #1
	strb r0, [r3]
_08035470:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
