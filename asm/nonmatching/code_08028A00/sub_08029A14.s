	.syntax unified

	thumb_func_start sub_08029A14
sub_08029A14: @ 0x08029A14
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _08029AE4 @ =0x084DE4BC
	ldr r1, _08029AE8 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08029AEC @ =0x0850ED18
	ldr r1, _08029AF0 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	movs r5, #0
	ldr r0, _08029AF4 @ =0x03001800
	mov sl, r0
	ldr r2, _08029AF8 @ =0x03002C30
	movs r6, #0xf8
	add r6, sl
	mov sb, r6
	movs r0, #0x84
	lsls r0, r0, #4
	adds r4, r2, r0
	mov r3, sl
	adds r3, #0x60
	ldr r6, _08029AFC @ =0x083B6100
	mov r8, r6
_08029A4E:
	mov r0, sl
	adds r0, #0xd2
	adds r0, r5, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029ABC
	adds r1, r5, #0
	adds r1, #0x21
	movs r7, #0
	ldr r0, _08029B00 @ =0x0000C404
	strh r0, [r4]
	strb r7, [r4, #0x1c]
	ldrb r0, [r3]
	adds r0, r0, r5
	lsls r0, r0, #8
	movs r6, #0xba
	lsls r6, r6, #5
	adds r0, r0, r6
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	strh r0, [r4, #2]
	ldrb r0, [r3]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r4, #4]
	movs r0, #7
	strb r0, [r4, #0xa]
	movs r0, #0xf0
	strb r0, [r4, #0xb]
	mov r6, r8
	ldr r0, [r6]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r2, [sp]
	str r3, [sp, #4]
	bl init_battle_sprite_entry_08040B90
	mov r0, sb
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	ldr r2, [sp]
	ldr r3, [sp, #4]
	cmp r0, #0
	beq _08029ABC
	ldrh r0, [r4]
	movs r6, #0x80
	lsls r6, r6, #5
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r4]
_08029ABC:
	adds r4, #0x40
	adds r5, #1
	cmp r5, #2
	bls _08029A4E
	movs r0, #0x2a
	bl play_sound_effect
	ldr r1, _08029AF4 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029AE4: .4byte 0x084DE4BC
_08029AE8: .4byte 0x06014800
_08029AEC: .4byte 0x0850ED18
_08029AF0: .4byte 0x050002E0
_08029AF4: .4byte 0x03001800
_08029AF8: .4byte 0x03002C30
_08029AFC: .4byte 0x083B6100
_08029B00: .4byte 0x0000C404
	.syntax divided
