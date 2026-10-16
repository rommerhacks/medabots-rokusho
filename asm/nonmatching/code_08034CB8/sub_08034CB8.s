	.syntax unified

	thumb_func_start sub_08034CB8
sub_08034CB8: @ 0x08034CB8
	push {lr}
	bl sub_0802A6AC
	ldr r0, _08034CD0 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034CCC
	bl sub_08034F08
_08034CCC:
	pop {r0}
	bx r0
	.align 2, 0
_08034CD0: .4byte 0x03001800
	.syntax divided
