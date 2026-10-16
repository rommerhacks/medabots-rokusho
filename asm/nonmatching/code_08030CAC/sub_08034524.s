	.syntax unified

	thumb_func_start sub_08034524
sub_08034524: @ 0x08034524
	push {lr}
	bl sub_08024998
	ldr r0, _0803453C @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034538
	bl sub_08034F08
_08034538:
	pop {r0}
	bx r0
	.align 2, 0
_0803453C: .4byte 0x03001800
	.syntax divided
