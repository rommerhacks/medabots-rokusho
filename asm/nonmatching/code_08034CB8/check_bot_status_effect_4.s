	.syntax unified

	thumb_func_start check_bot_status_effect_4
	.global check_bot_status_effect_4
check_bot_status_effect_4: @ 0x08035A70
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r5, _08035AA0 @ =0x03000590
	lsls r2, r2, #8
	adds r2, r2, r5
	adds r2, #0xc0
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08035AA4
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #3
	lsls r1, r4, #8
	adds r0, r0, r1
	adds r0, r0, r5
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #0x34
	bne _08035AA4
	movs r0, #1
	b _08035AA6
	.align 2, 0
_08035AA0: .4byte 0x03000590
_08035AA4:
	movs r0, #0
_08035AA6:
	pop {r4, r5}
	pop {r1}
	bx r1
	.syntax divided
