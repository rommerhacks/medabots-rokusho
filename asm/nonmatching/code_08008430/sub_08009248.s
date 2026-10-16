	.syntax unified

	thumb_func_start sub_08009248
sub_08009248: @ 0x08009248
	push {lr}
	bl sub_080093F8
	bl update_battle_sprite_visibility
	bl update_battle_sprite_and_check_done
	cmp r0, #0
	beq _0800926A
	movs r0, #7
	movs r1, #1
	bl clear_sprite_table_mask
	ldr r1, _08009270 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0800926A:
	pop {r0}
	bx r0
	.align 2, 0
_08009270: .4byte 0x0300137C
	.syntax divided
