	.syntax unified

	thumb_func_start sub_0805E2E8
sub_0805E2E8: @ 0x0805E2E8
	push {lr}
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	bl reset_bg_scroll
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0x60
	strh r0, [r1]
	ldr r1, _0805E30C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0805E30C: .4byte 0x0300137C
	.syntax divided
