	.syntax unified

	thumb_func_start sub_08034C9C
sub_08034C9C: @ 0x08034C9C
	push {lr}
	bl sub_0802A0E8
	ldr r0, _08034CB4 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034CB0
	bl sub_08034F08
_08034CB0:
	pop {r0}
	bx r0
	.align 2, 0
_08034CB4: .4byte 0x03001800
	.syntax divided
