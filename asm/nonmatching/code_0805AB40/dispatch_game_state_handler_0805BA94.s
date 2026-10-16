	.syntax unified

	thumb_func_start dispatch_game_state_handler_0805BA94
dispatch_game_state_handler_0805BA94: @ 0x0805BA94
	push {lr}
	ldr r2, _0805BAD0 @ =0x03005010
	ldr r0, _0805BAD4 @ =0x03002B64
	ldrh r0, [r0]
	movs r3, #0
	strh r0, [r2, #4]
	strh r3, [r2, #6]
	ldr r1, _0805BAD8 @ =0x03006F74
	ldr r0, _0805BADC @ =0x03001800
	str r0, [r1]
	ldr r0, _0805BAE0 @ =0x03005030
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0805BAF4
	ldr r0, [r2, #0x1c]
	ldr r1, _0805BAE4 @ =0x00FFFF00
	ands r0, r1
	cmp r0, #0
	beq _0805BAF4
	ldr r0, _0805BAE8 @ =0x0300178C
	str r3, [r0]
	ldr r1, _0805BAEC @ =0x03002B8C
	movs r0, #0xa
	str r0, [r1]
	ldr r1, _0805BAF0 @ =0x0300137C
	movs r0, #0x10
	str r0, [r1]
	b _0805BB04
	.align 2, 0
_0805BAD0: .4byte 0x03005010
_0805BAD4: .4byte 0x03002B64
_0805BAD8: .4byte 0x03006F74
_0805BADC: .4byte 0x03001800
_0805BAE0: .4byte 0x03005030
_0805BAE4: .4byte 0x00FFFF00
_0805BAE8: .4byte 0x0300178C
_0805BAEC: .4byte 0x03002B8C
_0805BAF0: .4byte 0x0300137C
_0805BAF4:
	ldr r1, _0805BB08 @ =0x08483B00
	ldr r0, _0805BB0C @ =0x03002B8C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_0805BB04:
	pop {r0}
	bx r0
	.align 2, 0
_0805BB08: .4byte 0x08483B00
_0805BB0C: .4byte 0x03002B8C
	.syntax divided
