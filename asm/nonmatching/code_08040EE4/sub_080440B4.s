	.syntax unified

	thumb_func_start sub_080440B4
	.global sub_080440B4
sub_080440B4: @ 0x080440B4
	movs r3, #0
	movs r2, #0
	ldr r1, _080440D0 @ =0x030017A0
_080440BA:
	ldrb r0, [r1]
	cmp r0, #3
	bne _080440C2
	adds r3, #1
_080440C2:
	adds r1, #8
	adds r2, #1
	cmp r2, #8
	bls _080440BA
	adds r0, r3, #0
	bx lr
	.align 2, 0
_080440D0: .4byte 0x030017A0
	.syntax divided
