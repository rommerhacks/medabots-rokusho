	.syntax unified

	thumb_func_start sub_08004C58
sub_08004C58: @ 0x08004C58
	push {lr}
	bl sub_08004E74
	bl setup_overworld_scene_from_position
	ldr r0, _08004C90 @ =0x03000440
	adds r3, r0, #0
	adds r3, #0x86
	ldrh r0, [r3]
	cmp r0, #0x10
	bne _08004C9C
	ldr r0, _08004C94 @ =0x03001800
	adds r2, r0, #0
	adds r2, #0x51
	movs r1, #0
	strb r1, [r2]
	adds r2, #1
	strb r1, [r2]
	adds r2, #1
	strb r1, [r2]
	adds r0, #0x54
	strb r1, [r0]
	strh r1, [r3]
	ldr r1, _08004C98 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _08004CA0
	.align 2, 0
_08004C90: .4byte 0x03000440
_08004C94: .4byte 0x03001800
_08004C98: .4byte 0x0300137C
_08004C9C:
	adds r0, #1
	strh r0, [r3]
_08004CA0:
	pop {r0}
	bx r0
	.syntax divided
