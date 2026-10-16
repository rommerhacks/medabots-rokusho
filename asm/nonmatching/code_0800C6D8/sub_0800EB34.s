	.syntax unified

	thumb_func_start sub_0800EB34
sub_0800EB34: @ 0x0800EB34
	push {lr}
	bl sub_0800EBFC
	bl load_medapart_sprite_by_slot
	bl sub_0801013C
	cmp r0, #0
	beq _0800EB56
	movs r0, #4
	movs r1, #1
	bl clear_sprite_table_mask
	ldr r1, _0800EB5C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0800EB56:
	pop {r0}
	bx r0
	.align 2, 0
_0800EB5C: .4byte 0x0300137C
	.syntax divided
