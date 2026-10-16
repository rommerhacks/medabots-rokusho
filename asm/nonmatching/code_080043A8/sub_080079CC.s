	.syntax unified

	thumb_func_start sub_080079CC
sub_080079CC: @ 0x080079CC
	push {lr}
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r0, _080079E8 @ =0x03000440
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #4
	bne _080079EC
	movs r0, #0
	bl sub_08044CDC
	b _080079F8
	.align 2, 0
_080079E8: .4byte 0x03000440
_080079EC:
	ldr r1, _080079FC @ =0x03002B8C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08007A00 @ =0x0300137C
	movs r0, #0x10
	str r0, [r1]
_080079F8:
	pop {r0}
	bx r0
	.align 2, 0
_080079FC: .4byte 0x03002B8C
_08007A00: .4byte 0x0300137C
	.syntax divided
