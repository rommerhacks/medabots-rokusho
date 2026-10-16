	.syntax unified

	thumb_func_start sub_0806BB00
sub_0806BB00: @ 0x0806BB00
	push {lr}
	bl sub_0806CE58
	bl sub_0806C6F8
	cmp r0, #0
	beq _0806BB22
	ldr r0, _0806BB28 @ =0x03005310
	adds r0, #0x39
	movs r1, #1
	strb r1, [r0]
	movs r0, #0x30
	bl sound_stop_all_with_fade_guard
	ldr r1, _0806BB2C @ =0x0300137C
	movs r0, #8
	str r0, [r1]
_0806BB22:
	pop {r0}
	bx r0
	.align 2, 0
_0806BB28: .4byte 0x03005310
_0806BB2C: .4byte 0x0300137C
	.syntax divided
