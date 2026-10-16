	.syntax unified

	thumb_func_start scene_transition_countdown_tick
scene_transition_countdown_tick: @ 0x0806E278
	push {r4, lr}
	ldr r4, _0806E2BC @ =0x03001800
	ldr r0, [r4, #0x10]
	subs r0, #1
	str r0, [r4, #0x10]
	cmp r0, #0
	bne _0806E28C
	movs r0, #3
	bl play_song
_0806E28C:
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	beq _0806E2B6
	ldr r0, _0806E2C0 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0806E2B6
	ldr r1, _0806E2C4 @ =0x0300178C
	movs r0, #3
	str r0, [r1]
	ldr r1, _0806E2C8 @ =0x03002B8C
	movs r0, #2
	str r0, [r1]
	ldr r1, _0806E2CC @ =0x0300137C
	movs r0, #0
	str r0, [r1]
	ldr r1, _0806E2D0 @ =0x03007008
	movs r0, #1
	strb r0, [r1]
_0806E2B6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806E2BC: .4byte 0x03001800
_0806E2C0: .4byte 0x0300058C
_0806E2C4: .4byte 0x0300178C
_0806E2C8: .4byte 0x03002B8C
_0806E2CC: .4byte 0x0300137C
_0806E2D0: .4byte 0x03007008
	.syntax divided
