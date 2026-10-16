	.syntax unified

	thumb_func_start sub_080027BC
sub_080027BC: @ 0x080027BC
	push {lr}
	ldr r1, _080027D4 @ =0x083AC284
	ldr r0, _080027D8 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_080027D4: .4byte 0x083AC284
_080027D8: .4byte 0x0300137C
	.syntax divided
