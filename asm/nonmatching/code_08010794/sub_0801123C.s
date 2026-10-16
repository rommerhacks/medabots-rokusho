	.syntax unified

	thumb_func_start sub_0801123C
sub_0801123C: @ 0x0801123C
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r0, _08011260 @ =0x03001800
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, _08011264 @ =0x0300137C
	movs r0, #0x47
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08011260: .4byte 0x03001800
_08011264: .4byte 0x0300137C
	.syntax divided
