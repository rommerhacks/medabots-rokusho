	.syntax unified

	thumb_func_start scene_fade_and_scroll_camera
scene_fade_and_scroll_camera: @ 0x080647E4
	push {r4, lr}
	ldr r4, _08064834 @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x50
	bl blend_fade_step_08065598
	cmp r0, #0
	beq _080647FA
	ldr r1, _08064838 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
_080647FA:
	ldr r3, _0806483C @ =0x0300057C
	ldr r2, [r4]
	movs r1, #0x3a
	ldrsh r0, [r2, r1]
	lsls r0, r0, #4
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r1, _08064840 @ =0x000001FF
	ands r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r2, #0x3a]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	asrs r0, r0, #0x1f
	subs r4, #0xb8
	adds r1, r4, #0
	ands r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #0x3a]
	adds r0, #1
	strh r0, [r2, #0x3a]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08064834: .4byte 0x03006F74
_08064838: .4byte 0x0300137C
_0806483C: .4byte 0x0300057C
_08064840: .4byte 0x000001FF
	.syntax divided
