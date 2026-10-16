	.syntax unified

	thumb_func_start sound_channel_tick
sound_channel_tick: @ 0x08073EB0
	push {lr}
	mov r3, sb
	push {r3}
	sub sp, #4
	mov r1, sb
	str r1, [sp]
	ldr r2, _08073EF4 @ =0x03007014
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #3
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r0, [r2]
	adds r2, r0, r1
	ldr r0, [r2]
	cmp r0, #0
	beq _08073EE4
	ldr r0, [r2, #0xc]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08073EE4
	ldrh r0, [r2, #0x38]
	adds r0, #1
	strh r0, [r2, #0x38]
_08073EE4:
	adds r0, r2, #0
	bl sound_channel_state_dispatch
	add sp, #4
	pop {r3}
	mov sb, r3
	pop {r0}
	bx r0
	.align 2, 0
_08073EF4: .4byte 0x03007014
	.syntax divided
