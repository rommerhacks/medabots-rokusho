	.syntax unified

	thumb_func_start sub_0800DF14
sub_0800DF14: @ 0x0800DF14
	push {lr}
	bl sub_0800EBFC
	bl sub_0800EF58
	ldr r0, _0800DF44 @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #0x50
	bl sub_08041C14
	bl load_medapart_sprite_by_slot
	bl update_blend_effect
	cmp r0, #0
	beq _0800DF3E
	ldr r1, _0800DF48 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0800DF3E:
	pop {r0}
	bx r0
	.align 2, 0
_0800DF44: .4byte 0x03001780
_0800DF48: .4byte 0x0300137C
	.syntax divided
