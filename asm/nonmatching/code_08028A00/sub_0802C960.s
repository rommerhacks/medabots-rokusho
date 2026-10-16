	.syntax unified

	thumb_func_start sub_0802C960
sub_0802C960: @ 0x0802C960
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #0
	mov r8, r0
	movs r7, #0
	movs r5, #0
	ldr r1, _0802C9B4 @ =0x03001800
	str r1, [sp]
	adds r1, #0xf8
	mov sl, r1
	movs r4, #0x21
	ldr r2, _0802C9B8 @ =0x03002C30
	mov sb, r2
_0802C982:
	ldr r0, [sp]
	adds r0, #0xd2
	adds r0, r5, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C9DE
	adds r7, #1
	ldr r3, _0802C9BC @ =0x083B6088
	ldr r0, [r3]
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	mov r6, sl
	ldrb r1, [r6]
	movs r0, #1
	ands r0, r1
	adds r3, r4, #0
	cmp r0, #0
	bne _0802C9C0
	lsls r0, r4, #6
	add r0, sb
	ldrh r1, [r0, #0x18]
	subs r1, #0x40
	b _0802C9C8
	.align 2, 0
_0802C9B4: .4byte 0x03001800
_0802C9B8: .4byte 0x03002C30
_0802C9BC: .4byte 0x083B6088
_0802C9C0:
	lsls r0, r4, #6
	add r0, sb
	ldrh r1, [r0, #0x18]
	adds r1, #0x40
_0802C9C8:
	ldr r6, _0802CA40 @ =0x000003FF
	adds r2, r6, #0
	ands r1, r2
	strh r1, [r0, #0x18]
	adds r0, r3, #0
	bl move_sprite_toward_target
	cmp r0, #0
	beq _0802C9DE
	movs r0, #1
	add r8, r0
_0802C9DE:
	adds r4, #1
	adds r5, #1
	cmp r5, #2
	bls _0802C982
	cmp r8, r7
	bne _0802CA30
	ldr r1, _0802CA44 @ =0x03002C30
	ldr r2, _0802CA48 @ =0x00000858
	adds r0, r1, r2
	movs r2, #0
	strh r2, [r0]
	ldr r3, _0802CA4C @ =0x00000898
	adds r0, r1, r3
	strh r2, [r0]
	ldr r6, _0802CA50 @ =0x000008D8
	adds r1, r1, r6
	strh r2, [r1]
	ldr r4, _0802CA54 @ =0x083B5F80
	movs r0, #0x86
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r0, [r4]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r0, [r4]
	movs r1, #0x22
	bl init_battle_sprite_entry_08040B90
	ldr r0, [r4]
	movs r1, #0x23
	bl init_battle_sprite_entry_08040B90
	movs r0, #0x4e
	bl play_sound_effect
	ldr r1, _0802CA58 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802CA30:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802CA40: .4byte 0x000003FF
_0802CA44: .4byte 0x03002C30
_0802CA48: .4byte 0x00000858
_0802CA4C: .4byte 0x00000898
_0802CA50: .4byte 0x000008D8
_0802CA54: .4byte 0x083B5F80
_0802CA58: .4byte 0x03001800
	.syntax divided
