	.syntax unified

	thumb_func_start sub_08034D98
sub_08034D98: @ 0x08034D98
	push {lr}
	bl sub_0802CBE8
	ldr r0, _08034DB0 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034DAC
	bl sub_08034F08
_08034DAC:
	pop {r0}
	bx r0
	.align 2, 0
_08034DB0: .4byte 0x03001800
	.syntax divided
