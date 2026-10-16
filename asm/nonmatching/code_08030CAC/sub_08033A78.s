	.syntax unified

	thumb_func_start sub_08033A78
sub_08033A78: @ 0x08033A78
	push {lr}
	bl sub_0801D380
	ldr r0, _08033A90 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033A8C
	bl sub_08034F08
_08033A8C:
	pop {r0}
	bx r0
	.align 2, 0
_08033A90: .4byte 0x03001800
	.syntax divided
