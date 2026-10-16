	.syntax unified

	thumb_func_start sub_0801827C
	.global sub_0801827C
sub_0801827C: @ 0x0801827C
	ldr r2, _080182A0 @ =0x083AD3A4
	ldr r0, _080182A4 @ =0x03000440
	adds r3, r0, #0
	adds r3, #0x3d
	adds r0, #0x3c
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrb r3, [r3]
	adds r0, r0, r3
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r1, #0
	beq _080182A8
	subs r0, #0x10
	b _080182AA
	.align 2, 0
_080182A0: .4byte 0x083AD3A4
_080182A4: .4byte 0x03000440
_080182A8:
	adds r0, #0x10
_080182AA:
	bx lr
	.syntax divided
