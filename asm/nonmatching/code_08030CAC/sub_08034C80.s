	.syntax unified

	thumb_func_start sub_08034C80
sub_08034C80: @ 0x08034C80
	push {lr}
	bl sub_08029E0C
	ldr r0, _08034C98 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034C94
	bl sub_08034F08
_08034C94:
	pop {r0}
	bx r0
	.align 2, 0
_08034C98: .4byte 0x03001800
	.syntax divided
