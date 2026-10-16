	.syntax unified

	thumb_func_start sub_080036C8
sub_080036C8: @ 0x080036C8
	push {lr}
	bl sub_080039BC
	ldr r0, _080036EC @ =0x083B5F80
	ldr r0, [r0, #4]
	movs r1, #0
	bl process_sprite_anim_commands
	bl update_blend_effect
	cmp r0, #0
	beq _080036E8
	ldr r1, _080036F0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080036E8:
	pop {r0}
	bx r0
	.align 2, 0
_080036EC: .4byte 0x083B5F80
_080036F0: .4byte 0x0300137C
	.syntax divided
