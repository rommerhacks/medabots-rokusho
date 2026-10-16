	.syntax unified

	thumb_func_start sub_0803435C
sub_0803435C: @ 0x0803435C
	push {lr}
	bl sub_080209B0
	ldr r0, _08034374 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034370
	bl sub_08034F08
_08034370:
	pop {r0}
	bx r0
	.align 2, 0
_08034374: .4byte 0x03001800
	.syntax divided
