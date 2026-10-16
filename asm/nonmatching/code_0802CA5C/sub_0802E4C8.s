	.syntax unified

	thumb_func_start sub_0802E4C8
sub_0802E4C8: @ 0x0802E4C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _0802E5AC @ =0x084D6F88
	ldr r1, _0802E5B0 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802E5B4 @ =0x0850E938
	ldr r1, _0802E5B8 @ =0x050002E0
	movs r2, #0x10
	bl CpuFastSet
	movs r5, #0
	ldr r7, _0802E5BC @ =0x03001800
	ldr r3, _0802E5C0 @ =0x03002C30
	movs r0, #0
	mov sl, r0
	movs r1, #0x60
	adds r1, r1, r7
	mov sb, r1
	ldr r2, _0802E5C4 @ =0x000002A3
	adds r6, r3, r2
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r3, r0
_0802E500:
	movs r1, #0xd2
	adds r1, r1, r7
	mov r8, r1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E580
	adds r1, r5, #0
	adds r1, #0xa
	ldr r0, _0802E5C8 @ =0x0000C624
	strh r0, [r4]
	mov r2, sl
	strb r2, [r4, #0x1c]
	movs r0, #0x78
	strh r0, [r4, #2]
	movs r0, #0x40
	strh r0, [r4, #4]
	movs r0, #4
	strb r0, [r4, #8]
	strb r0, [r4, #9]
	movs r0, #0
	strh r0, [r4, #0x18]
	mov r2, sb
	ldrb r0, [r2]
	adds r0, r0, r5
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	strh r0, [r4, #0x30]
	mov r2, sb
	ldrb r0, [r2]
	adds r0, r0, r5
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r4, #0x32]
	movs r0, #6
	strb r0, [r6, #1]
	mov r0, sl
	strb r0, [r6]
	movs r0, #7
	strb r0, [r4, #0xa]
	movs r0, #0xe0
	strb r0, [r4, #0xb]
	movs r2, #0x48
	ldr r0, _0802E5CC @ =0x030004C4
	strb r2, [r0]
	ldr r0, _0802E5D0 @ =0x083B5F80
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r3, [sp]
	bl init_battle_sprite_entry_08040B90
	ldr r3, [sp]
_0802E580:
	adds r6, #0x40
	adds r4, #0x40
	adds r5, #1
	cmp r5, #2
	bls _0802E500
	movs r0, #0x6a
	bl play_sound_effect
	mov r1, r8
	subs r1, #0x28
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802E5AC: .4byte 0x084D6F88
_0802E5B0: .4byte 0x06014800
_0802E5B4: .4byte 0x0850E938
_0802E5B8: .4byte 0x050002E0
_0802E5BC: .4byte 0x03001800
_0802E5C0: .4byte 0x03002C30
_0802E5C4: .4byte 0x000002A3
_0802E5C8: .4byte 0x0000C624
_0802E5CC: .4byte 0x030004C4
_0802E5D0: .4byte 0x083B5F80
	.syntax divided
