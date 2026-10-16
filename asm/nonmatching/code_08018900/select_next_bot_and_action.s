	.syntax unified

	thumb_func_start select_next_bot_and_action
	.global select_next_bot_and_action
select_next_bot_and_action: @ 0x0801B69C
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r5, _0801B6FC @ =0x03000590
	lsls r2, r3, #8
	adds r4, r2, r5
	adds r0, r4, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0x2c
	bne _0801B6F4
	adds r0, r4, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	adds r1, r1, r5
	adds r0, r1, #0
	adds r0, #0x4a
	ldrb r0, [r0]
	cmp r0, #3
	bls _0801B6D6
	adds r0, r1, #0
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #0x34
	bne _0801B6F4
_0801B6D6:
	adds r0, r3, #0
	bl find_next_active_bot
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0xe0
	strb r0, [r1]
	ldrb r0, [r1]
	subs r0, #1
	bl sub_080330E8
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0xe1
	strb r0, [r1]
_0801B6F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801B6FC: .4byte 0x03000590
	.syntax divided
