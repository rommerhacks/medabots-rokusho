	.syntax unified

	thumb_func_start sub_08034BA0
sub_08034BA0: @ 0x08034BA0
	push {lr}
	bl sub_08026FD0
	ldr r0, _08034BB8 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034BB4
	bl sub_08034F08
_08034BB4:
	pop {r0}
	bx r0
	.align 2, 0
_08034BB8: .4byte 0x03001800
	.syntax divided
