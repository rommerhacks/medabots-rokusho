	.syntax unified

	thumb_func_start sub_0806BB30
sub_0806BB30: @ 0x0806BB30
	push {lr}
	bl sub_0806C20C
	bl sub_0806CFA4
	bl sub_0806CDE8
	bl sub_0806C7C4
	cmp r0, #0
	beq _0806BB5A
	ldr r0, _0806BB60 @ =0x03005310
	adds r0, #0x39
	movs r1, #2
	strb r1, [r0]
	movs r0, #0x30
	bl sound_stop_all_with_fade_guard
	ldr r1, _0806BB64 @ =0x0300137C
	movs r0, #8
	str r0, [r1]
_0806BB5A:
	pop {r0}
	bx r0
	.align 2, 0
_0806BB60: .4byte 0x03005310
_0806BB64: .4byte 0x0300137C
	.syntax divided
