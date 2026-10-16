	.syntax unified

	thumb_func_start update_all_battle_sprite_orbits
update_all_battle_sprite_orbits: @ 0x08012098
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r0, _080120C4 @ =0x03001800
	ldrb r1, [r0, #2]
	cmp r4, r1
	bhs _080120BC
	adds r6, r0, #0
	movs r5, #0x28
_080120A8:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl update_battle_sprite_orbiting_positions
	adds r5, #4
	adds r4, #1
	ldrb r0, [r6, #2]
	cmp r4, r0
	blo _080120A8
_080120BC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080120C4: .4byte 0x03001800
	.syntax divided
