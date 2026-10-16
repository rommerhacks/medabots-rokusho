	.syntax unified

	thumb_func_start sub_0803B0C0
sub_0803B0C0: @ 0x0803B0C0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	bl load_battle_sequence_commands
	movs r7, #0
	ldr r5, _0803B160 @ =0x03001800
	movs r0, #0xf8
	adds r0, r0, r5
	mov r8, r0
	ldr r6, _0803B164 @ =0x083AF94C
_0803B0D6:
	ldr r2, _0803B168 @ =0x03002C30
	adds r1, r7, #0
	adds r1, #0xa
	lsls r0, r1, #6
	adds r4, r0, r2
	movs r2, #0
	ldr r0, _0803B16C @ =0x0000C004
	strh r0, [r4]
	strb r2, [r4, #0x1c]
	ldrb r0, [r6, #2]
	strh r0, [r4, #4]
	movs r0, #0xe
	strb r0, [r4, #0xa]
	movs r0, #0x80
	strb r0, [r4, #0xb]
	movs r2, #0x81
	lsls r2, r2, #1
	adds r3, r5, r2
	ldrh r2, [r3]
	adds r0, r4, #0
	adds r0, #0x2c
	strb r2, [r0]
	ldrh r0, [r3]
	adds r3, r4, #0
	adds r3, #0x2b
	strb r0, [r3]
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	adds r2, r4, #0
	adds r2, #0x25
	strb r0, [r2]
	movs r2, #0x83
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r2, [r0]
	adds r0, r4, #0
	adds r0, #0x24
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x29
	movs r0, #0xb
	strb r0, [r2]
	movs r2, #0x84
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	adds r3, #2
	strb r0, [r3]
	ldr r2, _0803B170 @ =0x083B5F80
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
	mov r0, r8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803B174
	ldrh r0, [r6]
	strh r0, [r4, #2]
	b _0803B182
	.align 2, 0
_0803B160: .4byte 0x03001800
_0803B164: .4byte 0x083AF94C
_0803B168: .4byte 0x03002C30
_0803B16C: .4byte 0x0000C004
_0803B170: .4byte 0x083B5F80
_0803B174:
	ldrh r0, [r6]
	movs r1, #0xf6
	subs r1, r1, r0
	ldr r2, _0803B198 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	strh r1, [r4, #2]
_0803B182:
	adds r6, #4
	adds r7, #1
	cmp r7, #3
	bls _0803B0D6
	bl battle_advance_sequence_counter
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B198: .4byte 0x000001FF
	.syntax divided
