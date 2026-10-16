	.syntax unified

	thumb_func_start sub_08034C64
sub_08034C64: @ 0x08034C64
	push {lr}
	bl sub_08029840
	ldr r0, _08034C7C @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034C78
	bl sub_08034F08
_08034C78:
	pop {r0}
	bx r0
	.align 2, 0
_08034C7C: .4byte 0x03001800
	.syntax divided
