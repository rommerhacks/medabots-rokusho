	.syntax unified

	thumb_func_start sub_08072E98
sub_08072E98: @ 0x08072E98
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _08072EBE
	ldr r0, [r4, #0x30]
	cmp r0, #0
	beq _08072EAC
	subs r0, #1
	str r0, [r4, #0x30]
_08072EAC:
	ldr r0, [r4, #0x30]
	cmp r0, #0
	bne _08072EBE
	adds r0, r4, #0
	bl sound_channel_process_command_08072E04
	ldr r0, [r4, #0x24]
	cmp r0, #0
	bne _08072EAC
_08072EBE:
	adds r0, r4, #0
	bl sound_channel_update_pitch_sweep
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
