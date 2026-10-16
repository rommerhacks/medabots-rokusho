	.syntax unified

	thumb_func_start fade_transition_and_input_check
fade_transition_and_input_check: @ 0x0806591C
	push {r4, lr}
	ldr r2, _08065950 @ =0x08485BD8
	ldr r4, _08065954 @ =0x03006F74
	ldr r0, [r4]
	ldr r0, [r0, #8]
	movs r1, #0x10
	cmp r0, #0
	beq _0806592E
	movs r1, #0x14
_0806592E:
	adds r0, r1, r2
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _08065982
	ldr r3, [r4]
	ldr r2, [r3, #8]
	cmp r2, #0
	bne _0806595C
	ldr r1, _08065958 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	strh r2, [r3, #0x3a]
	b _08065982
	.align 2, 0
_08065950: .4byte 0x08485BD8
_08065954: .4byte 0x03006F74
_08065958: .4byte 0x0300137C
_0806595C:
	ldr r0, _08065988 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08065982
	movs r0, #0xd
	bl play_sound_effect
	ldr r2, _0806598C @ =0x03000440
	adds r1, r2, #0
	adds r1, #0x84
	movs r0, #0
	strb r0, [r1]
	strb r0, [r2, #0x1b]
	ldr r1, _08065990 @ =0x0300137C
	ldr r0, [r1]
	subs r0, #2
	str r0, [r1]
_08065982:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08065988: .4byte 0x0300058C
_0806598C: .4byte 0x03000440
_08065990: .4byte 0x0300137C
	.syntax divided
