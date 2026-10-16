	.syntax unified

	thumb_func_start sub_080121CC
sub_080121CC: @ 0x080121CC
	push {r4, lr}
	bl sub_080121F0
	adds r4, r0, #0
	bl sub_08043C94
	cmp r4, r0
	blt _080121E4
	bl sub_08012234
	cmp r0, #0
	bne _080121EA
_080121E4:
	movs r0, #3
	bl sub_080122F4
_080121EA:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
