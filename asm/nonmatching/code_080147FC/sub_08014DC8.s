	.syntax unified

	thumb_func_start sub_08014DC8
sub_08014DC8: @ 0x08014DC8
	push {lr}
	ldr r0, _08014DFC @ =0x03001800
	adds r1, r0, #0
	adds r1, #0x87
	ldrb r0, [r1]
	cmp r0, #2
	bls _08014DF0
	ldr r0, _08014E00 @ =0x03000590
	ldrb r2, [r1]
	lsls r1, r2, #8
	adds r1, r1, r0
	adds r1, #0xdd
	ldrb r0, [r1]
	cmp r0, #3
	bls _08014DF0
	adds r1, r0, #0
	subs r1, #4
	adds r0, r2, #0
	bl load_bot_palette_data
_08014DF0:
	ldr r1, _08014E04 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08014DFC: .4byte 0x03001800
_08014E00: .4byte 0x03000590
_08014E04: .4byte 0x0300137C
_08014E08:
	.byte 0x03, 0x49, 0x00, 0x20, 0xC8, 0x80, 0x03, 0x49
	.byte 0x45, 0x20, 0x08, 0x60, 0x70, 0x47, 0x00, 0x00, 0x10, 0x50, 0x00, 0x03, 0x7C, 0x13, 0x00, 0x03
	.syntax divided
