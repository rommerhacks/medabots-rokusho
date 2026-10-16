	.syntax unified

	thumb_func_start sub_080048B0
sub_080048B0: @ 0x080048B0
	push {lr}
	bl sub_08004E74
	bl setup_overworld_scene_from_position
	bl sub_08007480
	bl update_blend_effect
	cmp r0, #0
	beq _080048CE
	ldr r1, _080048D4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080048CE:
	pop {r0}
	bx r0
	.align 2, 0
_080048D4: .4byte 0x0300137C
	.syntax divided
