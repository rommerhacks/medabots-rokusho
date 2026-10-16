	.syntax unified

	thumb_func_start update_fade_transition_state_0805F778
update_fade_transition_state_0805F778: @ 0x0805F778
	push {lr}
	ldr r0, _0805F7B4 @ =0x03006F74
	ldr r1, [r0]
	ldrb r0, [r1]
	cmp r0, #1
	bne _0805F798
	adds r0, r1, #0
	adds r0, #0x49
	ldrb r0, [r0]
	movs r1, #4
	cmp r0, #0
	beq _0805F792
	movs r1, #5
_0805F792:
	adds r0, r1, #0
	bl play_sound_effect
_0805F798:
	ldr r2, _0805F7B4 @ =0x03006F74
	ldr r1, [r2]
	ldrb r0, [r1]
	cmp r0, #0x20
	beq _0805F7BC
	adds r0, #1
	strb r0, [r1]
	ldr r1, _0805F7B8 @ =0x04000054
	ldr r0, [r2]
	ldrb r0, [r0]
	lsrs r0, r0, #1
	strh r0, [r1]
	b _0805F7E0
	.align 2, 0
_0805F7B4: .4byte 0x03006F74
_0805F7B8: .4byte 0x04000054
_0805F7BC:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0805F7E4 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0805F7E8 @ =0x0300178C
	movs r0, #3
	str r0, [r1]
	ldr r1, _0805F7EC @ =0x03002B8C
	movs r0, #2
	str r0, [r1]
	ldr r1, _0805F7F0 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
	ldr r1, _0805F7F4 @ =0x03007008
	movs r0, #1
	strb r0, [r1]
_0805F7E0:
	pop {r0}
	bx r0
	.align 2, 0
_0805F7E4: .4byte 0x0000FDFF
_0805F7E8: .4byte 0x0300178C
_0805F7EC: .4byte 0x03002B8C
_0805F7F0: .4byte 0x0300137C
_0805F7F4: .4byte 0x03007008
	.syntax divided
