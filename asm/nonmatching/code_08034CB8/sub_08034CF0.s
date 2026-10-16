	.syntax unified

	thumb_func_start sub_08034CF0
sub_08034CF0: @ 0x08034CF0
	push {lr}
	bl sub_0802ACCC
	ldr r0, _08034D08 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034D04
	bl sub_08034F08
_08034D04:
	pop {r0}
	bx r0
	.align 2, 0
_08034D08: .4byte 0x03001800
	.syntax divided
