	.syntax unified

	thumb_func_start sub_0806C084
sub_0806C084: @ 0x0806C084
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r0, _0806C11C @ =0x03001800
	movs r1, #0xe
	ldrsb r1, [r0, r1]
	adds r4, r0, #0
	cmp r1, #0
	beq _0806C0D6
	ldr r1, [r4, #0x44]
	adds r0, r1, #0
	subs r0, #0x12
	ldr r2, [r4, #8]
	cmp r0, r2
	bge _0806C0D6
	adds r0, #9
	cmp r2, r0
	bge _0806C0D6
	ldr r3, _0806C120 @ =0x03002C30
	subs r0, #1
	movs r1, #1
	cmp r0, r2
	bne _0806C0B8
	movs r1, #2
_0806C0B8:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r3, r2
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	adds r0, r4, r0
	ldrb r1, [r0, #0xe]
	ldr r5, _0806C124 @ =0x00000821
	adds r0, r3, r5
	strb r1, [r0]
	ldr r1, _0806C128 @ =0x0000081A
	adds r0, r3, r1
	strh r2, [r0]
_0806C0D6:
	adds r2, r4, #0
	ldr r1, [r2, #0x44]
	ldr r0, [r2, #8]
	cmp r1, r0
	blt _0806C0E2
	b _0806C1EE
_0806C0E2:
	ldrb r1, [r2, #0xe]
	movs r0, #0xe
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _0806C1A4
	movs r4, #0
	ldr r0, _0806C120 @ =0x03002C30
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r1, r0, r2
_0806C0F6:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0806C0FE
	b _0806C1F6
_0806C0FE:
	adds r1, #0x40
	adds r4, #1
	cmp r4, #7
	ble _0806C0F6
	movs r0, #0
	bl play_song
	movs r0, #0xe
	bl play_song
	ldr r1, _0806C12C @ =0x0300137C
	movs r0, #6
	str r0, [r1]
	b _0806C1F6
	.align 2, 0
_0806C11C: .4byte 0x03001800
_0806C120: .4byte 0x03002C30
_0806C124: .4byte 0x00000821
_0806C128: .4byte 0x0000081A
_0806C12C: .4byte 0x0300137C
_0806C130:
	movs r1, #0xc8
	lsls r1, r1, #8
	movs r2, #3
	mov sb, r2
	str r2, [sp]
	movs r2, #0x10
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	ldr r0, _0806C194 @ =0x00000802
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r5, #2]
	movs r0, #0xc
	strh r0, [r5, #4]
	strh r6, [r5, #0x1a]
	movs r0, #1
	strb r0, [r7]
	ldr r0, _0806C198 @ =0x03001800
	movs r1, #0xe
	ldrsb r1, [r0, r1]
	adds r0, #0xf
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r1, r5, #0
	adds r1, #0x21
	strb r0, [r1]
	adds r4, #0x30
	ldr r1, _0806C19C @ =0x0000CC08
	mov r0, sb
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0x12
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	lsls r4, r4, #6
	add r4, r8
	ldrh r0, [r5, #2]
	strh r0, [r4, #2]
	movs r0, #0x10
	strh r0, [r4, #4]
	movs r0, #0x61
	bl play_sound_effect
	ldr r1, _0806C1A0 @ =0x000007C4
	add r1, r8
	movs r0, #0xc8
	strh r0, [r1]
	b _0806C1EE
	.align 2, 0
_0806C194: .4byte 0x00000802
_0806C198: .4byte 0x03001800
_0806C19C: .4byte 0x0000CC08
_0806C1A0: .4byte 0x000007C4
_0806C1A4:
	subs r0, r1, #1
	strb r0, [r4, #0xe]
	bl get_battle_state_value_div10
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	movs r1, #0x32
	bl sub_0807CBBC
	movs r1, #0xd
	ldrsb r1, [r4, r1]
	adds r0, r0, r1
	ldr r1, [r4, #0x44]
	adds r1, r1, r0
	str r1, [r4, #0x44]
	movs r4, #0
	ldr r2, _0806C204 @ =0x03002C30
	mov r8, r2
	movs r7, #0xa2
	lsls r7, r7, #4
	add r7, r8
	movs r5, #0xa0
	lsls r5, r5, #4
	add r5, r8
_0806C1DA:
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r6, [r7]
	cmp r6, #0
	beq _0806C130
	adds r7, #0x40
	adds r5, #0x40
	adds r4, #1
	cmp r4, #7
	ble _0806C1DA
_0806C1EE:
	ldr r1, _0806C208 @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
_0806C1F6:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C204: .4byte 0x03002C30
_0806C208: .4byte 0x03001800
	.syntax divided
