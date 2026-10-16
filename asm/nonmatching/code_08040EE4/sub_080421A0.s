	.syntax unified

	thumb_func_start sub_080421A0
	.global sub_080421A0
sub_080421A0: @ 0x080421A0
	movs r0, #0
	ldr r1, _080421B0 @ =0x030017A0
_080421A4:
	strb r0, [r1, #7]
	adds r1, #8
	adds r0, #1
	cmp r0, #8
	bls _080421A4
	bx lr
	.align 2, 0
_080421B0: .4byte 0x030017A0
	.syntax divided
