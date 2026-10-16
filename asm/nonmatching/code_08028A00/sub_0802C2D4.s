	.syntax unified

	thumb_func_start sub_0802C2D4
sub_0802C2D4: @ 0x0802C2D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _0802C41C @ =0x084D5EBC
	ldr r1, _0802C420 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802C424 @ =0x0850E7B8
	ldr r1, _0802C428 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r4, _0802C42C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	mov r8, r4
	ldr r7, _0802C430 @ =0x03002C30
	adds r2, r1, #0
	movs r0, #0x84
	lsls r0, r0, #4
	adds r4, r7, r0
	movs r3, #0
	mov sl, r3
	ldr r0, _0802C434 @ =0x083B6080
	mov sb, r0
_0802C31A:
	mov r6, r8
	adds r6, #0xd2
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C36C
	adds r1, r5, #0
	adds r1, #0x21
	ldr r0, _0802C438 @ =0x0000C404
	strh r0, [r4]
	mov r3, sl
	strb r3, [r4, #0x1c]
	ldrb r0, [r2]
	adds r0, r0, r5
	lsls r0, r0, #8
	movs r3, #0xba
	lsls r3, r3, #5
	adds r0, r0, r3
	adds r0, r0, r7
	ldrh r0, [r0, #2]
	strh r0, [r4, #2]
	ldrb r0, [r2]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r3
	adds r0, r0, r7
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r4, #4]
	movs r0, #7
	strb r0, [r4, #0xa]
	movs r0, #0xf0
	strb r0, [r4, #0xb]
	mov r3, sb
	ldr r0, [r3]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r2, [sp]
	bl init_battle_sprite_entry_08040B90
	ldr r2, [sp]
_0802C36C:
	adds r4, #0x40
	adds r5, #1
	cmp r5, #2
	bls _0802C31A
	adds r4, r6, #0
	subs r4, #0xd2
	adds r0, r6, #0
	subs r0, #0x4b
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r6, #0
	subs r1, #0x72
	strb r0, [r1]
	movs r5, #0
	mov r8, r4
	ldr r6, _0802C430 @ =0x03002C30
	adds r2, r1, #0
	movs r0, #0x90
	lsls r0, r0, #4
	adds r4, r6, r0
	movs r3, #0
	mov sl, r3
	ldr r0, _0802C43C @ =0x083B6084
	mov sb, r0
_0802C39E:
	lsls r0, r5, #1
	mov r7, r8
	adds r7, #0xd6
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, #0
	beq _0802C3F2
	adds r1, r5, #0
	adds r1, #0x24
	ldr r0, _0802C438 @ =0x0000C404
	strh r0, [r4]
	mov r3, sl
	strb r3, [r4, #0x1c]
	ldrb r0, [r2]
	adds r0, r0, r5
	lsls r0, r0, #8
	movs r3, #0xba
	lsls r3, r3, #5
	adds r0, r0, r3
	adds r0, r0, r6
	ldrh r0, [r0, #2]
	strh r0, [r4, #2]
	ldrb r0, [r2]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r3
	adds r0, r0, r6
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r4, #4]
	movs r0, #7
	strb r0, [r4, #0xa]
	movs r0, #0xf0
	strb r0, [r4, #0xb]
	mov r3, sb
	ldr r0, [r3]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r2, [sp]
	bl init_battle_sprite_entry_08040B90
	ldr r2, [sp]
_0802C3F2:
	adds r4, #0x40
	adds r5, #1
	cmp r5, #2
	bls _0802C39E
	movs r0, #0x4d
	bl play_sound_effect
	adds r1, r7, #0
	subs r1, #0x2c
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
_0802C41C: .4byte 0x084D5EBC
_0802C420: .4byte 0x06014800
_0802C424: .4byte 0x0850E7B8
_0802C428: .4byte 0x050002E0
_0802C42C: .4byte 0x03001800
_0802C430: .4byte 0x03002C30
_0802C434: .4byte 0x083B6080
_0802C438: .4byte 0x0000C404
_0802C43C: .4byte 0x083B6084
	.syntax divided
