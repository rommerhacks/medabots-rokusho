	.syntax unified

	thumb_func_start sub_080287C0
sub_080287C0: @ 0x080287C0
	push {lr}
	bl sub_08037B9C
	cmp r0, #0
	beq _080287D4
	ldr r1, _080287D8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080287D4:
	pop {r0}
	bx r0
	.align 2, 0
_080287D8: .4byte 0x03001800
	.syntax divided
