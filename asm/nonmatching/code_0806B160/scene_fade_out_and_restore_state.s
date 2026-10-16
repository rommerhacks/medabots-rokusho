	.syntax unified

	thumb_func_start scene_fade_out_and_restore_state
scene_fade_out_and_restore_state: @ 0x0806E99C
	push {r4, lr}
	ldr r1, _0806EA00 @ =0x03001800
	ldr r0, [r1, #8]
	cmp r0, #0x4c
	ble _0806E9C8
	adds r3, r1, #0
	adds r3, #0xee
	ldrb r4, [r3]
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	blt _0806E9C8
	ldrb r1, [r3]
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #0x18
	ldr r2, _0806EA04 @ =0x04000052
	lsrs r0, r0, #0x10
	orrs r1, r0
	strh r1, [r2]
	subs r0, r4, #1
	strb r0, [r3]
_0806E9C8:
	bl scene_transition_step_080686F4
	cmp r0, #0
	beq _0806E9F0
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0806EA08 @ =0x0000FBFF
	ands r0, r1
	strh r0, [r2]
	ldr r2, _0806EA0C @ =0x0300178C
	ldr r1, _0806EA00 @ =0x03001800
	ldrh r0, [r1]
	str r0, [r2]
	ldr r2, _0806EA10 @ =0x03002B8C
	ldrh r0, [r1, #2]
	str r0, [r2]
	ldr r2, _0806EA14 @ =0x0300137C
	ldrh r0, [r1, #4]
	str r0, [r2]
_0806E9F0:
	ldr r1, _0806EA00 @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806EA00: .4byte 0x03001800
_0806EA04: .4byte 0x04000052
_0806EA08: .4byte 0x0000FBFF
_0806EA0C: .4byte 0x0300178C
_0806EA10: .4byte 0x03002B8C
_0806EA14: .4byte 0x0300137C
	.syntax divided
