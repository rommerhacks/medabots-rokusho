	.syntax unified

	thumb_func_start sub_08068194
sub_08068194: @ 0x08068194
	push {lr}
	bl update_battle_sprite_explosions
	ldr r0, _080681C4 @ =0x03006F74
	ldr r2, [r0]
	ldrh r0, [r2, #0x3a]
	adds r1, r0, #1
	strh r1, [r2, #0x3a]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0x3b
	ble _080681D8
	subs r2, #0x3c
	cmp r2, #0x80
	bgt _080681CC
	ldr r0, _080681C8 @ =0x00007FFF
	asrs r2, r2, #2
	movs r1, #0x20
	subs r1, r1, r2
	movs r2, #1
	bl blend_obj_palettes_to_color_0803F998
	b _080681D8
	.align 2, 0
_080681C4: .4byte 0x03006F74
_080681C8: .4byte 0x00007FFF
_080681CC:
	bl sub_0803FB0C
	ldr r1, _080681DC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080681D8:
	pop {r0}
	bx r0
	.align 2, 0
_080681DC: .4byte 0x0300137C
	.syntax divided
