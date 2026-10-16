	.syntax unified

	thumb_func_start battle_calc_bot_count_minus_one_mod3
	.global battle_calc_bot_count_minus_one_mod3
battle_calc_bot_count_minus_one_mod3: @ 0x0801A640
	push {r4, lr}
	ldr r4, _0801A674 @ =0x03001800
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r0, [r2]
	subs r0, #1
	adds r1, r4, #0
	adds r1, #0x87
	strb r0, [r1]
	ldrb r0, [r2]
	subs r0, #1
	movs r1, #3
	bl sub_0807CBBC
	adds r1, r4, #0
	adds r1, #0x89
	strb r0, [r1]
	movs r1, #1
	eors r0, r1
	adds r1, r4, #0
	adds r1, #0x8a
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801A674: .4byte 0x03001800
	.syntax divided
