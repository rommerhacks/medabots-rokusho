	.syntax unified

	thumb_func_start sub_0803AF2C
sub_0803AF2C: @ 0x0803AF2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	bl load_battle_sequence_commands
	ldr r3, _0803AFAC @ =0x03002C30
	ldr r2, _0803AFB0 @ =0x03001800
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	ldr r4, _0803AFB4 @ =0x000002AB
	adds r0, r3, r4
	strb r1, [r0]
	movs r1, #0x83
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	subs r4, #0x27
	adds r0, r3, r4
	strh r1, [r0]
	movs r1, #0x85
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r4, #0x20
	adds r0, r3, r4
	strb r1, [r0]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r4, #8
	adds r0, r3, r4
	strb r1, [r0]
	ldr r0, _0803AFB8 @ =0x000002A9
	adds r1, r3, r0
	movs r0, #0x30
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803AFC0
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	subs r4, #0x2a
	adds r0, r3, r4
	strh r1, [r0]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	ldr r2, _0803AFBC @ =0x000002A5
	adds r0, r3, r2
	strb r1, [r0]
	b _0803AFE8
	.align 2, 0
_0803AFAC: .4byte 0x03002C30
_0803AFB0: .4byte 0x03001800
_0803AFB4: .4byte 0x000002AB
_0803AFB8: .4byte 0x000002A9
_0803AFBC: .4byte 0x000002A5
_0803AFC0:
	movs r4, #0x82
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r1, [r0]
	movs r0, #0xf0
	subs r0, r0, r1
	ldr r4, _0803B0A4 @ =0x00000282
	adds r1, r3, r4
	strh r0, [r1]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, #0x20
	subs r0, r0, r1
	movs r1, #0x1f
	ands r0, r1
	ldr r2, _0803B0A8 @ =0x000002A5
	adds r1, r3, r2
	strb r0, [r1]
_0803AFE8:
	movs r3, #0
	mov r8, r3
	ldr r4, _0803B0AC @ =0x03002C30
	mov sb, r4
	ldr r7, _0803B0B0 @ =0x03001800
	movs r0, #0xa1
	lsls r0, r0, #2
	add r0, sb
	mov sl, r0
	movs r5, #0xb7
	lsls r5, r5, #2
	add r5, sb
	movs r6, #0xb0
	lsls r6, r6, #2
	add r6, sb
_0803B006:
	mov r1, r8
	adds r1, #0xb
	movs r2, #0x87
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	lsls r0, r0, #0xa
	ldr r3, _0803B0B4 @ =0x00004004
	adds r2, r3, #0
	movs r3, #0
	orrs r0, r2
	strh r0, [r6]
	strb r3, [r5]
	movs r0, #0xe
	strb r0, [r6, #0xa]
	movs r0, #0x80
	strb r0, [r6, #0xb]
	movs r4, #0x88
	lsls r4, r4, #1
	adds r0, r7, r4
	ldrh r0, [r0]
	strb r0, [r5, #0x11]
	ldr r2, _0803B0B8 @ =0x083B5F80
	ldrb r0, [r5, #0x11]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	strb r0, [r5, #0xf]
	ldr r2, _0803B0BC @ =0x0300190C
	ldrh r0, [r2]
	strb r0, [r5, #0x10]
	movs r0, #0x31
	strb r0, [r5, #0xd]
	mov r3, r8
	lsls r4, r3, #6
	ldr r0, _0803B0A4 @ =0x00000282
	add r0, sb
	movs r1, #0
	ldrsh r3, [r0, r1]
	mov r2, sl
	movs r1, #0
	ldrsh r0, [r2, r1]
	str r0, [sp]
	add r0, sp, #4
	adds r1, r4, #0
	movs r2, #0x10
	bl calc_polar_to_screen_coords
	ldr r0, [sp, #4]
	strh r0, [r6, #2]
	asrs r0, r0, #0x10
	strh r0, [r6, #4]
	subs r4, #0x20
	strb r4, [r5, #0xa]
	adds r5, #0x40
	adds r6, #0x40
	movs r2, #1
	add r8, r2
	mov r3, r8
	cmp r3, #3
	bls _0803B006
	bl battle_advance_sequence_counter
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B0A4: .4byte 0x00000282
_0803B0A8: .4byte 0x000002A5
_0803B0AC: .4byte 0x03002C30
_0803B0B0: .4byte 0x03001800
_0803B0B4: .4byte 0x00004004
_0803B0B8: .4byte 0x083B5F80
_0803B0BC: .4byte 0x0300190C
	.syntax divided
