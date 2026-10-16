	.syntax unified

	thumb_func_start sub_08034D44
sub_08034D44: @ 0x08034D44
	push {lr}
	bl sub_0802BD6C
	ldr r0, _08034D5C @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034D58
	bl sub_08034F08
_08034D58:
	pop {r0}
	bx r0
	.align 2, 0
_08034D5C: .4byte 0x03001800
	.syntax divided
