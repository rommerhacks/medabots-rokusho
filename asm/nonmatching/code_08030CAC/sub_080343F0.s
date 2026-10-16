	.syntax unified

	thumb_func_start sub_080343F0
sub_080343F0: @ 0x080343F0
	push {lr}
	bl sub_08021E04
	ldr r0, _08034408 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034404
	bl sub_08034F08
_08034404:
	pop {r0}
	bx r0
	.align 2, 0
_08034408: .4byte 0x03001800
	.syntax divided
