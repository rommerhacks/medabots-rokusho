	.syntax unified

	thumb_func_start sub_080344D0
sub_080344D0: @ 0x080344D0
	push {lr}
	bl sub_08023AC8
	ldr r0, _080344E8 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _080344E4
	bl sub_08034F08
_080344E4:
	pop {r0}
	bx r0
	.align 2, 0
_080344E8: .4byte 0x03001800
	.syntax divided
