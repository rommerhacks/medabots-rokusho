	.syntax unified

	thumb_func_start sub_08042218
	.global sub_08042218
sub_08042218: @ 0x08042218
	movs r2, #0
	ldr r1, _08042228 @ =0x030017A0
_0804221C:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0804222C
	movs r0, #0
	b _08042236
	.align 2, 0
_08042228: .4byte 0x030017A0
_0804222C:
	adds r1, #8
	adds r2, #1
	cmp r2, #8
	bls _0804221C
	movs r0, #1
_08042236:
	bx lr
	.syntax divided
