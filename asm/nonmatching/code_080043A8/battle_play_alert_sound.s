	.syntax unified

	thumb_func_start battle_play_alert_sound
	.global battle_play_alert_sound
battle_play_alert_sound: @ 0x08007408
	push {lr}
	ldr r0, _08007434 @ =0x03000440
	adds r0, #0x50
	ldrb r0, [r0]
	cmp r0, #2
	bgt _0800742E
	cmp r0, #1
	blt _0800742E
	ldr r0, _08007438 @ =0x03001800
	adds r0, #0x41
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800742E
	movs r0, #4
	bl play_sound_effect
	ldr r1, _0800743C @ =0x0300137C
	movs r0, #0x20
	str r0, [r1]
_0800742E:
	pop {r0}
	bx r0
	.align 2, 0
_08007434: .4byte 0x03000440
_08007438: .4byte 0x03001800
_0800743C: .4byte 0x0300137C
	.syntax divided
