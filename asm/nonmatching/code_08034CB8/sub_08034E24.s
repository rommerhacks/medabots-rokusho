	.syntax unified

	thumb_func_start sub_08034E24
sub_08034E24: @ 0x08034E24
	push {lr}
	bl sub_0802F030
	ldr r0, _08034E3C @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034E38
	bl sub_08034F08
_08034E38:
	pop {r0}
	bx r0
	.align 2, 0
_08034E3C: .4byte 0x03001800
	.syntax divided
