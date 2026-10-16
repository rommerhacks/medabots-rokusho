	.syntax unified

	thumb_func_start set_battle_sprite_animation
	.global set_battle_sprite_animation
set_battle_sprite_animation: @ 0x08050720
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	adds r0, r5, #0
	bl sub_0804DBA4
	ldr r1, _0805076C @ =0x03002C30
	mov r8, r1
	adds r0, #0x4f
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x20
	strb r6, [r0]
	adds r0, r5, #0
	bl sub_0804DBA4
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r6, #0
	bl compute_battle_sprite_anim_offset
	adds r4, #0x4f
	lsls r4, r4, #6
	add r4, r8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #6]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805076C: .4byte 0x03002C30
	.syntax divided
