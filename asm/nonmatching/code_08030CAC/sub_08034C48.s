	.syntax unified

	thumb_func_start sub_08034C48
sub_08034C48: @ 0x08034C48
	push {lr}
	bl sub_080294B4
	ldr r0, _08034C60 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034C5C
	bl sub_08034F08
_08034C5C:
	pop {r0}
	bx r0
	.align 2, 0
_08034C60: .4byte 0x03001800
	.syntax divided
