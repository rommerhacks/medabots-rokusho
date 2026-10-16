	.syntax unified

	thumb_func_start sub_0803440C
sub_0803440C: @ 0x0803440C
	push {lr}
	bl sub_08022154
	ldr r0, _08034424 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034420
	bl sub_08034F08
_08034420:
	pop {r0}
	bx r0
	.align 2, 0
_08034424: .4byte 0x03001800
	.syntax divided
