	.syntax unified

	thumb_func_start sub_08034E5C
sub_08034E5C: @ 0x08034E5C
	push {lr}
	bl sub_0802F990
	ldr r0, _08034E74 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034E70
	bl sub_08034F08
_08034E70:
	pop {r0}
	bx r0
	.align 2, 0
_08034E74: .4byte 0x03001800
	.syntax divided
