	.syntax unified

	thumb_func_start advance_sprite_by_terrain_modifier
	.global advance_sprite_by_terrain_modifier
advance_sprite_by_terrain_modifier: @ 0x0805011C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r5, #0
	b _0805012E
_08050126:
	adds r0, r4, #0
	bl advance_sprite_animation_frame
	adds r5, #1
_0805012E:
	adds r0, r4, #0
	bl sub_080518F4
	cmp r5, r0
	blt _08050126
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
