	.syntax unified

	thumb_func_start sub_0800275C
sub_0800275C: @ 0x0800275C
	push {lr}
	bl poll_choice_menu
	cmp r0, #0
	beq _08002772
	bl sub_0803FB0C
	ldr r1, _08002778 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08002772:
	pop {r0}
	bx r0
	.align 2, 0
_08002778: .4byte 0x0300137C
	.syntax divided
