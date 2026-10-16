	.syntax unified

	thumb_func_start sound_channel_tick_decay
sound_channel_tick_decay: @ 0x080722D4
	push {lr}
	adds r3, r0, #0
	movs r0, #0x5f
	adds r0, r0, r3
	mov ip, r0
	ldrb r0, [r0]
	subs r0, #1
	mov r1, ip
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08072334
	adds r1, r3, #0
	adds r1, #0x60
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _08072302
	adds r0, r3, #0
	bl sub_08072280
	b _08072334
_08072302:
	subs r0, r2, #1
	strb r0, [r1]
	adds r2, r3, #0
	adds r2, #0x66
	ldrb r0, [r2]
	adds r1, r0, #0
	subs r0, #1
	cmp r0, #0
	bge _08072316
	movs r0, #0
_08072316:
	cmp r1, r0
	beq _08072328
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x50
	ldrb r1, [r0]
	movs r2, #2
	orrs r1, r2
	strb r1, [r0]
_08072328:
	adds r0, r3, #0
	adds r0, #0x5e
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov r1, ip
	strb r0, [r1]
_08072334:
	pop {r0}
	bx r0
	.syntax divided
