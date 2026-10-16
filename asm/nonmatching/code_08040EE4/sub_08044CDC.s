	.syntax unified

	thumb_func_start sub_08044CDC
	.global sub_08044CDC
sub_08044CDC: @ 0x08044CDC
	push {lr}
	cmp r0, #1
	beq _08044CF6
	cmp r0, #1
	blo _08044CF0
	cmp r0, #2
	beq _08044CFC
	cmp r0, #3
	beq _08044D02
	b _08044D06
_08044CF0:
	bl sub_08064A74
	b _08044D06
_08044CF6:
	bl sub_08064A94
	b _08044D06
_08044CFC:
	bl sub_08064AB4
	b _08044D06
_08044D02:
	bl sub_08064AD4
_08044D06:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
