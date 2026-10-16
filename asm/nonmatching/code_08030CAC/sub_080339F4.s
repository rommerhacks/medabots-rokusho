	.syntax unified

	thumb_func_start sub_080339F4
sub_080339F4: @ 0x080339F4
	push {lr}
	bl sub_0801C4FC
	ldr r0, _08033A0C @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033A08
	bl sub_08034F08
_08033A08:
	pop {r0}
	bx r0
	.align 2, 0
_08033A0C: .4byte 0x03001800
	.syntax divided
