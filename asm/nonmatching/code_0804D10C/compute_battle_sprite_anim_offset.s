	.syntax unified

	thumb_func_start compute_battle_sprite_anim_offset
compute_battle_sprite_anim_offset: @ 0x080502D4
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl sub_0804DBA4
	ldr r1, _08050308 @ =0x03002C30
	adds r0, #0x4f
	lsls r0, r0, #6
	adds r0, r0, r1
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	lsls r1, r4, #1
	adds r1, r1, r4
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08050308: .4byte 0x03002C30
	.syntax divided
