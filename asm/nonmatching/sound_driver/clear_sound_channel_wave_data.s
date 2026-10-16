	.syntax unified

	thumb_func_start clear_sound_channel_wave_data
clear_sound_channel_wave_data: @ 0x0807407C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, [r4, #8]
	cmp r1, #0
	beq _0807409E
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp]
	ldr r2, _080740A8 @ =0x0500000C
	mov r0, sp
	bl CpuSet
	ldr r0, [r4, #8]
	adds r0, #0x30
	movs r1, #0
	strb r1, [r0]
_0807409E:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080740A8: .4byte 0x0500000C
	.syntax divided
