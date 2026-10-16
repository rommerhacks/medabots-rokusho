	.syntax unified

	thumb_func_start sub_08014D94
sub_08014D94: @ 0x08014D94
	push {lr}
	ldr r0, _08014DBC @ =0x03001800
	adds r1, r0, #0
	adds r1, #0x87
	ldrb r0, [r1]
	cmp r0, #2
	bls _08014DB0
	ldr r2, _08014DC0 @ =0x03000590
	lsls r1, r0, #8
	adds r1, r1, r2
	adds r1, #0xdd
	ldrb r1, [r1]
	bl battle_bot_select_part
_08014DB0:
	ldr r1, _08014DC4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08014DBC: .4byte 0x03001800
_08014DC0: .4byte 0x03000590
_08014DC4: .4byte 0x0300137C
	.syntax divided
