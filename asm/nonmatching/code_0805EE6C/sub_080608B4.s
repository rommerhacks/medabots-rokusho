	.syntax unified

	thumb_func_start sub_080608B4
sub_080608B4: @ 0x080608B4
	push {lr}
	ldr r0, _080608E0 @ =0x03006F74
	ldr r0, [r0]
	ldrb r0, [r0, #0x17]
	ldr r1, _080608E4 @ =0x08485504
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _080608D4
	ldr r1, _080608E8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080608D4:
	bl update_battle_sprite_animation
	bl update_animation_timer
	pop {r0}
	bx r0
	.align 2, 0
_080608E0: .4byte 0x03006F74
_080608E4: .4byte 0x08485504
_080608E8: .4byte 0x0300137C
	.syntax divided
