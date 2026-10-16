	.syntax unified

	thumb_func_start sub_08034BBC
sub_08034BBC: @ 0x08034BBC
	push {lr}
	bl sub_0802793C
	ldr r0, _08034BD4 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034BD0
	bl sub_08034F08
_08034BD0:
	pop {r0}
	bx r0
	.align 2, 0
_08034BD4: .4byte 0x03001800
	.syntax divided
