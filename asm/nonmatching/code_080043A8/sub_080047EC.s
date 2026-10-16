	.syntax unified

	thumb_func_start sub_080047EC
sub_080047EC: @ 0x080047EC
	push {r4, r5, lr}
	bl sub_08004E74
	bl setup_overworld_scene_from_position
	bl sub_08007480
	ldr r0, _08004824 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #0x20
	bhi _0800482C
	adds r1, r0, #0
	ldr r4, _08004828 @ =0x0000FFFF
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r5]
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08004834
	.align 2, 0
_08004824: .4byte 0x03000440
_08004828: .4byte 0x0000FFFF
_0800482C:
	ldr r1, _0800483C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08004834:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800483C: .4byte 0x0300137C
	.syntax divided
