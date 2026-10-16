	.syntax unified

	thumb_func_start set_sprite_anim_and_store
	.global set_sprite_anim_and_store
set_sprite_anim_and_store: @ 0x08052140
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r1, r4, #0
	bl set_sprite_animation_state
	strb r4, [r5, #5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.syntax divided
