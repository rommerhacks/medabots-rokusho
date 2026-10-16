	.syntax unified

	thumb_func_start sub_0803402C
sub_0803402C: @ 0x0803402C
	push {lr}
	bl sub_0801DE1C
	ldr r0, _08034044 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034040
	bl sub_08034F08
_08034040:
	pop {r0}
	bx r0
	.align 2, 0
_08034044: .4byte 0x03001800
	.syntax divided
