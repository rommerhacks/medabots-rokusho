	.syntax unified

	thumb_func_start sub_080344EC
sub_080344EC: @ 0x080344EC
	push {lr}
	bl sub_08023C90
	ldr r0, _08034504 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034500
	bl sub_08034F08
_08034500:
	pop {r0}
	bx r0
	.align 2, 0
_08034504: .4byte 0x03001800
	.syntax divided
