	.syntax unified

	thumb_func_start sub_08034CD4
sub_08034CD4: @ 0x08034CD4
	push {lr}
	bl sub_0802AAD0
	ldr r0, _08034CEC @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034CE8
	bl sub_08034F08
_08034CE8:
	pop {r0}
	bx r0
	.align 2, 0
_08034CEC: .4byte 0x03001800
	.syntax divided
