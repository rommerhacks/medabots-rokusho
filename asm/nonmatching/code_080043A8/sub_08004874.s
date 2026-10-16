	.syntax unified

	thumb_func_start sub_08004874
sub_08004874: @ 0x08004874
	push {lr}
	bl sub_08004E74
	bl setup_overworld_scene_from_position
	bl sub_08007480
	ldr r0, _080048A8 @ =0x03000440
	adds r0, #0x5c
	ldrh r0, [r0]
	cmp r0, #0x3c
	bls _080048A4
	movs r0, #8
	bl sound_stop_all_with_fade_guard
	movs r0, #6
	movs r1, #0x3f
	movs r2, #8
	bl set_blend_effect_mode
	ldr r1, _080048AC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080048A4:
	pop {r0}
	bx r0
	.align 2, 0
_080048A8: .4byte 0x03000440
_080048AC: .4byte 0x0300137C
	.syntax divided
