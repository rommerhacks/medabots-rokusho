	.syntax unified

	thumb_func_start sub_080115E8
sub_080115E8: @ 0x080115E8
	push {r4, r5, lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl setup_battle_result_sprite
	bl sub_08012468
	ldr r0, _08011628 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _08011630
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r4, _0801162C @ =0x0000FFFF
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r5]
	lsls r1, r1, #2
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08011638
	.align 2, 0
_08011628: .4byte 0x03000440
_0801162C: .4byte 0x0000FFFF
_08011630:
	ldr r1, _08011640 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08011638:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08011640: .4byte 0x0300137C
	.syntax divided
