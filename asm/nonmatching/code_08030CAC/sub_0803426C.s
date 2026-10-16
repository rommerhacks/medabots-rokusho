	.syntax unified

	thumb_func_start sub_0803426C
sub_0803426C: @ 0x0803426C
	push {lr}
	bl sub_0801FDEC
	ldr r0, _08034284 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034280
	bl sub_08034F08
_08034280:
	pop {r0}
	bx r0
	.align 2, 0
_08034284: .4byte 0x03001800
	.syntax divided
