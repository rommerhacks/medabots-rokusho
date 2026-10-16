	.syntax unified

	thumb_func_start apply_battle_damage_tick
apply_battle_damage_tick: @ 0x0801CB74
	push {r4, lr}
	ldr r4, _0801CBA0 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0xd0
	ldrb r1, [r1]
	adds r2, r4, #0
	adds r2, #0xc8
	ldrh r2, [r2]
	bl reduce_bot_part_stat
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801CBA0: .4byte 0x03001800
	.syntax divided
