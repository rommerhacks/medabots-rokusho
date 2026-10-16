	.syntax unified

	thumb_func_start sub_08004A78
sub_08004A78: @ 0x08004A78
	push {r4, r5, lr}
	bl sub_08004E74
	bl setup_overworld_scene_from_position
	ldr r0, _08004AE0 @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x86
	ldrh r0, [r4]
	cmp r0, #0x18
	bne _08004AEC
	ldr r3, _08004AE4 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x51
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r2, #0xd3
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r2, #0
	strh r1, [r0]
	movs r5, #0xd4
	lsls r5, r5, #1
	adds r0, r3, r5
	strh r1, [r0]
	adds r5, #2
	adds r0, r3, r5
	strh r1, [r0]
	adds r5, #2
	adds r0, r3, r5
	strh r1, [r0]
	adds r5, #3
	adds r0, r3, r5
	strb r2, [r0]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r0, #1
	strb r0, [r2]
	strh r1, [r4]
	ldr r1, _08004AE8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _08004AF0
	.align 2, 0
_08004AE0: .4byte 0x03000440
_08004AE4: .4byte 0x03001800
_08004AE8: .4byte 0x0300137C
_08004AEC:
	adds r0, #1
	strh r0, [r4]
_08004AF0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
