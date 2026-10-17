	.syntax unified

	thumb_func_start battle_increment_bot_level
	.global battle_increment_bot_level
battle_increment_bot_level: @ 0x0801AF6C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0801AFA8 @ =0x03001800
	adds r2, r0, #0
	adds r2, #0x51
	ldrb r0, [r2]
	cmp r0, #0
	beq _0801AFB0
	ldr r1, _0801AFAC @ =0x03000590
	lsls r0, r4, #8
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0xc1
	ldrb r0, [r1]
	cmp r0, #0x50
	beq _0801AFB0
	adds r0, #1
	strb r0, [r1]
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	adds r0, r4, #0
	bl draw_medaforce_gauge_bar
	adds r0, r4, #0
	bl draw_medaforce_gauge_value
	movs r0, #0
	b _0801AFB2
	.align 2, 0
_0801AFA8: .4byte 0x03001800
_0801AFAC: .4byte 0x03000590
_0801AFB0:
	movs r0, #1
_0801AFB2:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
