	.syntax unified

	thumb_func_start sub_08004A40
sub_08004A40: @ 0x08004A40
	push {lr}
	bl sub_08004E74
	bl setup_overworld_scene_from_position
	bl sub_0803E79C
	cmp r0, #0
	beq _08004A66
	ldr r0, _08004A6C @ =0x03005010
	movs r1, #0
	strh r1, [r0, #6]
	ldr r0, _08004A70 @ =0x03000440
	adds r0, #0x86
	strh r1, [r0]
	ldr r1, _08004A74 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08004A66:
	pop {r0}
	bx r0
	.align 2, 0
_08004A6C: .4byte 0x03005010
_08004A70: .4byte 0x03000440
_08004A74: .4byte 0x0300137C
	.syntax divided
