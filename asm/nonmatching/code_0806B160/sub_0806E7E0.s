	.syntax unified

	thumb_func_start sub_0806E7E0
sub_0806E7E0: @ 0x0806E7E0
	push {r4, lr}
	ldr r0, _0806E7FC @ =0x03001800
	ldr r1, [r0, #8]
	adds r4, r0, #0
	cmp r1, #0
	bne _0806E804
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0806E800 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	b _0806E828
	.align 2, 0
_0806E7FC: .4byte 0x03001800
_0806E800: .4byte 0x0000FEFF
_0806E804:
	cmp r1, #0x3c
	ble _0806E828
	movs r0, #0
	str r0, [r4, #8]
	movs r0, #2
	movs r1, #4
	movs r2, #0
	bl setup_screen_transition_effect_080684F0
	movs r0, #0xa
	strh r0, [r4, #4]
	ldr r1, _0806E824 @ =0x0300137C
	movs r0, #2
	str r0, [r1]
	b _0806E82E
	.align 2, 0
_0806E824: .4byte 0x0300137C
_0806E828:
	ldr r0, [r4, #8]
	adds r0, #1
	str r0, [r4, #8]
_0806E82E:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
