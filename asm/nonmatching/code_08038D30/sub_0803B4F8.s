	.syntax unified

	thumb_func_start sub_0803B4F8
sub_0803B4F8: @ 0x0803B4F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	bl load_battle_sequence_commands
	movs r0, #0
	mov r8, r0
	ldr r1, _0803B5C8 @ =0x03001800
	mov sb, r1
	movs r0, #0x84
	lsls r0, r0, #1
	add r0, sb
	mov sl, r0
	ldr r1, _0803B5CC @ =0x03002C30
	movs r0, #0xb7
	lsls r0, r0, #2
	adds r6, r1, r0
	subs r0, #0x1c
	adds r7, r1, r0
_0803B524:
	mov r4, r8
	adds r4, #0xb
	ldr r0, _0803B5D0 @ =0x0000C604
	strh r0, [r7]
	movs r1, #0
	strb r1, [r6]
	mov r0, r8
	lsls r5, r0, #5
	mov r1, sl
	movs r0, #0
	ldrsh r2, [r1, r0]
	movs r0, #0x81
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	ldr r1, _0803B5CC @ =0x03002C30
	adds r0, r0, r1
	movs r1, #2
	ldrsh r3, [r0, r1]
	movs r1, #4
	ldrsh r0, [r0, r1]
	str r0, [sp]
	add r0, sp, #4
	adds r1, r5, #0
	bl calc_polar_to_screen_coords
	ldr r0, [sp, #4]
	strh r0, [r7, #2]
	asrs r0, r0, #0x10
	strh r0, [r7, #4]
	movs r0, #8
	strb r0, [r7, #8]
	strb r0, [r7, #9]
	movs r0, #0xe
	strb r0, [r7, #0xa]
	movs r0, #0x80
	strb r0, [r7, #0xb]
	movs r0, #0x36
	strb r0, [r6, #0xd]
	strb r5, [r6, #0xa]
	mov r1, sl
	ldrh r0, [r1]
	strb r0, [r6, #0xb]
	movs r0, #0
	strb r0, [r6, #0xf]
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	strb r0, [r6, #7]
	ldr r1, _0803B5D4 @ =0x03001906
	ldrh r0, [r1]
	strb r0, [r6, #0x11]
	ldr r1, _0803B5D8 @ =0x083B5F80
	ldrb r0, [r6, #0x11]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r1, r4, #0
	bl init_battle_sprite_entry_08040B90
	adds r6, #0x40
	adds r7, #0x40
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #7
	bls _0803B524
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
_0803B5C8: .4byte 0x03001800
_0803B5CC: .4byte 0x03002C30
_0803B5D0: .4byte 0x0000C604
_0803B5D4: .4byte 0x03001906
_0803B5D8: .4byte 0x083B5F80
	.syntax divided
