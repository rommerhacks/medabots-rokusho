	.syntax unified

	thumb_func_start calculate_battle_score_summary
calculate_battle_score_summary: @ 0x08012584
	push {lr}
	ldr r0, _080125B0 @ =0x03001800
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bl calc_average_bot_stat_080125B4
	bl accumulate_alive_bot_score
	bl calc_average_bot_stat_0801264C
	bl calc_medaforce_gauge_from_damage
	bl sub_0801275C
	bl accumulate_team_armor_stats
	pop {r0}
	bx r0
	.align 2, 0
_080125B0: .4byte 0x03001800
	.syntax divided
