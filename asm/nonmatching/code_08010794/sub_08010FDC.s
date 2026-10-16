	.syntax unified

	thumb_func_start sub_08010FDC
sub_08010FDC: @ 0x08010FDC
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl calculate_battle_score_summary
	ldr r0, _0801100C @ =0x030004DE
	ldr r1, _08011010 @ =0x03001800
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #0x35
	bl divide_by_100000_b
	bl sub_0803FB0C
	ldr r1, _08011014 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0801100C: .4byte 0x030004DE
_08011010: .4byte 0x03001800
_08011014: .4byte 0x0300137C
	.syntax divided
