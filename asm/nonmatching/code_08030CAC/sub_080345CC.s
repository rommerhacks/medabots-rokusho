	.syntax unified

	thumb_func_start sub_080345CC
sub_080345CC: @ 0x080345CC
	push {lr}
	bl sub_08025FA0
	ldr r0, _080345E4 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _080345E0
	bl sub_08034F08
_080345E0:
	pop {r0}
	bx r0
	.align 2, 0
_080345E4: .4byte 0x03001800
	.syntax divided
