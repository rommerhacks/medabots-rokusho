	.syntax unified

	thumb_func_start sub_0801372C
sub_0801372C: @ 0x0801372C
	push {r4, r5, lr}
	bl update_all_battle_status_sprites
	ldr r4, _08013778 @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	ldr r0, _0801377C @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _08013784
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r4, _08013780 @ =0x0000FFFF
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
	b _0801378C
	.align 2, 0
_08013778: .4byte 0x03001800
_0801377C: .4byte 0x03000440
_08013780: .4byte 0x0000FFFF
_08013784:
	ldr r1, _08013794 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0801378C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08013794: .4byte 0x0300137C
	.syntax divided
