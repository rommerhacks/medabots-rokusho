	.syntax unified

	thumb_func_start play_sound_from_command
play_sound_from_command: @ 0x08074BD8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	str r1, [sp]
	bl sub_080750CC
	mov sb, r0
	ldr r0, _08074C64 @ =0x0000068C
	add r0, sb
	ldr r1, [r0]
	mov r2, sl
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r5, [r0]
	movs r3, #0
	mov r8, r3
	movs r2, #0x80
	lsls r2, r2, #4
	adds r6, r5, #0
_08074C06:
	ldrh r0, [r5]
	ands r0, r2
	cmp r0, #0
	beq _08074C48
	movs r0, #0x74
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	mov r3, sb
	adds r4, r3, r0
	adds r7, r4, #0
	adds r7, #0x6d
	ldrb r0, [r7]
	ldrb r1, [r5, #2]
	cmp r0, r1
	bhi _08074C46
	ldr r1, [r6, #4]
	adds r0, r4, #0
	str r2, [sp, #4]
	bl init_sound_channel
	ldrb r0, [r5, #2]
	strb r0, [r7]
	adds r0, r4, #0
	adds r0, #0x4e
	mov r3, sl
	strh r3, [r0]
	adds r0, #0x22
	mov r1, sp
	ldrb r1, [r1]
	strb r1, [r0]
	ldr r2, [sp, #4]
_08074C46:
	adds r6, #4
_08074C48:
	lsrs r2, r2, #1
	movs r3, #1
	add r8, r3
	cmp r2, #0
	bne _08074C06
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08074C64: .4byte 0x0000068C
	.syntax divided
