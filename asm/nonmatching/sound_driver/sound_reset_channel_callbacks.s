	.syntax unified

	thumb_func_start sound_reset_channel_callbacks
sound_reset_channel_callbacks: @ 0x08074D28
	push {r4, lr}
	mov r4, sb
	push {r4}
	sub sp, #8
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, _08074D8C @ =0x03007014
	ldr r4, [r0]
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r4, r1
	mov sb, sp
	bl sub_08074CEC
	movs r1, #0x91
	lsls r1, r1, #2
	adds r0, r4, r1
	mov sb, sp
	bl sub_08074CEC
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r4, r1
	mov sb, sp
	bl sub_08074CEC
	movs r1, #0xcb
	lsls r1, r1, #2
	adds r0, r4, r1
	mov sb, sp
	bl sub_08074CEC
	movs r1, #0x91
	lsls r1, r1, #3
	adds r0, r4, r1
	mov sb, sp
	bl sub_08074CEC
	ldr r1, _08074D90 @ =0x000004FC
	adds r0, r4, r1
	mov sb, sp
	bl sub_08074CEC
	add sp, #8
	pop {r3}
	mov sb, r3
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08074D8C: .4byte 0x03007014
_08074D90: .4byte 0x000004FC
	.syntax divided
