	.syntax unified

	thumb_func_start sub_08004E98
	.global sub_08004E98
sub_08004E98: @ 0x08004E98
	push {r4, r5, lr}
	ldr r5, _08004EF0 @ =0x03002C30
	movs r0, #0
	ldr r4, _08004EF4 @ =0x0000C604
	strh r4, [r5]
	adds r1, r5, #0
	adds r1, #0x23
	strb r0, [r1]
	movs r0, #0
	bl update_battle_sprite_orbit_clockwise
	adds r0, r5, #0
	adds r0, #0x40
	strh r4, [r0]
	adds r1, r5, #0
	adds r1, #0x63
	movs r0, #0x10
	strb r0, [r1]
	movs r0, #1
	bl update_battle_sprite_orbit_clockwise
	adds r0, r5, #0
	adds r0, #0x80
	strh r4, [r0]
	adds r1, r5, #0
	adds r1, #0xa3
	movs r0, #0x20
	strb r0, [r1]
	movs r0, #2
	bl update_battle_sprite_orbit_clockwise
	adds r0, r5, #0
	adds r0, #0xc0
	strh r4, [r0]
	adds r1, r5, #0
	adds r1, #0xe3
	movs r0, #0x30
	strb r0, [r1]
	movs r0, #3
	bl update_battle_sprite_orbit_clockwise
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08004EF0: .4byte 0x03002C30
_08004EF4: .4byte 0x0000C604
	.syntax divided
