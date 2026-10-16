	.syntax unified

	thumb_func_start sub_080677E0
sub_080677E0: @ 0x080677E0
	push {r4, r5, r6, lr}
	bl update_scene_animation_frame
	ldr r0, _0806783C @ =0x0848417C
	ldr r5, _08067840 @ =0x03006F74
	ldr r3, [r5]
	ldrb r1, [r3, #5]
	adds r1, r1, r0
	ldrb r6, [r1]
	ldrh r4, [r3, #0x3a]
	movs r0, #0x1f
	ands r4, r0
	cmp r4, #0
	bne _08067874
	movs r0, #0x3a
	ldrsh r2, [r3, r0]
	adds r1, r2, #0
	cmp r2, #0
	bge _08067808
	adds r1, #0x1f
_08067808:
	asrs r1, r1, #5
	cmp r6, r1
	ble _08067868
	adds r0, r3, #0
	adds r0, #0xac
	ldr r0, [r0]
	ldr r3, [r0]
	adds r1, #0x10
	movs r0, #0x1f
	ands r1, r0
	adds r0, r3, #0
	bl render_text_right_aligned
	ldr r1, [r5]
	movs r2, #0x3a
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0806782E
	adds r0, #0x1f
_0806782E:
	asrs r0, r0, #5
	cmp r6, r0
	bne _08067844
	adds r0, r1, #0
	adds r0, #0x7d
	strb r4, [r0]
	b _08067856
	.align 2, 0
_0806783C: .4byte 0x0848417C
_08067840: .4byte 0x03006F74
_08067844:
	adds r0, r1, #0
	adds r0, #0xac
	ldr r0, [r0]
	ldr r0, [r0]
	bl sub_08067160
	ldr r1, [r5]
	adds r1, #0x7d
	strb r0, [r1]
_08067856:
	ldr r0, _08067864 @ =0x03006F74
	ldr r1, [r0]
	adds r1, #0xac
	ldr r0, [r1]
	adds r0, #4
	str r0, [r1]
	b _08067874
	.align 2, 0
_08067864: .4byte 0x03006F74
_08067868:
	ldr r0, _080678CC @ =0x0300137C
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	ldr r0, _080678D0 @ =0x0000FFFF
	strh r0, [r3, #0x3a]
_08067874:
	ldr r5, _080678D4 @ =0x03006F74
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0x7d
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r2, [r1, #0x3a]
	movs r4, #0x1f
	adds r1, r4, #0
	ands r1, r2
	bl clear_stack_buffer_64
	ldr r0, [r5]
	movs r2, #0x3a
	ldrsh r1, [r0, r2]
	adds r0, r1, #0
	cmp r1, #0
	bge _0806789C
	adds r0, #0x1f
_0806789C:
	asrs r0, r0, #5
	adds r0, #5
	ands r0, r4
	adds r1, #2
	ands r1, r4
	bl scroll_tilemap_column
	ldr r0, [r5]
	ldrh r1, [r0, #0x3a]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080678BE
	ldr r1, _080678D8 @ =0x03004C30
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
_080678BE:
	ldr r1, [r5]
	ldrh r0, [r1, #0x3a]
	adds r0, #1
	strh r0, [r1, #0x3a]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080678CC: .4byte 0x0300137C
_080678D0: .4byte 0x0000FFFF
_080678D4: .4byte 0x03006F74
_080678D8: .4byte 0x03004C30
	.syntax divided
