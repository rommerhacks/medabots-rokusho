	.syntax unified

	thumb_func_start sub_0802C864
sub_0802C864: @ 0x0802C864
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r0, _0802C93C @ =0x084D6098
	ldr r1, _0802C940 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802C944 @ =0x0850E7D8
	ldr r1, _0802C948 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	movs r5, #0
	ldr r6, _0802C94C @ =0x03001800
	ldr r3, _0802C950 @ =0x03002C30
	movs r0, #0x60
	adds r0, r0, r6
	mov sl, r0
	ldr r1, _0802C954 @ =0x00000864
	adds r7, r3, r1
	movs r2, #0x84
	lsls r2, r2, #4
	adds r4, r3, r2
	movs r0, #0x40
	mov sb, r0
_0802C8A4:
	movs r1, #0xd2
	adds r1, r1, r6
	mov r8, r1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C916
	adds r1, r5, #0
	adds r1, #0x21
	movs r2, #0
	ldr r0, _0802C958 @ =0x0000C624
	strh r0, [r4]
	strb r2, [r4, #0x1c]
	movs r0, #0x78
	strh r0, [r4, #2]
	movs r0, #0x40
	strh r0, [r4, #4]
	movs r0, #7
	strb r0, [r4, #0xa]
	movs r0, #0xf0
	strb r0, [r4, #0xb]
	mov r2, sb
	strb r2, [r4, #8]
	strb r2, [r4, #9]
	movs r0, #0
	strh r0, [r4, #0x18]
	mov r2, sl
	ldrb r0, [r2]
	adds r0, r0, r5
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	strh r0, [r4, #0x30]
	mov r2, sl
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
	strb r0, [r7]
	ldr r2, _0802C95C @ =0x083B6088
	ldr r0, [r2]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r3, [sp]
	bl init_battle_sprite_entry_08040B90
	ldr r3, [sp]
_0802C916:
	adds r7, #0x40
	adds r4, #0x40
	adds r5, #1
	cmp r5, #2
	bls _0802C8A4
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
_0802C93C: .4byte 0x084D6098
_0802C940: .4byte 0x06014800
_0802C944: .4byte 0x0850E7D8
_0802C948: .4byte 0x050002E0
_0802C94C: .4byte 0x03001800
_0802C950: .4byte 0x03002C30
_0802C954: .4byte 0x00000864
_0802C958: .4byte 0x0000C624
_0802C95C: .4byte 0x083B6088
	.syntax divided
