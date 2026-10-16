	.syntax unified

	thumb_func_start sound_channel_process_command_08072E04
sound_channel_process_command_08072E04: @ 0x08072E04
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x24]
	cmp r5, #0
	beq _08072E74
	adds r2, r5, #0
	ldrb r1, [r2]
	adds r3, r1, #0
	adds r2, #1
	str r2, [r4, #0x24]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0xd0
	bne _08072E3C
	movs r0, #0xf
	ands r1, r0
	adds r0, r4, #0
	bl sub_08072984
	ldr r0, [r4, #0x2c]
	str r0, [r4, #0x30]
	adds r2, r4, #0
	adds r2, #0x50
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	b _08072E74
_08072E3C:
	cmp r3, #0xe1
	beq _08072E5A
	cmp r3, #0xe1
	ble _08072E74
	cmp r3, #0xe2
	beq _08072E68
	cmp r3, #0xff
	bne _08072E74
	adds r0, r4, #0
	movs r1, #0
	bl sub_08072984
	movs r0, #0
	str r0, [r4, #0x24]
	b _08072E74
_08072E5A:
	ldrb r1, [r5, #1]
	adds r0, r2, #1
	str r0, [r4, #0x24]
	adds r0, r4, #0
	bl sub_080729A0
	b _08072E74
_08072E68:
	ldrb r1, [r5, #1]
	adds r0, r2, #1
	str r0, [r4, #0x24]
	adds r0, r4, #0
	bl sub_080729A8
_08072E74:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
