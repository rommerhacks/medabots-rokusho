	.syntax unified

	thumb_func_start sub_0806D3F4
sub_0806D3F4: @ 0x0806D3F4
	push {lr}
	bl update_bg2_affine_scanline_params
	ldr r1, _0806D418 @ =0x08485EC4
	ldr r0, _0806D41C @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	bl update_sprite_special_effects
	bl sub_0806D288
	pop {r0}
	bx r0
	.align 2, 0
_0806D418: .4byte 0x08485EC4
_0806D41C: .4byte 0x0300137C
	.syntax divided
