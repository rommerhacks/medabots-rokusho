	.syntax unified

	thumb_func_start sub_08034D60
sub_08034D60: @ 0x08034D60
	push {lr}
	bl sub_0802C2AC
	ldr r0, _08034D78 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034D74
	bl sub_08034F08
_08034D74:
	pop {r0}
	bx r0
	.align 2, 0
_08034D78: .4byte 0x03001800
	.syntax divided
