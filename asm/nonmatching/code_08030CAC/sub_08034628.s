	.syntax unified

	thumb_func_start sub_08034628
sub_08034628: @ 0x08034628
	push {lr}
	bl sub_08026108
	ldr r0, _08034640 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803463C
	bl sub_08034F08
_0803463C:
	pop {r0}
	bx r0
	.align 2, 0
_08034640: .4byte 0x03001800
	.syntax divided
