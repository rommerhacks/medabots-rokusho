	.syntax unified

	thumb_func_start check_and_update_battle_sprite_orbit
	.global check_and_update_battle_sprite_orbit
check_and_update_battle_sprite_orbit: @ 0x0800598C
	push {r4, r5, lr}
	sub sp, #4
	ldr r1, _080059C8 @ =0x030017A0
	ldr r0, _080059CC @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x51
	ldrb r4, [r5]
	lsls r4, r4, #3
	adds r4, r4, r1
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	ldrb r2, [r4, #4]
	ldrb r3, [r4, #5]
	ldrb r4, [r4, #6]
	str r4, [sp]
	bl validate_medapart_stats
	cmp r0, #0
	beq _080059BE
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, #0xa
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
_080059BE:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080059C8: .4byte 0x030017A0
_080059CC: .4byte 0x03000440
	.syntax divided
