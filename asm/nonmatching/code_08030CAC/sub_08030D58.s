	.syntax unified

	thumb_func_start sub_08030D58
sub_08030D58: @ 0x08030D58
	push {lr}
	movs r0, #0
	bl sub_0801C0BC
	cmp r0, #0
	beq _08030D6C
	ldr r1, _08030D70 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08030D6C:
	pop {r0}
	bx r0
	.align 2, 0
_08030D70: .4byte 0x0300137C
	.syntax divided
