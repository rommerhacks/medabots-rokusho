	.syntax unified

	thumb_func_start sub_0803B1EC
sub_0803B1EC: @ 0x0803B1EC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	bl load_battle_sequence_commands
	movs r3, #0
	ldr r0, _0803B20C @ =0x03002C30
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0803B210
	movs r5, #0xa
	b _0803B228
	.align 2, 0
_0803B20C: .4byte 0x03002C30
_0803B210:
	adds r3, #1
	cmp r3, #8
	bhi _0803B228
	ldr r0, _0803B2D8 @ =0x03002C30
	adds r2, r3, #0
	adds r2, #0xa
	lsls r1, r2, #6
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _0803B210
	adds r5, r2, #0
_0803B228:
	lsls r4, r5, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _0803B2D8 @ =0x03002C30
	lsls r0, r5, #6
	adds r6, r0, r1
	ldr r7, _0803B2DC @ =0x03001800
	movs r2, #0x87
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	lsls r0, r0, #0xa
	ldr r2, _0803B2E0 @ =0x00004004
	adds r1, r2, #0
	movs r2, #0
	mov r8, r2
	orrs r0, r1
	strh r0, [r6]
	mov r0, r8
	strb r0, [r6, #0x1c]
	movs r5, #0xe
	strb r5, [r6, #0xa]
	movs r0, #0x80
	strb r0, [r6, #0xb]
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	adds r2, r6, #0
	adds r2, #0x2d
	strb r0, [r2]
	ldr r1, _0803B2E4 @ =0x083B5F80
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r4, #0
	bl init_battle_sprite_entry_08040B90
	movs r2, #0x81
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x2b
	strb r0, [r1]
	movs r1, #0x83
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	strh r0, [r6, #4]
	adds r2, #8
	adds r0, r7, r2
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0x24
	strb r1, [r0]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0x2c
	strb r1, [r0]
	subs r0, #3
	strb r5, [r0]
	adds r0, r7, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803B2E8
	subs r2, #6
	adds r0, r7, r2
	ldrh r0, [r0]
	strh r0, [r6, #2]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0x25
	strb r1, [r0]
	b _0803B318
	.align 2, 0
_0803B2D8: .4byte 0x03002C30
_0803B2DC: .4byte 0x03001800
_0803B2E0: .4byte 0x00004004
_0803B2E4: .4byte 0x083B5F80
_0803B2E8:
	ldrh r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r6]
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r0, #0xf0
	subs r0, r0, r1
	strh r0, [r6, #2]
	movs r2, #0x84
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrb r1, [r0]
	movs r0, #0x20
	subs r0, r0, r1
	movs r1, #0x1f
	ands r0, r1
	adds r1, r6, #0
	adds r1, #0x25
	strb r0, [r1]
_0803B318:
	bl battle_advance_sequence_counter
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
