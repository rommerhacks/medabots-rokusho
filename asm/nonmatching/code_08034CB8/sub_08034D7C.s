	.syntax unified

	thumb_func_start sub_08034D7C
sub_08034D7C: @ 0x08034D7C
	push {lr}
	bl sub_0802C644
	ldr r0, _08034D94 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034D90
	bl sub_08034F08
_08034D90:
	pop {r0}
	bx r0
	.align 2, 0
_08034D94: .4byte 0x03001800
	.syntax divided
