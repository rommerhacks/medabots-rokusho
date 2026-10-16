	.syntax unified

	thumb_func_start sound_engine_init
	.global sound_engine_init
sound_engine_init: @ 0x08072234
	push {r4, lr}
	sub sp, #4
	adds r1, r0, #0
	ldr r4, _08072270 @ =0x03007014
	str r1, [r4]
	movs r0, #0
	str r0, [sp]
	ldr r2, _08072274 @ =0x050001CD
	mov r0, sp
	bl CpuSet
	bl init_all_sound_channels
	ldr r0, [r4]
	ldr r1, _08072278 @ =0x000006CA
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _0807227C @ =0x00000712
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	bl sound_init_wave_channel
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08072270: .4byte 0x03007014
_08072274: .4byte 0x050001CD
_08072278: .4byte 0x000006CA
_0807227C: .4byte 0x00000712
	.syntax divided
