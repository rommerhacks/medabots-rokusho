	.syntax unified

	thumb_func_start sub_0801112C
sub_0801112C: @ 0x0801112C
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r0, _08011150 @ =0x03001800
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, _08011154 @ =0x0300137C
	movs r0, #0x43
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08011150: .4byte 0x03001800
_08011154: .4byte 0x0300137C
	.syntax divided
