	.syntax unified

	thumb_func_start sub_080049EC
sub_080049EC: @ 0x080049EC
	push {lr}
	bl sub_08004E74
	bl setup_overworld_scene_from_position
	ldr r0, _08004A10 @ =0x083CF3B0
	ldr r0, [r0, #0x2c]
	bl run_message
	cmp r0, #0
	beq _08004A0A
	ldr r1, _08004A14 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08004A0A:
	pop {r0}
	bx r0
	.align 2, 0
_08004A10: .4byte 0x083CF3B0
_08004A14: .4byte 0x0300137C
	.syntax divided
