	.syntax unified

	thumb_func_start sub_08034C2C
sub_08034C2C: @ 0x08034C2C
	push {lr}
	bl sub_08028C40
	ldr r0, _08034C44 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034C40
	bl sub_08034F08
_08034C40:
	pop {r0}
	bx r0
	.align 2, 0
_08034C44: .4byte 0x03001800
	.syntax divided
