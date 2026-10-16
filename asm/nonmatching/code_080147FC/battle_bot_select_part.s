	.syntax unified

	thumb_func_start battle_bot_select_part
	.global battle_bot_select_part
battle_bot_select_part: @ 0x08015564
	push {r4, lr}
	ldr r4, _080155A4 @ =0x03000590
	lsls r2, r0, #8
	adds r3, r2, r4
	adds r0, r3, #0
	adds r0, #0xdd
	strb r1, [r0]
	cmp r1, #0
	beq _0801559C
	cmp r1, #3
	bhi _0801559C
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, r0, r4
	adds r1, r0, #0
	adds r1, #0x56
	ldrb r2, [r1]
	adds r1, r3, #0
	adds r1, #0xe0
	strb r2, [r1]
	adds r0, #0x57
	ldrb r1, [r0]
	adds r0, r3, #0
	adds r0, #0xe1
	strb r1, [r0]
_0801559C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080155A4: .4byte 0x03000590
	.syntax divided
