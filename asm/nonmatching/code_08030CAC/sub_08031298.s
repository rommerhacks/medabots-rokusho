	.syntax unified

	thumb_func_start sub_08031298
sub_08031298: @ 0x08031298
	push {lr}
	ldr r0, _080312B4 @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	beq _080312BC
	movs r0, #8
	bl sound_stop_all_with_fade_guard
	ldr r1, _080312B8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _080312C0
	.align 2, 0
_080312B4: .4byte 0x03000440
_080312B8: .4byte 0x0300137C
_080312BC:
	ldr r1, _080312C8 @ =0x0300137C
	movs r0, #0x58
_080312C0:
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080312C8: .4byte 0x0300137C
	.syntax divided
