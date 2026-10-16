	.syntax unified

	thumb_func_start sub_08034E08
sub_08034E08: @ 0x08034E08
	push {lr}
	bl sub_0802EBC0
	ldr r0, _08034E20 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034E1C
	bl sub_08034F08
_08034E1C:
	pop {r0}
	bx r0
	.align 2, 0
_08034E20: .4byte 0x03001800
	.syntax divided
