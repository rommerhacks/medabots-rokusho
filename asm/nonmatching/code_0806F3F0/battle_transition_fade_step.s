	.syntax unified

	thumb_func_start battle_transition_fade_step
	.global battle_transition_fade_step
battle_transition_fade_step: @ 0x08070080
	push {r4, r5, lr}
	ldr r4, _080700A4 @ =0x03001800
	ldr r0, [r4, #8]
	cmp r0, #0x3c
	beq _080700AC
	cmp r0, #0x3c
	ble _080700EA
	movs r0, #2
	movs r1, #2
	movs r2, #0
	bl setup_screen_transition_effect_080684F0
	ldr r1, _080700A8 @ =0x0300137C
	movs r0, #2
	str r0, [r1]
	movs r0, #1
	b _080700F4
	.align 2, 0
_080700A4: .4byte 0x03001800
_080700A8: .4byte 0x0300137C
_080700AC:
	ldr r2, _080700FC @ =0x00007FFF
	movs r0, #4
	movs r1, #1
	bl setup_screen_transition_effect_080682CC
	ldr r1, _08070100 @ =0x04000050
	ldr r2, _08070104 @ =0x00000844
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _08070108 @ =0x04000052
	movs r3, #0x10
	strh r3, [r0]
	adds r1, #4
	movs r0, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r5, #0x80
	lsls r5, r5, #3
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0807010C @ =0x0300137C
	ldr r0, [r1]
	strh r0, [r4, #4]
	adds r0, r4, #0
	adds r0, #0xee
	strb r3, [r0]
	movs r0, #5
	str r0, [r1]
_080700EA:
	ldr r1, _08070110 @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	movs r0, #0
_080700F4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080700FC: .4byte 0x00007FFF
_08070100: .4byte 0x04000050
_08070104: .4byte 0x00000844
_08070108: .4byte 0x04000052
_0807010C: .4byte 0x0300137C
_08070110: .4byte 0x03001800
	.syntax divided
