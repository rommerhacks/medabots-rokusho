	.syntax unified

	thumb_func_start sub_08015528
sub_08015528: @ 0x08015528
	ldr r3, _08015544 @ =0x03000590
	subs r1, #1
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r0, r0, #8
	adds r2, r2, r0
	adds r2, r2, r3
	adds r2, #0x59
	ldrb r0, [r2]
	cmp r0, #0
	beq _08015548
	movs r0, #0
	b _0801554A
	.align 2, 0
_08015544: .4byte 0x03000590
_08015548:
	movs r0, #1
_0801554A:
	bx lr
	.syntax divided
