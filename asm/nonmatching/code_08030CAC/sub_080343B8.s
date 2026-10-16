	.syntax unified

	thumb_func_start sub_080343B8
sub_080343B8: @ 0x080343B8
	push {lr}
	bl sub_08020CFC
	ldr r0, _080343D0 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _080343CC
	bl sub_08034F08
_080343CC:
	pop {r0}
	bx r0
	.align 2, 0
_080343D0: .4byte 0x03001800
	.syntax divided
