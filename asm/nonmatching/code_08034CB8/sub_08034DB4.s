	.syntax unified

	thumb_func_start sub_08034DB4
sub_08034DB4: @ 0x08034DB4
	push {lr}
	bl sub_0802D688
	ldr r0, _08034DCC @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034DC8
	bl sub_08034F08
_08034DC8:
	pop {r0}
	bx r0
	.align 2, 0
_08034DCC: .4byte 0x03001800
	.syntax divided
