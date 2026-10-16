	.syntax unified

	thumb_func_start sub_080725BC
	.global sub_080725BC
sub_080725BC: @ 0x080725BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0x58
	adds r0, r0, r7
	mov sb, r0
	ldrb r0, [r0]
	adds r2, r7, #0
	adds r2, #0x59
	movs r1, #0x5a
	adds r1, r1, r7
	mov r8, r1
	cmp r0, #0
	bne _080725E6
	strb r0, [r2]
	strb r0, [r1]
	str r0, [r7, #0x34]
	b _08072644
_080725E6:
	ldr r0, _08072654 @ =0x03007014
	ldr r1, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r6, r1, r0
	adds r0, r7, #0
	adds r0, #0x64
	ldrb r0, [r0]
	cmp r0, #4
	beq _08072600
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r6, r1, r0
_08072600:
	adds r0, r7, #0
	adds r0, #0x56
	ldrb r0, [r0]
	movs r1, #0
	mov sl, r1
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0x57
	ldrb r0, [r0]
	lsrs r0, r0, #1
	mov r2, r8
	strb r0, [r2]
	adds r5, r7, #0
	adds r5, #0x48
	ldrh r1, [r5]
	adds r1, #2
	adds r0, r6, #0
	bl sound_set_pitch_offset
	adds r4, r0, #0
	ldrh r1, [r5]
	adds r0, r6, #0
	bl sound_set_pitch_offset
	subs r4, r4, r0
	mov r1, sb
	ldrb r0, [r1]
	muls r0, r4, r0
	mov r2, r8
	ldrb r1, [r2]
	bl sub_0807CD58
	str r0, [r7, #0x34]
	mov r0, sl
_08072644:
	str r0, [r7, #0x38]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08072654: .4byte 0x03007014
	.syntax divided
