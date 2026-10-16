	.syntax unified

	thumb_func_start sub_08034428
sub_08034428: @ 0x08034428
	push {lr}
	bl sub_080223BC
	ldr r0, _08034440 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803443C
	bl sub_08034F08
_0803443C:
	pop {r0}
	bx r0
	.align 2, 0
_08034440: .4byte 0x03001800
	.syntax divided
