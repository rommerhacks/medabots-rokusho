	.syntax unified

	thumb_func_start sub_08030D3C
sub_08030D3C: @ 0x08030D3C
	push {lr}
	bl sub_0801C154
	cmp r0, #0
	beq _08030D4E
	ldr r1, _08030D54 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08030D4E:
	pop {r0}
	bx r0
	.align 2, 0
_08030D54: .4byte 0x0300137C
	.syntax divided
