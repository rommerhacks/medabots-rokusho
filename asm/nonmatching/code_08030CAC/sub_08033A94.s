	.syntax unified

	thumb_func_start sub_08033A94
sub_08033A94: @ 0x08033A94
	push {lr}
	bl sub_0801D40C
	ldr r0, _08033AAC @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033AA8
	bl sub_08034F08
_08033AA8:
	pop {r0}
	bx r0
	.align 2, 0
_08033AAC: .4byte 0x03001800
	.syntax divided
