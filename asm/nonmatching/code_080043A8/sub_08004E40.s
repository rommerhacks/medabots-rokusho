	.syntax unified

	thumb_func_start sub_08004E40
sub_08004E40: @ 0x08004E40
	push {lr}
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r0, _08004E64 @ =0x03000440
	adds r0, #0x96
	movs r1, #0
	strb r1, [r0]
	ldr r0, _08004E68 @ =0x03000430
	str r1, [r0]
	ldr r2, _08004E6C @ =0x03002B8C
	movs r0, #7
	str r0, [r2]
	ldr r0, _08004E70 @ =0x0300137C
	str r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08004E64: .4byte 0x03000440
_08004E68: .4byte 0x03000430
_08004E6C: .4byte 0x03002B8C
_08004E70: .4byte 0x0300137C
	.syntax divided
