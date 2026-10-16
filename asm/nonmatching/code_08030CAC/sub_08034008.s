	.syntax unified

	thumb_func_start sub_08034008
sub_08034008: @ 0x08034008
	push {lr}
	bl sub_08035BD4
	ldr r1, _08034028 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0x87
	ldrb r0, [r0]
	adds r1, #0xa7
	ldrb r1, [r1]
	bl sub_08035BFC
	bl sub_08034F08
	pop {r0}
	bx r0
	.align 2, 0
_08034028: .4byte 0x03001800
	.syntax divided
