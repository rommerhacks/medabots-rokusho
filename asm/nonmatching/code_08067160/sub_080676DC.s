	.syntax unified

	thumb_func_start sub_080676DC
sub_080676DC: @ 0x080676DC
	push {r4, r5, r6, lr}
	bl update_scene_animation_frame
	ldr r0, _08067720 @ =0x03000440
	adds r6, r0, #0
	adds r6, #0x84
	ldrb r0, [r6]
	cmp r0, #0x40
	bhi _0806772C
	adds r1, r0, #0
	lsrs r1, r1, #1
	movs r4, #0x20
	subs r1, r4, r1
	ldr r5, _08067724 @ =0x0000FFFF
	movs r0, #0
	adds r2, r5, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r6]
	lsrs r0, r0, #1
	subs r4, r4, r0
	movs r0, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r6]
	adds r0, #1
	movs r1, #0
	strb r0, [r6]
	ldr r0, _08067728 @ =0x03006F74
	ldr r0, [r0]
	strb r1, [r0, #5]
	b _08067734
	.align 2, 0
_08067720: .4byte 0x03000440
_08067724: .4byte 0x0000FFFF
_08067728: .4byte 0x03006F74
_0806772C:
	ldr r1, _0806773C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08067734:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806773C: .4byte 0x0300137C
	.syntax divided
