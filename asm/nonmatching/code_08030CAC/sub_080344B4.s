	.syntax unified

	thumb_func_start sub_080344B4
sub_080344B4: @ 0x080344B4
	push {lr}
	bl sub_08023730
	ldr r0, _080344CC @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _080344C8
	bl sub_08034F08
_080344C8:
	pop {r0}
	bx r0
	.align 2, 0
_080344CC: .4byte 0x03001800
	.syntax divided
