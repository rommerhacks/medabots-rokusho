	.syntax unified

	thumb_func_start sub_08034BD8
sub_08034BD8: @ 0x08034BD8
	push {lr}
	bl sub_08027F5C
	ldr r0, _08034BF0 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034BEC
	bl sub_08034F08
_08034BEC:
	pop {r0}
	bx r0
	.align 2, 0
_08034BF0: .4byte 0x03001800
	.syntax divided
