	.syntax unified

	thumb_func_start sub_0803447C
sub_0803447C: @ 0x0803447C
	push {lr}
	bl sub_08022FF0
	ldr r0, _08034494 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034490
	bl sub_08034F08
_08034490:
	pop {r0}
	bx r0
	.align 2, 0
_08034494: .4byte 0x03001800
	.syntax divided
