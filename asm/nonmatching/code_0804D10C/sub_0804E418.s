	.syntax unified

	thumb_func_start sub_0804E418
sub_0804E418: @ 0x0804E418
	push {lr}
	ldr r0, _0804E430 @ =0x03006D20
	ldrb r0, [r0, #0xa]
	bl sub_080507E0
	cmp r0, #0
	beq _0804E42A
	bl sub_08050244
_0804E42A:
	pop {r0}
	bx r0
	.align 2, 0
_0804E430: .4byte 0x03006D20
	.syntax divided
