	.syntax unified

	thumb_func_start sub_08065418
sub_08065418: @ 0x08065418
	push {r4, r5, lr}
	movs r5, #1
	ldr r4, _08065444 @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x4c
	ldrb r0, [r0]
	cmp r0, #0
	beq _08065448
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _08065456
	ldr r0, [r4]
	adds r0, #0x4c
	movs r1, #0
	strb r1, [r0]
	movs r0, #1
	movs r2, #0
	bl text_window_init
	b _08065456
	.align 2, 0
_08065444: .4byte 0x03006F74
_08065448:
	ldr r0, _08065478 @ =0x08485788
	ldr r0, [r0, #0x3c]
	bl run_message
	cmp r0, #0
	beq _08065456
	movs r5, #0
_08065456:
	cmp r5, #0
	bne _08065470
	ldr r0, _0806547C @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08065470
	bl sub_0803FB0C
	ldr r1, _08065480 @ =0x0300137C
	movs r0, #5
	str r0, [r1]
_08065470:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08065478: .4byte 0x08485788
_0806547C: .4byte 0x0300058C
_08065480: .4byte 0x0300137C
	.syntax divided
