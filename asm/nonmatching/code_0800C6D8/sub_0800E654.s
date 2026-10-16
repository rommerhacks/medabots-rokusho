	.syntax unified

	thumb_func_start sub_0800E654
sub_0800E654: @ 0x0800E654
	push {lr}
	bl sub_0800EBFC
	bl load_medapart_sprite_by_slot
	movs r0, #1
	movs r1, #5
	bl clear_sprite_table_mask
	ldr r0, _0800E684 @ =0x084E2E78
	ldr r1, _0800E688 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	bl setup_battle_cursor_sprite_0800FF50
	bl sub_0803FB0C
	ldr r1, _0800E68C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800E684: .4byte 0x084E2E78
_0800E688: .4byte 0x050003C0
_0800E68C: .4byte 0x0300137C
	.syntax divided
