	.syntax unified

	thumb_func_start sub_0800E9F0
sub_0800E9F0: @ 0x0800E9F0
	push {lr}
	bl sub_0800EBFC
	bl load_medapart_sprite_by_slot
	movs r0, #6
	movs r1, #1
	bl clear_sprite_table_mask
	ldr r0, _0800EA20 @ =0x084E2E58
	ldr r1, _0800EA24 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	bl sub_0803FB0C
	bl setup_battle_bot_count_sprites
	ldr r1, _0800EA28 @ =0x0300137C
	movs r0, #0x13
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800EA20: .4byte 0x084E2E58
_0800EA24: .4byte 0x050003C0
_0800EA28: .4byte 0x0300137C
	.syntax divided
