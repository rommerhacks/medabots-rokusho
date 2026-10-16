	.syntax unified

	thumb_func_start sub_0801DAEC
sub_0801DAEC: @ 0x0801DAEC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	ldr r7, _0801DC2C @ =0x03001800
	movs r0, #0xde
	adds r0, r0, r7
	mov sb, r0
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, #0x59
	ldr r1, _0801DC30 @ =0x03002C30
	mov sl, r1
	adds r1, r7, #0
	adds r1, #0x87
	ldrb r2, [r1]
	lsls r2, r2, #8
	movs r3, #0xba
	lsls r3, r3, #5
	adds r2, r2, r3
	add r2, sl
	movs r3, #4
	ldrsh r1, [r2, r3]
	ldrh r2, [r2, #4]
	adds r2, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	bl sprite_move_toward_target
	cmp r0, #0
	bne _0801DB30
	b _0801DC38
_0801DB30:
	mov r0, sb
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, #0x59
	adds r1, #0x71
	bl check_sprite_overlap_and_adjust
	mov r2, sb
	ldrb r1, [r2]
	subs r1, #1
	lsls r0, r1, #2
	adds r0, #0x5a
	adds r6, r7, #0
	adds r6, #0xf8
	ldrb r3, [r6]
	movs r2, #1
	mov r8, r2
	movs r5, #1
	adds r2, r5, #0
	ands r2, r3
	mov r3, r8
	eors r2, r3
	bl update_battle_sprite_orbiting_positions
	movs r0, #0x41
	bl play_sound_effect
	mov r1, sb
	ldrb r0, [r1]
	subs r0, #1
	adds r4, r7, #0
	adds r4, #0x64
	adds r1, r4, #0
	bl get_bot_part_effective_values
	ldrb r0, [r4]
	adds r1, r7, #0
	adds r1, #0x65
	ldrb r1, [r1]
	adds r2, r7, #0
	adds r2, #0x66
	ldrb r2, [r2]
	adds r3, r7, #0
	adds r3, #0x67
	ldrb r3, [r3]
	mov ip, r3
	mov r3, sb
	ldrb r3, [r3]
	adds r4, r3, #0
	subs r4, #1
	str r4, [sp]
	mov r3, sb
	ldrb r3, [r3]
	lsls r4, r3, #2
	adds r4, #0x56
	str r4, [sp, #4]
	mov r3, sb
	ldrb r3, [r3]
	lsls r4, r3, #8
	movs r3, #0xb2
	lsls r3, r3, #5
	adds r4, r4, r3
	add r4, sl
	movs r3, #2
	ldrsh r4, [r4, r3]
	str r4, [sp, #8]
	mov r3, sb
	ldrb r3, [r3]
	lsls r4, r3, #8
	movs r3, #0xb2
	lsls r3, r3, #5
	adds r4, r4, r3
	add r4, sl
	movs r3, #4
	ldrsh r4, [r4, r3]
	subs r4, #4
	str r4, [sp, #0xc]
	ldrb r4, [r6]
	ands r5, r4
	mov r3, r8
	eors r5, r3
	str r5, [sp, #0x10]
	adds r4, r7, #0
	adds r4, #0x3c
	ldrb r4, [r4]
	adds r4, #2
	str r4, [sp, #0x14]
	mov r3, sb
	ldrb r4, [r3]
	lsls r4, r4, #2
	adds r4, #0x56
	str r4, [sp, #0x18]
	mov r3, ip
	bl setup_battle_sprite_group
	mov r1, sb
	ldrb r0, [r1]
	lsls r0, r0, #8
	movs r2, #0xae
	lsls r2, r2, #5
	adds r0, r0, r2
	add r0, sl
	movs r4, #0
	movs r1, #0
	strh r1, [r0, #0x18]
	mov r3, sb
	ldrb r0, [r3]
	lsls r0, r0, #8
	adds r2, #0x40
	adds r0, r0, r2
	add r0, sl
	strh r1, [r0, #0x18]
	ldrb r0, [r3]
	adds r0, #0x71
	bl sub_080356B4
	ldr r0, _0801DC34 @ =0x03000440
	adds r0, #0x84
	strb r4, [r0]
	adds r1, r7, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0801DC62
	.align 2, 0
_0801DC2C: .4byte 0x03001800
_0801DC30: .4byte 0x03002C30
_0801DC34: .4byte 0x03000440
_0801DC38:
	mov r3, sb
	ldrb r1, [r3]
	subs r1, #1
	lsls r0, r1, #2
	adds r0, #0x5a
	adds r2, r7, #0
	adds r2, #0xf8
	ldrb r3, [r2]
	movs r4, #1
	movs r2, #1
	ands r2, r3
	eors r2, r4
	bl update_battle_sprite_orbiting_positions
	mov r0, sb
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, #0x59
	adds r1, #0x71
	bl check_sprite_overlap_and_adjust
_0801DC62:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
